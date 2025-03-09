#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
class Employee
{
    std::string m_Name;
    int m_Id;

public:
    Employee(const std::string &n, int id) : m_Name(n), m_Id(id)
    {
    }
    const std::string &GetName() const
    {
        return m_Name;
    }
    int GetId() const
    {
        return m_Id;
    }
};

// Custom hash function
struct EmployeeHash
{
    size_t operator()(const Employee &emp) const
    {
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};
// Custom function object for equality
struct EmpEquality
{
    bool operator()(const Employee &e1, const Employee e2) const
    {
        return e1.GetId() == e2.GetId();
    }
};

int main()
{
    std::hash<std::string> h;
    // Hash is computed by the function object
    std::cout << "Hash:" << h("Hello") << std::endl;

    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee("Umar", 123));
    coll.insert(Employee("Bob", 678));
    coll.insert(Employee("Joey", 612));

    for (const auto &x : coll)
    {
        std::cout << x.GetId() << ":" << x.GetName() << std::endl;
    }
    return 0;
}