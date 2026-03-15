#include <iostream>
#include <string>

class Entity;
class entity;

void printentity(const entity * e);
void printEntity(const Entity &e);

class Entity
{
public:
    int x, y;
    // Entity(int x, int y) : x(x), y(y) // this is called member initializer list
    // when we have to initialize a member variable with the same name as the parameter,
    // we can use the member initializer list to avoid ambiguity and directly initialize the member variables. 
    // This is more efficient than assigning values inside the constructor body.
    Entity(int x, int y) : x(x), y(y)
    {
        printEntity(*this); // we can pass the current object to a function that expects a reference to an Entity object.
    }
    
};

void printEntity(const Entity & e)
{
    std::cout << "x: " << e.x << ", y: " << e.y << std::endl;
}

class entity
{  
public:
    int x, y;
    // This is a constructor that initializes the member variables x and y with the values passed as parameters.
    // this keyword is used to refer to the current object,
    // and it is necessary here to distinguish between the member variables and the parameters with the same name.
    entity(int x, int y) 
    {
        this->x = x;//(*this).x = x; // this is another way to access the member variable x using the dereference operator.
        this->y = y;
        printentity(this); // we can pass the current object to a function that expects a pointer to an Entity object.

    }// using -> means we are accessing a member of the object pointed to by this pointer,
    // . means we are accessing a member of the current object directly.

    int getx()const// in this function,we can't modify any member variables of the class, 
    //and we can only call other const member functions.
    {
        return this->x;
    }
};

void printentity(const entity * e)
{
    std::cout << "x: " << e->x << ", y: " << e->y << std::endl;
}

int main()
{
    Entity e(5, 10);
    entity e1(15, 20);
    std::cout << "e.getx(): " << e1.getx() << std::endl;
    return 0;
}