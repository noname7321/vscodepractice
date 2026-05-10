#include<iostream>

class Base
{
public:
    Base(){std::cout<<"Base constructor called."<<std::endl;}
    virtual ~Base(){std::cout<<"Base destructor called."<<std::endl;}
    //确保基类的析构函数被声明为虚函数，这样在通过基类指针删除对象时，能够正确调用派生类的析构函数。
};

class Derived : public Base
{
public:
    Derived(){std::cout<<"Derived constructor called."<<std::endl;}
    ~Derived(){std::cout<<"Derived destructor called."<<std::endl;}
};

int main()
{
    Base *base=new Base();
    delete base;//我们创建了一个 Base 类的对象，并将其指针赋值给 base 变量。
    //当我们调用 delete base 时，只有 Base 类的析构函数被调用，而 Derived 类的析构函数没有被调用。
    std::cout<<"-----------------------------"<<std::endl;
    Derived *derived = new Derived();
    delete derived;//我们创建了一个 Derived 类的对象，并将其指针赋值给 derived 变量。
    //当我们调用 delete derived 时，Derived 类的析构函数被调用，然后 Base 类的析构函数也被调用。
    //这是因为 Derived 类继承自 Base 类，所以在销毁 Derived 对象时，
    //Base 类的析构函数也会被调用来清理 Base 类部分的资源。
    std::cout<<"-----------------------------"<<std::endl;
    Base *base2 = new Derived();
    delete base2;//我们创建了一个 Derived 类的对象，并将其指针赋值给 base2 变量，这是一种向上转型。
    //当我们调用 delete base2 时，只有 Base 类的析构函数被调用，而 Derived 类的析构函数没有被调用。
    //这是因为 Base 类的析构函数没有被声明为虚函数，所以在删除 base2 时，
    //编译器只会调用 Base 类的析构函数，而不会调用 Derived 类的析构函数。
    //如果在 derived 类的建构函数中分配了资源，而在 derived 类的析构函数中释放了这些资源，那么在删除 base2 时就会导致资源泄漏，因为 derived 类的析构函数没有被调用来释放资源。
    //如果我们希望在删除 base2 时能够正确调用 Derived 类的析构函数，
    //应该将 Base 类的析构函数声明为虚函数，即在 Base 类中将 ~Base() 声明为 virtual ~Base()。
    //把 Base 的析构函数声明成 virtual 以后，delete 会走动态绑定，先调用最派生类的析构函数 Derived::Derived()，再自动调用 Base::Base()。这样才能把整个对象都正确销毁。对应到你这段 virtualdelete.cpp 里的 Base *base2 = new Derived(); delete base2;，virtual 之后输出顺序会变成先 Derived，再 Base。
    //本质上不是“virtual 让 delete 能删除”，而是“virtual 让 delete 在通过基类指针销毁对象时，能找到正确的析构链”。如果基类不打算通过指针被继承后删除，析构函数一般也就不必是 virtual；但只要存在 Base* 指向 Derived* 并且会 delete，就应该把 Base 析构函数设成 virtual。
    //加入virtual让编译器意识到，这个类可能会被扩展成其他类，并且通过基类指针来删除对象时需要正确调用析构函数链。这样，在删除 base2 时，编译器会正确地调用 Derived 类的析构函数，然后再调用 Base 类的析构函数，从而确保整个对象都被正确销毁，避免资源泄漏和未定义行为。
    std::cin.get();
    return 0;
}