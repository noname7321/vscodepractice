#include<iostream>
#include<string>

class Animal {
public:
    virtual void speak() {
        std::cout << "The animal makes a sound." << std::endl;
    }
};  
class Dog : public Animal {
public:
    void speak() override {
        std::cout << "The dog barks." << std::endl;
    }
};
class Cat : public Animal {
public:
    void speak() override {
        std::cout << "The cat meows." << std::endl;
    }
};
int main() {
    Animal* myAnimal= new Animal();

    Dog myDog;
    Cat myCat;

    myAnimal->speak();  // Outputs: The animal makes a sound.
     
    myAnimal = &myDog;
    myAnimal->speak();  // Outputs: The dog barks.

    Dog yourDog;
    yourDog.speak();    // Outputs: The dog barks.

    myAnimal = &myCat;
    myAnimal->speak();  // Outputs: The cat meows.

    return 0;
}
//虚函数允许在派生类中重写基类的方法，从而实现动态绑定。
//这使得程序在运行时能够根据对象的实际类型调用相应的方法，而不是在编译时决定调用哪个方法。
//使用虚函数可以实现多态性，使得代码更加灵活和可扩展。