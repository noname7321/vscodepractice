#include<iostream>
#include<variant>
#include<future>
#include<thread>
std::string readfileasstring(const std::string& filepath)
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate time-consuming file reading
    return "File content goes here.";
}
