#include<iostream> 
#include<string>

class Entity {
private:
    int m_x;
    mutable int m_y;//mutable allows modification even in const context
    int *a,b;//means a is a pointer to int, b is an int
    int *c, *d; // both c and d are pointers to int 
    int* const p; // p is a constant pointer to an int
    const int *q; // q is a pointer to a constant int
    const int *const r; // r is a constant pointer to a constant int
public:
    int getX() const { m_y=3; m_x; } // Const member function
    //this methond cannot modify any member variables,you can't do m_x = 5; here
};

void printentity(const Entity& e) {//reference 
    std::cout << "Entity X: " << e.getX() << std::endl; 
    //if getX() were not const, this line would cause a compilation error,beacause we are passing a const reference
}

int main()
{
    const int value = 42; // Constant integer
    //value = 50; // This line would cause a compilation error
    int *ptr = new int;
    *ptr = 100; // Modifying the value pointed to is allowed
    //ptr = nullptr; // This line would cause a compilation error
    ptr =(int*) &value; // Changing the pointer to point to a different address is allowed
    *ptr = 200; // Modifying the value at the new address is undefined behavior
    //the value of 'value' is still 42
    std::cout << "Pointer Value: " << *ptr << std::endl;
    //

    const double pi = 3.14159; // Constant double
    //pi = 3.14; // This line would cause a compilation error

    const char *message = "Hello, World!"; // Constant pointer to a string literal
    //message[0] = 'h'; // This line would cause a compilation error

    const std::string greeting = "Welcome to C++26!"; // Constant std::string
    //greeting += " Enjoy coding!"; // This line would cause a compilation error

    std::cout << "Value: " << value << std::endl;
    std::cout << "Pi: " << pi << std::endl;
    std::cout << "Message: " << message << std::endl;
    std::cout << "Greeting: " << greeting << std::endl;

    const int *constPtr = &value; // Constant pointer to a constant integer
    // *constPtr = 50; // This line would cause a compilation error
    //constPtr = nullptr; // Changing the pointer is allowed




    delete ptr; // Clean up dynamically allocated memory
    return 0;
}