#include "Account.hpp"


int Account::m_ANGenerator{ 1000 };
Account::Account(const std::string& name, float Balance):m_name(name),m_Balance(Balance)
{
	m_AccNumber = ++m_ANGenerator;
	std::cout << __FUNCTION__ << std::endl;

}

Account::~Account()
{
	std::cout << __FUNCTION__ << std::endl;
}

const std::string Account::GetName(void) const
{
	return m_name;
}

float Account::GetBalance(void) const
{
	return m_Balance;
}

int Account::GetAccountNumber(void) const
{
	return m_AccNumber;
}

void Account::AccumulateInterest()
{
}

void Account::Withdraw(float amount)
{
	if (amount < m_Balance)
	{
		m_Balance -= amount;
	}
	else
	{
		std::cout << "Insufficient Balance" << std::endl;
	}
}

void Account::Deposit(float amount)
{
	m_Balance += amount;
}

float Account::GetInterestRate() const
{
	return 0.0f;
}
