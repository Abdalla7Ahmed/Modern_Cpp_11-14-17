#include <iostream>
#include <array>

int main(int argc, char const *argv[])
{
    std::array<int, 5> arr{3, 1, 8, 5, 9};
    for (int i = 0; i < arr.size(); ++i)
    {
        arr[i] = i;
    }
    auto itr = arr.begin();
    for (auto x : arr)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    arr.data();
    return 0;
}

/*
Static or Dynamic:

    std::array is static; its size is fixed at compile time.

Storage Mechanism:

    Internally, it is a thin wrapper over a C-style static array.

Supported Algorithms & Features:

    Random access using the subscript ([]) operator.
    Supports iterators (begin(), end()) for element traversal.
    Provides a size() function to determine its length.
    data() returns a pointer to the underlying C-style array, making it compatible with C functions.
    Can be initialized using uniform initialization syntax.

Additional Notes:

    Cannot grow dynamically; size remains fixed at compile time.
    Iterators help traverse elements and modify them using *iterator.
    End iterator (end()) points beyond the last element and should never be dereferenced.
    If dynamic resizing is needed, std::vector should be used instead.
*/