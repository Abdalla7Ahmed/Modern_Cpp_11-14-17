#include"header.hpp"

void Pointer_test(void)
{
	/*
	
	Pointer
	• Points to another type
	• Holds the memory address of another variable
	• Used for indirect access to other variables
	• Need not be initialized during declaration
	• Declared with * operator int * ptr; int *p1, *p2, *p3, p4;      p4 is not a pointer 
	*/

	int x{ 10 };
	int* ptr1 = &x;
	//int* ptr2;		//error
	//float* ptr3 = &x;   // error initializing cann't convert from int to float 
	void* ptr4 = &x;     // wild pointer 

	std::cout << " x = " << x << std::endl;
	std::cout << " address of x  = " << &x << std::endl;
	std::cout << " address of x  = " << ptr1 << std::endl;
	std::cout << " address of x  = " << ptr4 << std::endl;

	/*
	Null Pointer
	• NULL is a macro in C & pre-C++11
	• It is defined as 0 in most compilers
	• Used to initialize pointer types
	• C++11 introduced a new type of null called nullptr
	• This is type safe and better than NULL macro
	Always use nullptr to initialize a pointer, instead of NULL macro
	
	*/

	int* ptr5 = nullptr;
	//std::cout << *ptr5 << std::endl;    //crash --> Exception thrown: read access violation.
	//*ptr5 = 10;						  //crash --> write access violation 
	int* ptr6 = NULL;
	//std::cout << *ptr6 << std::endl;    //crash --> Exception thrown: read access violation.
	//*ptr6 = 10;                         //crash --> write access violation 
	 
}