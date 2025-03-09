#include"Account.hpp"
#include"Checking.hpp"
#include<typeinfo>
void Transaction(Account* Account)
{
	
	std::cout << "Transaction start " << std::endl;
	std::cout << "Initial Balance is " << Account->GetBalance() << std::endl;
	Account->Deposit(100);
	Account->AccumulateInterest();
	/*if (typeid(*Account) == typeid(Checking))
	{
		Checking* ch = static_cast<Checking*>(Account);
		std::cout << "minimum balance is " << ch->Get_minimumBalance() << std::endl;
	}*/
	Checking* ch = dynamic_cast<Checking*>(Account);
	if (ch != nullptr)
	{
		std::cout << "minimum balance is " << ch->Get_minimumBalance() << std::endl;

	}

	Account->Withdraw(1000);
	std::cout << "Interest rate " << Account->GetInterestRate() << std::endl;
	std::cout << "final Balance is " << Account->GetBalance() << std::endl;

}
void Transaction(Account& Account)
{

	std::cout << "Transaction start " << std::endl;
	std::cout << "Initial Balance is " << Account.GetBalance() << std::endl;
	Account.Deposit(100);
	Account.AccumulateInterest();
	/*if (typeid(*Account) == typeid(Checking))
	{
		Checking* ch = static_cast<Checking*>(Account);
		std::cout << "minimum balance is " << ch->Get_minimumBalance() << std::endl;
	}*/
	Checking& ch = dynamic_cast<Checking&>(Account);
	//reference can't be compair with null , instade it will be runtime error if it hold nothing 
	std::cout << "minimum balance is " << ch.Get_minimumBalance() << std::endl;

	Account.Withdraw(1000);
	std::cout << "Interest rate " << Account.GetInterestRate() << std::endl;
	std::cout << "final Balance is " << Account.GetBalance() << std::endl;

}
