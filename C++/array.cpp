#include<iostream>

int main()
{
    int example[5];
    int *ptr = example;//pointer to the first element of the array
    for(int i = 0; i < 5; i++)//initialize array using pointer
    {
        ptr[i] = (i + 1) * 10;
    }
    for(int i = 0; i < 5; i++)
    {
        std::cout << "example[" << i << "] = " << ptr[i] << std::endl;
    }
    example[2] = 100;//modify array element using array name
    *((int*)((char*)ptr+2*4)) = 120;//modify array element using pointer arithmetic and type casting
    //for every int, there are 4 bytes, so we move 2*4 bytes to reach the third element
    std::cout << "After modification:" << std::endl;
    for(int i = 0; i < 5; i++)
    {
        std::cout << "example[" << i << "] = " << ptr[i] << std::endl;
    }
    return 0;
}