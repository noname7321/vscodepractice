#include<iostream>
#include<string>

class entity { 
public:
    virtual std::string GetName()
    {
        return "entity";
    }
};
class player : public entity {
public:
    player(const std::string& playerName) : name(playerName) {}
    std::string GetName() override
    {
        return name;
    }
private:
    std::string name;
};