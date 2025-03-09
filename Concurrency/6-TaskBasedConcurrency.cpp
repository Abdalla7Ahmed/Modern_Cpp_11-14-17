#include <iostream>
#include <future>
#include <list>
#include <thread>
int Operate(int count)
{
    int Sum{};
    for (int i = 0; i < count; i++)
    {
        Sum++;
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return Sum;
}

int main(int argc, char const *argv[])
{
    // std::future<void> result = std::async(Download);
    // std::launch::async   --> run asynchronous
    // std::launch::deferred --> run synchronous (no threads creted)
    // std::async(Download); -- > by default it depends on the compiler
    std::future<int> result = std::async(std::launch::async, Operate, 10);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Main thread" << std::endl;
    // once you call get of the future, the shared state is destroyed and you can't get it again
    // to check it valid or not
    if (result.valid())
    {
        auto sum = result.get(); // this will block the main thread until the Download thread complete (like join)
        std::cout << "Sum : " << sum << std::endl;
    }
    return 0;
}

/*
std::async runs a function asynchronously and returns a std::future to retrieve the result once it’s available.

*/