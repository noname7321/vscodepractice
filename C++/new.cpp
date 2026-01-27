#include<iostream>
#include<string>

class entity {
private:
    std::string name;   
public:
    entity(){
        name = "Default Name";
    }
    entity(const std::string& newName) {
        name = newName;
    }
    const std::string& getName() const {
        //reference here means we are not making a copy,but returning the original
        return name;
    }
};

int main()
{
    int a=2;
    int *b = new int;//new keyword returns a pointer to the allocated memory
    *b = 5;//dereference the pointer to assign value
    int *c = new int(10);//directly initialize with value 10
    int *d = new int[3];//allocate array of 3 integers, uninitialized,
    //12 bytes (assuming int is 4 bytes)
    entity *e = new entity[30];//new object on heap, array of 30 entity objects
    //new returns a pointer to the first element of the array
    entity *f = new entity();//new not only allocates memory but also calls the constructor
    entity *g = (entity*)malloc(sizeof(entity));//malloc only allocates memory, does not call constructor
    delete b; // Clean up dynamically allocated memory
    delete c;
    delete[] d; // Clean up array memory
    delete[] e; // Clean up array of objects
    delete f; // Clean up single object
    free(g); // Free memory allocated by malloc
    std::cin.get();
}