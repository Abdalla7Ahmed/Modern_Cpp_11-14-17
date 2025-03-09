#include <iostream>

int main(int argc, char const *argv[])
{

    auto i = {10, 10};
    std::cout << typeid(i).name() << std::endl;
    return 0;
}
