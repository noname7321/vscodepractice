#include<iostream>
#include<string>
struct Vector2
{
    float x, y;
};
void offsetwrong()
{
    ((Vector2*)nullptr)->x;//这里我们将nullptr转换为Vector2类型的指针，然后尝试访问它的x成员。这是一个未定义行为，因为我们正在解引用一个空指针。虽然编译器可能不会报错，但在运行时，这段代码可能会导致程序崩溃或产生不可预测的结果。总之，这种做法是非常危险的，应该避免。
    int offset = (int)&((Vector2*)nullptr)->x;// 我们通过将nullptr转换为Vector2类型的指针，并访问它的x成员，来计算x成员在Vector2结构体中的偏移量。这个偏移量表示了x成员相对于结构体起始地址的位置。虽然这种做法在某些编译器上可能会得到正确的结果，但它仍然是未定义行为，因为我们正在解引用一个空指针。
    std::cout << "Offset of x in Vector2: " << offset << std::endl;//我们输出了x成员在Vector2结构体中的偏移量。这个偏移量表示了x成员相对于结构体起始地址的位置。通常情况下，x成员的偏移量应该是0，因为它是结构体中的第一个成员。
    std::cin.get();
}
//我们可以使用offsetof宏来安全地计算结构体成员的偏移量，而不需要进行任何指针操作。offsetof宏是C++标准库提供的一个宏，它接受两个参数：结构体类型和成员名称，并返回该成员在结构体中的偏移量。例如，我们可以这样使用offsetof宏来计算x成员的偏移量：
#include <cstddef> // 包含offsetof宏的定义
struct Vector3
{
    float x, y, z;
};
void offsetcorrect()
{
    size_t offset = offsetof(Vector3, x);//我们使用offsetof宏来计算x成员在Vector3结构体中的偏移量。这个偏移量表示了x成员相对于结构体起始地址的位置。通常情况下，x成员的偏移量应该是0，因为它是结构体中的第一个成员。
    std::cout << "Offset of x in Vector3: " << offset << std::endl;//我们输出了x成员在Vector3结构体中的偏移量。这个偏移量表示了x成员相对于结构体起始地址的位置。通常情况下，x成员的偏移量应该是0，因为它是结构体中的第一个成员。
    std::cin.get();
}
int main()
{
    offsetwrong();
    offsetcorrect();
}