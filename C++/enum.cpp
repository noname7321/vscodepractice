#include <iostream>

class LOG{
public:
    enum LOGLEVEL { Debug, Info, Warning, Error };

    void setloglevel(LOGLEVEL level) {
        loglevel = level;
    }

    void warn(const char * message) {
        if (loglevel <= Warning) {
            std::cout << "[WARNING]: " << message << std::endl;
        }
    }

    void error(const char * message) {
        if (loglevel <= Error) {
            std::cout << "[ERROR]: " << message << std::endl;
        }
    }

    void info(const char * message) {
        if (loglevel <= Info) {
            std::cout << "[INFO]: " << message << std::endl;
        }
    }
private:
    LOGLEVEL loglevel;
};


int main() {
    LOG log;
    log.setloglevel(LOG::Warning);//:: 是作用域解析运算符，用来引用类作用域内的类型或名字
    log.warn("This is a warning message.");
    log.error("This is an error message.");
    log.info("This is an info message.");
    std::cin.get();
    return 0;
}
//静态方法不受到类里面的成员变量的影响，可以直接通过类名调用，而不需要创建类的实例对象。静态方法不能访问类的非静态成员变量和非静态方法，因为它们不依赖于类的实例对象。