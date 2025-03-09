#include <iostream>

int main(int argc, char const *argv[])
{

    if (int x = 10; x < 100)
    {
        std::cout << "x less than 100" << std::endl;
    }
    // std::cout << x << std::endl; // error ‘x’ was not declared in this scope

    if (int *p = (int *)malloc(sizeof(int)); p != nullptr)
    {
        *p = 50;
        free(p);
    }
    else
    {
        // here p will be nullptr
    }
    switch (int y = 10; y)
    {
    case 10:
        std::cout << "y is equal to 10" << std::endl;
        break;

    default:
        std::cout << "y is not equal to 10" << std::endl;

        break;
    }
    return 0;
}

/*
C++17 introduced "if" and "switch" with initialization,
allowing variables to be declared and initialized within the if and switch statements.
This feature improves scope management and reduces unnecessary variable declarations before conditions.
*/