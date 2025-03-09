// #include <iostream>

// void fun(int *ptr, int x)
// {
//     if (ptr == nullptr)
//     {
//         throw ptr;
//     }
//     if (x == 0)
//     {
//         throw x;
//     }
// }
// int main()
// {
//     int x{10};

//     try
//     {

//         fun(&x, 0); // Caught 0
//         // fun(nullptr,0); // Caught ptr
//         // fun(nullptr,50); // Caught ptr
//         // fun(&x,50); // Caught exception from fun()
//     }
//     catch (int *ptr)
//     {
//         std::cout << "Caught ptr" << std::endl;
//     }
//     catch (int x)
//     {
//         std::cout << "Caught 0" << std::endl;
//     }
//     catch (...)
//     {
//         std::cout << "Caught exception from fun()" << std::endl;
//     }

//     return 0;
// }

// A better way to write the above code:

// C++ program to demonstate property 4 in better way

#include <iostream>

// Here we specify the exceptions that this function throws.
void fun(int *ptr, int x) throw (
    int *, int) // Dynamic Exception specification
{
    if (ptr == nullptr)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}

int main()
{
    try
    {
        fun(nullptr, 0);
    }
    catch (...)
    {
        std::cout << "Caught exception from fun()" << std::endl;
    }
    return 0;
}

/*

but it doesn't allowed in c++17 or above
abdallah@abdallah:~/Documents/Github/ModernCPlusPlus/06_advanced$ g++ error-handle2.cpp -std=c++20
error-handle2.cpp:37:27: error: ISO C++17 does not allow dynamic exception specifications
   37 | void fun(int *ptr, int x) throw (
      |                           ^~~~~
abdallah@abdallah:~/Documents/Github/ModernCPlusPlus/06_advanced$ g++ error-handle2.cpp -std=c++14
error-handle2.cpp:37:27: warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
   37 | void fun(int *ptr, int x) throw (
*/