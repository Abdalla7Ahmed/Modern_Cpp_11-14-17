#include"header.hpp"


namespace AVG
{
	void calculate()
	{
		std::cout << "calculate inside AVG namespace called " << std::endl;
	}
}
namespace SUM
{
	void calculate()
	{
		std::cout << "calculate inside SUM namespace called " << std::endl;
	}
}


namespace Sort {
	void Quicksort() {
		std::cout << "Quicksort inside Sort namespace called " << std::endl;
	}
	void Insertionsort() {
		std::cout << "Insertionsort inside Sort namespace called " << std::endl;
	}
	void Mergesort() {
		std::cout << "Mergesort inside Sort namespace called " << std::endl;
	}
	namespace Comparision {
		void Less() {
			std::cout << "Less inside Sort inside Comparision namespace called " << std::endl;
		}
		void Greater() {
			std::cout << "Greater inside Sort inside Comparision namespace called " << std::endl;
		}
	}
}
// this namespace is visible to this file only and we can use it direct
namespace {
	void InternalFunction() {
		std::cout << "InternalFunction inside namespace with no name is called " << std::endl;
	}
}

void namespace_test(void)
{
	/*
	Namespace
	• Named declarative region used for declaring types
	• The types are not visible outside the namespace
	• Standard library is in std namespace
	• Prevents name clashes
	• Helps modularize code
	• namespace <name> {
		(namespace, class, structure, function, variable, etc)
	}
	*/

	/*
	Namespace Access
	• Types inside a namespace have a scope
	• Cannot be accessed outside the namespace
	• Either open the namespace or the type
		1• use the global using declarative and open the entire namespace 
					using namespace std;
		2• use the using declarative and open a specific type using 
					std::cout;
		3• using the full qualified name 
					std::cout << "C++" << std::endl;
	*/

	AVG::calculate();
	SUM::calculate();
	Sort::Quicksort();
	Sort::Insertionsort();
	Sort::Mergesort();
	Sort::Comparision::Less();
	Sort::Comparision::Greater();
	InternalFunction();
}