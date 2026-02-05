class Student:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @classmethod
    def from_birth_year(cls, name, birth_year):
        age = 2026 - birth_year
        return cls(name, age)

a=Student("张三",20)
print(a.name,a.age)  # 张三 20
a.age=21
print(a.name,a.age)  # 张三 21
s = Student.from_birth_year("王五", 2008)
print(s.name, s.age)  # 王五 18
s.age=19
print(s.name, s.age)  # 王五 19
a.from_birth_year("李四", 2000)  
print(a.name, a.age)  # 张三 21
b=a.from_birth_year("李四", 2000) # 创建了一个新的 Student 实例
print(b.name, b.age)  # 李四 26
print(a.__dict__)  # {'name': '张三', 'age': 21}
print(s.__dict__)  # {'name': '王五', 'age': 19}