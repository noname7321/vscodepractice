#include<iostream>
#include<vector>

void helloworld()
{
    std::cout<<"Hello, World!"<<std::endl;
}

void HelloWorld(int a)
{
    std::cout<<"Hello, World! "<<a<<std::endl;
}

void printvalue(int value)
{
    std::cout<<"Value: "<<value<<std::endl;
}

void foreach(const std::vector<int>& values,auto func)
{
    for(int value:values)
    {
        func(value);
    }
}

void foreach(const std::vector<int>& values, void (*func)(int))
{
    for (int value : values)
    {
        func(value);
    }
}

template<typename Func>
void Foreach(const std::vector<int>& values,Func func)
{
    for(int value:values)
    {
        func(value);
    }
}

int main()
{
    auto function = &helloworld;//我们使用了取地址运算符 & 来获取函数 helloworld 的地址，并将其赋值给一个名为 function 的变量。这个变量 function 是一个函数指针，它可以用来调用 helloworld 函数。
    function();//我们通过函数指针 function 来调用 helloworld 函数。这会输出 "Hello, World!" 到控制台。
    (*function)();
    void(*func)()=&helloworld;//我们定义了一个函数指针变量 func，它可以指向任何返回类型为 void、参数列表为空的函数。我们将 helloworld 函数的地址赋值给 func，这样 func 就指向了 helloworld 函数。
    func();//我们通过函数指针 func 来调用 helloworld 函数。这会输出 "Hello, World!" 到控制台。
    auto func2=&HelloWorld;//我们使用 auto 关键字来自动推断 func2 的类型。由于 HelloWorld 是一个函数，它的类型是 void(int)，因此 func2 的类型将被推断为 void(*)(int)，即一个指向返回类型为 void、参数列表为 int 的函数的指针。我们将 HelloWorld 函数的地址赋值给 func2，这样 func2 就指向了 HelloWorld 函数。
    func2(42);//我们通过函数指针 func2 来调用 HelloWorld 函数。这会输出 "Hello, World! 42" 到控制台
    
    std::vector<int> values = {4, 2, 3, 1, 5};
    foreach(values,&printvalue);
    
    std::cin.get(); 
    return 0;

} 
//[](int value){std::cout<<"Value: "<<value<<std::endl;}//这是一个 lambda 表达式，它定义了一个匿名函数，接受一个整数参数 value，并在函数体内输出 "Value: " followed by the value of the parameter to the console. Lambda 表达式是一种方便的方式来定义匿名函数，可以直接在需要函数对象的地方使用，而不需要单独定义一个命名函数。
//我们可以将这个 lambda 表达式作为参数传递给 foreach 函数，这样 foreach 函数就可以在遍历 values 向量时调用这个匿名函数来处理每个元素。