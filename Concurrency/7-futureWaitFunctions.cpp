#include <iostream>
#include <future>
#include <list>
#include <thread>

#define WAIT_UNTIL
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

    std::future<int> result = std::async(std::launch::async, Operate, 10);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Main thread" << std::endl;

#ifdef WAIT
    if (result.valid())
    {
        std::cout << "Waiting for result...\n";
        result.wait();                                        // Blocks until computation is done
        std::cout << "Result: " << result.get() << std::endl; // Retrieve the result
        return 0;
    }
#endif

#ifdef WAIT_FOR
    if (result.valid())
    {
        using namespace std::chrono_literals;
        std::cout << "Waiting for result...\n";
        auto status = result.wait_for(15s);
        switch (status)
        {
        case std::future_status::deferred:
            std::cout << "Task is synchronous " << std::endl;
            break;
        case std::future_status::ready:
            std::cout << "Result is ready " << std::endl;
            std::cout << "Result: " << result.get() << std::endl;
            break;
        case std::future_status::timeout:
            std::cout << "Task is still running" << std::endl;
            break;
        }
        return 0;
    }
#endif
#ifdef WAIT_UNTIL
    if (result.valid())
    {
        using namespace std::chrono_literals;
        auto timeout = std::chrono::system_clock::now();
        timeout += 15s;
        std::cout << "Waiting for result...\n";
        auto status = result.wait_until(timeout);
        switch (status)
        {
        case std::future_status::deferred:
            std::cout << "Task is synchronous " << std::endl;
            break;
        case std::future_status::ready:
            std::cout << "Result is ready " << std::endl;
            std::cout << "Result: " << result.get() << std::endl;
            break;
        case std::future_status::timeout:
            std::cout << "Task is still running" << std::endl;
            break;
        }
        return 0;
    }
#endif
}

/*
wait() → Blocks until the result is available
wait_for() → Waits for a specified duration
wait_until() → Waits until a specified time point
*/