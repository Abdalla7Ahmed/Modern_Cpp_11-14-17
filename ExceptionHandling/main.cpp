

#include <stdio.h>
#include <iostream>
#include <limits>
#include <memory>
#include <vector>
// malloc return null when it fails to allocate memory
// new threw an exception when it fails to allocate memory
// you should avoid manual memory management (use the containers and smart pointers instead)

class Test
{
public:
    Test() { std::cout << "Test():Acquire resources" << std::endl; }
    ~Test() { std::cout << "~Test():Release resources" << std::endl; }
};

void fun(int count)
{
    // instade of using row pointer use the smart ointer
    std::unique_ptr<Test> t1 = std::make_unique<Test>(); // no memory leakage and the destructor is called if the exception happens
    if (count < 10)
        throw std::out_of_range("Count should be grater than 10");
    // use vector container instead of pointer array
    std::vector<int> records;
    records.reserve(count); // it will throw an exception (bad_alloc) if it fails to allocate memory
    for (int i = 0; i < count; ++i)
    {
        records.push_back(i);
    }
    /*  ============ old code ============
    Test t1;
    // If an exception is thrown before t1 goes out of scope, its destructor is automatically called when stack unwinding occurs.
    Test *t2 = new Test();
    // If an exception occurs before deleting t2, it causes a memory leak because delete t2; is never called.

     if (count < 10)
        throw std::out_of_range("Count should be grater than 10");
    int *p = new int[count]; // throw a bad alloc exception when it fail
    int *pArray = (int *)malloc(count * sizeof(int));
    if (pArray == nullptr)
    {
        throw std::runtime_error("Failed to allocate memory");
    }
    int i;
    for (i = 0; i < count; i++)
    {
        pArray[i] = i;
    }
    std::cout << i << std::endl;
    free(pArray);
    delete[] p;
    delete t2;
    */
}

int main(int argc, const char **argv)
{
    try
    {
        fun(std::numeric_limits<int>::max()); // max of integer
        // fun(5); // max of integer
    }
    // catch (std::runtime_error &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch (std::out_of_range &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch (std::bad_alloc &e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    // catch (std::exception &e)
    // {
    //     // all the exceptions classes inherit from the base class exception
    //     // we catch all the child classes exceptions by using the base class exception
    //     std::cerr << e.what() << '\n';
    // }
    catch (...)
    {
        // catch all the exceptions without knowing the exception type
        // this type should be avoided because it doesn't give you any information about the exception
        // or we can use it as the last catch blcok
        std::cout << "Exception" << std::endl;
    }
    return 0;
}