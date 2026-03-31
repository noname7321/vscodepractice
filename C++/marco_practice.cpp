#include<iostream>
#include<string>
#define PR_DEBUG 1

#if PR_DEBUG ==1
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

#define MAIN int main()\
{\
    std::cout << "Hello, World!" << std::endl;\
    std::cin.get();\
}

int main()
{
    LOG("Hello, World!");
    std::cin.get();
}