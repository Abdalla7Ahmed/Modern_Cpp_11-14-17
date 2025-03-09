#include "test.hpp"
#include <memory>

Integer *Get_Pointer_uniqueptr(int value)
{
	std::cout << __FUNCTION__ << std::endl;
	Integer *p = new Integer{value};
	return p;
}

void Display_uniqueptr(Integer *p)
{
	std::cout << __FUNCTION__ << std::endl;
	if (p == nullptr)
	{
		return;
	}
	std::cout << p->GetValue() << std::endl;
}

/*void store(std::unique_ptr<Integer> p)
{
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "storing data" <<p->GetValue()<< std::endl;
}*/
void store_uniqueptr(std::unique_ptr<Integer> &p)
{
	std::cout << __FUNCTION__ << std::endl;
	std::cout << "storing data" << p->GetValue() << std::endl;
}
void operate_uniqueptr(int value)
{
	std::cout << __FUNCTION__ << std::endl;
	// Integer* p = Get_Pointer(value);         // raw pointer
	std::unique_ptr<Integer> p{Get_Pointer_uniqueptr(value)}; // unique pointer is not a pointer but it is an object
	if (p == nullptr)
	{
		// p = new Integer{ value };      // if we use the unique pointer we can't use the = to assigne but
		p.reset(new Integer{value}); // we can use function called reset
									 // if the p is hold an existing pointer the reset function will delete it first
	}
	p->SetValue(100);
	// Display_uniqueptr(p);      // error we can't copy the unique pointer

	/*
			in the unique class , disable the copy
		  // Disable copy from lvalue.
		  unique_ptr(const unique_ptr&) = delete;
		  unique_ptr& operator=(const unique_ptr&) = delete;
	*/

	Display_uniqueptr(p.get()); // we can path this get function to any function doesn't accept the unique pointer
	// p.get()  return pointer to opject p
	// delete p; we can't delete p because it is an object not pointer
	// no need to assigne it to nullptr because the reset function assigne it and reuse it
	// p = nullptr;
	// p = new Integer{};
	p.reset(new Integer{});
	*p = Integer{__LINE__};
	Display_uniqueptr(p.get());
	// store(p); // error because we copy the unique pointer in the store function copy constructor is deleted in the unique function pointer
	// store(std::move(p));  // move allowed
	// std::cout << p->GetValue() << std::endl;// we can't use the p pointer after moving it(runtime error)
	//  instade this we can initialize the function store with reference
	store_uniqueptr(p);
	// we can use the p pointer after it because the function accept reference to this pointer
	*p = Integer{__LINE__};
	Display_uniqueptr(p.get());
	// delete p;
}
void stduniqueptr(void)
{
	operate_uniqueptr(5);
}