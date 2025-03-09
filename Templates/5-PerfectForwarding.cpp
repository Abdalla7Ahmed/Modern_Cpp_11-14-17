#include <iostream>
#include "Integer.h"

/*
std::forward is a utility in C++ that is used for perfect forwarding.
It allows you to forward arguments while preserving their value category
(whether they are lvalues or rvalues).
This is particularly useful in template functions where you want to
forward arguments to another function without unintentionally converting rvalues to lvalues.
*/
class Employee
{
private:
    std::string m_name;
    Integer m_Id;

public:
    template <typename T1, typename T2>
    Employee(T1 &&name, T2 &&Id)
        : m_name{std::forward<T1>(name)},
          m_Id{std::forward<T2>(Id)}
    {
        std::cout << "Employee(std::string &&name, Integer &&Id)" << std::endl;
    }
};

template <typename T1, typename T2>
Employee *CreateEmployee(T1 &&a, T2 &&b)
{
    return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main(int argc, char const *argv[])
{
    int value = 10;
    // Employee emp{"Ali", value};
    auto emp = CreateEmployee("Ali", 100);
    return 0;
}
