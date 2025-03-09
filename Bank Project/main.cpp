#include"Account.hpp"
#include "Checking.hpp"
#include "Transaction.hpp"
#include"Savings.hpp"

int main(void)
{
	Savings ch("abc", 1000, .05f);
	try
	{
		Transaction(ch);

	}
	catch (const std::exception&ex)
	{
		std::cout << "Exeption : " << ex.what() << std::endl;      
	}
	return 0;
}