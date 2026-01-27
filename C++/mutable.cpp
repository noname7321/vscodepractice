#include<iostream>
class MutableExample {
private:
    mutable int accessCount; // mutable member variable
    int data;
public:
    MutableExample(int val) : data(val), accessCount(0) {}
    int getData() const {
        accessCount++; // Modifying mutable member variable in const method
        return data;
    }
    int getAccessCount() const {
        return accessCount;
    }
};

class entity {
private:
    std::string name;
public:
    const std::string& getName() const {//reference here means we are not making a copy,but returning the original
        return name;
    }
    void setName(const std::string& newName) {
        name = newName;
    }
};

int main()
{
    const entity e;
    e.getName(); // Calling const method
    //非 const 成员函数不能在 const 对象上被调用

    int x=9;
    auto f= [&]() mutable
    {
        std::cout<<x<<std::endl;
        x=10; // lambda 捕获的变量默认是不可变的，除非使用 mutable 关键字 
    };
    f();
    std::cout<<x<<std::endl; // x remains 9 outside the lambda
}