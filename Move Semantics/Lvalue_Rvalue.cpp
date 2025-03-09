#include<iostream>
#include"header.hpp"

void fun1(int x)
{
	std::cout << x << std::endl;
}
void fun2(int &x)
{
	std::cout << x << std::endl;
}
void fun3(const int &x)
{
	std::cout << x << std::endl;
}
int global = 0;
// functio return r-value
int retfun1(void)
{
	return global;
}
// functio return l-value
int &retfun2(void)
{
	return global;
}

int ADD(int x, int y)
{
	return x + y;
}
void print(int &x)
{
	std::cout << "print(int x)" << std::endl;
}
void print(const int &x)
{
	std::cout << "print(const int &x)" << std::endl;
}
void print(int &&x)
{
	std::cout << "print(int &&x)" << std::endl;
}
void testMoveSemantics(int&& y)
{
	std::cout << y << std::endl;
}
void testMoveSemantics(const int&& y)
{
	std::cout << y << std::endl;
}

Move_semantics Add(Move_semantics& a,Move_semantics& b);
Number CreateNumber(int num);
Integer CopyElision(int a, int b);
void PRINT(Integer a);
void Lvalue_Rvalue(void)
{
	// left value has name , so has address , so it can be accessible
	// right value has no name , so it will be temporary and has no address
	//=================== 
	int x = 10;    // x is Lvalue , 5 is Rvalue 
	int u = (x + 1);  // note x+1 is rvalue
	fun1(x);
	fun1(10);
	//=================== 
	// lvalue reference ----> {lvalue only}
	int& x1 = x;
	fun2(x);
	//fun2(10);      // error can't convert argument from int to &
	//=================== 
	// const lvalue reference --->{lvalue and rvalue}
	const int& x2 = x;
	const int& x3 = 10;
	fun3(x);
	fun3(10);		// valid
	//=================== 

	int y1 = retfun1();
	int y2 = retfun2();
	std::cout << y1 << std::endl;				// 0
	std::cout << y2 << std::endl;				// 0

	//int &y3 = retfun1();		// error  retfun1 return {temp --> rvalue} 
	int& y4 = retfun2();		// retfun2 return lvalue 
	retfun2() = 100;
	int& y5 = retfun2();
	int y6 = retfun2();
	std::cout << y4 << std::endl;				// 100
	std::cout << y5 << std::endl;				// 100
	std::cout << y6 << std::endl;				// 100

	// ===========================================================================
	int result = (x + y1) * y2;	// Exepression return r-value 
	++x = 6;					// Exepression return l-value(++x) 



	/*
	L-value														& R-value
	• Has a name												• Does not have a name
	• All variables are l-values								• R - value is a temporary value
	• Can be assigned values									• Cannot be assigned values
	• Some expressions return l-value							• Some expressions return r - value
	• L-value persists beyond the expression					• Does not persist beyond the expression
	• Functions that return by reference return l-value			• Functions that return by value return r - value
	• Reference to l-value (called l-value reference)			• R-value reference to r-value (called r-value reference)
	*/


	/*
	R-Value References
	• A reference created to a temporary Represents a temporary
	• Created with && operator
	• Cannot point to I-values
	• R-value references always bind to temporaries
	• L-value references always bind to I-values
	*/
	int &&r1 = 10;        //R-value reference
	int &&r2= ADD(5,8);	  //Add returns by value (temporary)
	int &&r3 = 7+2;		  //Expression return a temporary
	int tmp = 0;
	//int&& r4 = tmp;		// error R-value references always bind to temporaries	

	int t = 10;
	print(t);				// print(int x)
	print(10);				//print(int &&x)  note that if we have not implement this function the print(const int &x) will called 

	
	/* 
	the different between int p1=10 and int &&p2 = 10 
	
	int p1=10 --> the compiler will reserve a temp value and assigne 10 to it then copy the value to p1
	int &&p2 = 10 --> more optimization , compiler reserve a temp value and then make p2 point to it 
	
	*/
		
	//int&& r4 = tmp; // we see above that this exepression is an error
	int l = 20;
	const int l2 = 40;
	int&& r4 = std::move(l);	// by using the move semantics
	std::cout << "&l = " << &l << std::endl;							
	std::cout << "&r4 = " << &r4 << std::endl;					// l and r4 have the same address


	testMoveSemantics(std::move(l));		// call testMoveSemantics(int &&y) -->  20
	testMoveSemantics(std::move(l2));		// call testMoveSemantics(const int &&y) -->  40

	//Move_semantics m1;
	//Move_semantics m2(std::move(m1));
	//m2.print_Message();
	//m1.set_ptr(10); // crash in this line becaause m_ptr of m1 is null

	//Move_semantics m1(5), m2(10);
	//m1.Set_value(Add(m1, m2).Get_Value());
		
	// once any function called in this class , the coresponding function in Integer class called
	
	
	//Number n1{ 1 };      // call the parametarize constructor of Number , so call the  parametarize constructor of Integer also 
	//auto n2{ n1 };	     // call the copy constructor of Number , so call the  copy constructor of Integer also
	//n2 = n1;			 // call the copy assignment constructor
 		
	//auto n3{ CreateNumber(3) };
	//n3 = CreateNumber(3);

	//Integer N1 =3;	// call the copy and move constructor because it seem like this Integer N1 = Integer (3);
		// visual stadio don't show this 
		// in gcc there is a flag called -fno-elide-constructors 
		// if we write this flag during the build the move constructor will appear
	//Integer N2 = CopyElision(3,5);	
	
	
	//===========================================
	// std::move
	Integer a(1);		 // call the parametarize constructor
	auto b(a);			 // call the copy constructor 
		//why we need move semantics ?
		//1. after we create an object and perform some operations on it , we no longer need it's state ,
		// but we can reuse it again by reinitialize it.
		//2. is useful with none copiable objects  if we not implement the copy constructor then Integer b(a); this will be error but Integer b(std::move(a)); will work  
	auto c(std::move(a));// call the move constructor 	set m_ptr to null but the object still work and we can reuse it again 
	//std::cout << a.GetValue()<< std::endl;		// error crash 
	a.SetValue(3);
	std::cout << a.GetValue()<< std::endl;
	//	example 

	Integer I(50);
	PRINT(std::move(I));		// PRINT function : 50
	//std::cout << I.GetValue() << std::endl;		// error it will crash but 
	I.SetValue(20);
	std::cout << I.GetValue() << std::endl;			//20
	PRINT(I);	// PRINT function : 20
	std::cout << I.GetValue() << std::endl;			// 20 without crash
}
void PRINT(Integer a)
{
	std::cout << "PRINT function : " << a.GetValue() << std::endl;
}
Integer CopyElision(int a, int b)
{
	Integer tmp(a+b);	
	return tmp;

	/*
	this senario will happend
	call the copy constructor  Integer tmp(a+b);
	call move constructor because the copiler will store tmp first and return it return tmp;
	call the destructor 
	after calling the function 
	Integer N1 = CopyElision(3+5); this line above will call also the move constructor 
	in visual satusio the return will not call any constructor 
	so the best implementation of this function is 
	return Integer(a+b);	in debug and release mode will not call any constructor 
	this named return value optimization
	*/
}

Number CreateNumber(int num)
{
	Number n{ num };
	return n;
}

Move_semantics::Move_semantics()
{
	std::cout << "Move_semantics()" << std::endl;
	m_ptr = new int(0);
}
Move_semantics::Move_semantics(int value)
{
	std::cout << "Move_semantics(int value)" << std::endl;
	m_ptr = new int(value);
}

Move_semantics::Move_semantics(const Move_semantics& ref)
{
	m_ptr = new int(*ref.m_ptr);
}

Move_semantics::Move_semantics(Move_semantics&& ref)
{
	std::cout << "Move_semantics(Move_semantics&& ref)" << std::endl;
	m_ptr = ref.m_ptr;
	ref.m_ptr = nullptr;
}

void Move_semantics::print_Message(void)
{
	std::cout << "print_Message(void)" << std::endl;

}

void Move_semantics::Set_value(int value)
{
	*this->m_ptr = value;
}
int Move_semantics::Get_Value(void)
{
	return *m_ptr;
}

Move_semantics::~Move_semantics()
{
	std::cout << "~Move_semantics()" << std::endl;
	delete m_ptr;
}

Move_semantics Add(Move_semantics& a,Move_semantics& b)
{
	Move_semantics m;
	m.Set_value(a.Get_Value() + b.Get_Value());
	return m;


} 

//================================================================

Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_ptr = new int(0);
}

Integer::Integer(int value)
{
	std::cout << "Integer(int value)" << std::endl;

	m_ptr = new int(value);
}

Integer::Integer(const Integer& obj)
{
	std::cout << "Integer(Integer& obj)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}

Integer::Integer(Integer&& obj)
{
	std::cout << "Integer(Integer&& obj)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

Integer& Integer::operator=(const Integer& obj)
{
	std::cout << "operator=(const Integer& obj)" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	delete m_ptr;
	m_ptr = new int(*obj.m_ptr);
	return *this;

	// TODO: insert return statement here
}

Integer& Integer::operator=(Integer&& obj)
{
	std::cout << "operator=(Integer&& obj)	" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	delete m_ptr;
	m_ptr = obj.m_ptr;
	return *this;
	// TODO: insert return statement here
}

int Integer::GetValue(void) const
{

	return *m_ptr;
}

void Integer::SetValue(int value)
{
	if (m_ptr == nullptr)
		m_ptr = new int{};
	*m_ptr = value;

}

Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;

}

