#include <iostream>
#include <deque>

int main(int argc, char const *argv[])
{
    std::deque<int> coll;
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
    }
    for (int i = 0; i < 5; ++i)
    {
        coll.push_front(i * 10);
    }
    coll[0] = 100;
    for (int i = 0; i < coll.size(); ++i)
    {
        std::cout << coll[i] << " ";
    }
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    coll.insert(coll.begin(), 700);
    coll.erase(coll.end() - 5);
    coll.pop_back();
    coll.pop_front();
    return 0;
}

/*
What is std::deque?

    Deque stands for Double-Ended Queue.
    Similar to std::vector, but allows efficient insertion and deletion from both ends.

Key Features:

    Dynamic growth: Expands automatically when elements are added.
    Random access: Supports the [] subscript operator for direct element access.
    Efficient insertion/removal at both ends: Supports push_front(), push_back(), pop_front(), and pop_back().
    Inefficient insertion/removal in the middle: Similar to vector, shifting elements can be costly.


*/