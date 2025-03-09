#include "test.hpp"
#include <cstdlib>
#include <memory>

// function object
struct Free
{
	void operator()(int *ptr)
	{
		std::cout << "Deleting memory at address: " << ptr << std::endl;
		free(ptr);
	}
};

// use function as a custom deleter
void Deleter_func(int *ptr)
{
	std::cout << "Deleting memory at address: " << ptr << std::endl;
	free(ptr);
}

struct FreeArray
{
	void operator()(int *ptr)
	{
		std::cout << "Deleting memory at address: " << ptr << std::endl;
		delete[] ptr;
	}
};
void Deleter_func_array(int *ptr)
{
	std::cout << "Deleting memory at address: " << ptr << std::endl;
	delete[] ptr;
}

void Deleter(void)
{
	/*
	In C++, a deleter is a function or function object that specifies how to release the resources
	associated with a smart pointer when it goes out of scope or is explicitly reset.
	The deleter is typically used with smart pointers like std::unique_ptr and std::shared_ptr
	to provide customized resource management.
	*/

	// with unique pointer
	// the default deleter of the unique pointer will call delete , so we can write a custom delete
	// std::unique_ptr<int, Free> Unique{ (int*)malloc(sizeof(int)) ,Free{}};
	std::unique_ptr<int, void (*)(int *)> Unique{(int *)malloc(sizeof(int)), Deleter_func};
	*Unique = 200;
	std::cout << " Unique = " << *Unique << std::endl;
	// free(Unique);   // we can't use free with smart pointers

	// with shaired pointer
	// std::shared_ptr<int> Shared{ (int*)malloc(sizeof(int)) ,Deleter_func };
	std::shared_ptr<int> Shared{(int *)malloc(sizeof(int)), Free{}};

	*Shared = 300;
	std::cout << " Shared = " << *Shared << std::endl;

	// the default deleter of the unique and shared pointer will call delete not delete []
	std::unique_ptr<int[]> array{new int[5]{1, 2, 3, 4, 5}};
	// by adding [] after int ,
	// the compiler will use another class of unique_ptr
	// we can acces the elements like this array[0]=10
	// the default deleter will call delete []
	array[0] = 10;
	array.get()[0] = 10; // without  [] this is the only way to access the array elements
	std::cout << array[0] << std::endl;
	std::shared_ptr<int[]> array2{new int[5]{1, 2, 3, 4, 5}}; // supported in c++ 17

	// we can write function or function object that specifies how to release the resources
	// std::shared_ptr<int> array3{ new int[5] {1,2,3,4,5},FreeArray{} };
	std::shared_ptr<int> array3{new int[5]{1, 2, 3, 4, 5}, Deleter_func_array};
}