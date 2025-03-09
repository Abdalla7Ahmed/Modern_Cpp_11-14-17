#include "Savings.hpp"

Savings::Savings(const std::string& name, float Balance, float rate):Account(name,Balance),m_rate(rate)
{
	std::cout << __FUNCTION__ << std::endl;

}

Savings::~Savings()
{
	std::cout << __FUNCTION__ << std::endl;
}

float Savings::GetInterestRate() const
{
	return m_rate;
}

void Savings::AccumulateInterest()
{
	m_Balance += (m_Balance * m_rate);
}
