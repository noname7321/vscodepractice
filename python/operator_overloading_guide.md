# Python 运算符重载与特殊方法

本文档整理图片中的内容，介绍常见运算符与对应的特殊方法（魔法方法），并给出清晰示例。

---

## 1. 加法与减法

| 运算符 | 特殊方法 | 作用 |
|---|---|---|
| `+` | `__add__()` | 执行加法运算 |
| `-` | `__sub__()` | 执行减法运算 |

**示例：**
```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y)

    def __repr__(self):
        return f"Vector({self.x}, {self.y})"

v1 = Vector(3, 4)
v2 = Vector(1, 2)
print(v1 + v2)  # Vector(4, 6)
print(v1 - v2)  # Vector(2, 2)
```

---

## 2. 比较运算符

| 运算符 | 特殊方法 | 作用 |
|---|---|---|
| `<` | `__lt__()` | 小于比较 |
| `<=` | `__le__()` | 小于等于比较 |
| `==` | `__eq__()` | 等于比较 |
| `>` | `__gt__()` | 大于比较 |
| `>=` | `__ge__()` | 大于等于比较 |
| `!=` | `__ne__()` | 不等于比较 |

**示例：**
```python
class Student:
    def __init__(self, name, score):
        self.name = name
        self.score = score

    def __lt__(self, other):
        return self.score < other.score

    def __eq__(self, other):
        return self.score == other.score

    def __repr__(self):
        return f"{self.name}({self.score})"

s1 = Student("张三", 85)
s2 = Student("李四", 92)
print(s1 < s2)   # True
print(s1 == s2)  # False
print(sorted([s2, s1]))  # [张三(85), 李四(92)]
```

---

## 3. 乘法与除法

| 运算符 | 特殊方法 | 作用 |
|---|---|---|
| `*` | `__mul__()` | 乘法运算 |
| `/` | `__truediv__()` | 非整除（真除） |

**示例：**
```python
class Money:
    def __init__(self, amount):
        self.amount = amount

    def __mul__(self, times):
        return Money(self.amount * times)

    def __truediv__(self, divisor):
        return Money(self.amount / divisor)

    def __repr__(self):
        return f"Money({self.amount})"

m = Money(100)
print(m * 3)    # Money(300)
print(m / 4)    # Money(25.0)
```

---

## 4. 取余与整除

| 运算符 | 特殊方法 | 作用 |
|---|---|---|
| `%` | `__mod__()` | 取余运算 |
| `//` | `__floordiv__()` | 整除运算 |

**示例：**
```python
class Number:
    def __init__(self, value):
        self.value = value

    def __mod__(self, other):
        return self.value % other

    def __floordiv__(self, other):
        return self.value // other

n = Number(17)
print(n % 5)   # 2
print(n // 5)  # 3
```

---

## 5. 幂运算

| 运算符 | 特殊方法 | 作用 |
|---|---|---|
| `**` | `__pow__()` | 幂运算 |

**示例：**
```python
class Power:
    def __init__(self, base):
        self.base = base

    def __pow__(self, exp):
        return self.base ** exp

p = Power(2)
print(p ** 5)  # 32
```

---

## 6. 常见注意事项

1. **与内置类型行为一致**：设计重载时应保持语义直观。
2. **返回新对象或值**：通常不修改原对象，返回新的结果。
3. **类型检查**：可用 `isinstance()` 判断 `other` 的类型，避免不合理运算。

**示例：**
```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        if not isinstance(other, Vector):
            return NotImplemented
        return Vector(self.x + other.x, self.y + other.y)
```

---

## 总结速查表

| 运算符 | 特殊方法 |
|---|---|
| `+` | `__add__()` |
| `-` | `__sub__()` |
| `<` | `__lt__()` |
| `<=` | `__le__()` |
| `==` | `__eq__()` |
| `>` | `__gt__()` |
| `>=` | `__ge__()` |
| `!=` | `__ne__()` |
| `*` | `__mul__()` |
| `/` | `__truediv__()` |
| `%` | `__mod__()` |
| `//` | `__floordiv__()` |
| `**` | `__pow__()` |
