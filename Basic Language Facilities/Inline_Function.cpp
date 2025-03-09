#include"header.hpp"


int retsum(int x, int y)
	{
	return x + y;
}
void Inline_Function_test(void)
{
	auto summation = retsum(5, 6);
	std::cout << summation << std::endl;

	/*
	Inline Function
	• A function that is marked with inline keyword
	• Such functions are defined in a header file
	• Requests the compiler to replace the call with the function body
	• The overhead of the function call is avoided
	• Stack memory for arguments not required
	• No need to save the return address
	• May improve the performance of the code
	• inline void Function(arguments){
				//Implementation
	}
	*/

	/*
	Points
	• Only a request to the compiler
	• Certain functions may not be inlined
		• large functions
		• functions having too many conditional statements
		• recursive functions
		• functions invoked through pointers
		• etc
	• Different compilers have different rules
	• Modern compilers may automatically inline even non-inline functions
	• Excessive inlining may increase binary size	
	*/

	/*
	Macros Vs Inline Functions
	Macros
		• Works through text substitution
		• Error prone due to substitution nature
		• Does not have an address
		• Difficult to use with multiple lines of code
		• Cannot be used for member functions of a class
	Inline Functions
		• The call is replaced with body
		• Safe to use as it has function semantics
		• Has an address
		• Can have multiple lines of code
		• Class member functions can be inline
	*/


}
