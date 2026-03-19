#include<iostream>
#include<memory>
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
    void Print()
    {
        std::cout << "Hello World" << std::endl;
    }
};
int main()
{
    {
        std::unique_ptr<Entity> e1(new Entity());// the Entity is created on the heap, and its constructor is called, which will print "Entity created".
        e1->Print();// we can use the unique_ptr to call the Print function of the Entity object, which will print "Hello World".
    }// when the block ends, the destructor for e1 will be called automatically, and we will see the output "Entity destroyed".
    {
        std::unique_ptr<Entity> e2 = std::make_unique<Entity>();//It's the more preferable way to create a unique_ptr, as it is more efficient and safer than using the new operator directly.
        // the Entity is created on the heap, and its constructor is called, which will print "Entity created".
    }// when the block ends, the destructor for e2 will be called automatically, and we will see the output "Entity destroyed". 
    // unique_ptr is a smart pointer that manages a dynamically allocated object and ensures that it is properly deleted when it goes out of scope. 
    // It provides exclusive ownership of the object, meaning that only one unique_ptr can point to a given object at a time. 
    // When the unique_ptr goes out of scope, it automatically deletes the object it owns, preventing memory leaks and ensuring proper resource management.
    {
        std::shared_ptr<Entity> e3 = std::make_shared<Entity>();// shared_ptr is a smart pointer that manages a dynamically allocated object and allows multiple shared_ptr instances to share ownership of the same object.
        // the Entity is created on the heap, and its constructor is called, which will print "Entity created".
        std::shared_ptr<Entity> e4 = e3;// we can create another shared_ptr (e4) that shares ownership of the same Entity object as e3. This will increase the reference count of the shared_ptr, indicating that there are now two shared_ptr instances pointing to the same object.
        std::weak_ptr<Entity> e5 = e3;// we can also create a weak_ptr (e5) that points to the same Entity object as e3, but does not increase the reference count. A weak_ptr is used to break circular references and to check if the object still exists without owning it.
    }// when the block ends, the destructor for e3 will be called automatically, and we will see the output "Entity destroyed".
    // shared_ptr uses reference counting to keep track of how many shared_ptr instances are pointing to the same object. When the last shared_ptr that owns the object is destroyed, the object is automatically deleted.
}