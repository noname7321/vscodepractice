#include<iostream>
#include<string>
#include<cstring>

//经常用const reference传递参数，避免不必要的复制操作，提高性能。
class String
{
private:
    char* m_Buffer;
    unsigned int m_Size;
public:
    String(const char* string)
    {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size + 1];//plus 1 for the null terminator
        memcpy(m_Buffer, string, m_Size);// 是把参数 string 指向的原始字符数组复制到当前对象的新缓冲区里。这里的源是构造函数传进来的 const char*。
        m_Buffer[m_Size] = 0;
    }
    //String(const String &other)=delete;//我们删除了String类的拷贝构造函数，禁止了对象的拷贝操作。
    //这意味着我们不能通过复制一个String对象来创建另一个String对象，也不能将一个String对象赋值给另一个String对象。
    //这样做是为了避免浅拷贝带来的问题，如内存泄漏或双重释放，因为默认的拷贝构造函数会进行浅拷贝，即复制指针的值而不是指针所指向的内容。
    String(const String& other):m_Size(other.m_Size)
    {
        m_Buffer = new char[m_Size + 1];//plus 1 for the null terminator
        memcpy(m_Buffer, other.m_Buffer, m_Size);//我们在拷贝构造函数中为新的对象分配了独立的内存，并将原对象的内容复制到新的内存中。这实现了深拷贝，确保每个对象都有自己的内存资源，避免了浅拷贝带来的问题。
        m_Buffer[m_Size] = 0;
    }

    ~String()
    {
        delete[] m_Buffer;// we use delete[] to free the memory allocated for the character array.
        //This is important to prevent memory leaks, as the String class allocates memory on the heap for its internal buffer.
    }
    char& operator[](unsigned int index)
    {
        return m_Buffer[index];// we return a reference to the character at the specified index in the m_Buffer array. This allows us to modify the character directly through the returned reference.
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);
};
std::ostream& operator<<(std::ostream& stream, const String& string)
{
//参数 stream 不是复制一份输出流对象
// 而是直接引用外面的那个流对象
// 返回值也不是复制，而是返回同一个流对象的引用
    stream << string.m_Buffer;//这一句真正把 String 内部保存的字符数组输出到流里。
    return stream;//返回同一个流对象的引用。
// 这样可以支持连续输出，比如：
// std::cout << a << b;
}
// std::ostream 是 C++ 标准库里的“输出流类型”。
// 可以把它理解成一类“负责输出数据的对象”的类型，比如：
// 屏幕：std::cout
// 文件：std::ofstream
// 字符串缓冲区：std::ostringstream
// 它们都属于输出流这一类。
int main()
{   
    // 为什么 String a = "Hello, World!"; 会走 String(const char*)：
    // 字符串字面量 "Hello, World!" 的类型可以看成 const char* 相关形式
    // 这正好匹配 String(const char*)
    // 所以它用的是“从 C 字符串构造 String”，不是拷贝另一个 String
    String a = "Hello, World!";
    // 为什么 String b = a; 会走 String(const String& other)：
    // a 的类型就是 String
    // 初始化 b 时，编译器优先找能直接接收 String 的构造函数
    // String(const String&) 是完全匹配
    // String(const char*) 需要把 String 先转成 const char*，但你类里又没有这个转换能力，所以它根本不适用
    String b = a; // 在这个地方，b的拷贝属于浅拷贝，只是让b的m_Buffer指针指向了a的m_Buffer所指向的同一块内存区域。这意味着a和b共享同一块内存，当a或b被销毁时，都会调用析构函数释放这块内存，导致另一个对象的m_Buffer指针变成悬空指针（dangling pointer），访问它会导致未定义行为。
    // 这就是浅拷贝的问题所在：当一个对象被复制时，如果它包含指针成员，复制操作只是复制指针的值（即内存地址），而不是复制指针所指向的内容。这会导致多个对象共享同一块内存，进而引发资源管理问题，如内存泄漏或双重释放。
    std::cout<< a<< b << std::endl;
    b[0] = 'h';//我们修改了b的第一个字符为小写的'h'，由于a和b共享同一块内存，这个修改也会影响到a。因此，当我们输出a时，它也会显示为"hello, World!"，而不是原来的"Hello, World!"。这进一步说明了浅拷贝的问题：当一个对象被复制时，如果它包含指针成员，复制操作只是复制指针的值（即内存地址），而不是复制指针所指向的内容。这会导致多个对象共享同一块内存，进而引发资源管理问题，如内存泄漏或双重释放。
    std::cout<< a<< b << std::endl;
    std::cin.get();
}