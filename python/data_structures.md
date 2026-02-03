# Python 常用数据类型：序列、列表、元组、字典、集合

本文档按“每个方法一个示例”的结构讲解 Python 常用数据类型与操作。涵盖：序列（`str`/`bytes`/`list`/`tuple`）、映射（`dict`）与集合（`set`/`frozenset`）。

**目录**
- 如何创建这些数据类型
- 序列通用操作（每个方法一个示例）
- 列表（每个方法一个示例）
- 元组（每个操作一个示例）
- 字典（每个方法一个示例）
- 集合（每个方法一个示例）
- 常用内置函数（每个函数一个示例）
- 常见注意事项与建议

---

## 如何创建这些数据类型

```python
# 字符串与字节
s = "hello"
b = b"hello"

# 列表与元组
L = [1, 2, 3]
T = (1, 2, 3)
single = (1,)    # 单元素元组需要逗号

# 字典
d = {'a': 1, 'b': 2}
d2 = dict(a=1, b=2)
pairs = dict([('x', 9), ('y', 8)])

# 集合与不可变集合
s = {1, 2, 3}
empty_set = set()      # {} 是空字典
fs = frozenset([1, 2])
```

---

## 序列通用操作（每个方法一个示例）

适用于 `str`、`bytes`、`list`、`tuple`。

### 索引 `seq[i]`

```python
seq = [10, 20, 30]
print(seq[1])  # 20
```

### 切片 `seq[a:b]`

```python
seq = [10, 20, 30, 40]
print(seq[1:3])  # [20, 30]
```

### 连接 `seq1 + seq2`

```python
print([1, 2] + [3, 4])  # [1, 2, 3, 4]
```

### 重复 `seq * n`

```python
print(["a"] * 3)  # ['a', 'a', 'a']
```

### 成员测试 `x in seq`

```python
print(30 in [10, 20, 30])  # True
```

### 长度 `len(seq)`

```python
print(len((1, 2, 3)))  # 3
```

### 查找 `str.find(sub[, start[, end]])` / `str.rfind(sub[, start[, end]])`

```python
s = "hello world"
print(s.find("o"))   # 4
print(s.find("z"))   # -1
print(s.rfind("o"))  # 7
```

- `find` 返回子串首次出现的索引，找不到返回 `-1`；`rfind` 返回最后一次出现的索引。
- 注意：`str.index(sub)` 语义类似，但找不到时会抛出 `ValueError`，而不是返回 `-1`。
- 同样适用于 `bytes.find` / `bytes.rfind`。

**时间复杂度（平均）**
- 索引 `seq[i]`：$O(1)$
- 切片 `seq[a:b]`：$O(k)$（$k$ 为切片长度）
- 连接 `seq1 + seq2`：$O(n+m)$
- 成员测试 `x in seq`：$O(n)$
- 长度 `len(seq)`：$O(1)$

---

## 列表（每个方法一个示例）

列表可变，适合频繁增删改。

### `list.append(x)`：末尾追加

```python
L = [1, 2]
L.append(3)
print(L)  # [1, 2, 3]
```

### `list.extend(iterable)`：批量追加

```python
L = [1, 2]
L.extend([3, 4])
print(L)  # [1, 2, 3, 4]
```

### `list.insert(i, x)`：插入到指定位置

```python
L = [1, 3]
L.insert(1, 2)
print(L)  # [1, 2, 3]
```

### `list.remove(x)`：删除第一个匹配项

```python
L = [1, 2, 2, 3]
L.remove(2)
print(L)  # [1, 2, 3]
```

### `list.pop(i=-1)`：弹出并返回

```python
L = [1, 2, 3]
last = L.pop()
print(last, L)  # 3 [1, 2]
```

### `list.sort(key=None, reverse=False)`：原地排序

```python
L = [3, 1, 2]
L.sort()
print(L)  # [1, 2, 3]
```

### `sorted(iterable, key=None, reverse=False)`：返回新列表

```python
L = [3, 1, 2]
print(sorted(L, reverse=True))  # [3, 2, 1]
```

### `list.reverse()`：原地反转

```python
L = [1, 2, 3]
L.reverse()
print(L)  # [3, 2, 1]
```

### `list.index(x)`：返回首次出现的索引

```python
L = [10, 20, 30]
print(L.index(20))  # 1
```

### `list.count(x)`：统计出现次数

```python
L = [1, 2, 2, 3]
print(L.count(2))  # 2
```

**时间复杂度（平均）**
- 索引 `L[i]`：$O(1)$
- 追加 `list.append`：均摊 $O(1)$
- 末尾弹出 `list.pop()`：$O(1)$
- 插入/删除 `list.insert`、`list.remove`：$O(n)$
- 搜索 `list.index` / 成员测试 `x in L`：$O(n)$
- 排序 `list.sort` / `sorted`：$O(n\log n)$

---

## 元组（每个操作一个示例）

元组不可变，适合只读与结构化数据。

### 索引与切片

```python
t = (10, 20, 30)
print(t[0])    # 10
print(t[1:3])  # (20, 30)
```

### 解包

```python
t = (1, 2, 3)
a, b, c = t
print(a, b, c)  # 1 2 3
```

### `tuple.count(x)`：统计出现次数

```python
t = (1, 2, 2, 3)
print(t.count(2))  # 2
```

### `tuple.index(x)`：返回首次出现的索引

```python
t = (10, 20, 30)
print(t.index(20))  # 1
```

**时间复杂度（平均）**
- 索引 `t[i]`：$O(1)$
- 切片 `t[a:b]`：$O(k)$
- 成员测试 `x in t`：$O(n)$
- 连接 `t1 + t2`：$O(n+m)$

---

## 字典（每个方法一个示例）

字典是键到值的映射（哈希表），键必须可哈希。

### `d[key]`：读写

```python
d = {'a': 1}
d['b'] = 2
print(d['a'])  # 1
```

### `dict.get(key, default=None)`：安全读取

```python
d = {'a': 1}
print(d.get('c', 0))  # 0
```

### `dict.setdefault(key, default)`：不存在则设置

```python
d = {'a': 1}
print(d.setdefault('b', 2))  # 2
print(d)  # {'a': 1, 'b': 2}
```

### `dict.pop(key, default)`：删除并返回

```python
d = {'a': 1, 'b': 2}
val = d.pop('b')
print(val, d)  # 2 {'a': 1}
```

### `dict.update(other)`：合并

```python
d = {'a': 1}
d.update({'b': 2})
print(d)  # {'a': 1, 'b': 2}
```

### `dict.keys()`：键视图

```python
d = {'a': 1, 'b': 2}
print(list(d.keys()))  # ['a', 'b']
```

### `dict.values()`：值视图

```python
d = {'a': 1, 'b': 2}
print(list(d.values()))  # [1, 2]
```

### `dict.items()`：键值对视图

```python
d = {'a': 1, 'b': 2}
print(list(d.items()))  # [('a', 1), ('b', 2)]
```

**时间复杂度（平均）**
- 读取/写入 `d[key]`、`dict.get`：$O(1)$
- 删除 `dict.pop`：$O(1)$
- 成员测试 `key in d`：$O(1)$
- 遍历 `for k in d`：$O(n)$
- 合并 `dict.update`：$O(m)$（$m$ 为新增项数量）

---

## 集合（每个方法一个示例）

集合无序且元素不重复，适合去重与集合运算。

### `set.add(x)`：添加元素

```python
s = {1, 2}
s.add(3)
print(s)  # {1, 2, 3}
```

### `set.update(iterable)`：批量添加

```python
s = {1, 2}
s.update([2, 3, 4])
print(s)  # {1, 2, 3, 4}
```

### `set.remove(x)`：删除元素（不存在会报错）

```python
s = {1, 2, 3}
s.remove(2)
print(s)  # {1, 3}
```

### `set.discard(x)`：删除元素（不存在不报错）

```python
s = {1, 2, 3}
s.discard(9)
print(s)  # {1, 2, 3}
```

### 并集 `|` / `set.union()`

```python
a = {1, 2}
b = {2, 3}
print(a | b)  # {1, 2, 3}
```

### 交集 `&` / `set.intersection()`

```python
a = {1, 2}
b = {2, 3}
print(a & b)  # {2}
```

### 差集 `-` / `set.difference()`

```python
a = {1, 2}
b = {2, 3}
print(a - b)  # {1}
```

**时间复杂度（平均）**
- 添加/删除 `set.add` / `set.remove` / `set.discard`：$O(1)$
- 成员测试 `x in s`：$O(1)$
- 并集/交集/差集：$O(n+m)$

---

## 常用内置函数（每个函数一个示例）

### `len(x)`：长度

```python
print(len("abc"))  # 3
```

### `min(x)` / `max(x)`：最小/最大

```python
print(min([3, 1, 2]), max([3, 1, 2]))  # 1 3
```

### `sum(x)`：求和

```python
print(sum([1, 2, 3]))  # 6
```

### `any(iterable)`：任一为 True

```python
print(any([0, "", 5]))  # True
```

### `all(iterable)`：全部为 True

```python
print(all([1, "x", True]))  # True
```

### `sorted(iterable, key=None, reverse=False)`：排序

```python
print(sorted([3, 1, 2]))  # [1, 2, 3]
```

### `enumerate(iterable, start=0)`：带索引迭代

```python
items = ['a', 'b', 'c']
print(list(enumerate(items, 1)))  # [(1, 'a'), (2, 'b'), (3, 'c')]
```

### `zip(*iterables)`：并行迭代

```python
print(list(zip([1, 2], ['a', 'b'])))  # [(1, 'a'), (2, 'b')]
```

---

## 常见注意事项与建议

- 明确可变性：需要就地修改用 `list` 或 `dict`，不希望修改用 `tuple` 或 `frozenset`。
- 使用推导式和内置函数能写出更简洁、高效的代码。
- 大数据量下使用生成器表达式以节约内存（如 `sum(x*x for x in it)`）。
