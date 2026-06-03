#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2 = std::move(v1); // Move v1 to v2
    v1.push_back(6); // v1 is now in a valid but unspecified state, so we can still use it
    std::cout << "v1 size: " << v1.size() << std::endl; // Output may be 0 or 1 depending on the implementation
    std::cout << "v2 size: " << v2.size() << std::endl; // Output will be 5
    std::cin.get();
    return 0;
}