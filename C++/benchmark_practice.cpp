#include<iostream>
#include<chrono>
#include<memory>
#include<array>
class Timer
{
public:
    Timer()
    {
        start_time=std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        auto end_time=std::chrono::high_resolution_clock::now();
        auto duration=std::chrono::duration_cast<std::chrono::microseconds>(end_time-start_time).count();
        std::cout<<"Time taken: "<<duration<<" us"<<std::endl;
    }
private:
    std::chrono::high_resolution_clock::time_point start_time;
    //starttime放在这里可以确保其对整个类都生效，放在timer的构造函数中在该函数结束后便会销毁
};

int main()
{
    volatile long long sum=0;
    {
        Timer timer;//在这个作用域内，timer对象被创建并开始计时，当这个作用域结束时，timer对象被销毁并输出时间
        for(int i=0;i<1000000;i++)
        {
            sum+=i;
        }
    }
    std::cout<<"Sum: "<<sum<<std::endl;

    struct vector2
    {
        float x,y;
    };
    std::cout<<"Benchmarking vector2 creation with shared_ptr..."<<std::endl;
    {
        std::array<std::shared_ptr<vector2>,10000> vecs;
        //创建一个固定长度为 1000000 的数组，数组里的每个元素都是一个空的 shared_ptr<vector2>，即每个元素都是一个指向 vector2 对象的智能指针，但目前还没有指向任何对象。
        Timer timer;
        for(int i=0;i<10000;i++)
        {
            vecs[i]=std::make_shared<vector2>(vector2{static_cast<float>(i),static_cast<float>(i)});
            //创建一个 vector2 对象，里面的 x 和 y 都等于当前的 i
            // 用 make_shared 把这个对象放到堆上
            // 返回一个指向它的 shared_ptr
            // 存进 vecs[i]
        }
    }
    std::cout<<"Benchmarking vector2 creation with shared_ptr and new..."<<std::endl;
    {
        std::array<std::shared_ptr<vector2>,10000> vecs;
        //创建一个固定长度为 1000000 的数组，数组里的每个元素都是一个空的 shared_ptr<vector2>，即每个元素都是一个指向 vector2 对象的智能指针，但目前还没有指向任何对象。
        Timer timer;
        for(int i=0;i<10000;i++)
        {
            vecs[i]=std::shared_ptr<vector2>(new vector2{static_cast<float>(i),static_cast<float>(i)});
            //创建一个 vector2 对象，里面的 x 和 y 都等于当前的 i
            // 用 new 把这个对象放到堆上
        }
    }
    std::cout<<"Benchmarking vector2 creation with unique_ptr..."<<std::endl;   
    {
        std::array<std::unique_ptr<vector2>,10000> vecs;
        //创建一个固定长度为 1000000 的数组，数组里的每个元素都是一个空的 unique_ptr<vector2>，即每个元素都是一个指向 vector2 对象的智能指针，但目前还没有指向任何对象。
        Timer timer;
        for(int i=0;i<10000;i++)
        {
            vecs[i]=std::make_unique<vector2>(vector2{static_cast<float>(i),static_cast<float>(i)});
            //创建一个 vector2 对象，里面的 x 和 y 都等于当前的 i
            // 用 make_unique 把这个对象放到堆上
            // 返回一个指向它的 unique_ptr
            // 存进 vecs[i]
        }
    }
    std::cin.get();
    return 0;
}