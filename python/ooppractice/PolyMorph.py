class Dog:
    def speak(self):
        return "汪汪汪！"

class Cat:
    def speak(self):
        return "喵喵喵！"

class Duck:
    def speak(self):
        return "嘎嘎嘎！"

def animal_sound(animal):
    # 不关心animal的具体类型，只关心它有没有speak方法
    return animal.speak()

# 使用不同对象调用同一函数
dog = Dog()
cat = Cat()
duck = Duck()

print(animal_sound(dog))   # 汪汪汪！
print(animal_sound(cat))   # 喵喵喵！
print(animal_sound(duck))  # 嘎嘎嘎！


class Person(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        return f"Hello, my name is {self.name} and I am {self.age} years old."
    
    def __str__(self):
        return f"Person(name={self.name}, age={self.age})"

per=Person("Tom", 28)
print(dir(per))  # 输出Person对象的所有属性和方法
print(per)
print(per.__str__())  # 调用自定义的字符串表示方法
