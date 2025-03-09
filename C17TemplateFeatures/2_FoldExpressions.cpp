#include <iostream>

auto sum()
{
    return 0;
}
template <typename T, typename... Args>
auto sum(T a, Args... args)
{
    return a + sum(args...);
}
/*
cppinsights
this expand to -->
template<>
int sum<int, int, int, int, int>(int a, int __args1, int __args2, int __args3, int __args4)
{
  return a + sum(__args1, __args2, __args3, __args4);
}
template<>
int sum<int, int, int, int>(int a, int __args1, int __args2, int __args3)
{
  return a + sum(__args1, __args2, __args3);
}
template<>
int sum<int, int, int>(int a, int __args1, int __args2)
{
  return a + sum(__args1, __args2);
}
template<>
int sum<int, int>(int a, int __args1)
{
  return a + sum(__args1);
}
template<>
int sum<int>(int a)
{
  return a + sum();
}
 * 1+(2+(3+(4+(5+0))))
 * 1+(2+(3+(4+ 5)))
 * 1+(2+(3+9))
 * 1+(2+12)
 * 1+14
 * 15
 */

template <typename... Args>
auto sum2(Args... args)
{
    return (args + ...); // uniray right fold
    // return (... + args); // uniray left fold
}

/*
 * uniray right fold
int sum2<int, int, int, int, int>(int __args0, int __args1, int __args2, int __args3, int __args4)
{
  return __args0 + (__args1 + (__args2 + (__args3 + __args4)));
}
 * 1+(2+(3+(4+(5))))
 *
 * uniray left fold
int sum2<int, int, int, int, int>(int __args0, int __args1, int __args2, int __args3, int __args4)
{
  return (((__args0 + __args1) + __args2) + __args3) + __args4;
}
 * ((((1+2)+3)+4)+5)
 */

template <typename... Args>
auto sum3(Args... args)
{
    // return (args + ... + 0); // binary right fold
    return (0 + ... + args); // binary left fold
}

/*
 * binary right fold
int sum3<int, int, int, int, int>(int __args0, int __args1, int __args2, int __args3, int __args4)
{
  return __args0 + (__args1 + (__args2 + (__args3 + (__args4 + 0))));
}
 * 1+(2+(3+(4+(5+0)))))
 *
 * binary left fold
int sum3<int, int, int, int, int>(int __args0, int __args1, int __args2, int __args3, int __args4)
{
  return ((((0 + __args0) + __args1) + __args2) + __args3) + __args4;
}
 * (((((0+1)+2)+3)+4)+5)
 */

template <typename... Args>
auto anyof(Args... args)
{
    return ((args % 2 == 0) || ...);
}

template <typename... Args>
auto allof(Args... args)
{
    return ((args % 2 == 0) && ...);
}

template <typename... Args, typename Predicate>
auto anyof2(Predicate P, Args... args)
{
    return (P(args) || ...);
}

int main(int argc, char const *argv[])
{
    auto result = sum2(1, 2, 3, 4, 5);
    std::cout << result << std::endl;

    result = sum3();
    std::cout << result << std::endl;

    std::cout << std::boolalpha;
    std::cout << "Any Even ? " << anyof(5, 9, 3, 1) << std::endl;
    std::cout << "All Even ? " << allof(2, 1, 6, 8) << std::endl;

    std::cout << "Any Even ? " << anyof2([](int x)
                                         { return x % 2 == 0; }, 5, 9, 3, 2)
              << std::endl;

    return 0;
}

/*
Fold expressions simplify the reduction of parameter packs in variadic
templates by applying an operator to all elements in the pack.

(... op pack)  // Unary Left Fold
(pack op ...)  // Unary Right Fold
(initial op ... op pack)  // Binary Left Fold
(pack op ... op initial)  // Binary Right Fold
op is a binary operator (e.g., +, *, &&, ||).
pack is a variadic template parameter pack.
*/