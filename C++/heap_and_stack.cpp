#include<iostream>
#include<string>
#include<cstring>

struct Vector3
{
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
};

int main()
{
    int value=42;//在栈上分配一个整数变量 value，并初始化为 42。这个变量的内存空间会在 main 函数结束时自动释放。 
    int array[5];
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;
    array[4] = 5;//在栈上分配一个包含 5 个整数的数组，并初始化每个元素的值。这个数组的内存空间会在 main 函数结束时自动释放。
    
    Vector3 vector;
    vector.x = 1.0f;

    int *hvalue=new int;// 这里我们使用 new 运算符在堆上动态分配了一个整数，并将其地址赋值给指针 hvalue。这样，我们就可以通过 hvalue 指针来访问和修改这个整数的值。
    *hvalue=value;
    int *harray=new int[5];// 这里我们使用 new 运算符在堆上动态分配了一个整数数组，包含 5 个整数，并将其地址赋值给指针 harray。这样，我们就可以通过 harray 指针来访问和修改这个整数数组的元素。
    harray[0] = 1;
    harray[1] = 2;
    harray[2] = 3;
    harray[3] = 4;
    harray[4] = 5;

    Vector3* hvec = new Vector3();// 这里我们使用 new 运算符在堆上动态分配了一个 Vector3 结构体，并将其地址赋值给指针 hvec。这样，我们就可以通过 hvec 指针来访问和修改这个 Vector3 结构体的成员变量 x、y 和 z。
    hvec->x = 1.0f;

    std::cin.get();
}