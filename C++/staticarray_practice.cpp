#include<iostream>
#include<string>
#include<array>
//std::size_t 指定了 N 的类型（无符号整型）。
// N 本身是一个值，在编译时确定，并被用作 std::array<int, N> 的第二个模板参数，表示数组的元素个数。
template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    for (const auto& value : arr)
    {
        std::cout << value << std::endl;
    }
}

int main()
{
    //std::array是一个模板类，接受两个模板参数：第一个参数是数组元素的类型，第二个参数是数组的大小。在这个例子中，我们定义了一个包含 5 个整数的 std::array。
    std::array<int, 5> arr = {1, 2, 3, 4, 5};//这里我们使用 std::array 来定义了一个包含 5 个整数的数组，并初始化了每个元素的值。std::array 是 C++ 标准库提供的一个固定大小的数组容器，它封装了一个固定大小的数组，并提供了一些成员函数来操作数组。
    arr[0]=10;
    //arr[6]=1;这个代码会在编译时产生错误，因为我们试图访问 std::array 中不存在的第 6 个元素（索引为 5）。std::array 的大小在编译时确定，并且访问越界的元素会导致编译错误或运行时错误。
    for(size_t i=0;i<arr.size();++i)
    {
        std::cout<<arr[i]<<std::endl;
    }
    for(int value:arr)//这里我们使用了范围-based for 循环（range-based for loop）来遍历 std::array 中的元素。这个循环会自动迭代 arr 中的每个元素，并将当前元素的值赋给变量 value，然后在循环体内输出 value 的值。
    {
        std::cout<<value<<std::endl;
    }
    int data[3];
    //data[4]=10;//而这里不会在编译时产生错误，因为 data 是一个普通的 C 风格数组，编译器不会检查访问是否越界。然而，在运行时，这段代码会导致未定义行为，因为我们试图访问 data 数组中不存在的第 5 个元素（索引为 4）。访问越界的数组元素可能会导致程序崩溃、数据损坏或其他不可预测的行为。
    std::cin.get();
}