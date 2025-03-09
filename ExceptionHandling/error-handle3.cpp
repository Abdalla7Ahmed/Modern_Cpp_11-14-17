#include <iostream>

int main()
{

    // nesting of try/catch
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            std::cout << "Handle Partially " << std::endl;
            throw; // Re-throwing an exception
        }
    }
    catch (int n)
    {
        std::cout << "Handle remaining " << std::endl;
    }
    return 0;
}