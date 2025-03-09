#include"header.hpp"


void wrong_swap(int, int);
void Pointer_swap(int*, int*);
void Reference_swap(int&, int&);
void print1(int*);
void print2(int&);

void Reference_test(void)
{
	/*

	Reference Type
	• Defines an alternative name for a variable (an alias)
	• It is created with the & operator during declaration
	• Always needs an initializer (called referent)
	• The referent should be a variable
	• It is bound to its referent
	• It can be used to modify a variable indirectly (like a pointer)
	• A reference is NOT a new variable; it is just another name
	*/

	int x = 10;
	int& ref = x;
	std::cout << "x = " << x << std::endl;		//10
	std::cout << "ref = " << ref << std::endl;  //10
	std::cout << "&x = " << &x << std::endl;    // address
	std::cout << "&ref = " << &ref << std::endl; // same address of x
	x = 20;
	std::cout << "x = " << x << std::endl;		//20
	std::cout << "ref = " << ref << std::endl;  //20
	ref = 30;
	std::cout << "x = " << x << std::endl;		//30
	std::cout << "ref = " << ref << std::endl;  //30

	int y = 55;
	ref = y;   // ref not reference to y but will take it's value
	std::cout << "x = " << x << std::endl;		//55
	std::cout << "ref = " << ref << std::endl;  //55
	//int& ref2;		// error reference must be initialized
	// =============================================
	/*
	Reference														Vs			Pointer
	• Always needs an initializer												• Initializer is optional
	• Initializer should be l-value												• Initializer need not be Ivalue
	• Cannot be nullptr															• Can be nullptr
	• Bound to its referent														• Can point to other variables
	• No storage required, so has same address as that of referent				• Has its own storage, so will have a different address
	• Dereference not required													• Requires dereference operator to access the value

	*/

	int a{ 5 }, b{ 10 };
	wrong_swap(a, b);
	std::cout << "a = " << a << " and b = " << b << std::endl;     // a = 5 and b = 10
	Pointer_swap(&a, &b);
	std::cout << "a = " << a << " and b = " << b << std::endl;     // a = 10 and b = 5
	Reference_swap(a, b);
	std::cout << " swap again" << std::endl;
	std::cout << "a = " << a << " and b = " << b << std::endl;     // a = 5 and b = 10
	int h = 20;
	print1(&h);
	print2(h);
	//print1(nullptr);       // crash  error read access violation
	//print2(nullptr);      // compiler error cann't convert argument 1 from nullptr to int
	
	const int& ref5 = 5;        // this is the only way to make  referent not should be a variabl
}

void wrong_swap(int x, int y)
{
	std::cout << __FUNCTION__ << std::endl;
	int tmp = x;
	x = y;
	y = tmp;
}
void Pointer_swap(int* x,int* y)
{
	std::cout << __FUNCTION__ << std::endl;
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
void Reference_swap(int &x, int &y)
{
	std::cout << __FUNCTION__ << std::endl;
	int tmp = x;
	x = y;
	y = tmp;
}

void print1(int* ptr)
{
	// to avoid runtime error
	if(ptr !=nullptr)
		std::cout << *ptr << std::endl;
}
void print2(int &ref)
{
	//if(ref !=nullptr) compiler error != no conversion from nullptr to int
	std::cout << ref << std::endl;

}