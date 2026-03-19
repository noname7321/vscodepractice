#include<iostream>
#include<string>
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
}