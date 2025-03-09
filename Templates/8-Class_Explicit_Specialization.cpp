#include <iostream>
#include <vector>
template <typename T>
class PrettyPrinter
{
private:
    T *m_data;

public:
    PrettyPrinter(T *data) : m_data(data) {}
    void print(void)
    {
        std::cout << "{" << *m_data << "}" << std::endl;
    }

    T *GetData(void)
    {
        return m_data;
    }
    ~PrettyPrinter() = default;
};

// Explicit specialization for const char *
template <>
class PrettyPrinter<const char *>
{
private:
    const char *m_data;

public:
    PrettyPrinter(const char *data) : m_data(data)
    {
    }
    void print(void)
    {

        std::cout << "{" << m_data << "}" << std::endl;
    }

    const char *GetData(void)
    {
        return m_data;
    }
    ~PrettyPrinter() = default;
};

// Explicit specialization for vector
template <>
void PrettyPrinter<std::vector<int>>::print(void)
{
    std::cout << "{";
    for (const auto element : *m_data)
    {
        std::cout << element;
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char const *argv[])
{
    int x = 5;
    float y = 10;
    PrettyPrinter<int> p1(&x);
    p1.print();
    PrettyPrinter<float> p2(&y);
    p2.print();

    std::string str{"ABCD"};
    PrettyPrinter<std::string> p3(&str);
    p3.print();

    const char *str2{"EFGH"};
    PrettyPrinter<const char *> p4(str2);
    auto string = p4.GetData();
    p4.print();

    std::vector<int> v{1, 2, 3, 4, 5};
    PrettyPrinter<std::vector<int>> pv(&v);
    pv.print();
    return 0;
}
