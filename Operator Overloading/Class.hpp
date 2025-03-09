#ifndef CLASS_HPP_
#define CLASS_HPP_

#pragma once

#include<iostream>


class LCD
{
public:
	LCD() = default;
	~LCD() = default;
	void Set_Text(std::string text);
	std::string GetText(void);
	//std::string operator+(std::string msg);
	LCD &operator+(std::string msg);
	LCD& operator-(std::string msg);
private:
	std::string text;
};

class Segment
{
public:
	Segment();
	~Segment();
	void Set_Number(int number);
	int Get_Number(void);
	void DisplayNumber(void);
	bool operator < (int n);
	bool operator> (int n);
	bool operator ==(int n);
	bool operator !=(int n);
	bool operator < (const Segment& tmp);
	bool operator> (const Segment& tmp);
	bool operator ==(const Segment& tmp);
	bool operator !=(const Segment& tmp);
	Segment& operator +=(int n);
	Segment& operator -=(int n);
	Segment& operator /=(int n);
	Segment& operator *=(int n);
	Segment& operator=(int n);
	void operator()(int x); //functor  can take any number of parameters or not 
	int operator++();		// pre increment
	int operator--();		// pre Decrement
	int operator++(int);    // post increment
	int operator--(int);    //post Decrement
	int operator&(int x);
	int operator|(int x); 
	int operator!();
	int operator<<(int x);
	int operator>>(int x);
	friend std::ostream& operator<<(std::ostream& out, const Segment& tmp);   // because cout will call the operator of ostream not this class , so to be able to access the private members we make it friend
private:
	int m_number;
};

/*

				Operator Overloading
• Custom implementation for primitive operators
• Allows usage of user-defined objects in mathematical expressions
• Overloaded as functions but provide a convenient notation
• Implemented as member or global functions
• Require usage of the operator keyword
				<ret> operator <#> (<arguments>)
• As global functions, require same no. of arguments as the operands
• As member functions, one operand is passed as argument through this pointer
• binary operator will require only one explicit argument
• unary operator will not require any explict argument
• Integer operator +(const Integer &, const Integer &) --> Global Function
• Integer Integer::operator +(const Integer &)   --> MemberFunction
*/

/*
Rules
• Associativity, precedence & arity (operand count) does not change
• Operator functions should be non-static
• except for new & delete
• One argument should be user defined type
• Global overload if first operand is primitive type
• Not all operators can be overloaded
(.),(?:),(*),(sizeof)	
• Cannot define new operators
• Overloaded for conventional behaviour only

*/


class Integer
{
public:
	// default constructor
	Integer();
	// parametarize constructor
	Integer(int value);
	// copy constructor
	Integer(const Integer& obj);
	// Move constructor
	Integer(Integer&& obj);
	//copy assignment constructor
	Integer& operator =(const Integer& obj);
	//move assignment constructor
	Integer& operator =(Integer&& obj);
	Integer& operator +(const Integer& obj);
	Integer& operator++();		// pre increment
	Integer operator++(int);    // post increment
	explicit operator int();
	friend std::istream& operator>>(std::istream& input, Integer& ref);





	int GetValue(void)const;
	void SetValue(int value);

	// Destructor
	~Integer();

private:
	int* m_ptr;

};

class Number
{
public:
	Number();
	~Number();
	Number(const Integer& ref);
	explicit operator Integer();

private:
	Integer m_integer;
};




void test_Operator_Overloading(void);
void test_Smart_Pointer(void);
void test_Conversions(void);

#endif