#include <iostream>
#include <future>
#include <list>
#include <thread>
int Operate(std::promise<int> &data)
{
    try
    {
        auto f = data.get_future();
        std::cout << "[Task] waiting for count " << std::endl;
        auto count = f.get();
        std::cout << "[Task] count aquired " << std::endl;
        int Sum{};
        for (int i = 0; i < count; i++)
        {
            Sum += i;
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        // we can throw an exception from the task also
        // throw std::runtime_error("Exception from the task");
        return Sum;
    }
    catch (std::exception &e)
    {
        std::cerr << "[Task] Exception " << e.what() << '\n';
    }
}

int main(int argc, char const *argv[])
{
    std::promise<int> data;
    std::future<int> result = std::async(std::launch::async, Operate, std::ref(data));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "[Main] Setting the data in promise" << std::endl;

    try
    {
        // throw std::runtime_error("Data not available");
        data.set_value(10);
        if (result.valid())
        {
            auto sum = result.get();
            std::cout << "Sum : " << sum << std::endl;
        }
    }
    catch (std::exception &ex)
    {
        data.set_exception(std::make_exception_ptr(std::runtime_error(ex.what())));
        // data.set_exception(std::make_exception_ptr(ex));
    }

    return 0;
}

/*
std::promise is a synchronization primitive in C++ that provides a way to set a value (or an exception)
that a std::future will later retrieve. It enables communication between threads where one thread
sets a value, and another retrieves it asynchronously.
*/