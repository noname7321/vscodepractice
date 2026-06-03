#include<iostream>

class Base
{
public:
    Base(){std::cout<<"Base constructor called."<<std::endl;}
    virtual ~Base(){std::cout<<"Base destructor called."<<std::endl;}
};

int main()
{
    double value = 3.14;
    double a=(int)(value+4.5);//我们将 double 类型的值 value 加上一个整数 4.5，然后将结果强制转换为 int 类型，最后再将其赋值给 a。
    //需要注意的是，这种类型转换可能会导致数据丢失，因为 double 类型的值在转换为 int 类型时会被截断，保留整数部分而丢弃小数部分。
    std::cout<<"Value: "<<a<<std::endl;
    double s=static_cast<double>(a);//我们使用 static_cast 运算符将整数 a 转换为 double 类型，并将结果赋值给 s。
    //static_cast 是 C++ 中的一种类型转换运算符，它提供了一种更安全和更明确的方式来进行类型转换。
    //与 C 风格的强制类型转换相比，static_cast 可以帮助我们避免一些潜在的错误和不安全的转换。
    std::cout<<"Value: "<<s<<std::endl;

    double c=reinterpret_cast<double&>(a);//我们使用 reinterpret_cast 运算符将整数 a 的引用 reinterpret_cast 为 double 类型的引用，并将结果赋值给 s。
    //reinterpret_cast 是 C++ 中的一种类型转换运算符，它提供了一种非常底层和不安全的方式来进行类型转换。它允许我们将一个类型的指针或引用 reinterpret_cast 为另一个类型的指针或引用，而不考虑它们之间的类型兼容性。
    //需要注意的是，reinterpret_cast 可能会导致未定义行为，因为它可能会导致内存访问错误或者数据损坏。使用 reinterpret_cast 时，我们需要非常小心，确保我们知道我们在做什么，并且确保我们不会访问到无效的内存区域或者产生不可预测的结果。
    std::cout<<"Value: "<<c<<std::endl;

    int d=42;
    Base* k=reinterpret_cast<Base*>(d);//我们使用 reinterpret_cast 运算符将整数 d 的引用 reinterpret_cast 为 Base 类型的引用，并调用 Base 类的析构函数。
    delete k;

    std::cin.get();
    return 0;
}