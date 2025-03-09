#include <chrono>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>
#include <execution>
class Timer
{
    std::chrono::steady_clock::time_point m_start;

public:
    Timer() = default;
    void start()
    {
        m_start = std::chrono::steady_clock::now();
    }
    void reset()
    {
        start();
    }
    void ShowResult(std::string_view message = "")
    {
        auto end = std::chrono::steady_clock::now();
        auto difference = end - m_start;
        std::cout << message
                  << ':'
                  << std::chrono::duration_cast<std::chrono::milliseconds>(difference).count()
                  << '\n';
    }
};
constexpr unsigned VEC_SIZE{100};
std::vector<long> CreateVector()
{
    std::vector<long> vec;
    vec.reserve(VEC_SIZE);
    std::default_random_engine engine{std::random_device{}()};
    std::uniform_int_distribution<long> dist{0, VEC_SIZE};
    for (unsigned i = 0; i < VEC_SIZE; ++i)
    {
        vec.push_back(dist(engine));
    }
    return vec;
}
int main()
{
    auto dataset = CreateVector();
    Timer t;
    // t.start();
    // std::sort(dataset.begin(), dataset.end());
    // t.ShowResult("sorting time for sequential algorithm"); // sorting time for sequential algorithm:3866 milli

    // t.reset();
    // std::sort(std::execution::par, dataset.begin(), dataset.end());
    // t.ShowResult("sorting time for pararithm algorithm"); // sorting time for pararithm algorithm:873 milli

    t.reset();
    auto result = std::accumulate(dataset.begin(), dataset.end(), 0L);
    t.ShowResult("Accumulate time for accumulate algorithm"); // Accumulate time for reduce algorithm:894

    // t.reset();
    // auto result = std::reduce(std::execution::par, dataset.begin(), dataset.end(), 0L);
    // t.ShowResult("Accumulate time for reduce algorithm"); // Accumulate time for reduce algorithm:142
}

/*
Parallel algorithms offer better performance for large datasets but have overhead due to thread initialization and element preparation.
For small datasets, sequential algorithms can be faster because the overhead of parallelization outweighs the benefits.
Exception Handling:

    Parallel algorithms call std::terminate if an exception occurs.
    Sequential algorithms allow exceptions to be caught and handled.

Limitations of Parallel Algorithms:

    Some algorithms (e.g., shuffle, binary search, max, min) are not easily parallelizable due to high synchronization costs.

Iterator Compatibility:

    Sequential algorithms work with both input and output iterators.
    Parallel algorithms have iterator restrictions.

*/