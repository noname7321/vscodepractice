print("µ".encode("ascii", errors="ignore"))            # b'' (丢弃不可编码字符)
print("µ".encode("ascii", errors="replace"))           # b'?' (用问号替换)
print("€".encode("ascii", errors="xmlcharrefreplace")) # b'&#8364;'
print("€".encode("ascii", errors="backslashreplace"))  # b'\\u20ac' 或类似转义表示