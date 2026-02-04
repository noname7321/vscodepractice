# Python 迭代器函数详解

本文档详细介绍Python中常用的迭代器函数，包含每个函数的说明、语法和实用示例。

---

## 1. sorted(iter)

**功能说明：** 对可迭代对象进行排序，返回一个新的已排序列表。

**语法：**
```python
sorted(iterable, key=None, reverse=False)
```

**参数：**
- `iterable`: 可迭代对象
- `key`: 排序依据的函数（可选）
- `reverse`: False升序（默认），True降序

**示例：**
```python
# 基本排序
numbers = [5, 2, 8, 1, 9]
print(sorted(numbers))  # [1, 2, 5, 8, 9]

# 降序排序
print(sorted(numbers, reverse=True))  # [9, 8, 5, 2, 1]

# 按字符串长度排序
words = ["python", "is", "awesome", "ai"]
print(sorted(words, key=len))  # ['is', 'ai', 'python', 'awesome']

# 按字典值排序
students = [
    {"name": "张三", "score": 85},
    {"name": "李四", "score": 92},
    {"name": "王五", "score": 78}
]
print(sorted(students, key=lambda x: x["score"], reverse=True))
# [{'name': '李四', 'score': 92}, {'name': '张三', 'score': 85}, {'name': '王五', 'score': 78}]
```

---

## 2. reversed(sequence)

**功能说明：** 反转序列，生成一个新的迭代器对象，元素顺序与原序列相反。

**语法：**
```python
reversed(sequence)
```

**参数：**
- `sequence`: 序列对象（列表、元组、字符串等）

**示例：**
```python
# 反转列表
numbers = [1, 2, 3, 4, 5]
print(list(reversed(numbers)))  # [5, 4, 3, 2, 1]

# 反转字符串
text = "Hello"
print(''.join(reversed(text)))  # olleH

# 反转元组
my_tuple = (10, 20, 30)
print(tuple(reversed(my_tuple)))  # (30, 20, 10)

# 遍历反转后的序列
for i in reversed(range(5)):
    print(i, end=' ')  # 4 3 2 1 0
```

---

## 3. zip(iter1, iter2, ...)

**功能说明：** 将多个可迭代对象打包成元组，返回一个zip对象（迭代器）。

**语法：**
```python
zip(*iterables)
```

**参数：**
- `*iterables`: 一个或多个可迭代对象

**示例：**
```python
# 基本用法：打包两个列表
names = ["张三", "李四", "王五"]
ages = [25, 30, 28]
print(list(zip(names, ages)))
# [('张三', 25), ('李四', 30), ('王五', 28)]

# 打包三个列表
cities = ["北京", "上海", "深圳"]
result = list(zip(names, ages, cities))
print(result)
# [('张三', 25, '北京'), ('李四', 30, '上海'), ('王五', 28, '深圳')]

# 不等长列表（以最短的为准）
a = [1, 2, 3, 4]
b = ['a', 'b', 'c']
print(list(zip(a, b)))  # [(1, 'a'), (2, 'b'), (3, 'c')]

# 解压（unzip）
pairs = [(1, 'a'), (2, 'b'), (3, 'c')]
numbers, letters = zip(*pairs)
print(numbers)  # (1, 2, 3)
print(letters)  # ('a', 'b', 'c')

# 创建字典
keys = ['name', 'age', 'city']
values = ['张三', 25, '北京']
print(dict(zip(keys, values)))
# {'name': '张三', 'age': 25, 'city': '北京'}
```

---

## 4. enumerate(iter)

**功能说明：** 根据可迭代对象创建一个enumerate对象，返回包含索引和值的元组。

**语法：**
```python
enumerate(iterable, start=0)
```

**参数：**
- `iterable`: 可迭代对象
- `start`: 起始索引（默认为0）

**示例：**
```python
# 基本用法
fruits = ["苹果", "香蕉", "橙子"]
for index, fruit in enumerate(fruits):
    print(f"{index}: {fruit}")
# 0: 苹果
# 1: 香蕉
# 2: 橙子

# 自定义起始索引
for index, fruit in enumerate(fruits, start=1):
    print(f"{index}. {fruit}")
# 1. 苹果
# 2. 香蕉
# 3. 橙子

# 转换为列表
print(list(enumerate(fruits)))
# [(0, '苹果'), (1, '香蕉'), (2, '橙子')]

# 实际应用：处理文件行号
lines = ["第一行", "第二行", "第三行"]
for line_num, line in enumerate(lines, start=1):
    print(f"行 {line_num}: {line}")
```

---

## 5. all(iter)

**功能说明：** 判断可迭代对象中所有元素的布尔值是否都为True。

**语法：**
```python
all(iterable)
```

**参数：**
- `iterable`: 可迭代对象

**返回值：** 如果所有元素都为True（或可迭代对象为空），返回True；否则返回False。

**示例：**
```python
# 基本用法
print(all([True, True, True]))   # True
print(all([True, False, True]))  # False
print(all([]))                   # True (空序列返回True)

# 检查所有数字是否为正数
numbers = [1, 2, 3, 4, 5]
print(all(n > 0 for n in numbers))  # True

numbers = [1, -2, 3]
print(all(n > 0 for n in numbers))  # False

# 检查所有字符串是否非空
strings = ["hello", "world", "python"]
print(all(strings))  # True

strings = ["hello", "", "python"]
print(all(strings))  # False

# 验证所有学生都及格
scores = [75, 82, 90, 68, 85]
print(all(score >= 60 for score in scores))  # True

# 检查列表中所有元素是否为偶数
numbers = [2, 4, 6, 8]
print(all(n % 2 == 0 for n in numbers))  # True
```

---

## 6. any(iter)

**功能说明：** 判断可迭代对象中是否至少有一个元素的布尔值为True。

**语法：**
```python
any(iterable)
```

**参数：**
- `iterable`: 可迭代对象

**返回值：** 如果至少有一个元素为True，返回True；所有元素都为False（或可迭代对象为空）时返回False。

**示例：**
```python
# 基本用法
print(any([False, False, True]))  # True
print(any([False, False, False])) # False
print(any([]))                    # False (空序列返回False)

# 检查是否存在负数
numbers = [1, 2, -3, 4, 5]
print(any(n < 0 for n in numbers))  # True

# 检查是否有空字符串
strings = ["hello", "", "world"]
print(any(s == "" for s in strings))  # True

# 检查是否有及格的学生
scores = [45, 52, 38, 59]
print(any(score >= 60 for score in scores))  # False

scores = [45, 52, 68, 59]
print(any(score >= 60 for score in scores))  # True

# 检查字符串中是否包含数字
text = "hello123"
print(any(c.isdigit() for c in text))  # True
```

---

## 7. next(iter)

**功能说明：** 获取迭代器的下一个元素。

**语法：**
```python
next(iterator, default)
```

**参数：**
- `iterator`: 迭代器对象
- `default`: 可选，当迭代器耗尽时返回的默认值

**示例：**
```python
# 基本用法
numbers = iter([1, 2, 3])
print(next(numbers))  # 1
print(next(numbers))  # 2
print(next(numbers))  # 3
# print(next(numbers))  # 会抛出 StopIteration 异常

# 使用默认值
numbers = iter([1, 2])
print(next(numbers))        # 1
print(next(numbers))        # 2
print(next(numbers, "结束")) # 结束 (不会抛出异常)

# 手动遍历文件
with open("example.txt", "w") as f:
    f.write("第一行\n第二行\n第三行")

with open("example.txt") as f:
    file_iter = iter(f)
    print(next(file_iter).strip())  # 第一行
    print(next(file_iter).strip())  # 第二行

# 结合while循环
numbers = iter([1, 2, 3, 4, 5])
while True:
    item = next(numbers, None)
    if item is None:
        break
    print(item)
```

---

## 8. filter(function, iter)

**功能说明：** 通过指定条件过滤序列，返回一个迭代器对象，包含所有使函数返回True的元素。

**语法：**
```python
filter(function, iterable)
```

**参数：**
- `function`: 判断函数，返回True或False
- `iterable`: 可迭代对象

**示例：**
```python
# 过滤偶数
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
even_numbers = filter(lambda x: x % 2 == 0, numbers)
print(list(even_numbers))  # [2, 4, 6, 8, 10]

# 过滤空字符串
strings = ["hello", "", "world", "", "python"]
non_empty = filter(lambda s: s != "", strings)
print(list(non_empty))  # ['hello', 'world', 'python']

# 或者使用None作为函数（过滤假值）
strings = ["hello", "", "world", None, "python", 0]
print(list(filter(None, strings)))  # ['hello', 'world', 'python']

# 过滤及格分数
scores = [45, 72, 88, 59, 91, 63]
passing = filter(lambda x: x >= 60, scores)
print(list(passing))  # [72, 88, 91, 63]

# 过滤长字符串
words = ["hi", "hello", "a", "python", "programming"]
long_words = filter(lambda w: len(w) > 3, words)
print(list(long_words))  # ['hello', 'python', 'programming']

# 使用自定义函数
def is_positive(n):
    return n > 0

numbers = [-5, 3, -1, 7, 0, 9]
positive_numbers = filter(is_positive, numbers)
print(list(positive_numbers))  # [3, 7, 9]
```

---

## 9. map(function, iter)

**功能说明：** 通过函数对可迭代对象的每个元素进行操作，返回一个迭代器对象。

**语法：**
```python
map(function, iterable, ...)
```

**参数：**
- `function`: 对每个元素执行的函数
- `iterable`: 一个或多个可迭代对象

**示例：**
```python
# 基本用法：平方数
numbers = [1, 2, 3, 4, 5]
squared = map(lambda x: x ** 2, numbers)
print(list(squared))  # [1, 4, 9, 16, 25]

# 转换字符串为整数
str_numbers = ["1", "2", "3", "4"]
int_numbers = map(int, str_numbers)
print(list(int_numbers))  # [1, 2, 3, 4]

# 转换为大写
words = ["hello", "world", "python"]
upper_words = map(str.upper, words)
print(list(upper_words))  # ['HELLO', 'WORLD', 'PYTHON']

# 多个可迭代对象
numbers1 = [1, 2, 3]
numbers2 = [4, 5, 6]
result = map(lambda x, y: x + y, numbers1, numbers2)
print(list(result))  # [5, 7, 9]

# 自定义函数
def celsius_to_fahrenheit(c):
    return (c * 9/5) + 32

celsius = [0, 10, 20, 30, 40]
fahrenheit = map(celsius_to_fahrenheit, celsius)
print(list(fahrenheit))  # [32.0, 50.0, 68.0, 86.0, 104.0]

# 格式化输出
names = ["张三", "李四", "王五"]
ages = [25, 30, 28]
formatted = map(lambda n, a: f"{n}今年{a}岁", names, ages)
print(list(formatted))
# ['张三今年25岁', '李四今年30岁', '王五今年28岁']
```

---

## 附：lambda 函数

**功能说明：** `lambda` 用于创建匿名函数，适合写短小的函数逻辑，常用于 `map()`、`filter()`、`sorted()` 的 `key` 参数等场景。

**语法：**
```python
lambda 参数1, 参数2, ... : 表达式
```

**特点：**
- 只能包含一个表达式（不能写多行语句）
- 表达式的结果会自动返回
- 适合一次性、简短逻辑

**示例：**
```python
# 基本用法
add = lambda x, y: x + y
print(add(2, 3))  # 5

# 与 map 结合
numbers = [1, 2, 3, 4]
print(list(map(lambda x: x * 2, numbers)))  # [2, 4, 6, 8]

# 与 filter 结合
print(list(filter(lambda x: x % 2 == 0, numbers)))  # [2, 4]

# 与 sorted 结合（按长度排序）
words = ["python", "is", "awesome", "ai"]
print(sorted(words, key=lambda w: len(w)))  # ['is', 'ai', 'python', 'awesome']

# 多参数
points = [(1, 2), (3, 1), (2, 5)]
print(sorted(points, key=lambda p: (p[1], p[0])))  # [(3, 1), (1, 2), (2, 5)]
```

**注意事项：**
- 逻辑复杂时建议使用 `def`，可读性更好。
- 需要异常处理或多步逻辑时，不适合用 `lambda`。

---

## 综合示例

结合多个函数使用的实际案例：

```python
# 示例1：数据处理流水线
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# 过滤偶数 -> 平方 -> 排序（降序）
result = sorted(
    map(lambda x: x ** 2, 
        filter(lambda x: x % 2 == 0, numbers)
    ),
    reverse=True
)
print(result)  # [100, 64, 36, 16, 4]

# 示例2：学生成绩处理
students = [
    {"name": "张三", "scores": [85, 92, 78]},
    {"name": "李四", "scores": [90, 88, 95]},
    {"name": "王五", "scores": [75, 82, 88]}
]

# 计算平均分并排序
def calculate_average(student):
    return sum(student["scores"]) / len(student["scores"])

sorted_students = sorted(students, key=calculate_average, reverse=True)
for rank, student in enumerate(sorted_students, start=1):
    avg = calculate_average(student)
    print(f"第{rank}名: {student['name']}, 平均分: {avg:.2f}")

# 示例3：文本处理
text = "Python is awesome and powerful"
words = text.split()

# 过滤长单词 -> 转大写 -> 按字母排序
processed = sorted(
    map(str.upper, 
        filter(lambda w: len(w) > 5, words)
    )
)
print(processed)  # ['AWESOME', 'POWERFUL', 'PYTHON']
```

---

## 性能提示

1. **惰性求值**：`map()`、`filter()`、`zip()` 等返回迭代器，只在需要时计算，节省内存。
2. **列表推导式 vs 内置函数**：对于简单操作，列表推导式通常更快更易读。
3. **链式操作**：可以将这些函数组合使用，创建数据处理管道。

```python
# 列表推导式（推荐用于简单操作）
result = [x ** 2 for x in numbers if x % 2 == 0]

# 等价于
result = list(map(lambda x: x ** 2, filter(lambda x: x % 2 == 0, numbers)))
```

---

## 总结

这些迭代器函数是Python函数式编程的基础工具：

- **sorted()** 和 **reversed()** 用于序列排序和反转
- **zip()** 用于并行处理多个序列
- **enumerate()** 在遍历时获取索引
- **all()** 和 **any()** 用于逻辑判断
- **next()** 手动控制迭代
- **filter()** 和 **map()** 用于数据转换和过滤

掌握这些函数能让你的代码更简洁、高效、符合Python风格。
