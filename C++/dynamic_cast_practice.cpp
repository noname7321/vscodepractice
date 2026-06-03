#include<iostream>
#include<string>

class entity
{
public:
    virtual ~entity() = default;
};

class player:public entity
{
};

class enemy:public entity
{
};

int main()
{
    player* p=new player();
    entity *actualplayer=p;//向上转型，隐式转换，安全的
    player* p2=dynamic_cast<player*>(actualplayer);//向下转型，安全的
    if(p2)//dynamic_cast<Player*>(actualplayer)返回的指针不为nullptr，说明转换成功
    {
        std::cout<<"dynamic_cast success."<<std::endl;
    }
    else
    {
        std::cout<<"dynamic_cast failed."<<std::endl;
    }

    enemy* actualenemy=dynamic_cast<enemy*>(actualplayer);//向下转型，失败的
    if(actualenemy)
    {
        std::cout<<"dynamic_cast success."<<std::endl;
    }
    else
    {
        std::cout<<"dynamic_cast failed."<<std::endl;
    }   
    //dynamic_cast会记录RTTI（Run-Time Type Information）信息，在运行时检查类型是否匹配，如果匹配则返回指向该类型的指针，否则返回nullptr。
    std::cin.get();
    return 0;
}