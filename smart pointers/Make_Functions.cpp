#include "test.hpp"

class test
{
public:
    test(int x, int y)
    {
        std::cout << "x + y is " << x + y << std::endl;
    }
};
void Make_Functions(void)
{

    auto uniquePtr1 = std::make_unique<int>(24);
    auto sharedPtr1 = std::make_shared<int>(42);

    auto uniquePtr2 = std::make_unique<test>(5, 10);
    auto sharedPtr2 = std::make_shared<test>(12, 6);

    auto uniquePtr3 = std::make_unique<int[]>(5); // 5 is the size of the array
    // auto sharedPtr3 = std::make_shared<int[]>(5); // std::make_shared  "make_shared<T[]> not supported");
}