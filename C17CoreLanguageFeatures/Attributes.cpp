#include <iostream>

[[deprecated("USe the new version instead")]]
int *CreateArea(int size)
{
    return new int[size];
}
template <typename T, int size>
[[nodiscard]]
T *CreateArea()
{
    return new T[size];
}

class [[deprecated("This class is replaced by new class")]] testClass
{
};

namespace [[deprecated("Don't use this namespace")]] oldnamespace
{

}

class [[nodiscard]] Number
{
};

Number getInstance()
{
    return Number();
}

int main(int argc, char const *argv[])
{
    // warning: ‘int* CreateArea(int)’ is deprecated: USe the new version instead
    // CreateArea(3);
    // ignoring return value of ‘T* CreateArea() [with T = int; int size = 3]’, declared with attribute ‘nodiscard
    // CreateArea<int, 3>();
    // // warning: ‘testClass’ is deprecated: This class is replaced by new class
    // testClass t1;
    // // warning: ‘oldnamespace’ is deprecated: Don't use this namespace
    // using namespace oldnamespace;
    auto p = CreateArea<int, 3>();
    // warning: ignoring returned value of type ‘Number’, declared with attribute ‘nodiscard
    // getInstance();
    auto n = getInstance();
    [[maybe_unused]] int x = 10;
    int y{1};
    switch (y)
    {
    case 1:
        std::cout << "Case 1\n";
        [[fallthrough]]; // No warning for missing `break`
    case 2:
        std::cout << "Case 2\n";
        break;
    }

    return 0;
}

/*
attributes provide a standardized way to annotate code with additional information that can influence compiler behavior,
static analysis, or runtime behavior. Introduced in C++11 and expanded in later versions,
attributes are enclosed in double square brackets ([[...]]).

[[noreturn]] – Indicates that a function does not return.
[[deprecated]] – Marks a function, variable, or type as deprecated.
[[deprecated("Reason")]] – Allows specifying a reason for deprecation.
[[nodiscard]] – Warns if the return value of a function is ignored.
[[maybe_unused]] – Suppresses warnings for unused variables or functions.
[[fallthrough]] – Explicitly marks fallthrough behavior in a switch statement.
*/