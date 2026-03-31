#include <iostream>
#include <string>

void print(int value) {
    std::cout << "Integer: " << value << std::endl;
}

void print(double value) {
    std::cout << "Double: " << value << std::endl;
}

void print(const std::string& value) {
    std::cout << "String: " << value << std::endl;
}

template<typename T>// 这是一个函数模板，T 是一个占位符类型参数，可以代表任何类型。typename也可以用class来声明模板参数，效果是一样的。 
// 当我们调用 print 函数时，编译器会根据传入的参数类型自动推断出 T 的具体类型，并生成相应的函数实例。 
void print(T value) {
    std::cout << "Generic: " << value << std::endl;
}

template<typename wrong>
void printwrong(wrong value) {//部分编译器对报错的处理不同，可能会直接报错，也可能会生成一个函数实例，但在调用时才报错。我们可以通过调用 printwrong 函数来触发这个错误，看看编译器的反应。
    std::cout << "Wrong: " << value << std::endl;
}

template<int N>
class array {
private:
    int data[N];// 这里我们定义了一个模板类 array，它有一个非类型模板参数 N，表示数组的大小。data 是一个固定大小的整数数组，大小由模板参数 N 决定。我们可以通过实例化 array 模板来创建不同大小的数组，例如：array<5> myArray; 这将创建一个包含 5 个整数的数组。
public:
    int Getsize() const { return N; }
};

template<typename T, int N>
class Array {
private:
    T data[N];// 这里我们定义了一个模板类 array，它有一个非类型模板参数 N，表示数组的大小。data 是一个固定大小的数组，大小由模板参数 N 决定。我们可以通过实例化 array 模板来创建不同大小的数组，例如：array<5> myArray; 这将创建一个包含 5 个元素的数组。
public:
    int Getsize() const { return N; }
};

int main() {
    print(42); // 调用 print(int)
    print(3.14); // 调用 print(double)
    print("Hello, World!"); // 调用 print(const std::string&)
    print<std::string>("Hello, Template!"); // 也可以显式指定模板参数 T 为 std::string，调用 print(T)
    array<5> myArray; // 创建一个包含 5 个整数的数组
    std::cout << "array size: " << myArray.Getsize() << std::endl;
    Array<int, 10> anotherArray; // 创建一个包含 10 个整数的数组
    std::cout << "Another array size: " << anotherArray.Getsize() << std::endl;
    std::cin.get();
    return 0;
}