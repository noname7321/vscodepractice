# Python 变量赋值、浅拷贝与深拷贝详解

本文档根据图片内容，详细介绍 Python 中**变量赋值**、**浅拷贝**和**深拷贝**的区别，并提供清晰示例。

---

## 1. 变量的赋值（Assignment）

**核心概念：**
- 只是创建了一个新的变量名。
- 两个变量指向**同一个对象**。
- 修改对象会影响所有指向它的变量。

**示例：**
```python
a = [1, 2, 3]
b = a  # 赋值：b 指向 a 指向的同一个对象

b.append(4)
print(a)  # [1, 2, 3, 4]
print(b)  # [1, 2, 3, 4]

print(a is b)  # True
```

---

## 2. 外层与内层的含义（关键澄清）

**外层对象**：最外层的容器对象（例如最外层的 `list` / `dict` / `set`）。

**内层对象（子对象）**：外层容器里面的元素；当元素本身也是容器时，它就是“子对象”。

**理解要点：**
- 浅拷贝只会复制外层容器，内层元素仍然指向原来的对象。
- 如果内层元素是**不可变对象**（如 `int`、`str`、`tuple`），修改表现为“重新绑定”，不会影响原对象。
- 如果内层元素是**可变对象**（如 `list`、`dict`、`set`），就地修改会相互影响。

**示例（内层为可变对象时会共享）：**
```python
original = [[1, 2], [3, 4]]
shallow = original[:]

print(original is shallow)       # False（外层不同）
print(original[0] is shallow[0]) # True（内层同一对象）
```

---

## 3. 浅拷贝（Shallow Copy）

**核心概念：**
- 只复制**外层对象**。
- 内部的子对象**不会被复制**，仍然共享同一引用。
- 修改**子对象**会相互影响；修改外层结构只影响副本。

**常见方式：**
- 切片 `[:]`
- `list()`、`dict()`、`set()` 等构造函数
- `copy.copy()`

**示例：**
```python
import copy

original = [[1, 2], [3, 4]]
shallow = copy.copy(original)   # 或者 shallow = original[:]

# 修改外层
shallow.append([5, 6])
print(original)  # [[1, 2], [3, 4]]
print(shallow)   # [[1, 2], [3, 4], [5, 6]]

# 修改内层（共享子对象）
shallow[0].append(99)
print(original)  # [[1, 2, 99], [3, 4]]
print(shallow)   # [[1, 2, 99], [3, 4], [5, 6]]

print(original[0] is shallow[0])  # True
```

---

## 4. 深拷贝（Deep Copy）

**核心概念：**
- 使用 `copy.deepcopy()` 递归复制对象中的**所有子对象**。
- 新对象与原对象**完全独立**。
- 修改任何层级都不会相互影响。

**示例：**
```python
import copy

original = [[1, 2], [3, 4]]
deep = copy.deepcopy(original)

# 修改内层
deep[0].append(99)
print(original)  # [[1, 2], [3, 4]]
print(deep)      # [[1, 2, 99], [3, 4]]

print(original[0] is deep[0])  # False
```

---

## 对比总结

| 类型 | 是否创建新对象 | 是否复制子对象 | 修改子对象是否互相影响 | 常用方式 |
|---|---|---|---|---|
| 赋值 | ❌ | ❌ | ✅ | `b = a` |
| 浅拷贝 | ✅（外层） | ❌ | ✅ | `a[:]` / `list(a)` / `copy.copy(a)` |
| 深拷贝 | ✅（完全） | ✅ | ❌ | `copy.deepcopy(a)` |

---

## 实际场景建议

1. **仅需别名** → 赋值
2. **只复制一层结构**（内部不可变）→ 浅拷贝
3. **内部包含可变对象**且希望完全独立 → 深拷贝

---

## 小提示

- `is` 用于判断两个变量是否指向同一对象。
- `==` 用于判断两个对象的值是否相等。

**示例：**
```python
a = [1, 2]
b = a[:]
print(a == b)  # True
print(a is b)  # False
```
