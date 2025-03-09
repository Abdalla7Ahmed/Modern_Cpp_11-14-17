/*#include <iostream>
#include <memory>
#include <vector>
class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};
class B
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};
class Test
{
    A *pA{};
    B pB{};
    int *pInt{};
    char *pStr{};
    int *pArr{};

public:
    Test()
    {
        std::cout << "Test():Acquire resources" << std::endl;

        pA = new A;
        pInt = new int;
        throw std::runtime_error("Failed to initialize");
        pStr = new char[1000];
        pArr = new int[50000];
    }
    ~Test()
    {
        std::cout << "~Test():Release resources" << std::endl;
        // throw std::runtime_error("Failed to initialize");
        delete pA;
        delete pInt;
        delete[] pStr;
        delete[] pArr;
    }
};

int main()
{
    try
    {
        Test t;
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
*/
// output
/*
B()
Test():Acquire resources
A()
~B()
Failed to initialize


the destructor of B is called because it is a concreat object
(all the concrete objects created by the runtime will be automatically destroyed when the constructor throws an exception)
but the memory that is allocated through new will not be deleted automatically
*/

#include <iostream>
#include <memory>
#include <vector>
class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }
    ~A()
    {
        std::cout << "~A()" << std::endl;
    }
};
class B
{
public:
    B()
    {
        std::cout << "B()" << std::endl;
    }
    ~B()
    {
        std::cout << "~B()" << std::endl;
    }
};
class Test
{
    std::unique_ptr<A> pA{};
    B b{};
    std::unique_ptr<int> pInt{};
    std::string pStr{};
    std::vector<int> pArr{};

public:
    Test()
    {
        std::cout << "Test():Acquire resources" << std::endl;
        throw std::runtime_error("Failed to initialize");
        pA.reset(new A);
    }
    ~Test()
    {
        std::cout << "~Test():Release resources" << std::endl;
    }
};

int main()
{
    try
    {
        Test t;
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

/*
Throwing an exception in a destructor is dangerous
because it can lead to program termination (std::terminate) if another exception is already active. Here’s why:

1. Exception During Stack Unwinding
    If an exception is already being handled and another exception is thrown inside a destructor, the program will immediately terminate (std::terminate() is called).
    This happens because C++ does not allow multiple active exceptions at the same time.
2. Alternative Approach: Handle Errors Inside Destructor
    If a destructor needs to handle errors (e.g., logging or releasing resources), it should catch exceptions instead of throwing them.
        ~SafeDestructor() {
        try {
            // Some cleanup code that might fail
            throw std::runtime_error("Exception in destructor");
        } catch (const std::exception &e) {
            std::cerr << "Destructor caught an exception: " << e.what() << std::endl;
            // Log the error instead of throwing
        }
    }
    */
