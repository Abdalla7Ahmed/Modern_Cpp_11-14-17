#include <iostream>
#include <string_view>

void PrettyPrint(std::string_view message, char ch)
{
    /*
    The function prints a character line followed by a message.
    Optimization: Replacing std::string with std::string_view avoids unnecessary memory allocation.
    */
    for (int x = 0; x < message.length(); ++x)
    {
        std::cout << ch;
    }
    std::cout << '\n';
    std::cout << message << '\n';
}

enum class Title
{
    MR,
    MRS,
    MS
};
std::string &CombineName(std::string &name, std::string_view last, Title s)
{
    /*
    The first parameter (name) is passed by reference and modified, so it cannot be replaced by std::string_view.
    The second parameter (last) is not modified, so it can be replaced with std::string_view to avoid unnecessary string construction.
    */
    switch (s)
    {
    case Title::MR:
        name.insert(0, "Mr.");
        break;
    case Title::MRS:
        name.insert(0, "Mrs.");
        break;
    case Title::MS:
        name.insert(0, "Ms.");
        break;
    }
    return name += last;
}

class Person
{
    /*
    std::string_view is not an owning type—it merely points to an existing character buffer.
    If the original buffer is destroyed (such as when pointing to a temporary std::string),the std::string_view will become dangling, leading to undefined behavior.
    */
    std::string m_Name;

public:
    Person(std::string name) : m_Name{std::move(name)}
    {
    }
    void Print() const
    {
        std::cout << m_Name << std::endl;
    }
};

Person CreatePerson(std::string_view name)
{
    std::string n{name};
    Person p{n};
    return p;
}
void WithClass()
{
    using namespace std::string_literals;
    // std::string n{} ;
    Person p{"Hello"};

    p.Print();
}

void BasicUsage()
{
    using namespace std::string_view_literals;
    std::string_view sv1 = "Hello world";

    std::string str1{"Hello"};
    std::string_view sv2 = str1;

    auto sv3 = "Using\0literals"sv;

    std::cout << "Size:" << sv3.length() << std::endl;
    std::cout << sv3 << std::endl;

    std::cout << "data()" << sv3.data() << std::endl;

    std::cout << sv3[0] << std::endl;
    std::cout << sv3.at(0) << std::endl;

    auto f = sv3.find("literals");
    if (f != std::string::npos)
    {
        std::cout << "Found at index:" << f << std::endl;
    }

    // sv3.remove_prefix(3) ;
    // std::cout << sv3 << std::endl ;

    // sv3.remove_suffix(2) ;
    // std::cout << sv3 << std::endl ;

    auto sv4 = sv1.substr(0, 5);

    std::cout << sv4 << std::endl;
}

int main()
{
    // PrettyPrint("Hello world", '#') ;
    WithClass();
}

/*
Concept of std::string_view:

    Introduced in C++17 as a special type of string class.
    Allows working with strings without allocating memory.
    Acts as a reference to a sequence of constant characters.
    Cannot modify the underlying character sequence.
    Fast and cheap to copy since it only stores a pointer and a length.
    Not a replacement for std::string and must be used carefully to avoid bugs.

Properties of std::string_view:

    Two main members:
        Pointer to the character sequence.
        Length of the sequence.
    Can point to any kind of string (e.g., std::string, C-strings, Qt's QString, COM strings).
    May not be null-terminated, so it should not be used with C-string functions.
    The data() function can return a null pointer if the underlying sequence does not exist.

Methods of std::string_view:

    size() / length(): Get the length of the sequence.
    data(): Get a pointer to the character sequence.
    [] and at(): Access individual characters (subscript operator does not perform bounds checking, at() does).
    find(): Locate a substring.
    remove_prefix(n): Move the view forward by n characters (without modifying the string).
    remove_suffix(n): Shrink the view from the end by n characters.
    substr(pos, count): Extract a substring.
Best Practices and Cautions:

    Avoid using data() to print a std::string_view since it may contain embedded null characters.
    std::string_view is ideal for passing read-only strings to functions, reducing unnecessary allocations.
    Not suitable for modifying strings, as it does not own the data.
*/