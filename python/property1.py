class Student:
    def __init__(self, name, age):
        self.name = name
        self.__age = age  # Private attribute
    @property # transforming method into property, so we can access it like an attribute
    def age(self):
        return self.__age
stu=Student("John", 25)
print(stu.name)  # Accessing public attribute
print(stu.age)   # Accessing private attribute via property