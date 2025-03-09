#include<iostream>
// this file contain the max and min values of any integer type(int , char , signed int , .......)
#include<limits.h>
// this file contain the max and min values of floating data type
#include<float.h>


#include"header.hpp"

int main(void)
{
	using namespace std;
	//int i1;          
	//cout << i1;		// error because i1 is not initialized
	int arr[5];     // not error will take garbage  value
	int i{ 1 };
	int arr1[5]{ 1,2,3,4,5 };
	char a = 'a';
	bool state = true;
	float f = 125.6f;
	double d = 1563.2154;
	std::cout << "minmum number of char is " << _I8_MIN << std::endl;
	// input output 
	char buffer[50];
	cout << "Enter your name ";
	cin >> buffer;
	cout << "your name is " << buffer << endl;
	// the problem with cin it can read until space only 
 	// we can use a funcion with a specific diameter
	cin.getline(buffer, 50, '\n');
	cout << "your name is " << buffer << endl;
	int x, y;
	cout << "enter two values " << endl;
	cin >> x >> y;
	int result = add(x, y);
	cout << "x + y is " << result << endl;

	print("hello from print function ");
	test_initialization();
	Pointer_test();
	Reference_test();
	Const_test();
	Auto_test();
	Ranged_Based_For_test();
	Function_Overload_test();
	Function_Default_test();
	Inline_Function_test();
	Function_Pointers_test();
	namespace_test();
}