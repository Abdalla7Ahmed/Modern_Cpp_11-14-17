#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
void UnSet()
{
    std::unordered_multiset<std::string> coll;
    // elements are stored based on the hash, but in unspecified order,
    coll.insert("Hulk");
    coll.insert("Batman");
    coll.insert("Green Lantern");
    coll.insert("The Flash");
    coll.insert("Wonder Woman");
    coll.insert("Iron man");
    coll.insert("Iron man");
    coll.insert("Iron man");
    coll.insert("Wolverine");
    coll.insert("Dr. Strange");
    coll.insert("Hawkman");

    for (const auto x : coll)
    {
        std::cout << "Bucket #:" << coll.bucket(x) << " contains :" << x << std::endl;
    }
    std::cout << "Bucket count:" << coll.bucket_count() << std::endl;
    std::cout << "Number of elements:" << coll.size() << std::endl;
    std::cout << "Load factor:" << coll.load_factor() << std::endl;
}
void UnMap()
{
    std::unordered_multimap<std::string, std::string> coll;
    // Only unordered_map support [] operator
    /*coll["Batman"] = "Brue Wayne";
    coll["Superman"] = "Clark Kent";
    coll["Hulk"] = "Bruce Banner";*/
    coll.insert(std::make_pair("Batman", "Bruce Wayne"));
    coll.insert(std::make_pair("Batman", "Matches Malone"));
    coll.insert(std::make_pair("Superman", "Clark Kent"));
    coll.insert(std::make_pair("Hulk", "Bruce Banner"));

    for (const auto &x : coll)
    {
        std::cout << "Bucket #:" << coll.bucket(x.first) << " ->" << x.first << ":" << x.second << std::endl;
    }
}

int main()
{
    // UnSet();
    UnMap();
    return 0;
}

/*
1. Static or Dynamic?

    Unordered containers (like unordered_map and unordered_set) are dynamic.
    They allocate memory dynamically as elements are inserted.
    If the load factor (number of elements / bucket count) exceeds a threshold, rehashing occurs, increasing the table size.

2. How Are Elements Stored?

    Internally implemented using a hash table.
    Each element is assigned a bucket based on a hash function applied to the key.
    Buckets typically hold pointers to linked lists to handle collisions (known as separate chaining).

3. Supported Algorithms

    Insert, Search, and Delete: Average O(1) time complexity, worst case O(N) (if all elements collide into one bucket).
    Find (find(key)): Returns an iterator to the element or end() if not found.
    Erase (erase(key)): Removes an element in O(1) average time.
    Rehashing: When the load factor exceeds a threshold, the hash table grows, and all elements are rehashed.

4. Additional Information

    No Ordering: Unlike map or set, elements are not stored in sorted order.
    Iterators Are Not Stable: Since rehashing moves elements, iterators can become invalid.
    Custom Hash Functions: You can provide a custom hash function for user-defined types.
    Unordered Multimap & Multiset: Variants that allow duplicate keys.

*/