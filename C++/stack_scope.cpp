#include<iostream>
#include<string>

class Entity
{  
public:
    Entity()
    {
        std::cout << "Entity created" << std::endl;
    }
    ~Entity()
    {
        std::cout << "Entity destroyed" << std::endl;
    }
};

int * createarray()
{
    int * myarray = new int[5];// this creates an array of 5 integers on the heap and returns a pointer to the first element of the array.
    return myarray;
}

int * createarraywrong()
{
    int myarray[5];// this creates an array of 5 integers on the stack, and when the function returns,
    // the array goes out of scope and is destroyed, so returning a pointer to it will lead to undefined behavior.
    return myarray;
}

class ScopedPtr
{
    private:
        Entity * ptr;
    public://ptr(p) means that we are initializing the member variable ptr with the value of the parameter p passed to the constructor.
        ScopedPtr(Entity * p) : ptr(p) {}
        ~ScopedPtr()
        {
            delete ptr;// this will call the destructor of the Entity object pointed to by ptr, and free the memory allocated for it.
        }
};        

int main()
{
    {
        Entity e1;// the Entity is created on the stack, and its constructor is called, which will print "Entity created".
        Entity e2;// when the block ends, the destructor for e1 and e2 will be called automatically, and we will see the output "Entity destroyed" twice.
    }// stack scope means that the lifetime of the object is limited to the block in which it is defined.
    // When the block ends, the object is automatically destroyed, and its destructor is called. 
    //This is a key feature of C++ that allows for automatic memory management and helps prevent memory leaks.
    {// the new operator is used to create an object on the heap, and it returns a pointer to the object.
        Entity* e3 = new Entity();// the Entity is created on the heap, and its constructor is called, which will print "Entity created".
        delete e3;// we have to manually delete the object created on the heap to free the memory, and this will call the destructor, which will print "Entity destroyed".
    }
    {
        Entity* e4 = new Entity();// the Entity is created on the heap, and its constructor is called, which will print "Entity created".
        delete e4;// we have to manually delete the object created on the heap to free the memory, and this will call the destructor, which will print "Entity destroyed".
    }// when the block ends, the destructor for e4 will not be called automatically because it is created on the heap, and we will not see the output "Entity destroyed".
    // This can lead to a memory leak if we forget to delete the object, as the memory allocated for e4 will not be freed until the program ends.
    // delete e4;
    //the name of e4 is not in scope here, so this will lead to a compile-time error. We cannot delete an object that is out of scope, and we should always ensure that we delete objects created on the heap before they go out of scope to avoid memory leaks.
    {
        ScopedPtr e= new Entity();// the Entity is created on the heap, the e is a ScopedPtr object that manages the lifetime of the Entity object, and its constructor is called, which will print "Entity created".
    }// when the block ends, the destructor for e will be called automatically, which will delete the Entity object it manages,
    //and we will see the output "Entity destroyed".
    
    std::cin.get();
    return 0;
}