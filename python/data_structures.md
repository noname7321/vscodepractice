# Python 常用数据类型：序列、列表、元组、字典、集合

本文档简要介绍 Python 中常用的数据类型，并把相同性质的内容合并说明，减少重复。包含：序列（`str`/`bytes`/`list`/`tuple`）、映射（`dict`）与集合（`set`/`frozenset`）。

**目录**
- 如何创建这些数据类型
- 序列（通用操作与复杂度）
- 列表与元组（区别与常用方法）
- 字典（映射）
- 集合（Set）
- 常用内置函数
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

## 序列（通用操作与复杂度）

序列支持索引、切片、迭代和长度查询。适用于 `str`、`bytes`、`list`、`tuple`。

通用操作：连接（`+`）、重复（`*`）、成员测试（`in`）、长度（`len()`）。

示例：

```python
seq = [10, 20, 30, 40, 50]
print(seq[1])      # 20
print(seq[1:4])    # [20, 30, 40]
print(seq + [60])  # [10, 20, 30, 40, 50, 60]
print(30 in seq)   # True
print(len(seq))    # 5
```

时间复杂度（平均）：

- 索引 `seq[i]`：$O(1)$
- 切片 `seq[a:b]`：$O(k)$（$k$ 为切片长度）
- 连接 `seq1 + seq2`：$O(n+m)$
- 成员测试 `x in seq`：$O(n)$
- 长度 `len(seq)`：$O(1)$

---

## 列表与元组（区别与常用方法）

列表可变，适合频繁修改；元组不可变，适合只读、固定结构或作为字典键（元素可哈希时）。

### 列表常用方法

- `list.append(x)`：末尾追加
- `list.extend(iterable)`：批量追加
- `list.insert(i, x)`：插入
- `list.remove(x)`：删除第一个匹配项
- `list.pop(i=-1)`：弹出并返回
- `list.sort()` / `sorted()`：排序
- `list.reverse()`：反转

示例：

```python
L = [1, 2, 3]
L.append(4)          # [1,2,3,4]
L.insert(1, 99)      # [1,99,2,3]
last = L.pop()       # last=4, L=[1,99,2,3]
print(sorted(L))     # [1,2,3,99]
```

### 元组常用操作

元组不支持就地修改，常见用法是解包。

```python
t = (10, 20, 30)
x, y, z = t
print(t[0])     # 10
print(t[1:3])   # (20, 30)
```

### 时间复杂度（平均）

列表：

- 索引 `L[i]`：$O(1)$
- 追加 `list.append`：均摊 $O(1)$
- 末尾弹出 `list.pop()`：$O(1)$
- 插入/删除 `list.insert`、`list.remove`：$O(n)$
- 搜索 `list.index` / 成员测试 `x in L`：$O(n)$
- 排序 `list.sort` / `sorted`：$O(n\log n)$

元组：

- 索引 `t[i]`：$O(1)$
- 切片 `t[a:b]`：$O(k)$
- 成员测试 `x in t`：$O(n)$
- 连接 `t1 + t2`：$O(n+m)$

---

## 字典（映射）

字典是键到值的映射（哈希表），键必须可哈希。适合快速查找与更新。

常用方法：

- `dict.get(key, default=None)`：安全读取
- `dict.setdefault(key, default)`：不存在则设置
- `dict.pop(key, default)`：删除并返回
- `dict.update(other)`：合并
- `dict.keys()` / `dict.values()` / `dict.items()`：视图

示例：

```python
d = {'a': 1, 'b': 2}
print(d['a'])            # 1
print(d.get('c', 0))     # 0
d['c'] = 3               # {'a':1,'b':2,'c':3}
d.pop('b')               # {'a':1,'c':3}
print('a' in d)          # True
```

时间复杂度（平均）：

- 读取/写入 `d[key]`、`dict.get`：$O(1)$
- 删除 `dict.pop`：$O(1)$
- 成员测试 `key in d`：$O(1)$
- 遍历 `for k in d`：$O(n)$
- 合并 `dict.update`：$O(m)$（$m$ 为新增项数量）

---

## 集合（Set）

集合是无序且不重复的容器，适合去重与集合运算。

常用方法：

- `set.add(x)` / `set.update(iterable)`：添加
- `set.remove(x)` / `set.discard(x)`：删除
- 并集 `|` / `set.union()`、交集 `&` / `set.intersection()`、差集 `-` / `set.difference()`

示例：

```python
s = {1, 2, 3}
s.add(4)          # {1,2,3,4}
s.discard(2)      # {1,3,4}
print(3 in s)     # True
print(s | {5,6})  # {1,3,4,5,6}
```

时间复杂度（平均）：

- 添加/删除 `set.add` / `set.remove` / `set.discard`：$O(1)$
- 成员测试 `x in s`：$O(1)$
- 并集/交集/差集：$O(n+m)$

---

## 常用内置函数

- `len(x)`：长度
- `min(x)` / `max(x)`：最小/最大
- `sum(x)`：求和（数字序列）
- `any(iterable)` / `all(iterable)`：逻辑判断
- `sorted(iterable, key=..., reverse=...)`：排序
- `enumerate(iterable, start=0)`：带索引迭代
- `zip(*iterables)`：并行迭代

示例：

```python
items = ['a','b','c']
for i, v in enumerate(items, 1):
    print(i, v)

pairs = [(1,'one'), (2,'two')]
d = dict(pairs)
```

---

## 常见注意事项与建议

- 明确可变性：需要就地修改用 `list` 或 `dict`，不希望修改用 `tuple` 或 `frozenset`。
- 使用推导式和内置函数能写出更简洁、高效的代码。
- 大数据量下使用生成器表达式以节约内存（如 `sum(x*x for x in it)`）。
