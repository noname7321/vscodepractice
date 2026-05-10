#include<iostream>

struct vector3
{
    float x,y,z;
};

struct vector4
{
    float x,y,z,w;
};

void printvector3(const vector3& v)
{
    std::cout<<"vector3: ("<<v.x<<", "<<v.y<<", "<<v.z<<")"<<std::endl;
}

void printvector4(const vector4& v)
{
    std::cout<<"vector4: ("<<v.x<<", "<<v.y<<", "<<v.z<<", "<<v.w<<")"<<std::endl;
}

int main()
{
    struct Union
    {
        union
        {
            float a;
            int b;
        };
    };
    Union u;
    u.a=3.14f;
    std::cout<<u.a<<','<<u.b<<std::endl;//我们将浮点数 3.14f 赋值给了联合体成员 a，然后通过访问成员 b 来查看它的整数表示形式。
    //由于联合体的成员共享同一块内存，所以当我们将一个值赋给成员 a 时，它会覆盖成员 b 的值。
    //因此，访问成员 b 时，我们会得到一个整数值，这个值是浮点数 3.14f 在内存中的二进制表示形式被解释为整数后的结果。
    //需要注意的是，这种行为是平台和编译器相关的，因为不同的平台和编译器可能会使用不同的浮点数表示方式和内存布局。
    //因此，输出的整数值可能会有所不同，甚至可能会导致未定义行为。
    std::cin.get();
    return 0;
}