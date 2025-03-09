
#include <iostream>
#include <cstring>
/*
Explicit specializations are used when you want to provide a custom implementation
of a template for a specific type or set of types.
It allows you to override the default behavior of a template for specific types.
Unlike explicit instantiations, explicit specializations require you to provide
a separate definition for each specialized version of the template.
Explicit specializations are useful when you want to handle specific cases differently
from the generic template implementation.
*/

// Template declaration
template <typename T>
void Print(T value);

// Template definition
template <typename T>
void Print(T value)
{
    std::cout << value << std::endl;
}

// Explicit specialization for int
template <>
void Print<int>(int value)
{
    std::cout << "Specialized: " << value << std::endl;
}

template <typename T>
T Max(T a, T b)
{
    std::cout << typeid(T).name() << std::endl;
    return a > b ? a : b;
}

template <>
const char *Max<const char *>(const char *a, const char *b)
{
    std::cout << __PRETTY_FUNCTION__ << std::endl; // T Max(T, T) [with T = const char*]
    return strcmp(a, b) > 0 ? a : b;
}
int main()
{
    // The specialized version Print<int> is used for integers
    Print(42);              // Output: Specialized: 42
    Print("Hello, World!"); // Output: Hello, World!

    const char *B = {"B"};
    const char *A = {"A"};
    auto m = Max(A, B);
    std::cout << "the max is " << m << std::endl; // the max is A
    // because the address of A is grater than the address of B
    // we must write an Explicit specialization for char
    return 0;
}