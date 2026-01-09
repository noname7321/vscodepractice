#include<iostream>
#include<string>

int main()
{
    const char *name = "Alice";
    char greeting[] = "Hello, ";
    const char *name1 = "Bob";// This line is problematic in C++26, as string literals are immutable
    //store in the read-only memory segment.
    //name1[0] = 'C'; // This line will cause a compilation error in C++26
    greeting[0] = 'h'; // Modifying an array initialized with a string literal is allowed
    std::cout << greeting << name << std::endl;
    const wchar_t *wideName = L"Alice";// Wide string literal
    const char16_t *utf16Name = u"Alice";// UTF-16 string literal,2bytes per character
    const char32_t *utf32Name = U"Alice";// UTF-32 string literal,4bytes per character
    std::wcout << L"Wide Name: " << wideName << std::endl;

    using namespace std::string_literals;
    std::string str1 = "Hello, "s + "World!"s; //
    std::string str1b = std::string("Hello, ") + "World!"; //
    std::u32string str2 = U"Hello, "s + U"World!"s; //
    std::u16string str3 = u"Hello, "s + u"World!"s; //
    std::wstring str4 = L"Hello, "s + L"World!"s; //

}