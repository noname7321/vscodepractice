# 字符串专题：常用方法、格式化、编码解码与处理技巧

本文档围绕以下主题进行详细说明：

1. 字符串的常用方法（基础）
2. 字符串常用的方法（进阶）
3. 格式化字符串的三种方式
4. `format()` 的详细格式控制
5. 字符串的编码与解码
6. 数据验证的方法
7. 字符串的处理：拼接操作
8. 字符串的处理：去重操作

---

## 1. 字符串的常用方法（基础）

这些方法适合日常文本处理与清洗：

- `str.strip([chars])`：去除两端空白或指定字符

	```python
	text = "  Hello  "
	print(text.strip())          # "Hello"
	print(",,Hi,,".strip(","))  # "Hi"
	```

- `str.lstrip([chars])` / `str.rstrip([chars])`：去除左侧/右侧空白或指定字符

	```python
	text = "--Hello--"
	print(text.lstrip("-"))  # "Hello--"
	print(text.rstrip("-"))  # "--Hello"
	```

- `str.lower()` / `str.upper()` / `str.title()`：大小写转换

	```python
	text = "hello world"
	print(text.upper())  # "HELLO WORLD"
	print(text.title())  # "Hello World"
	```

- `str.replace(old, new, count=-1)`：替换子串

	```python
	text = "foo foo foo"
	print(text.replace("foo", "bar"))     # "bar bar bar"
	print(text.replace("foo", "bar", 2))  # "bar bar foo"
	```

- `str.split(sep=None, maxsplit=-1)`：分割成列表

	```python
	csv = "a,b,c,d"
	print(csv.split(","))      # ['a', 'b', 'c', 'd']
	print(csv.split(",", 2))   # ['a', 'b', 'c,d']
	```

- `str.join(iterable)`：把可迭代对象连接为字符串

	```python
	print("-".join(["a", "b"]))  # "a-b"
	```

- `str.find(sub[, start[, end]])` / `str.rfind(sub[, start[, end]])`：查找子串位置（找不到返回 `-1`）

	```python
	text = "hello hello"
	print(text.find("lo"))           # 3
	print(text.find("lo", 5))        # 9
	print(text.rfind("lo", 0, 8))    # 3
	```

- `str.startswith(prefix[, start[, end]])` / `str.endswith(suffix[, start[, end]])`：前后缀判断

	```python
	path = "/usr/local/bin"
	print(path.startswith("/usr"))       # True
	print(path.startswith("/usr", 0, 4)) # True
	print(path.endswith("bin"))          # True
	print(path.endswith("bin", 0, 14))   # True
	```

---

## 2. 字符串常用的方法（进阶）

常用于格式化和校验的场景：

- `str.count(sub)`：统计子串出现次数

	```python
	s = "banana"
	print(s.count("an"))  # 2
	```

- `str.center(width, fillchar=' ')`：居中填充

	```python
	print("hi".center(6))      # "  hi  "
	print("hi".center(6, "-"))  # "--hi--"
	```

- `str.ljust(width, fillchar=' ')` / `str.rjust(width, fillchar=' ')`

	```python
	print("hi".ljust(5, "."))  # "hi..."
	print("hi".rjust(5, "."))  # "...hi"
	```

- `str.partition(sep)` / `str.rpartition(sep)`：三段切分

	```python
	print("a=b=c".partition("="))   # ('a', '=', 'b=c')
	print("a=b=c".rpartition("="))  # ('a=b', '=', 'c')
	```

- `str.splitlines(keepends=False)`：按行分割

	```python
	lines = "a\nb\n"
	print(lines.splitlines())          # ['a', 'b']
	print(lines.splitlines(True))      # ['a\n', 'b\n']
	```

- `str.translate(table)` / `str.maketrans()`：映射替换

	```python
	table = str.maketrans("ae", "12", "x")#把字符 'a' 映射为 '1'，把 'e' 映射为 '2'，并把第三个参数中的字符（此处为 'x'）标记为应被删除
	print("example".translate(table))  # "21mpl2"（删除 x）注意这里操作的对象是example，table是这个翻译表的名字
	```

---

## 3. 格式化字符串的三种方式

### 3.1 f-string（推荐，Python 3.6+）

```python
name = "Tom"
age = 18
print(f"{name} is {age} years old")
```

### 3.2 `str.format()`

```python
print("{} is {} years old".format("Tom", 18))
print("{name} is {age} years old".format(name="Tom", age=18))
```

### 3.3 `%` 旧式格式化

```python
print("%s is %d years old" % ("Tom", 18))
```

推荐顺序：f-string > `str.format()` > `%`。

---

## 4. `format()` 详细格式控制

格式说明符结构：

```
{字段名:填充 对齐 宽度.精度 类型}
```
- 宽度：整数，表示输出占用的最小字符数；若内容长度不足将用填充字符补齐。
- 精度：使用 `.N` 指定小数位数（常用于浮点），如 `:.2f`。
常用类型：

- `d`：整数
- `f`：浮点数
- `s`：字符串
- `%`：百分比
- `x` / `X`：十六进制

示例：

```python
num = 3.14159
print("{:.2f}".format(num))     # 3.14    -> {:.2f}: 固定点浮点显示，保留2位小数（四舍五入）
print("{:8.2f}".format(num))    # "    3.14" -> {:8.2f}: 宽度为8，默认右对齐；保留2位小数；不足用空格填充
print("{:0>8.2f}".format(num))  # "00003.14" -> {:0>8.2f}: 宽度8，右对齐，使用 '0' 填充到指定宽度
print("{:<8}".format("hi"))    # "hi      " -> {:<8}: 宽度8，左对齐，右侧用空格填充
print("{:^8}".format("hi"))    # "  hi    " -> {:^8}: 宽度8，居中对齐，两侧填充空格
print("{:>8}".format("hi"))    # "      hi" -> {:>8}: 宽度8，右对齐，左侧空格填充
print("{:.1%}".format(0.123))   # 12.3%  -> {:.1%}: 百分比显示（内部乘100并加 '%'），保留1位小数


千分位分隔：

```python
print("{:,.0f}".format(1234567))  # 1,234,567
```

f-string 与 `format()` 语法一致：

```python
print(f"{num:0>8.2f}")
```

---

## 5. 字符串的编码与解码

Python 中 `str` 是 Unicode 字符串，`bytes` 是字节序列：

- `str.encode(encoding, errors='strict')`：字符串 → 字节

	```python
	s = "中文"
	b = s.encode("utf-8")
	print(b)  # b'\xe4\xb8\xad\xe6\x96\x87'
	print("a?".encode("ascii", errors="ignore"))  # b'a'
	```

- `bytes.decode(encoding, errors='strict')`：字节 → 字符串

	```python
	b = b"\xe4\xb8\xad\xe6\x96\x87"
	print(b.decode("utf-8"))  # "中文"
	print(b"a?".decode("ascii", errors="replace"))  # "a?"
	```

常见编码：`utf-8`、`gbk`、`utf-16`。

---

## 6. 数据验证的方法

常用字符串判定方法：

- `str.isdigit()`：是否全是数字字符

	```python
	print("123".isdigit())   # True
	print("12.3".isdigit())  # False
	```

- `str.isdecimal()`：严格十进制数字

	```python
	print("123".isdecimal())  # True
	print("Ⅻ".isdecimal())    # False
	```

- `str.isalpha()`：是否全是字母

	```python
	print("abc".isalpha())   # True
	print("abc1".isalpha())  # False
	```

- `str.isalnum()`：字母或数字

	```python
	print("abc123".isalnum())  # True
	print("abc 123".isalnum()) # False
	```

- `str.isspace()`：是否全空白

	```python
	print("  \n".isspace())  # True
	print(" a ".isspace())   # False
	```

- `str.islower()` / `str.isupper()`：大小写判定

	```python
	print("abc".islower())  # True
	print("ABC".isupper())  # True
	```

如果需要更复杂验证（手机号、邮箱等），建议用正则：

```python
import re
print(bool(re.fullmatch(r"1[3-9]\d{9}", "13800138000")))
```

---

## 7. 字符串的处理：拼接操作

不同拼接方式：

- `+`：适合少量拼接
- `str.join()`：大量拼接更高效
- f-string：适合格式化拼接

示例：

```python
parts = ["a", "b", "c"]
print("".join(parts))  # "abc"
print("a" + "b" + "c")  # "abc"
print(f"{parts[0]}-{parts[1]}-{parts[2]}")  # "a-b-c"
```

---

## 8. 字符串的处理：去重操作

保留顺序去重（推荐）：

```python
s = "banana"
result = "".join(dict.fromkeys(s))
print(result)  # "ban"
```

不保留顺序去重：

```python
s = "banana"
result = "".join(set(s))
print(result)  # 顺序不保证
```

如果需要按大小写不敏感去重：

```python
s = "AaBbAa"
result = "".join(dict.fromkeys(s.lower()))
print(result)  # "ab"
```
