

#include <iostream>
#include <random>
void ProcessRecords(int count)
{
    int errors{};
    std::default_random_engine eng;   // eng: Random number generator.
    std::bernoulli_distribution dist; // dist: A Bernoulli distribution (outputs true or false with equal probability of 0.5).
    for (int i = 0; i < count; i++)
    {
        try
        {
            std::cout << "Processing record # : " << i << " ";
            if (!dist(eng))
            {
                ++errors;
                throw std::runtime_error("Could not process the record"); // Throw exception for failed processing.
            }
            std::cout << std::endl;
        }
        catch (std::runtime_error &ex) // Handle individual record failures.
        {
            std::cout << "[ERROR " << ex.what() << "]" << std::endl;
            if (errors > 4)
            {
                // Create a new exception with a more descriptive message.
                std::runtime_error err("Too many errors. Abandoning operation"); // creat new exception
                ex = err;                                                        // assign the new exception in the ex exception (call be reference)
                throw;                                                           // Re-throw a new exception.
            }
        }
    }
}

int main(int argc, const char **argv)
{
    try
    {
        ProcessRecords(15);
    }
    catch (std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}