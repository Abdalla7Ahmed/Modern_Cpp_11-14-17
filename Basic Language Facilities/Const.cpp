#include"header.hpp"
void print(int*);
void const_val(const int*);
void const_val_and_pointer(const int* const ptr);
void const_print(const int&);

void Const_test()
{
	/*
	const Qualifier
	• Creates a variable that is constant
	• Value cannot be modified
	• Attempt to modify will cause compilation error
	• Qualified to a declaration, but always needs an initializer
	• Replaces C macros
	• Commonly used with references
	• const <type> <variable> { initializer} const float PI {3.141f };
	*/

	float radius = 0;
	std::cin >> radius;
	const float PI = 3.14159f; 
	float area = PI * radius * radius;
	float circumference = PI * 2 * radius;
	std::cout << "Area is: " << area <<std::endl;
	std::cout << "Circumference is : " << circumference << std::endl;


	// const int yy;	 // compiler error const must be initialized if not extern
	const int SIZE{ 512 };
	//int* ptr = &SIZE; // error can't convert from const to int
	const int* ptr = &SIZE;
	// *ptr = 50;						// error you can't assigne to variable that is const
	int x;
	ptr = &x;        // alloed
	//*ptr = 20;		// not allowed ptr is point to const data
	const int VAR=10;
	const int* const ptr2 = &VAR;    // const pointer point to const variable
	//ptr2 = &x;			// not allowed
	//*ptr2 = 20;			// not allowed 


	int y = 10;
	print(&y);             // 10
	std::cout << "y after calling " << y << std::endl;      //y after calling 200

	const int& ref5 = 5;       // allowd because constant 
	int u = 10;
	const_print(u);
	const_print(20);       //  allowd because constant


}
void print(int* ptr)
{
	std::cout << *ptr << std::endl;
	*ptr = 200;
}

void const_val(const int* ptr)
{
	std::cout << *ptr << std::endl;
	//*ptr = 200;            // error
	int y = 20;
	ptr = &y; // alloed 
}


void const_val_and_pointer(const int*const ptr)
{
	std::cout << *ptr << std::endl;
	//*ptr = 200;            // error
	int y = 20;
	//ptr = &y;	//error
}

void const_print(const int&ref)
{
	std::cout << ref << std::endl;
	// ref = 50;          error 

}