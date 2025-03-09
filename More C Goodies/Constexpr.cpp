#include"test.hpp"

constexpr int GetNumber(void)
{
	return 55;
}

constexpr int Add(int x, int y)
{
	return x + y;
}

constexpr int GetMax(int x, int y)
{ 
	if (x > y)
	{
		return x;
	}
	return y;        // in c++17 it is allowed to constexpr function contain more han one line
	//return (x > y) ? x : y;
}
void Constant_expressions(void)
{

	constexpr int x1 = 5;
	int arr1[x1]{ 1,2,3,4, 5};          // allowd becasue the constexpr combuted at compile time 

	// behaves as constexpr function (combuted at compile time)
	constexpr int x2 = GetNumber();
	int arr2[x2]{};

	// behaves as constexpr function
	const int x3 = GetNumber();
	int arr3[x3]{};

	// behaves as normal function(combuted at run time)
	int x4 = GetNumber();

	// behaves as constexpr function
	constexpr int x5 = Add(5, 6);

	// error because x4 is not combuted at compile time 
	//constexpr int x6 = Add(x4, 6);
	const int x7{ 0 };
	constexpr int x8 = Add(x7, 6);			// x7 is combuted at compile time 


	/*
	constexpr expression function rules 
	1. should access and return	literal types only (void ,scailer types(int , float , char ) , reference ,...)
	2. should contain only single line statement that should be return statement
	
	*/
	/*
	const vs constexpr
	• Initialization of a const variable can be deferred until runtime
	• However, a constexpr variable must be initialized at compile time
	• All constexpr variables are const, but not the other way round
	• Use const keyword to indicate the value cannot be modified
	• Use constexpr to create expressions that can be evaluated at compile time
	*/

}

