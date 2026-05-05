#include<iostream>
#include<string>
#include<cstring>
#include<vector>

namespace apple
{
    void print()
    {
        std::cout<<"This is apple namespace."<<std::endl;
    }
}

namespace orange
{
    void print()
    {
        std::cout<<"This is orange namespace."<<std::endl;
    }
}

namespace reverse
{
    void print(const std::string& str)
    {
        std::string reversed_str(str.rbegin(), str.rend());//我们使用了字符串的反向迭代器（rbegin() 和 rend()）来创建一个新的字符串 reversed_str，它包含了原字符串 str 的字符，但顺序是反转的。
        std::cout<<reversed_str<<std::endl;
    }
}

int main()
{
    apple::print();//我们通过 apple::print() 来调用 print 函数，这里的 apple 是命名空间的名称，print 是命名空间中的函数。使用命名空间可以帮助我们组织代码，避免命名冲突，并提高代码的可读性和维护性。
    orange::print();
    reverse::print("Hello, World!");
    using namespace apple;//我们使用 using namespace apple; 来引入 apple 命名空间，这样我们就可以直接调用 apple 命名空间中的函数，而不需要每次都写出命名空间的名称。
    print();//现在我们可以直接调用 print() 函数，而不需要使用 apple::print()，因为我们已经引入了 apple 命名空间。
    std::cin.get();
    return 0;
}