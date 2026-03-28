#include<iostream>
#include<string>
#include<vector>
struct Vector
{
    float x, y, z;
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector(const Vector& other) : x(other.x), y(other.y), z(other.z) {std::cout << "Vector copied!" << std::endl;} // 拷贝构造函数
};

int main()
{
    std::vector<Vector> vectors;
    vectors.reserve(3); // 这里我们调用 vectors 向量的 reserve() 函数来预先分配足够的内存空间，以容纳至少3个 Vector 对象。reserve() 函数会增加向量的容量，但不会改变向量的大小。这样，我们可以避免在添加元素时频繁地重新分配内存，从而提高性能。
    vectors.push_back({1.0f, 2.0f, 3.0f}); // 这里调用 vectors 向量的 push_back() 函数来添加一个新的 Vector 对象到向量中。push_back() 函数会将提供的参数复制到向量中，创建一个新的 Vector 对象，并将值 {1.0f, 2.0f, 3.0f} 复制到这个新的对象中。
    vectors.push_back({4.0f, 5.0f, 6.0f});//和下面的 emplace_back 不同，push_back 先创建一个临时对象，再把这个临时对象复制到向量中，而 emplace_back 则直接在向量中构造一个新的对象，避免了不必要的复制操作，提高性能。
    vectors.push_back({7.0f, 8.0f, 9.0f});
    vectors.emplace_back(10.0f, 11.0f, 12.0f); // 这里我们调用 vectors 向量的 emplace_back() 函数来直接在向量中构造一个新的 Vector 对象，而不是先创建一个临时对象再复制到向量中。emplace_back() 函数会将提供的参数直接传递给 Vector 的构造函数，在向量中原地构造一个新的 Vector 对象。这样，我们可以避免不必要的复制操作，提高性能。
    std::cout <<"vectors: " << vectors[0].x << ", " << vectors[0].y << ", " << vectors[0].z << std::endl; // 输出 vectors 向量中第一个元素的值，即我们添加的 Vector 对象的值 {1.0f, 2.0f, 3.0f}。
    std::cin.get();
}
