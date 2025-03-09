

/*

Before C++17, inline was mainly used for functions, but C++17 introduced inline variables.
This allows defining global or static variables in header files without violating the One Definition Rule (ODR).

Before C++17, if you declared a global const variable in a header file like this:
// header.h
const int value = 10;  // Defined in a header
And included it in multiple .cpp files, each translation unit would get a separate copy of value.
This led to multiple definition errors for non-const variables.

With C++17 inline variables, you can do:
// header.h
inline int value = 10;  // Single definition across all translation units
Now, value is treated similarly to an inline function, meaning it can be included
in multiple .cpp files without causing multiple definition errors.


One Definition Rule (ODR) & Inline Variables
In C++, the One Definition Rule (ODR) states that a variable or function must not have multiple definitions across translation units.
Before C++17, global variables in headers often violated ODR. or using the extern keyword
With inline variables, the compiler guarantees that there is only one definition across all translation units.


Static Members Inside a Class with Inline
Before C++17, static data members of a class had to be defined outside the class.
// header.h
struct Config {
    static int maxConnections;  // Declaration only
};

// source.cpp
#include "header.h"
int Config::maxConnections = 100;  // Definition required

With C++17 inline variables, you can define the static variable inside the class itself
// header.h
struct Config {
    static inline int maxConnections = 100; // No need for separate definition
};
A constexpr variable in a class is implicitly inline, meaning:
struct Config {
    static constexpr int maxConnections = 100; // Implicitly inline
};
This means:
No need to define it separately outside the class.
The compiler ensures there's only one definition across translation units.

If you explicitly mark it as inline, it's redundant but still valid:
struct Config {
    static inline constexpr int maxConnections = 100; // Still fine
};

*/