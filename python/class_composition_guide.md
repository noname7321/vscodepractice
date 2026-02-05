# Python 类的组成：属性与方法详解

本文档根据图片内容，系统介绍 Python 类的组成，包括：类属性、实例属性、实例方法、静态方法、类方法，并提供清晰示例。

---

## 1. 类属性（Class Attributes）

**定义说明：**
- 直接定义在类中、方法外的变量。
- 由所有实例共享。
- 通过类名或实例名都可访问，但推荐用类名访问。

**示例：**
```python
class Student:
    school = "No.1 Middle School"  # 类属性

    def __init__(self, name):
        self.name = name  # 实例属性

print(Student.school)  # No.1 Middle School
s1 = Student("张三")
print(s1.school)  # No.1 Middle School

# 修改类属性（影响所有实例）
Student.school = "No.2 Middle School"
print(s1.school)  # No.2 Middle School
```

---

## 2. 实例属性（Instance Attributes）

**定义说明：**
- 定义在 `__init__` 方法中。
- 使用 `self.xxx` 形式创建。
- 每个实例独有，互不影响。

**示例：**
```python
class Student:
    def __init__(self, name, age):
        self.name = name  # 实例属性
        self.age = age    # 实例属性

s1 = Student("张三", 18)
s2 = Student("李四", 20)

print(s1.name, s1.age)  # 张三 18
print(s2.name, s2.age)  # 李四 20
```

---

## 3. 实例方法（Instance Methods）

**定义说明：**
- 定义在类中。
- 第一个参数必须是 `self`（代表实例对象）。
- 通过实例调用，常用于操作实例属性。

**示例：**
```python
class Student:
    def __init__(self, name):
        self.name = name

    def say_hi(self):  # 实例方法
        print(f"你好，我是{self.name}")

s1 = Student("张三")
s1.say_hi()  # 你好，我是张三
```

---

## 4. 静态方法（Static Methods）

**定义说明：**
- 使用装饰器 `@staticmethod`。
- 不需要 `self` 或 `cls` 参数。
- 本质上是定义在类中的普通函数，用来组织工具类功能。
- 不能调用实例属性和实例方法

**示例：**
```python
class MathTool:
    @staticmethod
    def add(a, b):  # 静态方法
        return a + b

print(MathTool.add(2, 3))  # 5
```

**适用场景：**
- 与类相关，但不需要访问类或实例数据的工具函数。

---

## 5. 类方法（Class Methods）

**定义说明：**
- 使用装饰器 `@classmethod`。
- 第一个参数是 `cls`（代表类本身）。
- 常用于操作类属性或提供替代构造器。
- 不能调用实例属性和实例方法

**示例：**
```python
class Student:
    school = "No.1 Middle School"

    def __init__(self, name):
        self.name = name

    @classmethod
    def change_school(cls, new_school):  # 类方法
        cls.school = new_school

Student.change_school("No.3 Middle School")
print(Student.school)  # No.3 Middle School
```

**替代构造器示例：**
```python
class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def from_birth_year(cls, name, birth_year):
        age = 2026 - birth_year
        return cls(name, age)

s = Student.from_birth_year("王五", 2008)
print(s.name, s.age)  # 王五 18
```

---

## 对比总结

| 类型 | 定义位置 | 第一个参数 | 是否可访问类属性 | 是否可访问实例属性 | 调用方式 |
|---|---|---|---|---|---|
| 类属性 | 类中、方法外 | 无 | ✅ | ❌ | 类名/实例 |
| 实例属性 | `__init__` 中 | `self` | ✅ | ✅ | 实例 |
| 实例方法 | 类中 | `self` | ✅ | ✅ | 实例 |
| 静态方法 | 类中 | 无 | ❌ | ❌ | 类名/实例 |
| 类方法 | 类中 | `cls` | ✅ | ❌ | 类名/实例 |

---

## 综合示例（完整类结构）

```python
class Student:
    school = "No.1 Middle School"  # 类属性

    def __init__(self, name, age):
        self.name = name  # 实例属性
        self.age = age    # 实例属性

    def introduce(self):  # 实例方法
        print(f"我是{self.name}，今年{self.age}岁，就读于{self.school}")

    @staticmethod
    def is_adult(age):  # 静态方法
        return age >= 18

    @classmethod
    def change_school(cls, new_school):  # 类方法
        cls.school = new_school

# 使用示例
s1 = Student("张三", 18)
s1.introduce()  # 我是张三，今年18岁，就读于No.1 Middle School

print(Student.is_adult(17))  # False

Student.change_school("No.2 Middle School")
s1.introduce()  # 我是张三，今年18岁，就读于No.2 Middle School
```
