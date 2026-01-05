#include <iostream>
#include <string>
#include <memory>
#include <vector>

// ==================== 1. 命名空间和作用域解析运算符 :: ====================
//命名空间用于将一组相关的标识符（如变量、函数、类等）组织在一起，以避免名称冲突。
namespace School {//namespace是用来定义命名空间的关键字，School是命名空间的名称
    // 全局变量
    int totalStudents = 0;
    
    // 基类
    class Person {
    public:
        static int personCount;  // 静态成员变量，属于类而不是某个对象
        std::string name;
        int age;
        
        Person(std::string n, int a) : name(n), age(a) {// 构造函数
            personCount++;
            totalStudents++;
        }
        
        virtual ~Person() {// 虚析构函数
            personCount--;
            totalStudents--;
        }
        
        // 虚函数 - 用于多态
        virtual void introduce() {
            std::cout << "我叫" << name << "，今年" << age << "岁" << std::endl;
        }
        
        // 静态方法
        static void showPersonCount() {
            std::cout << "当前总人数: " << personCount << std::endl;
        }
    };
    
    // 在命名空间中定义静态成员
    int Person::personCount = 0;// ::在这里的作用是指定personCount属于Person类的静态成员变量。
    
    // 子类
    class Student : public Person {
    public:
        std::string studentId;//std是标准库命名空间， ：：在这里的作用是指定studentId属于Student类的成员变量，string是std命名空间下的类型。
        double gpa;
        
        Student(std::string n, int a, std::string id, double g)  // 构造函数的参数
            : Person(n, a),        // 1. 调用基类Person的构造函数
            studentId(id),       // 2. 初始化成员变量studentId
            gpa(g)               // 3. 初始化成员变量gpa
        {
            // 构造函数体（这里为空）
        }
        
        // 重写父类方法
        void introduce() override {// override关键字表示这是对基类虚函数的重写
            std::cout << "我是学生 " << name << "，学号: " << studentId 
                      << "，GPA: " << gpa << std::endl;
        }
        
        void study() {
            std::cout << name << "正在学习..." << std::endl;
        }
    };
    
    class Teacher : public Person {
    public:
        std::string department;
        
        Teacher(std::string n, int a, std::string dept) 
            : Person(n, a), department(dept) {}
        
        // 重写父类方法
        void introduce() override {
            std::cout << "我是教师 " << name << "，所在院系: " << department << std::endl;
        }
        
        void teach() {
            std::cout << name << "正在教学..." << std::endl;
        }
    };
}

// 全局变量（与命名空间中的变量同名）
int totalStudents = 999;

// ==================== 2. 演示各种运算符的用法 ====================
void demonstrateOperators() {
    using namespace School;
    
    std::cout << "\n========== 演示各种运算符 ==========\n" << std::endl;
    
    // ==================== 2.1 作用域解析运算符 :: ====================
    std::cout << "1. 作用域解析运算符 :: 的用法:\n" << std::endl;
    
    // 访问命名空间成员
    std::cout << "a) 访问命名空间成员:" << std::endl;
    std::cout << "School::totalStudents = " << School::totalStudents << std::endl;
    
    // 访问全局变量（解决名称冲突）
    std::cout << "\nb) 访问全局变量（解决名称冲突）:" << std::endl;
    std::cout << "全局变量 totalStudents = " << ::totalStudents << std::endl;
    std::cout << "School::totalStudents = " << School::totalStudents << std::endl;
    
    // 访问静态成员
    std::cout << "\nc) 访问静态成员:" << std::endl;
    Person::showPersonCount();  // 使用::调用静态方法
    std::cout << "Person::personCount = " << Person::personCount << std::endl;
    
    // ==================== 2.2 点运算符 . ====================
    std::cout << "\n\n2. 点运算符 . 的用法:\n" << std::endl;
    
    // 创建对象（栈上）
    std::cout << "a) 对象访问成员:" << std::endl;
    Person person1("张三", 25);
    person1.introduce();  // 对象使用点运算符
    std::cout << "姓名: " << person1.name << ", 年龄: " << person1.age << std::endl;
    
    Student student1("李四", 20, "2023001", 3.8);
    student1.introduce();  // 子类对象使用点运算符
    student1.study();      // 调用子类特有方法
    
    // 创建对象数组
    std::cout << "\nb) 对象数组访问:" << std::endl;
    Person people[2] = {Person("王五", 30), Person("赵六", 35)};
    for (int i = 0; i < 2; i++) {
        people[i].introduce();  // 数组元素是对象，用点运算符
    }
    
    // ==================== 2.3 箭头运算符 -> ====================
    std::cout << "\n\n3. 箭头运算符 -> 的用法:\n" << std::endl;
    
    // 创建指针（堆上）
    std::cout << "a) 普通指针访问成员:" << std::endl;
    Person* personPtr = new Person("钱七", 28);
    personPtr->introduce();  // 指针使用箭头运算符
    std::cout << "姓名: " << personPtr->name << ", 年龄: " << personPtr->age << std::endl;
    
    Student* studentPtr = new Student("孙八", 22, "2023002", 3.9);
    studentPtr->introduce();  // 子类指针使用箭头运算符
    studentPtr->study();      // 调用子类特有方法
    
    // 指针数组
    std::cout << "\nb) 指针数组访问:" << std::endl;
    Person* personArray[2] = {new Person("周九", 40), new Teacher("吴十", 45, "计算机系")};
    for (int i = 0; i < 2; i++) {
        personArray[i]->introduce();  // 数组元素是指针，用箭头运算符
    }
    
    // ==================== 2.4 多态演示 ====================
    std::cout << "\n\n4. 多态演示（指针使用 ->）:\n" << std::endl;
    
    // 基类指针指向不同子类对象
    Person* polyPtr;
    
    Student student2("郑十一", 21, "2023003", 3.7);
    Teacher teacher1("王十二", 50, "数学系");
    
    polyPtr = &student2;  // 指向Student对象
    polyPtr->introduce(); // 多态：调用Student::introduce()
    
    polyPtr = &teacher1;  // 指向Teacher对象
    polyPtr->introduce(); // 多态：调用Teacher::introduce()
    
    // ==================== 2.5 引用使用点运算符 ====================
    std::cout << "\n\n5. 引用使用点运算符 . :\n" << std::endl;
    
    Person& personRef = person1;  // 引用
    personRef.introduce();        // 引用使用点运算符
    
    Student& studentRef = student2;
    studentRef.study();           // 引用使用点运算符
    
    // ==================== 2.6 智能指针使用 -> ====================
    std::cout << "\n\n6. 智能指针使用 -> :\n" << std::endl;
    
    std::unique_ptr<Person> smartPtr1 = std::make_unique<Student>("智能学生", 23, "2023004", 4.0);
    smartPtr1->introduce();  // 智能指针使用箭头运算符
    
    // ==================== 2.7 综合示例 ====================
    std::cout << "\n\n7. 综合示例:\n" << std::endl;
    
    std::vector<Person*> peopleVector;
    peopleVector.push_back(new Student("向量学生1", 19, "2023005", 3.5));
    peopleVector.push_back(new Teacher("向量教师1", 38, "物理系"));
    peopleVector.push_back(new Student("向量学生2", 20, "2023006", 3.6));
    
    for (Person* p : peopleVector) {
        p->introduce();  // 多态调用，使用箭头运算符
    }
    
    // 访问静态成员的不同方式
    std::cout << "\n静态成员访问方式:" << std::endl;
    std::cout << "Person::personCount = " << Person::personCount << std::endl;
    std::cout << "person1.personCount = " << person1.personCount << std::endl;  // 通过对象访问
    std::cout << "personPtr->personCount = " << personPtr->personCount << std::endl;  // 通过指针访问
    
    // ==================== 2.8 清理内存 ====================
    std::cout << "\n\n8. 清理内存:" << std::endl;
    
    delete personPtr;
    delete studentPtr;
    
    for (int i = 0; i < 2; i++) {
        delete personArray[i];
    }
    
    for (Person* p : peopleVector) {
        delete p;
    }
    
    std::cout << "清理完成！" << std::endl;
}

// ==================== 3. 类外定义成员函数（使用 ::） ====================
class Example {
private:
    int value;
    
public:
    Example(int v);
    void showValue();
    static void staticMethod();
};

// 使用::在类外定义成员函数
Example::Example(int v) : value(v) {}

void Example::showValue() {
    std::cout << "值: " << this->value << std::endl;  // 使用->访问成员
}

void Example::staticMethod() {
    std::cout << "这是静态方法" << std::endl;
}

// ==================== 4. 主函数 ====================
int main() {
    std::cout << "======= C++ 运算符 :: -> . 综合演示程序 =======\n" << std::endl;
    
    // 演示各种运算符
    demonstrateOperators();
    
    std::cout << "\n\n======= 类外定义成员函数演示 =======\n" << std::endl;
    
    // 演示类外定义成员函数
    Example ex1(100);
    ex1.showValue();        // 对象使用点运算符
    Example::staticMethod(); // 使用::调用静态方法
    
    Example* ex2 = new Example(200);
    ex2->showValue();       // 指针使用箭头运算符
    delete ex2;
    
    std::cout << "\n\n======= 最终统计信息 =======\n" << std::endl;
    
    // 访问不同作用域的同名变量
    std::cout << "全局 ::totalStudents = " << ::totalStudents << std::endl;
    std::cout << "School::totalStudents = " << School::totalStudents << std::endl;
    School::Person::showPersonCount();
    
    std::cout << "\n程序结束！" << std::endl;
    return 0;
}

// 1. :: 运算符的用法：
// 访问命名空间成员：School::Person

// 访问静态成员：Person::personCount

// 访问全局变量：::totalStudents

// 在类外定义成员函数：Example::Example()

// 2. -> 运算符的用法：
// 指针访问成员：personPtr->introduce()

// 智能指针访问成员：smartPtr1->introduce()

// 多态调用：基类指针调用子类方法

// 3. . 运算符的用法：
// 对象访问成员：person1.introduce()

// 引用访问成员：personRef.introduce()

// 数组元素访问：people[i].introduce()