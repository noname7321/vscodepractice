#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdint>

static uint64_t counter = 0;

void printname(const std::string& name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

void printname(std::string_view name) {//string view 的优点是它不需要复制字符串数据，而是直接引用原始字符串的内存。这意味着在使用 string view 时，不会发生额外的内存分配和复制操作，从而提高了性能和效率。
    std::cout << "Hello, " << name << "!" << std::endl;
}

void *operator new(size_t size) {
    counter++;
    std::cout << "Allocating memory: " << size << " bytes. Total allocations: " << counter << std::endl;
    return malloc(size);
}

int main() {
    std::string name = "long long long long long long long World";
    const char *cstr_name = name.c_str();
    printname(name);
#if 0
    std::string name = "John Doe";
    std::string firstname = name.substr(0, 3);
    std::string lastname = name.substr(4,9);
    std::cout << "First name: " << firstname << std::endl;
    std::cout << "Last name: " << lastname << std::endl;
#else
    std::string_view firstname_view = name.substr(0, 3);
    std::string_view lastname_view = name.substr(4,9);
    std::cout << "First name (view): " << firstname_view << std::endl;
    std::cout << "Last name (view): " << lastname_view << std::endl;
#endif
    std::cin.get();
    return 0;
}