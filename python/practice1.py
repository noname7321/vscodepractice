class Cicrle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        import math
        return math.pi * pow(self.radius, 2)

    def circumference(self):
        import math
        return 2 * math.pi * self.radius
    
class instrument():
    def make_sound(self):
        pass
        
class Erhu(instrument):
    def make_sound(self):
        return "Erhu sound"

class Guitar(instrument):
    def make_sound(self):
        return "Guitar sound"

class Piano(instrument):
    def make_sound(self):
        return "Piano sound"
    
def play_instrument(instrument):
    print(instrument.make_sound())

if __name__ == "__main__":
    c =float(input("请输入圆的半径："))
    circle = Cicrle(c) 
    print(f"面积为：{circle.area():.6f}")
    print(f"周长为：{circle.circumference():.6f}")