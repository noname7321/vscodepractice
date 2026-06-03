#include<iostream>
#include<variant>

enum error_code
{
    Success,
    FileNotFound,
    PermissionDenied,
    UnknownError
};

std::variant<std::string,error_code> readfileasstring(const std::string& filepath)
{
    // Simulate file reading logic
    if(filepath=="data.txt")
    {
        return "File content goes here.";
    }
    else if(filepath=="missing.txt")
    {
        return error_code::FileNotFound;
    }
    else if(filepath=="protected.txt")
    {
        return error_code::PermissionDenied;
    }
    return error_code::UnknownError;
}


int main()
{
    std::variant<int,std::string> data;
    data = 42;
    std::cout<<sizeof(int)<<std::endl; //size of int
    std::cout<<sizeof(std::string)<<std::endl; //size of string (usually small, but can vary based on implementation)
    std::cout<<sizeof(data)<<std::endl; //size of variant is size of largest type + some overhead

    std::cout<<"Data holds int: "<<std::get<int>(data)<<std::endl;
    data = "Hello, Variant!";
    std::cout<<"Data holds string: "<<std::get<std::string>(data)<<std::endl;
    std::cout<<"Index of currently held type: "<<data.index()<<std::endl;
    auto ptr = std::get_if<int>(&data);//returns nullptr if data does not hold an int
    if(ptr)
    {
        std::cout<<"Data holds int: "<<*ptr<<std::endl;
    }
    else
    {
        std::cout<<"Data does not hold an int."<<std::endl;
    }

    try
    {
        std::cout<<"Trying to get int from data: "<<std::get<int>(data)<<std::endl;
    }
    catch(const std::bad_variant_access& e)
    {
        std::cout<<"Caught exception: "<<e.what()<<std::endl;
    }

    if(std::holds_alternative<int>(data))
    {
        std::cout<<"Data currently holds an int."<<std::endl;
    }
    else if(std::holds_alternative<std::string>(data))
    {
        std::cout<<"Data currently holds a string."<<std::endl;
    }

    std::cin.get();
}