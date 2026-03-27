#include<iostream>
#include<string>
#include <cstring>
struct Vector2
{
    float x, y;
}; 

int main()
{
    Vector2 a= {1.0f, 2.0f};// we create a Vector2 object named a and initialize its x and y members with the values 1.0f and 2.0f, respectively.
    Vector2 b = a;// we create another Vector2 object named b and initialize it with the value of a. This is a copy operation, where the values of a's members (x and y) are copied to b's members. After this line, both a and b will have the same values for x and y (1.0f and 2.0f).
    b.x = 3.0f;// we modify the x member of b to 3.0f. This does not affect a, as a and b are separate objects with their own memory. After this line, a will still have x = 1.0f and y = 2.0f, while b will have x = 3.0f and y = 2.0f.
    std::cout << "a: (" << a.x << ", " << a.y << ")" << std::endl;// we print the values of a's members, which will output "a: (1.0, 2.0)".
    std::cout << "b: (" << b.x << ", " << b.y << ")" << std::endl;// we print the values of b's members, which will output "b: (3.0, 2.0)". 
    std::cin.get();
    Vector2* c = new Vector2{4.0f, 5.0f};// we create a pointer to a Vector2 object on the heap and initialize it with the values 4.0f and 5.0f. This is the correct way to create a Vector2 object on the heap.
    Vector2* d = c;// we create another pointer to a Vector2 object and initialize it with the value of c. This is a copy operation, where the value of c (which is a memory address) is copied to d. After this line, both c and d will point to the same Vector2 object on the heap (with values 4.0f and 5.0f).
    d->x = 6.0f;// we modify the x member of the Vector2 object that d points to. Since c and d point to the same object, this modification will affect both c and d. After this line, the Vector2 object on the heap will have x = 6.0f and y = 5.0f.
    std::cout << "c: (" << c->x << ", " << c->y << ")" << std::endl;// we print the values of the Vector2 object that c points to, which will output "c: (6.0, 5.0)".
    std::cout << "d: (" << d->x << ", " << d->y << ")" << std::endl;// we print the values of the Vector2 object that d points to, which will also output "d: (6.0, 5.0)" since c and d point to the same object.
    delete c;// we free the memory allocated for the Vector2 object on the heap. After this line, c and d will be dangling pointers, meaning they point to memory that has been deallocated. Accessing c or d after this line will lead to undefined behavior.  
    
}