class Student:
    def __init__(self, name, age):
        self.name = name
        self.__age = age  # Private attribute
    @property # transforming method into property, so we can access it like an attribute
    def age(self):
        return self.__age
    @age.setter
    def age(self, age):
        if age >= 0:
            self.__age = age
        else:
            print("Age cannot be negative")

stu=Student("John", 25)
print(stu.name)  # Accessing public attribute
print(stu.age)   # Accessing private attribute via property
stu.age = 30     # Modifying private attribute via property setter
print(stu.age)   # Accessing modified private attribute via property

