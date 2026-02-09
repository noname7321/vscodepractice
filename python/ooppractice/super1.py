class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def greet(self):
        return f"Hello, my name is {self.name} and I am {self.age} years old."

class Student(Person):
    def __init__(self, name, age, student_id):
        super().__init__(name, age) 
        # Call the constructor of the parent class
        self.student_id = student_id

    def study(self, subject):
        return f"{self.name} is studying {subject}."

class Teacher(Person):
    def __init__(self, name, age, employee_id):
        super().__init__(name, age) 
        # Call the constructor of the parent class
        self.employee_id = employee_id

    def teach(self, subject):
        return f"{self.name} is teaching {subject}."

# Example usage:
student = Student("Alice", 20, "S12345")
teacher = Teacher("Bob", 35, "T67890")
print(student.greet())  # Inherited method
print(student.study("Math"))  # Student-specific method
print(teacher.greet())  # Inherited method
print(teacher.teach("Science"))  # Teacher-specific method
