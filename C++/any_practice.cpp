#include<iostream>
#include<any>

int main()
{
    std::any data;
    data = 42;
    std::cout<<"Data holds int: "<<std::any_cast<int>(data)<<std::endl;
    data = std::string("Hello, Any!");
    std::cout<<"Data holds string: "<<std::any_cast<std::string>(data)<<std::endl;
    std::string& str = std::any_cast<std::string&>(data);
    std::cout<<"Data holds string reference: "<<str<<std::endl;
    try
    {
        std::cout<<"Trying to get int from data: "<<std::any_cast<int>(data)<<std::endl;
    }
    catch(const std::bad_any_cast& e)
    {
        std::cout<<"Caught exception: "<<e.what()<<std::endl;
    }
}