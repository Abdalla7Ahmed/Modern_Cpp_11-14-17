#pragma once
#include<iostream>
class car
{
public:
	car();
	car(float fuel,float speed,int passengers,int const_value);
	~car();
	void FillFuel(float fuel);
	void Accelerate(void);
	void Break(void);
	void AddPassengers(int passengers);
	void set_values(float ammount, float speed, int pass);
	void Dashboard(void);
	static void Show_Total_Cars(void);
	void Const_Function(void)const;

private:
	float fuel;
	float speed;
	int passengers;
	//auto x ;		// error auto is not allowed here
	static int TotalCars;
	const int const_value;//must initialized here or within the constrictor 
	// we can't use the default constructor without initialize this const member 


};


// ==========================================

class Number
{
public:
	Number();
	~Number();
	//Number(Number n1);    // big problem , copy constructor will created infinite times 
	Number(const Number &n1);
	void Set_Value(int value);
	int Get_Value(void);

private:
	int* m_ptr;

};

// ==========================================
//Delegating Constructor
class MyClass
{
public:
	MyClass();
	~MyClass();
	MyClass(int a);
	MyClass(int a,int b);
	MyClass(int a,int b,int c);

private:
	int a;
	int b;
	int c;

};

class test1
{
public:
	test1() = default; 
	/*	
	test1() {}
	*/
	test1(const test1&ref) = default;
	/*
	test1(const test1&ref){
	value1 = ref.value1;
	value2 = ref.value2;
	value3 = ref.value3;
	value4 = ref.value4;
	}
	*/
	void setValue(int value1) {
		this->value1 = value1;
	}
	void setValue(float) = delete;     // if the user pass float value to this function will be error
	~test1() = default;
	/*
	test1() {}
	*/
private:
	int value1;
	int value2;
	int value3;
	int value4;

};
// =============================================================




class Test_frend
{
public:
	Test_frend();
	~Test_frend();
	// this function can access the private members and doesn't related to the class
	friend void Access_Private(void);
	// we can make class friend also to be this class can access the private members
	friend class Access_pri;
private:
	int m_privaye1;
	int m_privaye2;
	int m_privaye3;
	void print_Private(void);


};

class Access_pri
{
public:
	Access_pri();
	~Access_pri();

private:
	Test_frend t2;
};

