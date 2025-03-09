/*
Stack Unwinding
What is Stack Unwinding?

Stack unwinding is the process of cleaning up function call stack frames when an exception is thrown and not immediately caught in the same function. It ensures that destructors of local objects are called as the program searches for a matching exception handler.
How Does Stack Unwinding Work?

    When an exception is thrown, the current function stops execution immediately.
    The runtime searches for a suitable catch block (try-catch) to handle the exception.
    If no handler is found in the current function, the function exits, and control moves to the caller.
    This process repeats until an appropriate catch block is found.
    During this process, destructors of local objects in each function scope are called automatically to release resources.
*/

#include <iostream>
#include <stdexcept>

class Test
{
public:
    Test(int id) : id(id) { std::cout << "Constructing Test " << id << std::endl; }
    ~Test() { std::cout << "Destroying Test " << id << std::endl; }

private:
    int id;
};

void func2()
{
    Test t2(2);
    throw std::runtime_error("Error in func2"); // Exception is thrown here
}

void func1()
{
    Test t1(1);
    func2(); // Calls func2() which throws an exception
}

int main()
{
    try
    {
        func1();
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}
