#include"Class.hpp"
#include<memory>

void Print(std::unique_ptr<Integer> ptr)
{
	std::cout<<"void Print(std::unique_ptr<Integer> ptr)"<< std::endl;
	std::cout << ptr->GetValue() << std::endl;
}
void Print(std::shared_ptr<Integer> ptr)
{
	std::cout << "void Print(std::shared_ptr<Integer> ptr)" << std::endl;

	std::cout << ptr->GetValue() << std::endl;
}
void test_Smart_Pointer(void)
{
	// the first smart pointer is unique pointer

	std::unique_ptr<Integer> p(new Integer); // unique pointer
	p->SetValue(10);          // or (*p)SetValue(10);
	std::cout << (*p).GetValue() << std::endl;
	// the smart pointer call the destrctor to delete the pointer 

	// from it's name it is a unique so we can't copy this pointer to another 
	//std::unique_ptr<Integer> p2(p);   //error
	//Print(p);		// error because we copy the pointer here
	std::unique_ptr<Integer> p2(std::move(p));
	std::cout << p2->GetValue() << std::endl;		// 10 
	//Print(std::move(p));          // run time error (crash) because we move the pointer above 
	Print(std::move(p2));

	// std::cout << p2->GetValue() << std::endl;		// run time error (crash) 


	// the second smart pointer is shared pointer
	std::shared_ptr<Integer> R(new Integer); // shared pointer

	R->SetValue(30);          // or (*R)SetValue(10);
	std::cout << (*R).GetValue() << std::endl;
	Print(R);		     // valid			
	Print(std::move(R)); // valid

	std::shared_ptr<Integer> R1(new Integer);
	std::shared_ptr<Integer> R2(R1);    // valid
	R2->SetValue(255);
	std::cout << R2->GetValue() << std::endl;     //255
	std::cout << R1<< std::endl;     
	std::cout << R2 << std::endl;    //R1 and R2 have the same address

}