#ifndef _ACCOUNT_HPP__
#define _ACCOUNT_HPP__
#pragma once
#include<iostream>
class Account
{
public:
	Account(const std::string& name, float Balance);
	virtual ~Account();
	const std::string GetName(void)const;
	float GetBalance(void)const;
	int GetAccountNumber(void)const;
	void Deposit(float amount);
	virtual void AccumulateInterest();
	virtual void Withdraw(float amount);
	virtual float GetInterestRate() const;
private:
	std::string m_name{};
	int m_AccNumber;
	static int m_ANGenerator;
protected:
	float m_Balance;

};

#endif