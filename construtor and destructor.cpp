#include<stdio.h>
#include<iostream>

enum example:unsigned int {
    A = 1,
    B,
    C = 5,
    D
};
class entity
{
    private:
        
    public:
        int a,b;
        void print()
        {
            std::cout<<a<<","<<b<<std::endl;
        }
        entity()
        {
            a = A;
            b = B;
        }//constructor，default
        entity(int x,int y)
        {
            a = x;
            b = y;
        }//constructor，parameterized
        ~entity()
        {
            std::cout<<"destructor called"<<std::endl;
        }//destructor
};
int main() {
    entity e1;
    e1.print();
    std::cout <<e1.b << std::endl;
    entity e2( C, D);
    e2.print();
    return 0;
} 