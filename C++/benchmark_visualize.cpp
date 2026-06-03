#include<iostream>
#include<string>
#include<chrono>
#include<thread>

class Timer {
public:
    Timer() : start_time(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cout << "Elapsed time: " << duration << " ms" << std::endl;
    }
private:
    std::chrono::high_resolution_clock::time_point start_time;
};

void function1()
{
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // Simulate some work
    }
}

void function2()
{
    for (int i = 0; i < 100; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // Simulate some work
    }
}

int main() {
    {
        std::cout << "Running function1..." << std::endl;
        Timer timer; // Start timer for function1
        function1();
    }

    {
        std::cout << "Running function2..." << std::endl;
        Timer timer; // Start timer for function2
        function2();
    }

    return 0;
}