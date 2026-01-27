#include<iostream>
using string = std::string;
class entity {
private:
    string name;
public:
    entity(){
        name = "Default Name";
    }
    entity(const string& newName) {
        name = newName;
    }
    const string& getName() const {//reference here means we are not making a copy,but returning the original
        return name;
    }
};    
int main()
{
    entity *e;
   // std::cout << e->getName() << std::endl;
    {
        entity e2("Custom Name");
        e = &e2;
        entity* e3 = new entity("Dynamic Name");//new object on heap
        //new returns a pointer to the newly created object
        std::cout << e3->getName() << std::endl;
    } // e2 goes out of scope here, dangling pointer
    
    std::cout << e->getName() << std::endl; // Calling const method
    //非 const 成员函数不能在 const 对象上被调用
    delete e; // Clean up dynamically allocated memory
  
}