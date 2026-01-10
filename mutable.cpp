#include<iostream>
class MutableExample {
private:
    mutable int accessCount; // mutable member variable
    int data;
public:
    MutableExample(int val) : data(val), accessCount(0) {}
    int getData() const {
        accessCount++; // Modifying mutable member variable in const method
        return data;
    }
    int getAccessCount() const {
        return accessCount;
    }
};