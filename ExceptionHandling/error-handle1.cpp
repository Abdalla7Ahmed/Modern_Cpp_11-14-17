#include <iostream>

/*

malloc return null when it fails to allocate memory
new threw an exception when it fails to allocate memory
1. try in C++
The try keyword represents a block of code that may throw an exception placed inside the try block.
It’s followed by one or more catch blocks. If an exception occurs, try block throws that exception.

2. catch in C++
The catch statement represents a block of code that is executed when a particular exception is thrown from the try block.
The code to handle the exception is written inside the catch block.

3. throw in C++
An exception in C++ can be thrown using the throw keyword. When a program encounters a throw statement,
then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.

*/

int main()
{

    try
    {
        int numerator{};
        int denominator{};
        int res{};
        std::cout << "Enter numerator" << std::endl;
        std::cin >> numerator;
        std::cout << "Enter denominator" << std::endl;
        std::cin >> denominator;

        if (denominator == 0)
        {
            throw std::runtime_error("Division by zero not allowed!");
        }
        // calculate result if no exception occurs
        res = numerator / denominator;
        //[printing result after division
        std::cout << "Result after division: " << res << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception " << e.what() << '\n';
        // throw;
    }
    // if thre throw keyword exist in catch , it will terminate befor execute any line after the throw keyword
    std::cout << "After catch (Will be executed) \n";
    int x = -1;
    try
    {

        std::cout << "Inside try \n";
        if (x < 0)
        {
            // throwing an exception
            throw x;
            std::cout << "After throw (Never executed) \n";
        }
    }
    catch (int x)
    {
        std::cout << "Exception Caught x less than 1\n";
    }
    std::cout << "After catch (Will be executed) \n";

    try
    {
        throw 10;
    }
    // catch block
    catch (char *excp)
    {
        std::cout << "Caught " << excp;
    }

    // catch all
    catch (...)
    {
        std::cout << "Default Exception\n"; // Default Exception
    }

    try
    {
        throw 10;
    }
    // catch block
    catch (int excp)
    {
        std::cout << "Caught " << excp << "\n"; // Caught 10
    }

    // catch all
    catch (...)
    {
        std::cout << "Default Exception\n";
    }

    try
    {
        throw 'a';
    }
    catch (int x) // if it char x   this catch will executed
    {
        std::cout << "Caught " << x;
    }
    catch (...)
    {
        std::cout << "Default Exception\n"; // Default Exception
    }

    return 0;
}