#include<iostream>
#include<chrono>
#include<thread>

class Timer
{
public:
    Timer()
    {
        start_time = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end_time = std::chrono::high_resolution_clock::now();
        duration = end_time - start_time;
        std::cout << "Execution time: " << duration.count()*1000 << " milliseconds" << std::endl;
    }
private:
    std::chrono::high_resolution_clock::time_point start_time,end_time;
    std::chrono::duration<double> duration;//这个会决定duration.count()的单位，默认是秒，如果我们想要毫秒，可以将其改为 std::chrono::duration<double, std::milli>，这样 duration.count() 就会返回以毫秒为单位的持续时间。
};   

void someFunction()
{
    Timer timer; // Create a Timer instance, which will automatically start timing when it is created and will print the execution time when it goes out of scope (at the end of the function).
    for(int i = 0; i < 100; ++i)
    {
        std::cout << "Processing..." << std::endl;
    }
}

void someOtherFunction()
{
    Timer timer; // Create a Timer instance, which will automatically start timing when it is created and will print the execution time when it goes out of scope (at the end of the function).
    for(int i = 0; i < 100; ++i)
    {
        std::cout << "Processing...\n";// we can use \n instead of std::endl to avoid flushing the output buffer after each line, which can improve performance when printing a large number of lines.
    }
}

int main()
{
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    auto start_time = std::chrono::high_resolution_clock::now();
    //我们使用 std::chrono::high_resolution_clock 来获取当前的高精度时间点，
    //并将其存储在 start_time 变量中。这将作为我们测量代码执行时间的起点。
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //我们使用 std::this_thread::sleep_for 来让当前线程休眠一段时间，这里我们让它休眠了 2 秒钟。这个函数接受一个 std::chrono::duration 对象作为参数，我们使用 std::chrono::seconds 来创建一个表示 2 秒的 duration 对象。
    auto end_time = std::chrono::high_resolution_clock::now();
    //我们再次获取当前的高精度时间点，并将其存储在 end_time 变量中。这将作为我们测量代码执行时间的终点。
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    //我们计算了 end_time 和 start_time 之间的时间差，并使用 std::chrono::duration_cast 将其转换为毫秒（milliseconds）。这个 duration 变量现在包含了代码执行的时间长度，以毫秒为单位。
    std::cout << "Execution time: " << duration.count() << " milliseconds" << std::endl;
    //最后，我们输出了代码执行的时间，使用 duration.count() 来获取持续时间的数值部分，并将其与字符串一起输出到控制台。
    someFunction();
    someOtherFunction();
    //我们调用了 someFunction() 函数，
    //这个函数内部创建了一个 Timer 实例，这个实例会在函数开始时自动记录开始时间，
    //并在函数结束时自动记录结束时间并计算持续时间。
    //这样，我们可以测量 someFunction() 函数的执行时间，而不需要手动管理计时器。
    std::cin.get();
    return 0;
}