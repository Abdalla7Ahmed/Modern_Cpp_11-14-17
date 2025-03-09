#include <iostream>
#include <list>
#include <forward_list>
void List()
{
    std::list<int> coll;
    for (int i = 0; i < 5; ++i)
    {
        coll.push_back(i * 10);
    }
    auto itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    itr = coll.begin();
    coll.insert(itr, 800);
    itr = coll.begin();
    while (itr != coll.end())
    {
        std::cout << *itr++ << " ";
    }
    // coll.erase(itr);
}
void ForwardList()
{
    std::forward_list<int> coll;
    for (int i = 0; i < 10; ++i)
    {
        coll.push_front(i);
    }
    for (auto x : coll)
    {
        std::cout << x << " ";
    }
    coll.insert_after(coll.begin(), 10);
    coll.erase_after(coll.begin());
    for (auto x : coll)
    {
        std::cout << x << " ";
    }
}
int main(int argc, char const *argv[])
{
    List();
    ForwardList();
    return 0;
}

/*
1. std::list (Doubly Linked List)

    Implemented as a two-way linked list.
    Each node contains:
        Data
        A pointer to the next node
        A pointer to the previous node
    Supports bidirectional traversal.
    Efficient insertions and deletions (O(1)) anywhere in the list.
    Does NOT provide random access (No [] operator).
    Accessing elements requires iterators.
    Uses more memory due to extra pointers.

Operations:

    push_back(value): Adds an element to the end.
    push_front(value): Adds an element to the beginning.
    insert(iterator, value): Inserts at a specific location.
    erase(iterator): Removes an element.

Use Cases:

    When frequent insertions/deletions are needed anywhere.
    When bidirectional traversal is required.

*/

/*
2. std::forward_list (Singly Linked List)

    Implemented as a one-way linked list.
    Each node contains:
        Data
        A pointer to the next node (no previous pointer).
    Supports only forward traversal.
    More memory-efficient than std::list.
    Efficient insertions and deletions (O(1)) anywhere.
    Does NOT provide random access.
    Does NOT support size() because of the absence of backward traversal.

Operations:

    push_front(value): Always adds at the front.
    insert_after(iterator, value): Inserts after the given iterator.
    erase_after(iterator): Erases the element after the given iterator.

Use Cases:

    When memory is limited.
    When you only need forward traversal.
    When frequent insertions/deletions are required.
*/