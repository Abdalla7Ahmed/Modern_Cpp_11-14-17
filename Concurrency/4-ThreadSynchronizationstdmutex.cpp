#include <iostream>
#include <list>
#include <thread>
#include <mutex>
// g_Data is a global std::list<int> that is accessed by multiple threads.
std::list<int> g_Data;
const int SIZE = 10000;

std::mutex mut1;
void Download1()
{
    for (int i = 0; i < SIZE; i++)
    {
        // mut1.lock();
        // g_Data.push_back(i);
        // if (i == 5000)
        //     return;
        // mut1.unlock();
        // if this happen the mutex will never unlock and the other thread will wait indefinitely
        // the solution is use the lock_guard

        std::lock_guard<std::mutex> lock(mut1);
        g_Data.push_back(i);
        if (i == 5000)
            return;

        /*
        in the destructor it unlock the mutex
      ~lock_guard()
      { _M_device.unlock(); }
        */
    }
}
void Download2()
{
    for (int i = 0; i < SIZE; i++)
    {
        std::lock_guard<std::mutex> lock(mut1);
        g_Data.push_back(i);
    }
}

int main(int argc, char const *argv[])
{

    std::thread thdownloader1(Download1);
    std::thread thdownloader2(Download2);
    thdownloader1.join();
    thdownloader2.join();
    std::cout << g_Data.size() << std::endl;
    return 0;
}

/*
Race condition:
Occurs when multiple threads access and modify shared data concurrently,leading to unpredictable results.
This happens because the outcome depends on the order and timing of thread execution.

Task synchronization:
Ensures that multiple threads execute in a controlled manner,
preventing race conditions and data inconsistency.
Ways to Achieve Synchronization
    std::mutex → Locks a resource so only one thread can modify it at a time.
    std::condition_variable → Makes a thread wait until a condition is met.
    std::atomic → Provides a lock-free way to handle shared variables.

Deadlock
A deadlock happens when two or more threads wait indefinitely for each other to release a lock.

Why Avoid std::mutex When Possible?

When using std::mutex, if a thread locks the mutex and exits prematurely (due to an exception or early return),
the mutex remains locked forever, causing other threads to wait indefinitely.
This can lead to deadlocks and performance issues.

Instead of manually locking and unlocking the mutex, we can use RAII (Resource Acquisition Is Initialization)
with std::lock_guard. This ensures the mutex is automatically unlocked when the function exits.

std::lock_guard is a wrapper class that locks a mutex when the object is created and automatically unlocks
it when the object goes out of scope (i.e., when the function ends or an exception is thrown).
*/