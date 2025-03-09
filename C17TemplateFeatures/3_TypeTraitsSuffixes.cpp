#include <type_traits>
#include <iostream>

template <typename T>
using enable_if_integral_t = std::enable_if_t<std::is_integral_v<T>, int>;

template <typename T>
enable_if_integral_t<T> testFunc()
{
    return 42;
}
int main()
{
    std::cout << std::boolalpha;
    /*
    _v Suffix → Returns a constexpr bool value
        Used with type traits that check properties of types.
        Avoids ::value for simpler syntax.
    */
    std::cout << std::is_integral_v<int> << "\n";         // true
    std::cout << std::is_integral_v<double> << "\n";      // false
    std::cout << std::is_integral<int>::value << "\n";    // true
    std::cout << std::is_integral<double>::value << "\n"; // false
    /*
    _t Suffix → Returns the type directly
    Used with type transformation traits.
    Avoids ::type for better readability.
    */

    using Type = std::remove_pointer_t<int *>;      // int
    std::cout << std::is_same_v<Type, int> << "\n"; // true

    /*
    _class Suffix → Helper type aliases for SFINAE
    Less common than _v and _t, used for detecting classes.
    */
    std::cout << testFunc<int>() << "\n"; //   Works (int is integral)
    // std::cout << testFunc<double>();      //   Compilation Error (double is not integral)
}
