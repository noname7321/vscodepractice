#include<iostream>

class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    void doSomething()
    {
        std::cout << "Doing something with the singleton instance." << std::endl;
    }
    float RNG()
    {
        std::cout << "Generating random number." << randomValue << std::endl;
        return randomValue;
    }

private:
    Singleton(){}
    Singleton(const Singleton&) = delete;             // 禁止拷贝构造
    Singleton& operator=(const Singleton&) = delete;  // 禁止拷贝赋值
    float randomValue = 0.0f; // 示例成员变量
};

namespace RNGclass {
    float generateRandomNumber() {
        // 这里可以实现一个简单的随机数生成算法，或者使用 C++ 标准库中的随机数生成器
        return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    }
}


Singleton &singleton1 = Singleton::getInstance();
Singleton &singleton2 = Singleton::getInstance();
auto& singleton3 = Singleton::getInstance(); // 使用 auto 关键字

int main()
{
    singleton1.doSomething();
    singleton2.doSomething();

    if (&singleton1 == &singleton2) {
        std::cout << "singleton1 and singleton2 are the same instance." << std::endl;
    } else {
        std::cout << "singleton1 and singleton2 are different instances." << std::endl;
    }
    float number = singleton1.RNG();

    return 0;
}