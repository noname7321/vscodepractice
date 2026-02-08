"""
Low-frequency sitemap-driven scraper for codex.torporgames.com.

Respects robots.txt (sitemap-only is allowed) and throttles requests.
It walks from seed pages, follows internal links that appear in sitemap.xml,
and saves each page's text into folders that mirror the Codex left-nav tree
rather than the crawl order. Text comes from Archbee's embedded JSON to avoid
capturing navigation chrome.

Dependencies: requests, beautifulsoup4 (pip install requests beautifulsoup4)
"""
from __future__ import annotations
import time
import random
import pathlib
import re
import json
import xml.etree.ElementTree as ET
import gzip
from collections import deque
from typing import Dict, List, Set, Tuple

import requests
from bs4 import BeautifulSoup

BASE = "https://codex.torporgames.com"
SITEMAP_URL = f"{BASE}/sitemap.xml"
OUT_DIR = pathlib.Path("output/codex")
HEADERS = {
    "User-Agent": "codex-scraper/0.2 (+contact: your-email@example.com)",
    "Accept-Language": "en-US,en;q=0.8",
}
# Minimum delay between requests (seconds)
MIN_DELAY = 1.0
MAX_DELAY = 1.5


def fetch_xml(url: str) -> ET.Element:
    resp = requests.get(url, headers=HEADERS, timeout=30)
    resp.raise_for_status()

    data = resp.content
    content_type = resp.headers.get("Content-Type", "").lower()
    if url.endswith(".gz") or "gzip" in content_type:
        data = gzip.decompress(data)

    try:
        return ET.fromstring(data)
    except ET.ParseError:
        sample = data[:200]
        raise RuntimeError(f"Failed to parse XML from {url}; first bytes: {sample!r}")


def collect_urls_from_sitemap(url: str) -> List[str]:
    root = fetch_xml(url)
    urls = []
    for elem in root.findall("{*}url/{*}loc"):
        loc = elem.text.strip()
        urls.append(loc)
    return urls


def slugify(text: str) -> str:
    cleaned = re.sub(r"[^A-Za-z0-9._-]", "_", text.strip())
    return cleaned or "page"


def extract_text_from_nodes(nodes: List[dict]) -> str:
    parts: List[str] = []

    def walk(node: dict) -> List[str]:
        collected: List[str] = []
        if node.get("text"):
            collected.append(node["text"])
        for child in node.get("children", []) or []:
            collected.extend(walk(child))
        return collected

    for node in nodes:
        ntype = node.get("type", "")
        if ntype == "image":
            caption = (node.get("data") or {}).get("caption")
            if caption:
                parts.append(f"[Image] {caption}")
            continue

        texts = walk(node)
        combined = " ".join(t.strip() for t in texts if t.strip()).strip()
        if combined:
            parts.append(combined)

    return "\n\n".join(parts)


def parse_next_data(soup: BeautifulSoup) -> Tuple[dict | None, dict | None]:
    script_tag = soup.find("script", id="__NEXT_DATA__")
    if not script_tag or not script_tag.string:
        return None, None
    try:
        data = json.loads(script_tag.string)
    except json.JSONDecodeError:
        return None, None

    page_props = (data.get("props") or {}).get("pageProps") or {}
    return page_props.get("_doc"), page_props.get("_docSpace")


def build_doc_paths(tree: List[dict], prefix: List[str] | None = None) -> Dict[str, List[str]]:
    prefix = prefix or []
    mapping: Dict[str, List[str]] = {}
    for node in tree:
        name = node.get("name") or "untitled"
        node_id = node.get("id")
        path_here = prefix + [name]
        if node_id:
            mapping[node_id] = path_here
        children = node.get("children") or []
        if children:
            mapping.update(build_doc_paths(children, path_here))
    return mapping


def extract_main_text(soup: BeautifulSoup) -> str:
    for selector in ("main", "article", "body"):
        main = soup.select_one(selector)
        if main:
            break
    else:
        main = soup

    for tag in main(["script", "style", "nav", "footer", "header"]):
        tag.decompose()

    return main.get_text("\n", strip=True)


def fetch_page(url: str) -> str:
    resp = requests.get(url, headers=HEADERS, timeout=30)
    resp.raise_for_status()
    return resp.text


def find_internal_links(soup: BeautifulSoup, allowed: Set[str]) -> List[str]:
    links = []
    for a in soup.find_all("a", href=True):
        href = a["href"]
        if href.startswith("/"):
            href = BASE + href
        if not href.startswith(BASE):
            continue
        if href in allowed:
            links.append(href)
    return links


def main() -> None:
    OUT_DIR.mkdir(parents=True, exist_ok=True)
    print("Fetching sitemap...")
    allowed_urls = collect_urls_from_sitemap(SITEMAP_URL)
    allowed_set = set(allowed_urls)
    print(f"Allowed URLs from sitemap: {len(allowed_set)}")

    # Seed pages to start traversal; extend as needed
    seeds = [
        BASE,
        f"{BASE}/world",
        f"{BASE}/countries",
        f"{BASE}/characters",
    ]
    seeds = [s for s in seeds if s in allowed_set or s == BASE]

    visited: Set[str] = set()
    queue = deque(seeds)

    while queue:
        url = queue.popleft()
        if url in visited:
            continue
        visited.add(url)

        print(f"[{len(visited)}/{len(allowed_set)}] Fetching {url}")
        try:
            html = fetch_page(url)
        except Exception as exc:  # noqa: BLE001
            print(f"Failed {url}: {exc}")
            continue

        soup = BeautifulSoup(html, "html.parser")
        doc, doc_space = parse_next_data(soup)

        if doc_space:
            path_map = build_doc_paths(doc_space.get("publicDocsTree") or [])
        else:
            path_map = {}

        if doc:
            path_names = path_map.get(doc.get("id")) or [doc.get("name") or "untitled"]
            subdir = OUT_DIR.joinpath(*[slugify(p) for p in path_names[:-1]])
            subdir.mkdir(parents=True, exist_ok=True)
            filename = slugify(doc.get("urlKey") or doc.get("name") or "page")
            nodes = (doc.get("data") or {}).get("nodes") or []
            body = extract_text_from_nodes(nodes)
            heading = doc.get("name", "")
            text = f"{heading}\n\n{body}" if body.strip() else heading
        else:
            subdir = OUT_DIR
            subdir.mkdir(parents=True, exist_ok=True)
            filename = slugify(url.split(BASE)[-1].lstrip("/") or "root")
            text = extract_main_text(soup)

        (subdir / f"{filename}.html").write_text(html, encoding="utf-8")
        (subdir / f"{filename}.txt").write_text(text, encoding="utf-8")

        links = find_internal_links(soup, allowed_set)
        for link in links:
            if link not in visited:
                queue.append(link)

        delay = random.uniform(MIN_DELAY, MAX_DELAY)
        time.sleep(delay)

    print(f"Done. Visited {len(visited)} pages. Output: {OUT_DIR}")


if __name__ == "__main__":
    main()
