#include <iostream>
#include <vector>
#include <mutex>

template <typename T>
class Test
{

public:
    Test(const T &a) {}
    ~Test()
    {
    }
};

// Explicit Deduction Guides
Test(const char *) -> Test<std::string>;
Test(int) -> Test<long>;

int main(int argc, char const *argv[])
{
    // required before c++17 to specify the type
    std::pair<int, int> P1{1, 2};
    // in c++17 we don't need to specify the type
    std::pair P2{1, 2};

    std::vector V1{1, 2, 3, 4, 5};
    std::mutex m;
    std::lock_guard lock{m};

    Test T1{10};   // deduced to int
    Test T2{10.5}; // deduced to double
    Test T3 = T1;
    auto T4 = new Test{10};
    Test T5{"Hello"}; // deduced to char[n];
    // we can write the Explicit Deduction Guides to make it deduced to std::string not char[]
    return 0;
}

/*
Class Template Argument Deduction (CTAD) is a feature introduced in C++17 that allows the compiler to deduce
template arguments for class templates without requiring explicit specification by the programmer.

Before C++17, when instantiating a class template, we had to explicitly specify template arguments.
With CTAD, the compiler can infer them automatically based on constructor arguments.

When you instantiate a class template without specifying template arguments,
the compiler looks at the constructor parameters and deduces the appropriate template arguments.

CTAD types
1-Default Deduction (Implicit CTAD) compiler generated
This is the default behavior where the compiler deduces template arguments automatically from constructor parameters.

2-User-Defined CTAD (Explicit Deduction Guides)
Sometimes, the compiler cannot deduce the correct type, or we want custom deduction behavior.
In such cases, user-defined deduction guides help specify how types should be deduced.
*/