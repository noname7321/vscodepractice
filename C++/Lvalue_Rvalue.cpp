#include<iostream>

int &getvalue()
{
    static int value = 42; // 使用 static 使变量在函数返回后仍然存在
    return value; // 返回变量的引用  
}

void setvalue(const int &newValue)
{
    // 这里不能修改 newValue，因为它是一个常量引用
    // 但是我们可以通过 getvalue() 来修改 value 的值
    getvalue() = newValue; // 修改 value 的值
}

void printname_lvalue(std::string & name) {// 左值引用，接受一个可修改的对象
    std::cout << "Hello, " << name << "!" << std::endl;
}

void PrintName(const std::string &name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void printname_rvalue(std::string &&name) {// 右值引用，接受一个临时对象
    std::cout << "Hello, " << name << "!" << std::endl;
}

int main()
{
    int &ref = getvalue(); // 获取变量的引用
    std::cout << "Value: " << ref << std::endl; // 输出变量的值

    getvalue() = 100; // 修改变量的值
    std::cout << "Modified Value: " << ref << std::endl; // 输出修改后的值

    const int &a=10; // a 是一个常量引用，绑定到字面值 10 上
    std::cout << "Constant Reference a: " << a << std::endl; // 输出常量引用的值

    setvalue(40);
    int i =20;
    setvalue(i);

    std::string fistname = "John";
    std::string lastname = "Doe";
    std::string fullname = fistname + " " + lastname; // 使用 std::string 来连接字符串
    printname_lvalue(fullname); // 左值引用接受一个可修改的对象，输出完整的名字
    //printname_lvalue(fistname + " " + lastname); // 错误：不能将一个临时对象绑定到一个非 const 的左值引用
    PrintName(fullname); // 输出完整的名字
    PrintName(fistname + " " + lastname); // 临时对象可以绑定到 const 引用，输出完整的名字
    printname_rvalue(fistname + " " + lastname); // 右值引用接受一个临时对象，输出完整的名字
    return 0;
}