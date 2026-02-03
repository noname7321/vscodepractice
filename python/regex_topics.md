# 正则表达式：基础符号与 re 模块常用函数

本文档覆盖以下内容，并为每个函数给出示例与参数解释：

1. 正则表达式简介及相关符号
2. `re.match()` 的使用
3. `re.search()` 与 `re.findall()` 的使用
4. `re.sub()` 与 `re.split()` 的使用

---

## 1. 正则表达式简介及相关符号

正则表达式用于在文本中“查找/匹配/替换”模式。

常见元字符（特殊符号）：

- `.`：匹配任意单个字符（不含换行，除非 `re.S`）
- `^`：匹配字符串开头
- `$`：匹配字符串结尾
- `*`：前一个元素重复 0 次或多次
- `+`：前一个元素重复 1 次或多次
- `?`：前一个元素重复 0 或 1 次（或用于非贪婪）
- `{m,n}`：前一个元素重复 m 到 n 次
- `[]`：字符集合（如 `[a-z]`）
- `()`：分组（可捕获）
- `|`：或
- `\d`：数字，等价 `[0-9]`
- `\w`：字母数字下划线，等价 `[A-Za-z0-9_]`
- `\s`：空白字符
- `\b`：单词边界

示例（带说明）：

```python
import re

text = "cat, car, cut"
pattern = r"c.t"            # '.' 匹配任意一个字符
print(re.findall(pattern, text))  # ['cat', 'car', 'cut'] -> 找到所有满足 c? t 的子串

pattern = r"^cat"           # '^' 要求在开头
print(bool(re.search(pattern, text)))  # True -> 文本开头是 cat

pattern = r"t$"             # '$' 要求在结尾
print(bool(re.search(pattern, text)))  # True -> 文本以 t 结尾
```

---

## 2. `re.match()` 的使用

`re.match(pattern, string, flags=0)` 只在字符串开头进行匹配。

参数说明：

- `pattern`：正则表达式模式字符串
- `string`：待匹配文本
- `flags`：可选标志位，例如 `re.I`（忽略大小写）、`re.S`（点号匹配换行）、`re.M`（多行模式）

示例（带说明）：

```python
import re

text = "Hello123"
pat = r"Hello"              # 期望在开头匹配 'Hello'
res = re.match(pat, text)    # match 从开头匹配
print(res.group())           # 'Hello' -> 成功匹配开头

text2 = "Say Hello"
res2 = re.match(pat, text2)
print(res2)                   # None -> 因为开头不是 Hello
```

---

## 3. `re.search()` 与 `re.findall()` 的使用

### 3.1 `re.search()`

`re.search(pattern, string, flags=0)` 在全文中查找第一次匹配。不会全部查找

参数说明：

- `pattern`：正则表达式模式字符串
- `string`：待搜索文本
- `flags`：可选标志位

示例（带说明）：

```python
import re

text = "ID: 123, ID: 456"
pat = r"\d+"                # '\d+' 匹配连续数字
res = re.search(pat, text)
print(res.group())            # '123' -> 返回第一个匹配
```

### 3.2 `re.findall()`

`re.findall(pattern, string, flags=0)` 返回全部匹配结果列表。

参数说明：

- `pattern`：正则表达式模式字符串
- `string`：待搜索文本
- `flags`：可选标志位

示例（带说明）：

```python
import re

text = "ID: 123, ID: 456"
pat = r"\d+"
res = re.findall(pat, text)
print(res)                    # ['123', '456'] -> 返回所有匹配
```

提示：如果 `pattern` 中包含捕获组 `()`，`findall` 会返回组内容而不是整段匹配。

---

## 4. `re.sub()` 与 `re.split()` 的使用

### 4.1 `re.sub()`

`re.sub(pattern, repl, string, count=0, flags=0)` 用于替换匹配内容。

参数说明：

- `pattern`：正则表达式模式字符串
- `repl`：替换字符串或替换函数
- `string`：待处理文本
- `count`：替换次数上限，`0` 表示全部替换
- `flags`：可选标志位

示例（带说明）：

```python
import re

text = "Price: 100, Price: 200"
pat = r"\d+"
res = re.sub(pat, "X", text, count=1)  # 只替换第一个数字
print(res)                               # "Price: X, Price: 200"
```

使用函数作为 `repl`：

```python
import re

def add_one(m):
    return str(int(m.group()) + 1)       # 将匹配到的数字 +1
# m.group()
# 含义：返回整个匹配的文本（等同于 m.group(0)）。如果正则含有捕获组，m.group(1) 返回第 1 个组匹配的文本，m.group(2) 返回第 2 个组，等等。

text = "1 2 3" # '\d+' 匹配连续数字
print(re.sub(r"\d+", add_one, text))   # "2 3 4"
```

### 4.2 `re.split()`

`re.split(pattern, string, maxsplit=0, flags=0)` 按模式分割字符串。

参数说明：

- `pattern`：正则表达式模式字符串
- `string`：待分割文本
- `maxsplit`：最多分割次数，`0` 表示不限制
- `flags`：可选标志位

示例（带说明）：

```python
import re

text = "a1b2c3"
res = re.split(r"\d", text, maxsplit=2)  # 只分割前两次数字
print(res)                                  # ['a', 'b', 'c3']
```

---

## 常见 flags 速览

- `re.I`：忽略大小写
- `re.M`：多行模式（`^`/`$` 按行生效）
- `re.S`：点号 `.` 匹配换行
- `re.X`：允许正则中添加空白和注释

示例：

```python
import re

text = "a\nB"
print(bool(re.search(r"b", text, flags=re.I)))  # True -> 忽略大小写
print(bool(re.search(r"a.b", text)))            # False -> 默认 '.' 不匹配换行
print(bool(re.search(r"a.b", text, flags=re.S)))# True -> re.S 让 '.' 匹配换行
```
