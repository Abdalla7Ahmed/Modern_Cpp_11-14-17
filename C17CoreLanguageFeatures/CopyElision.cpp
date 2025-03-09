/*
Before C++17, copy elision (also known as return value optimization, RVO) was an optimization
performed by compilers in some cases to avoid unnecessary copies.
However, it was not guaranteed, meaning compilers were allowed—but not required—to optimize the copying.

Starting from C++17, copy elision became mandatory in certain cases, meaning:
    The compiler must optimize away the copy/move of objects.
    Even if the class has no move constructor, the compiler will not generate an extra copy.

What is Copy Elision?
Copy elision refers to eliminating unnecessary object copies or moves, particularly when:
    Returning a temporary object from a function.
    Constructing an object directly from a temporary.
*/

#include <iostream>

class Example
{
public:
    Example() { std::cout << "Constructor\n"; }
    // Example(const Example &) { std::cout << "Copy Constructor\n"; }
    // Example(Example &&) { std::cout << "Move Constructor\n"; }
    Example(const Example &) = delete; // Copy constructor deleted
    Example(Example &&) = delete;      // Move constructor deleted
};

Example createExample()
{
    return Example(); // Temporary object
}

int main()
{
    Example ex = createExample(); // Might call copy/move constructor before C++17
    /*
    Possible Output (Before C++17, if no RVO applied)
    Constructor
    Move Constructor  // Could be Copy Constructor if move is not available

    Here, Example() creates a temporary object.
    Before C++17, compilers might invoke the move constructor when returning the temporary object.
    Mandatory Copy Elision in C++17

    With C++17, the compiler must elide the copy/move constructor calls in cases where a temporary is returned.
    That means even if the class lacks a move constructor, no extra copy/move will happen.

    What If We Delete Copy and Move Constructors?
    Even if you delete both copy and move constructors, C++17 allows returning temporary objects:

    g++ CopyElision.cpp -o0 -std=c++14 --> error: use of deleted function ‘Example::Example(Example&&)’
    g++ CopyElision.cpp -o0 -std=c++17 --> passed

    Before C++17: Copy elision was an optimization, not guaranteed.
    After C++17: Copy elision is mandatory when returning temporaries, avoiding unnecessary copies.
    Key Benefit: Even if copy and move constructors are deleted, the code still works.
    */
}

/*

*/