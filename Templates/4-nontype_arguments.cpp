#include <iostream>
template <int size>
void print(void)
{
    // size++;   //increment of read-only location ‘size’
    char buffer[size];
    std::cout << size << std::endl;
}

template <typename T>
T Sum(T *arr, T size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

template <typename T, int size>
T Sum2(T (&ref)[size])
{
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += ref[i];
    }
    return sum;
}
int main(int argc, const char **argv)
{
    int x = 20;
    constexpr int size = 2;
    const int size2 = 10;
    print<3>();
    // print<x>();  // the value of ‘x’ is not usable in a constant expression , deduction occur during the compile time but x will initialized during runtime
    print<size>();  // no error because constexpr resolved during the compile time
    print<size2>(); // no error

    // ========================================
    int arr[3]{1, 2, 3};
    auto sum = Sum(arr, 3);
    std::cout << sum << std::endl;

    // ========= we can use reference
    auto sum2 = Sum2(arr);
    std::cout << sum2 << std::endl;

    // non type template arguments used in std::begin and std::end
    /*
      template<typename _Tp, size_t _Nm>
    [[__nodiscard__]]
    inline _GLIBCXX14_CONSTEXPR _Tp*
    begin(_Tp (&__arr)[_Nm]) noexcept
    { return __arr; }
    */
    return 0;
}
