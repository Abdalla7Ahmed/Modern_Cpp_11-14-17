#include "test.hpp"
#include <string>
#include <vector>

class Print
{
public:
	void Setvalue(std::weak_ptr<int> p)
	{
		this->p = p;
		std::cout << "Reference count is " << p.use_count() << std::endl;
	}
	void print()
	{
		if (p.expired())
		{
			// if the Reference count is 0 the expired function will return true
			// if the Reference count is not 0 the expired function will return false and we can access it
			std::cout << "Resource is no longer avaliable" << std::endl;
			return;
		}
		// we can't access the weak pointer direcly , we use lock function
		// lock function increment the Reference count by one and return the shared pointer
		auto sp = p.lock(); // std::weak_ptr<int> sp;   lock will increment the ref count with 1
		std::cout << "the value of p is " << *sp << std::endl;
		std::cout << "Reference count is " << sp.use_count() << std::endl;
	}

private:
	std::weak_ptr<int> p;
};

//======================================================================

/*
Circular references, also known as reference cycles,
occur when two or more objects hold strong references to each other,
creating a situation where the reference count of each object never reaches zero.
As a result, these objects are never deleted by the memory management system,
leading to memory leaks.

Let's consider an example of two classes, Person and Company,
that have a circular reference between them.
Each Person object has a strong reference to the Company it works for,
and each Company object has a collection of Person objects that work for it.

*/
class Company; // Forward declaration

class Person
{
public:
	Person(const std::string &name) : name(name)
	{
		std::cout << "Person " << name << " created." << std::endl;
	}

	~Person()
	{
		std::cout << "Person " << name << " destroyed." << std::endl;
	}

	void SetCompany(const std::weak_ptr<Company> &company)
	{
		this->company = company;
	}

private:
	std::string name;
	std::weak_ptr<Company> company;
};

class Company
{
public:
	Company(const std::string &name) : name(name)
	{
		std::cout << "Company " << name << " created." << std::endl;
	}

	~Company()
	{
		std::cout << "Company " << name << " destroyed." << std::endl;
	}

	void AddEmployee(const std::shared_ptr<Person> &person)
	{

		employees.push_back(person);
	}

private:
	std::string name;
	std::vector<std::shared_ptr<Person>> employees;
};

/*
In this example, we have two classes, Person and Company, with a circular reference.
Each Person object has a std::shared_ptr<Company> member, and each Company object
has a collection of std::shared_ptr<Person> objects. When the program runs, it creates two Person
objects, person1 and person2, and a Company object, company. The SetCompany() function is used
to establish the circular reference between Person and Company, and the AddEmployee()
function is used to add employees to the Company object.

The problem with this design is that when the main function finishes execution and the shared
pointers go out of scope, the reference count of each object will not reach zero due to the
circular references. As a result, the Person and Company objects will not be destroyed,
causing a memory leak.

To solve this issue and break the circular reference, we can use weak pointers.
We can modify the Person class to hold a std::weak_ptr<Company> instead of a
std::shared_ptr<Company>. Similarly, the Company class can hold a collection of
std::weak_ptr<Person> objects. This modification ensures that the reference count of
each object is not increased, allowing them to be properly destroyed when they are no longer needed.
*/

/*

By using std::weak_ptr, we break the circular reference between Person and Company,
allowing the objects to be properly destroyed. When accessing the Company object from
a Person object, we can use the lock() function of std::weak_ptr to obtain a std::shared_ptr
that provides temporary ownership of the object. If the object is still alive, lock() will
return a valid std::shared_ptr; otherwise, it will return an empty std::shared_ptr.

Using weak pointers in this scenario ensures that the objects can be properly destroyed when
they are no longer needed, avoiding memory leaks caused by circular references.
*/
void weakptr(void)
{
	/*
	In modern C++, a weak pointer is a smart pointer that provides a non-owning ("weak")
	reference to an object managed by a shared pointer. It allows you to observe or access
	the object without affecting its lifetime. Unlike a shared pointer, a weak pointer
	does not contribute to the reference count of the object, so it does not prevent
	the object from being deleted.
	The primary purpose of a weak pointer is to break potential reference cycles and
	prevent memory leaks. Reference cycles occur when objects hold shared pointers to each other,
	creating a situation where the reference count never reaches zero, and the objects are never
	deleted. Weak pointers help break these cycles by providing a way to observe objects without
	keeping them alive.
	In C++, you can use the std::weak_ptr class template from the <memory> header to create
	weak pointers. Here's an example:
	*/
	std::shared_ptr<int> shared = std::make_shared<int>(42);
	std::weak_ptr<int> weak(shared);

	// Access the object using the weak pointer
	if (auto locked = weak.lock())
	{
		std::cout << "Weak pointer value: " << *locked << std::endl;
	}
	else
	{
		std::cout << "Object is no longer available." << std::endl;
	}

	// Reset the shared pointer
	shared.reset();

	// Access the object again
	if (auto locked = weak.lock())
	{
		std::cout << "Weak pointer value: " << *locked << std::endl;
	}
	else
	{
		std::cout << "Object is no longer available." << std::endl;
	}
	/*
	In this example, a shared pointer shared is created, and a weak pointer weak is initialized
	with it. The lock() member function of std::weak_ptr is used to obtain a shared pointer that
	points to the same object as weak. If the object is still alive, lock() returns a valid shared
	pointer; otherwise, it returns an empty shared pointer. By checking the validity of the shared
	pointer obtained from lock(), you can determine if the object is still accessible.
	It's important to note that before using the shared pointer obtained from lock(),
	you should check its validity, as shown in the example. This is necessary because the object
	could have been deleted between the time you obtained the weak pointer and the time you
	attempted to lock it.
	Weak pointers are useful in situations where you need to maintain a temporary,
	non-owning reference to an object, such as caching or observer patterns, without extending
	the lifetime of the object.
	*/

	Print p1;
	int num;
	std::cin >> num;
	std::shared_ptr<int> p{new int{num}};
	p1.Setvalue(p);
	if (*p > 10)
	{
		p = nullptr;
	}
	p1.print();
	std::cout << "===========================================" << std::endl;

	std::shared_ptr<Person> person1 = std::make_shared<Person>("Alice");
	std::shared_ptr<Person> person2 = std::make_shared<Person>("Bob");

	std::shared_ptr<Company> company = std::make_shared<Company>("XYZ Corp");

	person1->SetCompany(company);
	person2->SetCompany(company);

	company->AddEmployee(person1);
	company->AddEmployee(person2);
}