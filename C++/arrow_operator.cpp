#include<iostream>
#include<string>
#include<cstring>
class Entity
{
public:
    void Print() const // const成员函数，表示该函数不会修改对象的状态，可以被const对象调用。const 对象不能调用非 const 函数
    {
        std::cout << "Hello" << std::endl;
    }
};

class ScopedPtr
{
private:
    Entity* m_Ptr;
public:
    ScopedPtr(Entity* ptr) : m_Ptr(ptr) {}
    ~ScopedPtr() { delete m_Ptr; }
    Entity* operator->() { return m_Ptr; } // 重载箭头运算符，使得我们可以通过ScopedPtr对象直接访问Entity对象的成员函数。
};

int main()
{
    Entity e;
    e.Print();// we call the Print() method on the Entity object e, which will output "Hello" to the console.
    Entity* ptr = &e;// we create a pointer to an Entity object and initialize it with the address of e. This allows us to access the members of e through the pointer ptr.
    ptr->Print();// we use the arrow operator (->) to call the Print() method on the Entity object that ptr points to. Since ptr points to e, this will also output "Hello" to the console.
    Entity& ref=*ptr;// we create a reference to an Entity object and initialize it with the object that ptr points to. This means ref is now an alias for the Entity object that ptr points to (which is e). We can use ref to access the members of e directly.
    ref.Print();// we call the Print() method on the Entity object that ref refers to.
    (*ptr).Print();// we dereference the pointer ptr to get the Entity object it points to, and then call the Print() method on that object. This will also output "Hello" to the console. The parentheses around *ptr are necessary because the dot operator (.) has higher precedence than the dereference operator (*), so we need to ensure that we dereference ptr before calling Print().
    ScopedPtr sp = new Entity();
    sp->Print();// we use the arrow operator (->) to call the Print() method on the Entity object that sp points to. Since sp is a ScopedPtr that manages a pointer to an Entity object, this will output "Hello" to the console. The ScopedPtr class is designed to manage the lifetime of the Entity object it points to, ensuring that it is properly deleted when the ScopedPtr goes out of scope.
    std::cin.get();
}