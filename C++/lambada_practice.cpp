#include<iostream>
#include<vector>
#include<algorithm>

void Foreach(const std::vector<int>& values, auto func)
{
    for(int value:values)
    {
        func(value);
    }
}

int main()
{
    std::vector<int> values = {4, 2, 3, 1, 5};

    int a=1;
    auto lambda = [&a](int value){std::cout << "Value: " << value << " (from lambda)" << a << std::endl;};

    Foreach(values, lambda);
    //返回类型是一个迭代器，具体来说是和 values 对应的 iterator。它表示“找到的那个元素的位置”。
    auto it = std::find_if(values.begin(), values.end(), [](int value){return value % 2 == 0;});
    if (it != values.end()) {
        std::cout << "Found even value: " << *it << std::endl;
    }
    std::cin.get();
}