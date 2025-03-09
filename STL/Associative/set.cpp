#include <iostream>
#include <set>
#include <functional>

int main(int argc, char const *argv[])
{
    std::multiset<int, std::greater<int>> s{8, 2, 0, 9, 5};
    // No push_back, only insert as elements are ordered automatically
    s.insert(1);

    // Only multiset allows duplicates
    s.insert(3);
    s.insert(3);
    s.insert(3);

    auto itr = s.begin();
    //*itr = 3;
    while (itr != s.end())
    {
        std::cout << *itr++ << " ";
    }
    std::cout << std::endl;

    // Erase by key or position
    s.erase(0);
    s.erase(s.begin());
    itr = s.find(9);
    if (itr != s.end())
    {
        std::cout << "Element found" << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }
    // to find  all the repeated elements
    auto found = s.equal_range(3);
    while (found.first != found.second)
    {
        std::cout << *found.first++ << " ";
    }
    return 0;
}

/*
1️ Static or Dynamic

    Dynamically allocated: The size of the set/multiset grows as elements are inserted.

2 How It Stores Elements

    Internally implemented as a binary tree (self-balancing).
    Elements are always stored in sorted order.
    Uses comparison operators (less or greater) for sorting.
    Set does not allow duplicates, but multiset does.

3️ Supported Algorithms

    Insertion: Uses insert() (no push_back or push_front).
    Accessing elements: Done via iterators (which are constant, meaning elements cannot be modified directly).
    Searching:
        find(key): Returns an iterator to the element if found, else end().
        equal_range(key): Returns a pair of iterators (first occurrence and the first greater element) for multisets.
    Deletion:
        erase(value): Removes elements by value.
        erase(iterator): Removes elements by position.

4️ Additional Notes

    Default order is ascending, but you can change it using greater for descending order.
    Set is efficient for lookups but not as efficient as list for insertions and deletions.
    Defined in <set> header.
*/