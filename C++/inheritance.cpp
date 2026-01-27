#include<iostream>

class entity {
    public:
        float x, y;
        void move(float dx, float dy) {
            x += dx;
            y += dy;
        }
};

class player : public entity {
    public:
        const char *name;
        void printname() {
            std::cout << "Player Name: " << name << std::endl;
        }
};

int main(){
    player p;
    p.name = "Hero";
    p.x = 0.0f;
    p.y = 0.0f;

    p.printname();
    std::cout << "Initial Position: (" << p.x << ", " << p.y << ")" << std::endl;

    p.move(5.0f, 3.0f);
    std::cout << "New Position: (" << p.x << ", " << p.y << ")" << std::endl;

    return 0;
}

// const char *name = "Hello";//创建一个hello字符串常量，并将其地址赋值给指针name，name指向的内容不可修改（const）
// name = "World";  // ✓ 完全合法：改变指针指向char *name = "Hello";
// name = "Test"; 