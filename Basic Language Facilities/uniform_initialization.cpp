#include"header.hpp"



int global;
void test_initialization(void)
{
	// uniform initialization
	/*
	in C++98 provides different types to initialize types
	scalar types can be initialize with = or ()
	array type can be initialize with {}
	in C++11 introduce the uniform initialization (we can initialize any type with {} or () )

	*/
	int local{};
	std::cout <<"the default value of global variables is " << global << std::endl;
	//int a1;	// uninitialized var
	int a2 = 0;		// copy initialization
	int a3(5);	  // direct initialization
	std::string s1;
	std::string s2("this is string"); // direct initialization

	//char c1[8];// uninitialized 
	char c2[8] = { 'a' }; // copy initialization
	char c3[8] = {"hello" }; // copy initialization
	char c4[8] = "hello"; // copy initialization
	char c5[8] = {'a','b','c'}; // aggregate initialization , // copy initialization.
	//std::cout << "erre" << std::endl;


	// uniform initialization
	int b1{};	//initialized with 0
	int b2{ 5 }; // direct initialization
	//int b3();	// warning not used because b may be declaration of function (most vexing parse)
	int b3(0);  // zero is must 
	int b4 = 0;
	char b5[8]{ 'a','b','c' };
	char b6[8]{ "abc" };
	int* p1 = new int{};
	char* p2 = new char[8] {};      // 8 bytes with values 0 
	char* p3 = new char[8] {"abcd"};

	std::string str1 = "hello"; // call the default constructor and then initializad with hello
	std::string str2{ "Hello" }; // not call the default constructor

	float f = 12.5;
	//int h{ f };	// error narrowing conversions
	int h(f);		
	std::cout << h << std::endl;       // 12 


	/*
	========================
	1. default initialization -->  T obj;
	2. value initialization   -->  T obj{v} ;
	3. Dircet initialization  -->  T obj(v) ;
	4. copy initialization    -->  T obj = v ;
	*/

	/*
		============ advantages of uniform initialization ============
		1. it forces initialization
		2. dircet initialization is allowed with array
		3. prevents narrowing conversions
		4. uniform syntax of all types 
	*/
}