class Student():
    def __init__(self, name, age, gender):
        self.name = name
        self.__age = age  # Private attribute
        self.gender = gender  # Public attribute

    def get_age(self):
        return self.__age  # Public method to access private attribute

    def set_age(self, age):
        if age >= 0:
            self.__age = age  # Public method to modify private attribute
        else:
            print("Age cannot be negative")

    def fun_1(self):
        print("This is a public method.")
    def __fun_2(self):
        print("This is a private method.")
    def access_private_method(self):
        self.__fun_2()  # Accessing private method within the class
        self.fun_1()  # Accessing public method within the class
        print(self.name)  # Accessing public attribute within the class
        print(self.__age)  # Accessing private attribute within the class
# Example usage:
student = Student("Alice", 20, "Female")
student.access_private_method()
# Accessing public attribute directly   
print(student.name)
student.set_age(21)
# Accessing private attribute via public method
print(student.get_age())
# Modifying private attribute via public method
#print(student.__age) # This will raise an AttributeError
#student.__fun_2() # This will raise an AttributeError
print(dir(student))  # To see the name-mangled attributes and methods

print(student._Student__age)  # Accessing private attribute using name mangling
student._Student__fun_2()  # Accessing private method using name mangling