#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

int main( )
{
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};
    
    // 使用 std::sort 对 vector 进行排序，默认是升序排序
    std::sort(vec.begin(), vec.end());
    
    // 输出排序后的结果
    std::cout << "Sorted vector: ";
    for (const auto& num : vec) {// &代表引用，const代表只读，auto代表自动推断类型，这样我们就不需要显式地指定 num 的类型了。
        std::cout << num << " ";
    }
    std::cout << std::endl;
    //: 表示“从容器中取出元素”；每次循环把 vec 的一个元素绑定到变量 num 上并执行循环体。
    // for (size_t i = 0; i < vec.size(); ++i) {
    // const auto& num = vec[i];
    // std::cout << num << " ";
    // }

    std::sort(vec.begin(), vec.end(), std::greater<int>()); // 使用 std::greater<int>() 进行降序排序
    std::cout << "Sorted vector (descending): ";
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b) { return a < b; }); // 使用 lambda 表达式进行升序排序
    //当a<b时返回true，表示a应该排在b前面，从而实现升序排序。
    std::cout << "Sorted vector (ascending with lambda): ";
    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cin.get(); 
    return 0;
}