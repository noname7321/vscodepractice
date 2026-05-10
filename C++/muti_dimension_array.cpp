#include<iostream>

int main()
{
    int* array =new int[50];
    int** multi_array = new int*[50];
    for(int i = 0; i < 50; ++i)
    {
        multi_array[i] = new int[50];
        //最终得到了一个 50x50 的二维数组，multi_array 是一个指向指针的指针，每个 multi_array[i] 都是一个指向整数数组的指针，这些整数数组分别存储了二维数组的每一行的数据。
    }
    // Don't forget to deallocate the memory
    delete[] array;
    for(int i = 0; i < 50; ++i)
    {
        delete[] multi_array[i];//先删除每一行的内存，然后再删除 multi_array 本身的内存。
    }
    delete[] multi_array;

    int * array2 =new int[5*5];
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            array2[i*5 + j] = i*5 + j;//我们使用了一个一维数组 array2 来模拟一个二维数组。通过计算索引 i*5 + j，我们可以访问到对应的元素，就像在二维数组中一样。
        }
    }
    delete[] array2;
    return 0;
}