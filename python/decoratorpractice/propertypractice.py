# @property 把类中的一个方法暴露成像属性一样访问的接口（即通过 obj.attr 读取），常用于
#提供计算属性（按需计算并返回值）
#封装内部变量的只读访问（控制访问、验证、懒计算）
#保持现有属性接口的同时增加逻辑（向后兼容）

class Rectangle:
    def __init__(self, width, height):
        self._width = width
        self._height = height

    @property
    def width(self):
        return self._width
#  rect.width 访问而不是 rect.width()。

    @property
    def height(self):
        return self._height
    
    @width.setter
    def width(self, value):
        if value < 0:
            raise ValueError("width must be >= 0")
        self._width = value

    @width.deleter
    def width(self):
        del self._width

    @height.setter
    def height(self, value):
        if value < 0:
            raise ValueError("height must be >= 0")
        self._height = value
    
    @height.deleter
    def height(self):
        del self._height

    
rectangle= Rectangle(5, 10)
rectangle.width = 3
rectangle.height = 6

print(rectangle.width)  # Output: 3
print(rectangle.height)  # Output: 6

del rectangle.width
del rectangle.height

def add_sprinkles(func):
    def wrapper():
        print('Adding sprinkles...')
        func()
        print('Sprinkles added!')
    return wrapper

def add_chocolate(func):
    def wrapper():
        print('Adding chocolate syrup...')
        func()
        print('Chocolate syrup added!')
    return wrapper

@add_sprinkles
@add_chocolate
def get_ice_cream():
    print('Here is your ice cream')