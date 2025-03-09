#include"header.hpp"


int sum(int x, int y)
{
	return x + y;
}

float average(int sum, int number)
{
	return (sum / number);
}
void Auto_test(void)
{
	auto x0 = 20;                       // x0 is int
	auto x1 = 20.5;                     // x1 is double
	auto x3 = 20.5F;                    // x2 is float
	auto x4 = 's';                      // x4 is char
	auto x5 = "hello char ";            // x5 is const char *
	auto x6 = std::string("Hello string");   // x6 is string

	auto a1 = 10;				// int
	auto a2 = 23.5f;		    // float
	auto a3 = 1 + 5;			// int
	auto a4 = a1 + a3;			// int
	auto a5 = a1 + 32.5f;		// float
	const auto a6 = 10;			// const int
	const int a7 = 20;
	auto a8 = a7;				// int
	const auto a9 = a7;			// const int

	auto& b1 = a1;				// int
	auto& b2 = a6;				// const int because a6 is const int

	auto ptr1 = &a1;			// int *ptr
	auto ptr2 = &a6;			// const int *ptr2
	// auto with function return type
	auto y =  sum(5, 6);		// y is int
	auto avg = average(562, 5); // avg is float

	// initializer list 
	auto list = { 1,2,3,4,5 };   // initializer_list copy initialization must here
	//auto list2{ 1,2,3,4,5 };	 // error
	auto var{ 1 };			 // var is int type

}