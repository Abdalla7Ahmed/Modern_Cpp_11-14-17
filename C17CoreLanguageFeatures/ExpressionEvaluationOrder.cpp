#include <iostream>

class EvaluationOrder
{
public:
    EvaluationOrder &First(int)
    {
        std::cout << __FUNCTION__ << std::endl;
        return *this;
    }
    EvaluationOrder &Second(int)
    {
        std::cout << __FUNCTION__ << std::endl;
        return *this;
    }
};
int FirstSubExpression(int)
{
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}
int SecondSubExpression(int)
{
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}
int main()
{
    EvaluationOrder eo;
    eo.First(FirstSubExpression(0)).Second(SecondSubExpression(0));
}

/*
Before C++17, function arguments and sub-expressions could be evaluated in any order,
and even interleaved, leading to unpredictable behavior.
However, C++17 introduced a stricter evaluation order to prevent such issues.
*/