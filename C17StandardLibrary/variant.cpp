#include <iostream>
#include <variant>

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

struct Visitor
{
    void operator()(const std::string &str) const
    {
        std::cout << "string: " << str << std::endl;
    }
    void operator()(const int &Int) const
    {
        std::cout << "Int: " << Int << std::endl;
    }
    void operator()(const Number &Num) const
    {
        std::cout << "Number: " << Num << std::endl;
    }
};

struct VisitorModify
{
    void operator()(std::string &str) const
    {
        str += " modified string";
    }
    void operator()(int &Int) const
    {
        Int += 100;
    }
    void operator()(Number &Num) const
    {
        Num += 50;
    }
};

#define initilization
int main()
{
#ifdef start

    std::variant<int, std::string> myVariant{"Abdallah"};

    std::cout << std::get<std::string>(myVariant) << '\n';
    std::cout << std::get<1>(myVariant) << std::endl; // by index
    // or we can get the active index
    auto activeIndex = myVariant.index();
    std::cout << activeIndex << std::endl;

    // if we pass the inactive member or inactive index--> it will throw wrong index for variant exception
    // if we pass non existing type or non existing index --> compiler error
    try
    {
        // the active member is the string not int
        auto t1 = std::get<int>(myVariant);
        std::cout << t1 << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n'; // Exception: std::get: wrong index for variant
    }

    // we can use std::get_if-- > it return pointer to the active member;
    // auto i = std::get_if<std::string>(&myVariant);
    auto i = std::get_if<1>(&myVariant);
    if (i == nullptr)
    {
        // if we pass the inactive member or inactive index--> it will return nullptr and doesn't throw an exception
        std::cout << "In active" << std::endl;
    }
    else
    {
        std::cout << *i << std::endl;
    }
    std::variant<int, std::string, Number> V{Number{10}};
    /*
    Number::Number(int)
    Number::Number(Number&&)
    Number::~Number()
    Number::~Number()
    */

    // std::variant<int, std::string, Number> V2{10};
    V2 = Number{10};
    //  or
    try
    {
        std::get<int>(V2) = 100;
        // note that , this will throw an exception if there is no instance created before , because it return the referance to the active member
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    V2.emplace<Number>(100);
#endif
    //    we can use the visitor
    std::variant<int, std::string, Number> V3{10};
    std::visit(VisitorModify{}, V3);
    std::visit(Visitor{}, V3);
    V3 = "Abdallah";
    std::visit(VisitorModify{}, V3);
    std::visit(Visitor{}, V3);
    V3 = Number{100};
    std::visit(VisitorModify{}, V3);
    std::visit(Visitor{}, V3);
    // we can use the lambda expression
    auto lambdavisitor = [](auto &x)
    {
        using T = std::decay_t<decltype(x)>;
        if constexpr (std::is_same_v<T, int>)
        {
            std::cout << "Int:" << x << std::endl;
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            std::cout << "string:" << x << std::endl;
        }
        else if constexpr (std::is_same_v<T, Number>)
        {
            std::cout << "Number:" << x << std::endl;
        }
    };

    std::variant<int, std::string, Number> V4{10};
    std::visit(VisitorModify{}, V4);
    std::visit(lambdavisitor, V4);
    V3 = "Abdallah";
    std::visit(VisitorModify{}, V4);
    std::visit(lambdavisitor, V4);
    V3 = Number{100};
    std::visit(VisitorModify{}, V4);
    std::visit(lambdavisitor, V4);
    return 0;
}
