#include"Class.hpp"

void print(std::string s)
{
	std::cout << s << std::endl;
}
void print(int x)
{
	std::cout << x << std::endl;
}


Integer operator +(int x, const Integer& ref)
{
	std::cout << "Integer operator +(int x, const Integer& ref)" << std::endl;
	Integer tmp;
	tmp.SetValue(x + ref.GetValue());
	return tmp;
}
std::ostream& operator<<(std::ostream& out, const Integer& ref)
{
	std::cout << "std::ostream &operator<<(std::ostream& out, const Integer& ref)" << std::endl;
	out << ref.GetValue();
	return out;
}
std::istream& operator>>(std::istream& input, Integer& ref)
{
	std::cout << "std::istream& operator>>(std::istream& input, Integer& ref)" << std::endl;
	int x;
	input >> x;
	//ref.SetValue(x);   if it not friend 
	*ref.m_ptr = x;     // because we make this function friend , it can access the private members
	return input;
}
void test_Operator_Overloading(void)
{
	LCD l1;
	std::string msg = "world";
	l1.Set_Text("Hello ");
	/*
	// std::string LCD::operator+(std::string msg)    return string
	std::cout << l1.GetText() << std::endl;       // Hello
	msg = l1 + msg;
	std::cout << msg << std::endl;				  // Hello world
	std::cout << l1.GetText() << std::endl;		  // Hello world
	*/

	//LCD &operator+(std::string msg);           return reference to class
	l1 = l1 + msg;
	std::cout << l1.GetText() << std::endl;	      // Hello world
	l1 = l1 - msg;
	std::cout << l1.GetText() << std::endl;	      // Hello 

	Segment seg1, seg2;
	seg1.Set_Number(7);
	seg2.Set_Number(8);

	seg1.DisplayNumber();
	seg2.DisplayNumber();

	if (seg1 < 10)
	{
		std::cout << "seg1 isless than 10" << std::endl;

	}
	if (seg1 > seg2)
	{
		std::cout << "seg1 is grater than seg2" << std::endl;
	}
	if (seg1 < seg2)
	{
		std::cout << "seg1 is less than seg2" << std::endl;
	}
	if (seg1 == seg2)
	{
		std::cout << "seg1 and seg2 are equal" << std::endl;
	}
	if (seg1 != seg2)
	{
		std::cout << "seg1 and seg2 are not equal" << std::endl;
	}


	seg1.Set_Number(5);
	seg1 += 2;
	seg1.DisplayNumber();			//7
	seg1 -= 2;
	seg1.DisplayNumber();			//5
	seg1 /= 0;
	seg1.DisplayNumber();			//Error can't devide by 0

	seg1 = 20;
	seg1.DisplayNumber();			//20



	seg1(10);						// set number with 10 and display it  

	seg1.Set_Number(5);
	std::cout << ++seg1 << std::endl;       // 6 pre increment
	std::cout << seg1++ << std::endl;		// 6 post increment
	seg1.DisplayNumber();					// 7 


	seg1.Set_Number(5);
	int x = seg1 & 0;
	std::cout << x << std::endl;       //0 

	x = !seg1;
	std::cout << x << std::endl;       //0 


	seg1.Set_Number(0);
	x = !seg1;
	std::cout << x << std::endl;       //1

	seg1.Set_Number(0);
	x = !seg1 << 3;
	std::cout << x << std::endl;       //8


	seg1.Set_Number(10);
	std::cout << seg1 << std::endl;   // 10

	//=========================================================
	std::cout << "==========================" << std::endl;
	Integer n1{ 1 }, n2{ 5 };
	Integer Sum = n1 + n2;		// call overload operator + "Integer::operator+(const Integer& obj)
	print(Sum.GetValue());		// 6 
	Integer Sum1 = n1 + 10; // work because it will be n1.operator + (5)
	//Integer Sum1 = 10 + n2; // doesn't work because it will be 5.operator + object  // must be a function 
	// when we implement the function , it work
	Integer Sum2 = 10 + n2;   // Integer operator +(int x, const Integer& ref)
	print(Sum2.GetValue());	// 10+5 = 15
	std::cout << Sum2 << std::endl; //std::ostream& operator<<(std::ostream & out, const Integer & ref)
	std::cin >> Sum2;	// std::istream& operator>>(std::istream& input, Integer& ref)
	std::cout << Sum2 << std::endl;
	Sum.SetValue(10);
	Integer x1 = ++Sum;
	print(x1.GetValue());	// 11
	Sum.SetValue(10);
	Integer y1 = Sum++;
	print(y1.GetValue());  // 10
	Integer y2(30);
	y2 = y2;
	print(y2.GetValue());  // 30

}