#include "class.hpp"

int car::TotalCars = 0;
car::car():const_value(0)
{
	TotalCars++;
	fuel = 0;
	speed = 0;
	passengers = 0;
	
	std::cout << "default constructor " << std::endl;
}

car::car(float fuel, float speed, int passengers, int const_value):fuel(fuel), speed(speed), passengers(passengers), const_value(const_value)//Initialization Lists
{ 
	//this->fuel = fuel;
	//this->speed = speed;
	//this->passengers = passengers;
	

	// error because const_vae is constant must initialize in the Initialization Lists or within the class
	//this->const_vae = const_vae;          // error
	//const_vae = 0;						// error   
	


	std::cout << "parametarize constructor " << std::endl;
	TotalCars++;
}

car::~car()
{
	TotalCars--;
	std::cout << "destructor " << std::endl;
}

void car::FillFuel(float fuel)
{
	this->fuel += fuel;
}

void car::Accelerate(void)
{
	speed++;
	fuel -= 0.5f;
}

void car::Break(void)
{
	speed = 0;
}

void car::AddPassengers(int passengers)
{
	this->passengers = passengers;
}

void car::set_values(float ammount, float speed, int pass)
{
	fuel = 0;
	speed = 0;
	++pass;
}

void car::Dashboard(void)
{
	std::cout << "fuel " << fuel << std::endl;
	std::cout << "speed " << speed << std::endl;
	std::cout << "passengers " << passengers << std::endl;
}


void sayhello(void)
{
	std::cout << "hello " << std::endl;
}
void car::Show_Total_Cars(void)
{
	std::cout << "TotalCars " << TotalCars << std::endl;
	// static member function can access any other functions from outside the class.
	sayhello();
	
	//fuel = 10;//error Cannot access non-static members of the class

}

void car::Const_Function(void) const
{
	// the const function can't change any parameter is the class
	//passengers = 10;	//error
	std::cout << "this is const function" << std::endl;
}


// ==============================================================

Number::Number()
{
	std::cout << "Default constructor " << std::endl;
	m_ptr = new int(0);
}

Number::~Number()
{
	std::cout << "Destructor " << std::endl;
	delete m_ptr;
	m_ptr = nullptr;
}

void Number::Set_Value(int value)
{
	std::cout << "Parametarize constructor " << std::endl;
	*m_ptr = value;
}

int Number::Get_Value(void)
{
	return *m_ptr;
}

Number::Number(const Number &n1)
{
	std::cout << "copy constructor " << std::endl;
	//this->m_ptr = *m_ptr;	// the same problem here the ptr whitch passed and this ptr hold the same address space 
	m_ptr = new int(*n1.m_ptr);
}

// ==============================================================


MyClass::MyClass():MyClass(0)
{
	std::cout << "MyClass default constructor" << std::endl;
}

MyClass::~MyClass()
{
	std::cout << "MyClass destructor" << std::endl;

}



MyClass::MyClass(int a):MyClass(0,0)
{
	std::cout << "MyClass (int a)" << std::endl;


}

MyClass::MyClass(int a, int b): MyClass(0, 0,0)
{
	std::cout << "MyClass (int a, int b)" << std::endl;

}
MyClass::MyClass(int a, int b, int c)
{
	std::cout << "MyClass (int a, int b, int c)" << std::endl;
}

// ==============================================================


Test_frend::Test_frend()
{

}

Test_frend::~Test_frend()
{
}
void Test_frend::print_Private(void)
{
	std::cout << "m_privaye1 = " << m_privaye1 << " m_privaye2 = " << m_privaye2 << " m_privaye3 = " << m_privaye3 << std::endl;
}
void Access_Private(void)
{
	Test_frend t1;
	t1.m_privaye1 = 5;
	t1.m_privaye2 = 10;
	t1.m_privaye3 = 20;
	t1.print_Private();

}

Access_pri::Access_pri()
{
	t2.m_privaye1 = 100;
	t2.m_privaye2 = 200;
	t2.m_privaye3 = 300;
	t2.print_Private();
}

Access_pri::~Access_pri()
{
}


// ==============================================================
