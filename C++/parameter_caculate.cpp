#include<iostream>

void printsum(int a, int b) {
    std::cout << a <<" + " << b << " = " << a + b << std::endl;
}

int main()
{
    int x = 0;
    printsum(x++, x++);
    std::cin.get();
    return 0;
}