#include<iostream>
#include<tuple>
#include<string>

std::tuple<std::string,int> CreatePerson()
{
    return std::make_tuple("Alice", 30);
}

struct Person
{
    std::string name;
    int age;
};

int main()
{
    auto person = CreatePerson();    
    auto name = std::get<0>(person);//std::string name = std::get<0>(person);我们使用 std::get<0>(person) 来获取元组 person 中的第一个元素，并将其赋值给 name 变量。由于 person 是一个 std::tuple<std::string, int> 类型的对象，所以 std::get<0>(person) 返回的是一个 std::string 类型的值，即 "Alice"。
    auto age = std::get<1>(person);
    std::cout<<"Name: "<<name<<", Age: "<<age<<std::endl;   
    auto[name1,age1]=CreatePerson();//结构化绑定
    return 0;
}