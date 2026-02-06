// instrument.cpp
#include <iostream>
#include <string>

class Instrument {
public:
    virtual std::string make_sound() const { return "Instrument sound"; }
    virtual ~Instrument() = default; // 虚析构函数，确保派生类对象正确销毁
};

class Erhu : public Instrument {
public:
    std::string make_sound() const override { return "Erhu sound"; }
};

class Guitar : public Instrument {
public:
    std::string make_sound() const override { return "Guitar sound"; }
};

class Piano : public Instrument {
public:
    std::string make_sound() const override { return "Piano sound"; }
};

void play_instrument(const Instrument& instr) {
    std::cout << instr.make_sound() << std::endl;
}

int main() {
    Erhu e;
    Guitar g;
    Piano p;

    play_instrument(e); // Erhu sound
    play_instrument(g); // Guitar sound
    play_instrument(p); // Piano sound

    // 也可以用基类指针演示多态
    Instrument* ptr = &g;
    std::cout << ptr->make_sound() << std::endl; // 调用 Guitar::make_sound
    return 0;
}