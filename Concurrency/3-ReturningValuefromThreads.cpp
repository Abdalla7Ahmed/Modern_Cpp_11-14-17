#include <iostream>
#include <thread>
#include <vector>
#include <future>
int Add(int x, int y)
{
    return x + y;
}

int Square(int x)
{
    return x * x;
}

int Compute(const std::vector<int> &Vector)
{
    int Sum{};
    for (const auto &V : Vector)
    {
        Sum += V;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
    }
    return Sum;
}
int main(int argc, char const *argv[])
{
    // std::packaged_task wraps a function and provides a std::future to obtain its result.
    std::packaged_task<int(int, int)> TaskAdd{Add};
    std::future<int> FtAdd = TaskAdd.get_future();
    TaskAdd(10, 20);
    auto result = FtAdd.get();
    std::cout << result << std::endl;

    std::packaged_task<int(int)> TaskSquare{Square};
    std::future<int> FtSquare = TaskSquare.get_future();
    TaskSquare(10);
    auto result2 = FtSquare.get();
    std::cout << result2 << std::endl;

    std::vector<int> data{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // std::packaged_task wrapper around the Compute function.
    // It binds the function and makes it possible to run it asynchronously.
    // It also allows us to retrieve the return value asynchronously via std::future.
    std::packaged_task<int(const std::vector<int>)> TaskCompute{Compute};
    // creates a std::future<int>, which allows us to obtain the result once the computation is finished.
    std::future<int> FtCompute = TaskCompute.get_future();

    std::thread ThreadCompute{std::move(TaskCompute), data};
    std::cout << "Start thread" << std::endl;
    // FtCompute.get(); waits for the Compute function to finish and retrieves the computed sum.
    // It will block the main thread until Compute is done.
    auto Sum = FtCompute.get();
    std::cout << Sum << std::endl;
    std::cout << "End of main" << std::endl;
    if (ThreadCompute.joinable())
    {
        ThreadCompute.join();
    }
    return 0;
}
