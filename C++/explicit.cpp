#include<iostream>
#include<string>
class Entity {
private:
    std::string m_name;
    int m_age;
public:
    Entity(const std::string& name, int age) : m_name(name), m_age(age) {}
    void printInfo() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    }  
};
class entity {
private:
    std::string m_name;
    int m_age;
public:
    explicit entity(const std::string& name) : m_name(name), m_age(-1) {}
    explicit entity(int age) : m_name("Unknown"), m_age(age) {}
    //forbid implicit conversion from string or int to entity, 
    //must use explicit constructor call
    void printInfo() const {
        std::cout << "Name: " << m_name << ", Age: " << m_age << std::endl;
    }  
};
int main() {
    Entity e("Alice", 30);
    e.printInfo(); // Calling const method
    entity b("Bob");//explicit calling constructor
    b.printInfo();
    entity c(25);//explicit calling constructor
    c.printInfo();  
    entity a("Charlie");//explicit calling constructor
    a.printInfo();
    entity f(40);//explicit calling constructor
    f.printInfo();
    entity d("David"), g(35);//multiple objects
    d.printInfo();
    g.printInfo();
    return 0;
}