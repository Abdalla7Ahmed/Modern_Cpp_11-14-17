#include"Class.hpp"
void print(std::string s);
void print(int x);
void print(float x)
{
	std::cout << x << std::endl;
}
void test_Conversions(void)
{
	/*
	Type Conversions
	• Conversion between types
	• Performed through casts
	• Ordered by compiler (implicit) or user(explicit)
	• Explicit conversion uses casting operators
	• Conversion between
		• basic & basic
		• basic & user-defined
		• user-defined & basic
		• user-defined & user-defined
	*/
	int a(5), b(2);
	float c ;
	c = a / b;
	print(c);			// 2 
	c = (float)a / b;   
	print(c);			// 2.5 
	c =static_cast<float>(a) / b;
	print(c);			// 2.5 
	// why we don't use C cast ?
	int p1;
	char* c1;
	//c1 = &p1;      // error
	c1 =(char *) & p1;      // allowed
	// c1 = static_cast<char*>(&p1);      // error static cast will check first if this conversion is valid or not 
	c1 = reinterpret_cast<char*>(&p1);    // it allowd the conversion between different types 
	
	const int y = 10;
	//int* Y = reinterpret_cast<int*>(&y);	// error
	int* Y = const_cast<int*>(&y);	// error

	//========================================
	Integer a1{ 5 };     // implicit  casting
	Integer a2= 5 ;      // explicit casting 
	// the compiler by default search on the parameterize constructor to do the implicit casting 
	// if we want to make it not allowed , just add explicit on the parameterize constructor 
	// Integer a2= 5 ;  error if explicit exist
	/*
	
	Type Conversion Operator
	operator <type>()
	No arguments 
	No return type
	operator int()
	*/

	int a3 =static_cast<int> (a2);	//Integer::operator int()

	// note that without explicit we can assigne a3 without explicit cast , but we should use it because it will cause a confussion in some code 
	print(a3);		// 5
	print("=========================");
	Number P{ 5 };
	Integer R = static_cast<Integer>(P);       //Number::operator Integer()
	Integer P2{ 10 };

 }