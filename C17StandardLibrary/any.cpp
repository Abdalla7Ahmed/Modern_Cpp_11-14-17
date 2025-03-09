#include <iostream>
#include <any>
struct Number
{
    int m_Num{};
    Number(int num) : m_Num{num}
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Number()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    ~Number()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Number(const Number &other)
    {
        m_Num = other.m_Num;

        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }

    Number(Number &&other) noexcept
    {
        m_Num = other.m_Num;
        other.m_Num = 0;
        std::cout << __PRETTY_FUNCTION__ << std::endl;
    }
    Number operator+=(int other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        m_Num += other;
        return *this;
    }
    Number &operator=(const Number &other)
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (this == &other)
        {
            return *this;
        }
        m_Num = other.m_Num;

        return *this;
    }

    Number &operator=(Number &&other) noexcept
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (this == &other)
            return *this;
        m_Num = other.m_Num;
        other.m_Num = 0;

        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, const Number &n)
    {
        return out << n.m_Num;
    }
};
void basic(void)
{
    std::any value = 42;
    std::cout << std::any_cast<int>(value) << '\n';
    try
    {
        std::cout << std::any_cast<std::string>(value) << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n'; // bad any_cast
    }
    value.reset();

    // value = "Abdallah"; // it will be const char * not std::string
    value = std::string("Abdallah");
    if (value.has_value())
    {
        std::cout << "has value" << std::endl;
        // std::cout << typeid(value).name() << std::endl;
        if (value.type() == typeid(int))
        {
            std::cout << std::any_cast<int>(value) << '\n';
        }
        else if (value.type() == typeid(std::string))
        {
            std::cout << std::any_cast<std::string>(value) << '\n';
        }
    }
    value.reset();
}
int main()
{
    // std::any number{Number{10}};
    auto n1 = std::make_any<Number>(10);
    std::cout << std::any_cast<Number>(n1) << std::endl;
    n1.reset();
    n1 = 100;
    std::cout << std::any_cast<int>(n1) << std::endl;
    // std::any_cast can return referance or pointer
    auto &n2 = std::any_cast<int &>(n1); // referance
    n2 = 150;
    std::cout << std::any_cast<int>(n1) << std::endl; // 150

    auto p = std::any_cast<int>(&n1); // pointer
    *p = 200;
    std::cout << std::any_cast<int>(n1) << std::endl; // 200
    return 0;
}
