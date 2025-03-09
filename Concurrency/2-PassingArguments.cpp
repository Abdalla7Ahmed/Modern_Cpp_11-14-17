#include <iostream>
#include <list>
#include <thread>

class myString
{
public:
    myString()
    {
        std::cout << "myString()" << std::endl;
    }
    myString(const myString &)
    {
        std::cout << "myString(const std::string &)" << std::endl;
    }
    myString &operator=(const myString &)
    {
        std::cout << "myString &operator=(const std::string &)" << std::endl;
        return *this;
    }
    ~myString()
    {
        std::cout << "~myString()" << std::endl;
    }
};
std::list<int> g_Data;
const int SIZE = 50000000;
void Download(const myString &filename)
{
    for (int i = 0; i < SIZE; i++)
    {
        g_Data.push_back(i);
    }
    std::cout << "[Downloder] Finish Download" << std::endl;
}

int main(int argc, char const *argv[])
{
    myString filename;
    std::cout << "[main] Start an operation" << std::endl;
    std::thread thdownloader(Download, std::cref(filename));
    std::cout << "[main] Start another operation" << std::endl;
    if (thdownloader.joinable())
    {
        thdownloader.join();
    }
    return 0;
}

/*
std::ref and std::cref are helper functions in C++ that allow you to pass objects by reference to functions,
particularly when working with std::bind, std::thread, and STL algorithms.

std::ref is used to create a reference wrapper for an object, ensuring that it is passed by reference instead of by value.
std::cref is similar to std::ref, but it creates a constant reference wrapper (const T&). This is useful when you want to pass a read-only reference.
*/