#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> coll{1, 2, 3, 4};
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
        std::cout << coll.size() << std::endl;
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
    return 0;
}

/*
Static or Dynamic:

    std::vector is dynamic; it can grow automatically when elements are added.

Storage Mechanism:

    Internally implemented as a dynamic array, which allows random access.

Supported Algorithms & Features:

    Efficient for adding/removing elements at the end (push_back(), pop_back()).
    Supports random access via the subscript ([]) operator.
    Provides iterators (begin(), end()) for traversal.
    Elements can be inserted at a specific position using insert(iterator, value).
    Supports deletion using erase(iterator) (removes one element) or erase(start, end) (removes a range).
    Uses copy and assignment when inserting elements in the middle (performance cost).
    size() returns the current number of elements.

Additional Notes:

    Not efficient for insertions and deletions in the middle or beginning, as it requires shifting elements.
    Best used for random access scenarios where elements are mostly added/removed from the end.
    Uses allocators internally for memory management (default allocator is sufficient for most cases).
    The end iterator (end()) should not be dereferenced, as it points beyond the last element
*/