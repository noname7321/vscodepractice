#include<iostream>

struct entity
{
    int x,y;

    int *getposition()
    {
        return &x;//我们返回了成员变量 x 的地址，
        //这样我们就可以通过这个指针来访问和修改结构体中的成员变量 x 和 y。
    }

};

int main()
{
    int a=50;
    double value=a;
    std::cout<<"Value: "<<value<<std::endl;

    int b=30;
    double c = *(double*)(&b);//`这里我们将整数 b 的地址强制转换为 double* 类型，然后解引用，将其赋值给 c。
    //需要注意的是，这种类型转换是不安全的，因为它可能会导致未定义行为。
    //因为我们将一个整数的地址解释为一个 double 类型的指针，这可能会导致内存访问错误或者数据损坏。
    //因为int本身只获取了4个字节，而double需要8个字节，
    //所以在访问c时可能会读取到未定义的内存区域，导致程序崩溃或者产生不可预测的结果。

    entity e={10,20};
    int* ptr = (int*)&e;//我们将结构体 entity 的地址强制转换为 int* 类型，
    //然后通过指针访问结构体中的成员变量 x 和 y。
    //entity 没有自己单独的地址，只有两个整型成员变量，它们在内存中是连续存储的。
    std::cout<<"x: "<<ptr[0]<<", y: "<<ptr[1]<<std::endl;
    int y = *(int*)((char*)&e + sizeof(int));//我们将结构体 entity 的地址强制转换为 char* 类型，
    //然后加上 sizeof(int) 来跳过第一个成员变量 x，最后再将其强制转换回 int* 类型并解引用，
    //来访问成员变量 y。这种方法也是不安全的，因为它依赖于结构体成员变量的内存布局和对齐方式，
    //这可能会因编译器和平台的不同而有所变化。
    std::cout<<"y: "<<y<<std::endl;

    int *position = e.getposition();//我们调用了结构体 entity 的成员函数 getposition()，它返回了成员变量 x 的地址。
    std::cout<<"Position: "<<*position<<std::endl;//我们通过解引用指针 position 来访问成员变量 x 的值，并将其输出到控制台上。

    std::cin.get();
    return 0;
}