#include"header.hpp"

void AddTowInteger(int x, int y = 10);
void Function_Default_test(void)
{

	AddTowInteger(5, 6);       // 11
	AddTowInteger(5);		   // 15            default of the second argument is 10

	/*
	• the default can only write in the declaration of the function not defination
	• it is not allowed to use any parameters without default value after the default parameter 
	• AddTowInteger(int y=10 , int x = 50 , int z)              // error
	*/
}

void AddTowInteger(int x, int y )
{
	std::cout << "x + y = " << x + y << std::endl;
}