#include<iostream>
#include<string>

class pirntable {
public:
    virtual std::string GetName() = 0; // 纯虚函数
};

class entity : public pirntable { 
public:
    virtual std::string GetName() override
    {
        return "entity";
    }
};
class player : public entity {
public:
    player(const std::string& playerName) : name(playerName) {}
    std::string GetName()
    {
        return name;
    }
private:
    std::string name;
};


void print(pirntable* obj)
{
    std::cout << obj->GetName() << std::endl;
}

int main()
{
    entity* e = new entity();
    std::cout << "Entity Name: " << e->GetName() << std::endl;

    player* p = new player("Hero");
    std::cout << "Player Name: " << p->GetName() << std::endl;
    print(e);
    print(p);
    delete e;
    delete p;
    return 0;
}