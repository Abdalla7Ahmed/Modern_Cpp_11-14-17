#ifndef CHECKING_HPP_
#define CHECKING_HPP_
#pragma once
#include "Account.hpp"
class Checking :
    public Account
{
    float m_minimumBalance;
public:
    Checking(const std::string& name, float Balance, float m_minimumBalance);
    //using Account::Account;         // Inherite the constructor of Account class
    ~Checking();
    void Withdraw(float amount);
    float Get_minimumBalance()const;
};

#endif