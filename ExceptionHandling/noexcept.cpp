/*
What is noexcept in C++?

• Applied to functions (both in declaration & definition)
• Indicates the function does not throw exceptions
• Compiler can optimize the function code
    • no need to generate stack unwinding code
• An exception from such function terminates the program
    • stack may or may not be unwinded
• Not all functions should use noexcept specifier
    • especially functions calling other functions (in library)
    • such functions will be exception-neutral

void func() noexcept;   // Guarantees that func() will not throw an exception
void func2() noexcept(false); // Explicitly allows exceptions (same as omitting noexcept)

Why Use noexcept?

    Performance Optimization:
        Functions marked noexcept enable better compiler optimizations like inlining.
        Move constructors (T(T&&) noexcept) allow efficient std::vector reallocation.

    Exception Safety:
        Helps avoid stack unwinding failures (e.g., in destructors).
        Used in destructors (~Class() noexcept) to prevent std::terminate() on exception propagation.

    Clear Intent:
        Makes it explicit that a function won't throw, improving readability.*/

#include <iostream>
#include <vector>

class Test
{
public:
    Test() {}
    // std::vector only uses move constructors if they're noexcept. Otherwise, it falls back to expensive copy operations.
    Test(Test &&) noexcept { std::cout << "Move constructor called\n"; }
    // Destructors should not throw exceptions, so marking them noexcept is recommended.
    ~Test() noexcept { std::cout << "Destructor called\n"; }
};
void safeFunc() noexcept {}
void riskyFunc() { throw 42; }
int main()
{
    std::vector<Test> v;
    v.reserve(2);        // Reserve space to prevent reallocation
    v.push_back(Test()); // Uses move constructor
    // /Use noexcept(expression) to check whether an expression is exception-safe.
    std::cout << std::boolalpha;
    std::cout << "safeFunc is noexcept: " << noexcept(safeFunc()) << "\n";   // true
    std::cout << "riskyFunc is noexcept: " << noexcept(riskyFunc()) << "\n"; // false
}
