#include<stdio.h>
#include<stdlib.h>
#include<iostream>

void Malloc(void)
{
	/*
	Dynamic Memory Allocation in C
	• C provides various functions for allocating memory from the heap
	• malloc allocate raw memory on the heap
	• calloc allocates memory on the heap and initializes it to zero
	• realloc allocates larger chunk of memory for an existing allocation
	• free deallocates/releases the memory allocated through the above functions
	*/


	/*
	
	malloc															new
	• Function														• Operator
	• Requires size during allocation								• Size is ascertained from the type
	• Cannot initialize memory										• Can initialize memory
	• Cannot call constructors										• Can call constructors
	• Returns void pointer that needs to be type casted				• Returns correct type of pointer
	• Cannot be customized											• Can be customized through overloading
	• malloc, calloc & realloc										• Has different forms
	• Return NULL on failure										• Throws exception on failure
	*/


	int* p = (int*)malloc(3 * sizeof(int));
	if (p == NULL)
	{
		printf("Failed to allocate memory \n");
		return ;
	}

	p[0] = 5;
	p[1] = 10;
	p[2] = 15;

	printf("*p = %d", *p);

	free(p);
	// p now is dangling pointer if we free p again it will crash
	p = NULL;
}

void New(void)
{
	/*
	Dynamic Memory Allocation in C++
	• C++ provides two operators for dynamic memory allocation
	• new allocates memory on the heap :
	• delete deallocates memory :
	• Memory that is allocated through new has to be released with delete
	• <type> *<variable> = new <type> (optional args); delete <variable>;
		int *p = new int(value);
		delete p;
	*/
	int* p = new int;
	int* p2 = new int(10);		// initialized with 10
	*p = 50;
	*p2 = 20;
	std::cout << *p << std::endl;
	std::cout << *p2 << std::endl;

	delete p;
	delete p2;
	p = nullptr;
	p2 = nullptr;

}

void New_For_Array(void)
{
	/*
	new For Arrays
	• Another form of new
	• Used for allocating dynamic arrays
	• Written as new[]
	• Subsequently, use delete [] for releasing the memory <type> *<variable> = new <type>[size]; delete [] <variable>;
	int *p = new int[5];//Allocate memory for 5 integers delete []p; //Note the usage of [] with delete
	int *p2=new int[5]{1,2,3,4,5} // initialize the elements
	*/
	int* p =new int[5];
	for (int i = 0; i < 5; i++)
	{
		p[i] = i;
		std::cout << p[i] << std::endl;
	}
	delete[]p;
	// there is no need to assigne nullptr to p because after execution this fuction all the variables will destroy 
	// we can use the uniform initialization with new 
	int* p2 = new int[5] {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++)
	{
		std::cout << p2[i] << std::endl;
	}
	delete[]p2;
	char* str = new char[4];
	strcpy_s(str, 4, "c++");       // must reserve 1 byte for null 
	std::cout << str << std::endl;
	delete[]str;
}

void TDarray(void)
{
	char* p1 = new char[6] {"hello"};
	char* p2 = new char[9] {"abdallah"};
	char** pdata = new char*[2];
	pdata[0] = p1;
	pdata[1] = p2;
	std::cout << pdata[0]<<' ';
	std::cout << pdata[1];

	// we must free the pointers in order 
	delete []p1;			// or delete []pdata[0]
	delete []p2;			// or delete []pdata[1]
	delete[]pdata;

}
int main(void)
{
	/*
	malloc															new
	• Function														• Operator
	• Requires size during allocation								• Size is ascertained from the type
	• Cannot initialize memory										• Can initialize memory
	• Cannot call constructors										• Can call constructors
	• Returns void pointer that needs to be type casted				• Returns correct type of pointer
	• Cannot be customized											• Can be customized through overloading
	• malloc, calloc & realloc										• Has different forms
	• Return NULL on failure										• Throws exception on failure
	*/
	New();
	Malloc();
	New_For_Array();
	TDarray();
	return 0;
}