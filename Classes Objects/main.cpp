#include"class.hpp"
// copy constructor
void fun1(Number n1)
{

}
Number fun2(void)
{
	
	Number n2;
	// copy constructor
	return n2;
}

int main(void)
{
	// we can called the static function with the name of class because it related to the class not the object 
	//car::Show_Total_Cars();
	//car car1(6, 200, 5,10),car2,car3,car4;
	// we can't create a default constructor if we not set the const value on it 
	//car1.FillFuel(20);
	//car1.Accelerate();
	//car1.Accelerate();
	//car1.Accelerate();
	//car1.Accelerate();
	//car1.Accelerate();
	//car1.Accelerate();
	//car1.Dashboard();
	//car::Show_Total_Cars();
	//car1.Const_Function();
	// =============================================================


	Number n1;
	
	Number n2(n1);
	n1.Set_Value(50);
	std::cout << n1.Get_Value() << std::endl;

	// the problem with the copy constructor 
	int* ptr1 = new int(0);
	// shallo copy
	int* ptr2 = ptr1;	// ptr1 and ptr2 hold the same address in memory 
	// deep copy
	int* ptr3 = new int(*ptr1); // reserve a new memory space and then assigne it with the value that ptr1 hold
	delete ptr1;		// no problem but , 
	//delete ptr2;		// there is the problem , we try to delete unaccessaple address because we delete it already,the program will crash  
	
	// the same problem occur on the default copy constructor , we have to implement userdefine copy constructor

	// ==============================================================

	MyClass M1;
	/*
	the output is :-
	MyClass (int a, int b, int c)
	MyClass (int a, int b)
	MyClass (int a)
	MyClass default constructor
	MyClass destructor
	*/
	// ==============================================================

	extern void Access_Private(void);
	Access_Private();

	Access_pri t;

	// ==============================================================


}

