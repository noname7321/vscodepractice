#include<iostream>
#include<vector>

int main()
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    std::vector<int> v2 = std::move(v1); // Move v1 to v2
    std::cout<< "v1 size: " << v1.size() << std::endl; // Output may be 0 or 5 depending on the implementation
    v1.push_back(6); // v1 is now in a valid but unspecified state, so we can still use it
    std::cout << "v1 size: " << v1.size() << std::endl; // Output may be 1 or 6 depending on the implementation
    std::cout << "v2 size: " << v2.size() << std::endl; // Output will be 5
    v1.push_back(7); // v1 is still valid, we can push back more elements
    std::cout << "v1 size: " << v1.size() << std::endl; // Output may be 2 or 7 depending on the implementation
    std::cout<<v1[0]<<v1[1]<<std::endl; // Output may be 6 and 7 or 0 and 0 depending on the implementation
    std::cin.get();
    return 0;
}