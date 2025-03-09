#include"test.hpp"


Integer* Get_Pointer_rawptr(int value)
{
	std::cout << __FUNCTION__ << std::endl;
	Integer* p = new Integer{ value };
	return p;
}

void Display_rawptr(Integer* p)
{
	std::cout << __FUNCTION__ << std::endl;
	if (p == nullptr)
	{
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

void operate_rawptr(int value)
{
	std::cout << __FUNCTION__ << std::endl;
	Integer* p = Get_Pointer_rawptr(value);         // raw pointer
	if (p == nullptr)
	{
		p = new Integer{ value };
	}
	p->SetValue(100);
	Display_rawptr(p);
	delete p;
	p = nullptr;
	p = new Integer{};
	*p = __LINE__;
	Display_rawptr(p);
	delete p;
	p = nullptr;
}
void raw_pointer(void)
{
	operate_rawptr(5);
}