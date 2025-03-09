#ifndef SAVINGS_HPP_
#define SAVINGS_HPP_
#pragma once
#include "Account.hpp"
class Savings : public Account
{
private:
    float m_rate;
public:
    Savings(const std::string& name, float Balance,float rate);
    ~Savings();
    float GetInterestRate() const;
    void AccumulateInterest();
};
#endif

