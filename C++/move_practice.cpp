#include<iostream>
#include<vector>
#include<cstring>
#include<cstdint>

class String{
public:
    String()=default;
    String(const char* string)
    {
        printf("String constructor called\n");
        m_size=strlen(string);
        m_data=new char[m_size+1];
        strcpy(m_data, string);
    }
    String(const String& other)
    {
        printf("String copy constructor called\n");
        m_size=other.m_size;
        m_data=new char[m_size+1];
        strcpy(m_data, other.m_data);
    }
    String(String&& other) noexcept//noexcept 是“不抛异常”的承诺；放在移动构造函数上，可以让 vector 等容器更放心地使用移动语义，而不是退回拷贝。
    {
        printf("String move constructor called\n");
        m_size=other.m_size;
        m_data=other.m_data;
        other.m_size=0;
        other.m_data=nullptr;
    }
    String & operator=(const String& other)
    {
        printf("String copy assignment operator called\n");
        if(this!=&other)
        {
            delete[] m_data;
            m_size=other.m_size;
            m_data=new char[m_size+1];
            strcpy(m_data, other.m_data);
        }
        return *this;
    }
    String & operator=(String&& other) noexcept
    {
        printf("String move assignment operator called\n");
        if(this!=&other)
        {
            delete[] m_data;
            m_size=other.m_size;
            m_data=other.m_data;
            other.m_size=0;
            other.m_data=nullptr;
        }
        return *this;
    }
    ~String()
    {
        delete[] m_data;
    }
    void Print()
    {
        for(uint32_t i=0;i<m_size;i++)
        {
            std::cout<<m_data[i];
        }
    }

private:
    size_t m_size;
    char* m_data;
};

class entity{
public:
    entity()=default;
    entity(const String& name):m_name(name)//构造 entity 对象的时候，用参数 name 来初始化成员变量 m_name
    {
        printf("entity copy constructor called\n");
    }
    entity(String&& name):m_name(std::move(name))//构造 entity 对象的时候，需要显式地使用 std::move 来将参数 name 转换为右值引用，以便调用 String 的移动构造函数来初始化成员变量 m_name
    {
        printf("entity move constructor called\n");
    }
    void printname()
    {
        m_name.Print();
    }
private:
    String m_name;
};

int main()
{
    // std::vector<int> v1{1, 2, 3, 4, 5};
    // std::vector<int> v2 = std::move(v1); // Move v1 to v2
    // std::cout<< "v1 size: " << v1.size() << std::endl; // Output may be 0 or 5 depending on the implementation
    // v1.push_back(6); // v1 is now in a valid but unspecified state, so we can still use it
    // std::cout << "v1 size: " << v1.size() << std::endl; // Output may be 1 or 6 depending on the implementation
    // std::cout << "v2 size: " << v2.size() << std::endl; // Output will be 5
    // v1.push_back(7); // v1 is still valid, we can push back more elements
    // std::cout << "v1 size: " << v1.size() << std::endl; // Output may be 2 or 7 depending on the implementation
    // std::cout<<v1[0]<<v1[1]<<std::endl; // Output may be 6 and 7 or 0 and 0 depending on the implementation
    entity e1(String("Hello"));
    e1.printname();
    String string = "World";
    String string2 = std::move(string);
    string2 = String("Move Assignment");// 这里是移动赋值，先创建一个临时的 String 对象，然后把它移动到 string2 中
    string = std::move(string2);// 这里是移动赋值，把 string2 的资源移动到 string 中，string2 之后就变成了一个空字符串
    string2.Print();
    std::cin.get();
    return 0;
}
// 这里的 operator 是 C++ 的运算符重载关键字。

// 这句：

// String& operator=(const String& other)
// 意思是：

// 定义 String 对象使用 = 赋值时该怎么做
// 比如你写：

// String a("Hello");
// String b("World");

// b = a;
// 编译器会把它理解成类似：

// b.operator=(a);
// 所以：

// operator=
// 可以理解成一个特殊函数名，意思是“重载赋值运算符 =”。

// 拆开看：

// String& operator=(const String& other)
// 分别是：

// String&              // 返回类型：返回当前 String 对象的引用
// operator=            // 函数名：重载 = 运算符
// const String& other   // 参数：等号右边那个 String
// 在这个例子里：

// b = a;
// 对应关系是：

// b        // this，等号左边的对象
// a        // other，等号右边的对象
// 所以函数内部：

// delete[] m_data;
// m_size = other.m_size;
// m_data = new char[m_size + 1];
// strcpy(m_data, other.m_data);
// return *this;
// 意思是：把 b 原来的数据删掉，然后复制 a 的数据，最后返回 b 自己。

// 为什么返回 String&？

// 为了支持这种写法：

// a = b = c;
// 执行顺序大概是：

// b = c;  // 返回 b
// a = b;
// 所以赋值运算符通常会写成：

// String& operator=(...)
// {
//     ...
//     return *this;
// }
// 这里 this 是指向当前对象的指针，*this 就是当前对象本身。

// 一句话：

// operator= 就是在告诉 C++：当两个 String 对象之间使用 = 时，不要用默认行为，而是按我这里写的规则来赋值。