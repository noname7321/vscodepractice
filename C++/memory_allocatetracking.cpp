#include<iostream>
#include<memory>

struct allocationmetrics
{
    size_t total_allocated = 0;
    size_t total_deallocated = 0;
    size_t current_usage() const {
        return total_allocated - total_deallocated;
    }
};

static allocationmetrics g_metrics;

static void printMetrics() {
    std::cout << "Total allocated: " << g_metrics.total_allocated << " bytes." << std::endl;
    std::cout << "Total deallocated: " << g_metrics.total_deallocated << " bytes." << std::endl;
    std::cout << "Current memory usage: " << g_metrics.current_usage() << " bytes." << std::endl;
}

void* operator new(size_t size) {
    g_metrics.total_allocated += size;
    //std::cout << "Allocating memory: " << size << " bytes." << std::endl;
    return malloc(size);
}

void operator delete(void* ptr,size_t size) noexcept {
    g_metrics.total_deallocated += size;
    //std::cout << "Deallocating memory: " << size << " bytes." << std::endl;
    free(ptr);
}

struct object
{
    int x,y,z;
};

int main()
{
    printMetrics();
    {
        std::string string1 ="Hello, World!";
        printMetrics();
    }
    {
        object *obj1 = new object{1,2,3};
        printMetrics();
        delete obj1;
        printMetrics();
    }
    {   
        std::unique_ptr<object> obj2 = std::make_unique<object>(object{4,5,6});
        printMetrics();
    }
    printMetrics();
}