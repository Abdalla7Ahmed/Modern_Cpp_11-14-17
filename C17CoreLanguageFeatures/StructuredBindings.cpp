#include <iostream>
#include <map>
struct Person
{
    std::string m_name;
    int m_age;
    Person() = default;
    Person(const std::string &name, int age) : m_name{name}, m_age{age} {}
};

struct info
{
    int arr1[10];
    char name[20];
};

class test
{
public:
    std::string m_name;
    int m_age;
    test() = default;
    test(const std::string &name, int age) : m_name{name}, m_age{age} {}
};
int main(int argc, char const *argv[])
{
    Person P1{"Abdallah", 24};
    // Structured binding creates new variables name and age that are copies of P1.m_name and P1.m_age.
    // Any modifications to name or age will not affect P1.
    auto [name, age] = P1;
    std::cout << "Name: " << name << " Age: " << age << std::endl;
    // This binds name2 and age2 directly to P1.m_name and P1.m_age.
    // Changes to name2 and age2 will reflect in P1.
    auto &[name2, age2] = P1;
    name2 = "Ali";
    age2 = 20;
    std::cout << "Name: " << P1.m_name << " Age: " << P1.m_age << std::endl;
    // we can use the const
    const auto &[name3, age3] = P1;

    // the same with class but the members must be public
    test t1{"Omar", 20};
    auto &[cname, cage] = t1;
    cname = "ali";
    std::cout << "Name: " << t1.m_name << " Age: " << cage << std::endl;
    // with pair
    std::pair<int, int> pair1{3, 10};
    auto [key, value] = pair1;
    std::cout << key << " " << value << std::endl;
    // with map
    std::map<int, std::string> languages{{1, "C++"}, {2, "Java"}, {3, "Python"}};
    for (const auto &language : languages)
    {
        std::cout << "# " << language.first << "-> " << language.second << std::endl;
    }

    for (const auto &[key, value] : languages)
    {
        std::cout << "# " << key << "-> " << value << std::endl;
    }

    // with array
    int arr[3] = {1, 2, 3};
    // The number of variables must match the number of elements in the array.
    auto [a, b, c] = arr;
    std::cout << a << " " << b << " " << c << std::endl;

    //
    int arr2[3] = {5, 6, 7};
    // Arrays normally decay to pointers when assigned with auto.
    // p is inferred as int* (pointer to an integer).
    auto p = arr2;
    std::cout << "Type of p is " << typeid(p).name() << std::endl; // Pi --> int pointer

    info i1;
    // Arrays inside structs do not decay to pointers when using structured bindings.
    // S1 remains an array of 10 integers, and S2 remains an array of 20 characters.
    auto [S1, S2] = i1;
    std::cout << "Type of S1 is " << typeid(S1).name() << std::endl; // A10_i --> array of 10 int not pointer
    std::cout << "Type of S2 is " << typeid(S2).name() << std::endl; // A20_c   --> array of 20 char

    return 0;
}

/*
Structured bindings, introduced in C++17, provide a convenient way to unpack tuples, pairs, structs, and arrays
into individual variables. This feature enhances readability and avoids verbose syntax when dealing with structured data.
*/
