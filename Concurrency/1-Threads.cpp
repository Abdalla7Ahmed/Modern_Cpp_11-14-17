#include <iostream>
#include <list>
#include <thread>

std::list<int> g_Data;
const int SIZE = 50000000;
void Download()
{
    std::cout << "[Downloder] Start Download" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        g_Data.push_back(i);
    }
    std::cout << "[Downloder] Finish Download" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "[main] Start an operation" << std::endl;
    std::thread thdownloader(Download);
    thdownloader.detach();
    std::cout << "[main] Start another operation" << std::endl;
    if (thdownloader.joinable())
    {
        thdownloader.join();
    }
    return 0;
}

/*
join()
    join() makes the calling thread wait for the thread to finish execution.
    Once a thread is joined, it cannot be joined again.
    Ensures that the thread has completed before the program proceeds.


detach()
    detach() allows the thread to run independently from the main thread.
    The detached thread runs in the background, and the main thread does not wait for it.
    Once detached, a thread cannot be joined.
    The detached thread’s execution is managed by the OS, and it is terminated when the program exits.
*/