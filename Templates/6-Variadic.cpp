#include <iostream>

// base case function to stop the recursion
void print()
{
    std::cout << std::endl;
}
// template parameter pack
template <typename T, typename... params>
// Function parameter pack
void print(T &&a, params &&...args)
{
    std::cout << a;
    if (sizeof...(args) != 0)
    {
        std::cout << ", ";
    }
    print(std::forward<params>(args)...);
}

int main(int argc, const char **argv)
{

    print(1, 2.5f, 3.45, 'A', "Abdallah");
    return 0;
}

/*
print(1, 2.5f, 3.45, 'A', "Abdallah");  // a = 1 , args = 2.5f,3.45,'A',"Abdallah"
print(2.5f, 3.45, 'A', "Abdallah");     // a = 2.5f , args = 3.45,'A',"Abdallah"
print(3.45, 'A', "Abdallah");           // a = 3.45 , args = 'A',"Abdallah"
print('A', "Abdallah");                 // a = 'A' , args = "Abdallah"
print("Abdallah");                      // a = "Abdallah" , args is empty
print();                                // a and args are empty so it will invoke the print function
*/