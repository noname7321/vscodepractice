#include <tuple>
#include <string>
#include <utility>

std::tuple<int, std::string, double> getUserInfo() {
    return {42, "Alice", 3.14};
}

std::pair<bool, std::string> login(const std::string& user) {
    if (user == "admin") return {true, "Welcome!"};
    return {false, "Access denied"};
}

struct ParseResult {
    int    lineNumber;
    double value;
    bool   isValid;
};

ParseResult parseLine(const std::string& line) {
    return {10, 3.14, true};
}

bool divide(int a, int b, int& quotient, int& remainder) {
    if (b == 0) return false;
    quotient  = a / b;
    remainder = a % b;
    return true;
}

int main() {
    auto [id, name, score] = getUserInfo(); // C++17 结构化绑定
    // 或者：
    auto info = getUserInfo();
    int id2      = std::get<0>(info);
    std::string name2 = std::get<1>(info);

    auto [success, msg] = login("admin");

    auto [line, value, isValid] = parseLine("10 3.14"); // C++17 结构化绑定
    
    int q, r;
    if (divide(10, 3, q, r)) {
        // q = 3, r = 1
    }
}