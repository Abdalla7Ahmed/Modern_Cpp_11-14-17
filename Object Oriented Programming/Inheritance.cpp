#include"test.hpp"

class Animal
{
public:
	Animal()
	{
		std::cout << __FUNCTION__ << std::endl;

	}
	~Animal()
	{
		std::cout << __FUNCTION__ << std::endl;

	}
	void Eat()
	{
		std::cout << "Animal eating " << std::endl;
	}
	void Run()
	{
		std::cout << "Animal running " << std::endl;

	}
	void Speak()
	{
		std::cout << "Animal speaking " << std::endl;

	}

};

class Dog : public Animal
{
public:
	Dog()
	{
		std::cout <<__FUNCTION__<< std::endl;
	}
	~Dog()
	{
		std::cout << __FUNCTION__ << std::endl;
	}
	void Eat()
	{
		std::cout << "Animal eating meat " << std::endl;
	}
	void Speak()
	{
		std::cout << "Animal barking " << std::endl;

	}

private:

};


void test_Inheritance()
{
	Dog d1;
	d1.Eat();
	d1.Run();
	d1.Speak();



}