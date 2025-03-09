#pragma once
#include<iostream>

class Move_semantics
{
public:
	Move_semantics();
	~Move_semantics();
	Move_semantics(int value);
	Move_semantics(const Move_semantics& ref);
	Move_semantics(Move_semantics&& ref);
	void print_Message(void);
	void Set_value(int value);
	int Get_Value(void);
	
private:
	int* m_ptr;
	int value;

};

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
	Integer& operator =(const  Integer& obj);
	//move assignment constructor
	Integer& operator =(Integer&& obj);
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
	//the compiler will automatically synthesize the 5 functions foe us if we don't implement any function Rule 5
	Number(int value) :m_value(value)
	{

	}
	Number() = default;
	Number(Number&& obj) = default;
	Number(const Number& obj) = default;
	Number& operator =(Number&&) = default;
	Number& operator =(const Number&) = default;
	~Number() = default;
private:
	// once any function called in this class , the coresponding function in Integer class called
	Integer m_value{};
};

void Lvalue_Rvalue(void);
