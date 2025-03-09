#include "Checking.hpp"

Checking::Checking(const std::string& name, float Balance,float m_minimumBalance) :Account(name, Balance), m_minimumBalance(m_minimumBalance)
{
}

Checking::~Checking()
{
	std::cout << __FUNCTION__ << std::endl;

}

void Checking::Withdraw(float amount)
{
	if ((m_Balance - amount) > m_minimumBalance)
	{
		Account::Withdraw(amount);
	}
	else
	{
		std::cout << "Invalid amount" << std::endl;
	}

}

float Checking::Get_minimumBalance() const
{
	return m_minimumBalance;
}
