#include<iostream>
#include<string>

class entity {
private:
    std::string name;
public:
    entity(){
        name = "Default Name";
    }
    entity(const std::string& newName) {
        name = newName;
    }
    const std::string& getName() const {//reference here means we are not making a copy,but returning the original
        return name;
    }
    void setName(const std::string& newName) {
        name = newName;
    }
};

class abc{
private:
    int data;
    std::string info;
public:
    abc():data(0), info("default") {}//have to initialize members in order
    abc(int d, const std::string& str):data(d), info(str) {}
};



int main()
{
    const entity e;
    e.getName(); // Calling const method
    //非 const 成员函数不能在 const 对象上被调用

  
}