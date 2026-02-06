class FatherA:
    def __init__(self,name):
        self.name = name
    def showA(self):
        return f"FatherA Name: {self.name}"
class FatherB:
    def __init__(self,age):
        self.age = age
    def showB(self):
        return f"FatherB Age: {self.age}"
class Child(FatherA, FatherB):# Multiple Inheritance
    def __init__(self, name, age, school):
        FatherA.__init__(self, name)  # Initialize FatherA part
        FatherB.__init__(self, age)   # Initialize FatherB part
        self.school = school
    def showChild(self):
        return f"Child School: {self.school}"

# Example usage:
child = Child("Charlie", 10, "Greenwood High")
print(child.showA())  # From FatherA
print(child.showB())  # From FatherB
print(child.showChild())  # From Child class