#include<iostream>
#include<string>
#include<vector>
struct Verctor
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Verctor& vector)
{
    stream << "x: " << vector.x << ", y: " << vector.y << ", z: " << vector.z;
    return stream;
}

int main()
{
    Verctor* vector = new Verctor{1.0f, 2.0f, 3.0f}; 
    std::vector<Verctor> vectors1;
    vectors1.push_back(*vector); // 这里我们把 vector 指针所指向的 Verctor 对象的值复制到 vectors 向量中。push_back 函数会调用 Verctor 的拷贝构造函数来创建一个新的 Verctor 对象，并将 vector 指针所指向的对象的值复制到这个新的对象中。这样，vectors 向量中就有了一个独立的 Verctor 对象，它与 vector 指针所指向的对象是两个不同的对象，拥有各自独立的内存空间。
    std::cout <<"vectors1: " <<vectors1[0] << std::endl; // 输出 vectors 向量中第一个元素的值，即 vector 指针所指向的 Verctor 对象的值。
    delete vector; // 这里我们释放了 vector 指针所指向的内存空间，避免了内存泄漏。虽然 vectors 向量中有一个独立的 Verctor 对象，但它与 vector 指针所指向的对象是两个不同的对象，所以我们可以安全地删除 vector 指针所指向的对象，而不会影响 vectors 向量中的对象。
    std::vector<Verctor> vectors2;
    vectors2.push_back({4.0f, 5.0f, 6.0f});//这里其实只塞入了一个Vector对象
    vectors2.push_back({7.0f, 8.0f, 9.0f});
    for(int i=0; i<vectors2.size(); i++)
    {
        std::cout <<"vectors2: " << vectors2[i] << std::endl;
    }
    std::cout<< "------------------" << std::endl;
    for(const Verctor &vector : vectors2)//Vector vector:vectors2 是一个范围for循环（range-based for loop），它的作用是遍历 vectors2 向量中的每个元素，并将当前元素的引用赋值给 vector 变量。这里的 const Verctor &vector 是一个常量引用，表示我们在循环中不会修改 vector 变量所引用的对象。通过使用范围for循环，我们可以更简洁地访问 vectors2 向量中的每个元素，而不需要使用索引来访问它们。
    {
        std::cout <<"vectors2: " << vector << std::endl;
    }
    vectors2.erase(vectors2.begin() + 1); // 这里我们调用 vectors2 向量的 erase() 函数来删除向量中索引为1的元素。erase() 函数会销毁被删除的元素，并将向量中后续元素向前移动以填补被删除元素的位置。这样，vectors2 向量中的元素就会重新排列，原来索引为2的元素会变成索引为1，原来索引为3的元素会变成索引为2，以此类推。最终，vectors2 向量中就只剩下了两个元素，即索引为0和索引为1的元素。
    std::cout <<"vectors2 size: " << vectors2.size() << std::endl; // 输出 vectors2 向量的大小，即删除元素后的大小，应该为2。
    for(const Verctor &vector : vectors2)
    {
        std::cout <<"vectors2: " << vector << std::endl;
    }
    vectors2.clear(); // 这里我们调用 vectors2 向量的 clear() 函数来清空向量中的所有元素。clear() 函数会销毁向量中的所有元素，并将向量的大小重置为0，但它不会释放向量占用的内存空间。这样，我们可以在需要时重新使用 vectors2 向量，而不需要重新分配内存。
    std::cout <<"vectors2 size: " << vectors2.size() << std::endl; // 输出 vectors2 向量的大小，即清空后的大小，应该为0。
    std::vector<float> floats;
    floats.push_back(1.0f); // 这里我们把一个 float 值 1.0f 添加到 floats 向量中。push_back 函数会将这个 float 值复制到 floats 向量中，创建一个新的 float 对象，并将值 1.0f 复制到这个新的对象中。这样，floats 向量中就有了一个独立的 float 对象，它与我们添加的 float 值是两个不同的对象，拥有各自独立的内存空间。
    std::cout <<"floats: " << floats[0] << std::endl; // 输出 floats 向量中第一个元素的值，即我们添加的 float 值 1.0f。
    std::cin.get();
}