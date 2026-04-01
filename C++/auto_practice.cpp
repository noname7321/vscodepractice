#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

class Device{};

class DeviceManager
{
private:
    std::unordered_map<std::string, Device*> m_devices;

public:
    const std::unordered_map<std::string, Device*>& GetDevices() const
    {
        return m_devices;
    }
};

int main()
{
    int a=5;
    auto b=a;// auto 关键字会根据初始化表达式的类型自动推断出变量 b 的类型。在这个例子中，a 是一个整数，所以 b 的类型也会被推断为 int。因此，b 将是一个整数变量，并且被初始化为 a 的值，即 5。  
    std::cout<<b<<std::endl;
    auto c=3.14;// 在这个例子中，c 的类型会被推断为 double，因为 3.14 是一个双精度浮点数字面量。因此，c 将是一个 double 类型的变量，并且被初始化为 3.14。
    std::cout<<c<<std::endl;

    std::vector<std::string> strings;
    strings.push_back("Hello");
    strings.push_back("World");
    strings.push_back("Auto");

    //std::vector<std::string>::iterator 是 vector 容器提供的迭代器类型，它类似于指针，可以指向容器中的元素。
    for(std::vector<std::string>::iterator it=strings.begin();it!=strings.end();++it)
    {
        std::cout<<*it<<std::endl;
    }//这里是旧式的迭代器使用方式，我们需要显式地指定迭代器的类型，并使用 begin() 和 end() 方法来获取容器的起始和结束迭代器。我们通过解引用迭代器（*it）来访问容器中的元素。
    
    for(auto it=strings.begin();it!=strings.end();++it)//这里我们使用 auto 关键字来自动推断迭代器的类型，这样我们就不需要显式地指定迭代器的类型了。编译器会根据 strings.begin() 的返回类型自动推断出 it 的类型。
    {
        std::cout<<*it<<std::endl;
    }

    DeviceManager manager;
    auto devices = manager.GetDevices();//这里我们使用 auto 关键字来自动推断 devices 的类型。GetDevices() 方法返回一个 const std::unordered_map<std::string, Device*>&，因此 devices 的类型将被推断为 const std::unordered_map<std::string, Device*>&。这样，我们就可以直接使用 devices 来访问设备管理器中的设备，而不需要显式地指定类型。
    const auto& devices_ref = manager.GetDevices();//避免了不必要的复制操作，提高了性能。

    DeviceManager manager2;
    using DeviceMap = std::unordered_map<std::string, Device*>;//我们使用 using 关键字来定义了一个类型别名 DeviceMap，它代表了 std::unordered_map<std::string, Device*> 这个类型。这样，我们就可以使用 DeviceMap 来代替 std::unordered_map<std::string, Device*>，使代码更加简洁和易读。
    const DeviceMap& devices2 = manager2.GetDevices();//这里我们使用了之前定义的类型

    std::cin.get();
}