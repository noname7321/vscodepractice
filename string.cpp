#include<iostream>
#include<vector>
#include<string>
#include <cstring>

void printstring(const std::string& str)//use reference to avoid copying
{
    for(size_t i = 0; i < str.size(); i++)
    {
        std::cout << "Character at index " << i << " : " << str[i] << std::endl;
    }
}

int main()
{
    const char* cstr = "Hello, World!";//C-style string
    strlen(cstr); //calculate the length of C-style string
    //const means the content(here is "Hello, World!") pointed to by cstr cannot be modified,but cstr can point to another string
    std::string str1 = "Hello, C++23!";//C++ string
    str1.size(); //calculate the length of C++ string
    str1+= " Let's learn about strings.";//concatenate C++ strings
    char name1[] = "Hello"; //C-style string using char array
    char name2[6]=  {'W','o','r','l','d','\0'}; //C-style string using char array
    //'\0' is the null terminator indicating the end of the string
    //''is used for single characters,"" is used for string literals
    std::string str2 =std::string(name1) + " " + std::string(name2)+ std::string("!"); 
    //convert C-style strings to C++ strings and concatenate
    bool contains = (str1.find("C++23") != std::string::npos); //check if str1 contains "C++23"
    std::cout << std::boolalpha << contains << std::endl;

    std::cout << name1 << std::endl;
    std::cout << name2 << std::endl;
    std::cout << cstr << std::endl;
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
    printstring(str1);
}