#include <iostream>
#include <thread>
#include <chrono>

// Function that runs in a separate thread
void Process()
{
    for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause for 1 second
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}

int main()
{
    std::thread t1(Process); // Start a new thread executing Process()

    pthread_setname_np(pthread_self(), "MyThread"); // Set thread name to "MyThread"

    auto id = t1.get_id(); // Get thread ID
    std::cout << "Thread ID: " << id << std::endl;

    // Get number of CPU cores
    int cores = std::thread::hardware_concurrency();
    std::cout << "Cores available: " << cores << std::endl;

    t1.join(); // Wait for thread to finish before exiting
    return 0;
}
