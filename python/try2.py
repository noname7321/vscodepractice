a=10
b=20
print(dir(a))
print(a+b)
print(a.__add__(b))
print(a.__sub__(b))

class A:
    pass
class B:
    pass
class C(A, B):
    def __init__(self, name, age):
        self.name = name
        self.age = age

obj1=A()
obj2=B()
obj3=C("Alice", 30)
print('the dict of obj1:', obj1.__dict__)
print('the dict of obj2:', obj2.__dict__)
print('the dict of obj3:', obj3.__dict__)

print('对象obj1所属于的类 ',obj1.__class__)
print('对象obj2所属于的类 ',obj2.__class__)
print('对象obj3所属于的类 ',obj3.__class__)

print('A的父类元组',A.__bases__)
print('B的父类元组',B.__bases__)
print('C的父类元组',C.__bases__)#C有两个直接父类A和B

print('A类的父类',A.__base__)
print('B类的父类',B.__base__)
print('C类的父类',C.__base__)#C只有一个直接父类A,如果有多个父类，则返回第一个父类