#include <iostream>
#include <type_traits>

template <typename T>
void print(const T &value)
{
    if constexpr (std::is_pointer_v<T>)
    {

        std::cout << *value << std::endl;
    }
    else if constexpr (std::is_array_v<T>)
    {
        for (const auto &v : value)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << value << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    int value{5};
    print(value);
    print(&value);
    int arr[5] = {1, 2, 3, 4, 5};
    print(arr);

    return 0;
}

/*
constexpr (short for constant expression) is used to evaluate expressions at compile-time rather than runtime.
Key Benefits of constexpr:

    Compile-Time Optimization: Eliminates unnecessary computations during execution.
    Enforces Constants: Ensures variables/functions can be evaluated at compile-time.
    Improves Performance: Reduces runtime overhead by precomputing results.

It evaluates conditions at compile-time and removes unused branches from compilation.
Unlike normal if, unused branches won’t even be compiled.

*/