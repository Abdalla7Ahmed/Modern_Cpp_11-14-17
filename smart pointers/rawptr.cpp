#include "test.hpp"

Integer *Get_Pointer_rawptr(int value)
{
	// std::cout << __FUNCTION__ << std::endl;
	Integer *p = new Integer{value};
	return p;
}

void Display_rawptr(Integer *p)
{
	// std::cout << __FUNCTION__ << std::endl;
	if (p == nullptr)
	{
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

void operate_rawptr(int value)
{
	// std::cout << __FUNCTION__ << std::endl;
	Integer *p = Get_Pointer_rawptr(value); // raw pointer
	if (p == nullptr)
	{
		p = new Integer{value};
	}
	p->SetValue(100);
	Display_rawptr(p);
	delete p;
	p = nullptr;
	p = new Integer{5};
	std::cout << "start" << std::endl;
	*p = Integer{__LINE__};
	std::cout << "end" << std::endl;

	Display_rawptr(p);
	delete p;
	p = nullptr;
}
void raw_pointer(void)
{
	operate_rawptr(5);
}

/*
output========
Integer(int value)
100
~Integer()
Integer(int value)
start
Integer(int value)
operator=(Integer&& obj)
~Integer()
end
34
~Integer()
========


The line *p = Integer{__LINE__}; calls the move assignment operator because of
how the assignment operation and temporary objects work in C++.

Here's a breakdown of why the move assignment operator is called:
1-Temporary Object Creation:
	Integer{__LINE__} creates a temporary Integer object. This temporary object is an rvalue,
	meaning it does not have a persistent address in memory and will be destroyed at the end of the expression.

2-Assignment to *p:
	The expression *p = Integer{__LINE__}; assigns this temporary Integer object to the object pointed to by p.
	Since the right-hand side of the assignment is a temporary (an rvalue),
	the move assignment operator is a more suitable match than the copy assignment operator. The move assignment operator
	is designed to handle rvalues efficiently by "moving" resources rather than copying them.
*/