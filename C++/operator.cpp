#include<iostream>
#include<string>
//operator overloading example
class Vector2D {
public:
    float x,y;
    Vector2D(float x=0, float y=0) : x(x), y(y) {}//initializer list
    // Overload + operator
    Vector2D operator+(const Vector2D& other) const {
        // const means this method does not modify the value of x and y
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
    Vector2D operator*(float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    Vector2D operator/(float scalar) const {
        return Vector2D(x / scalar, y / scalar);
    }
    Vector2D Add(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D add(const Vector2D& other) const {
        return *this + other; // Using overloaded + operator
    }
};
int main() {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    Vector2D v3 = v1 + v2; // Using overloaded + operator
    Vector2D v4 = v1.Add(v2); // Using Add method
    Vector2D v5 = v1.add(v2); // Using add method
    std::cout << "v3: (" << v3.x << ", " << v3.y << ")" << std::endl;
    std::cout << "v4: (" << v4.x << ", " << v4.y << ")" << std::endl;
    std::cout << "v5: (" << v5.x << ", " << v5.y << ")" << std::endl;
    return 0;
}