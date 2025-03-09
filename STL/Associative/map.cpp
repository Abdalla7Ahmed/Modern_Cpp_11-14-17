#include <iostream>
#include <functional>
#include <map>
int main()
{
    std::multimap<int, std::string> m{
        {1, "Superman"},
        {2, "Batman"},
        {3, "Green Lantern"}};
    m.insert(std::pair<int, std::string>(8, "Aquaman"));
    m.insert(std::make_pair(6, "Wonder Woman"));
    m.insert(std::make_pair(6, "Powergirl"));

    // Only map support [] operator
    /*m[0] = "Flash";
    m[0] = "Kid Flash";*/
    auto itr = m.begin();
    m.erase(0);
    // returns a pair that contains begin & end of the range.
    auto found = m.equal_range(6);
    while (found.first != found.second)
    {
        std::cout << found.first->first << ":" << found.first->second << std::endl;
        found.first++;
    }

    // std::cout << itr->first << ":" << itr->second << std::endl;

    // Avoid using [] for searching as it will insert an empty element if a key cannot be found
    // std::cout << "10:" << m[10] << std::endl;

    /*for (const auto &x : m) {
        std::cout << x.first << ":" << x.second << std::endl;
    }*/

    // Lookup by key
    /*itr = m.find(1);
    if (itr != m.end()) {
        std::cout << "Found:" << itr->second << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }*/
    return 0;
}

/*
1. Static or Dynamic

    map and multimap are dynamic containers, meaning they can grow or shrink in size as elements are inserted or removed.
    Memory allocation is handled internally using dynamic memory allocation.

2. How Elements Are Stored

    Both map and multimap store elements as key-value pairs using the std::pair structure.
    Internally, they use a self-balancing binary search tree (typically a Red-Black Tree).
    Elements are automatically sorted based on the key.
    map ensures unique keys, while multimap allows duplicate keys.

3. Supported Algorithms

    Insertion (insert() or operator[] in map) – Inserts key-value pairs. In multimap, duplicate keys are allowed.
    Search (find()) – Returns an iterator to the key if found; otherwise, it returns end().
    Deletion (erase()) – Removes elements based on key or iterator.
    Iteration (begin(), end()) – Allows traversal of all elements in sorted order.
    Range-based search (equal_range()) – Used in multimap to get all values for a given key.
    Lower and Upper Bound (lower_bound(), upper_bound()) – Finds the first and last positions of a given key range.
    Sorting – Since map is always sorted by key, explicit sorting is not needed.

4. Any Additions?

    Performance Complexity:
        Insert, Delete, Search: O(log N) due to the Red-Black Tree structure.
        Iteration: O(N).
    Alternative Containers:
        If ordering is not required, unordered_map and unordered_multimap (hash-based) provide faster average time complexity (O(1) for search, insert, and delete).
        If faster traversal is needed, vector<pair<K, V>> with manual sorting could be an alternative.
    Thread Safety:
        std::map and std::multimap are not thread-safe for concurrent read/write access.
*/