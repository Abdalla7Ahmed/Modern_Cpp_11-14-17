#include "test.hpp"
#include <string.h>
class Project
{
public:
	void Set_name(std::string project_name)
	{
		this->project_name = project_name;
	}
	void ShowProjectDetails() const
	{
		std::cout << "[Project Name ] " << project_name << std::endl;
	}

private:
	std::string project_name;
};

class Employee
{
public:
	void Set_Project(std::shared_ptr<Project> &m_project)
	{
		this->m_project = m_project;
	}
	const std::shared_ptr<Project> &GetProject(void) const
	{
		return m_project;
	}

private:
	std::shared_ptr<Project> m_project{};
};

void ShowInfo(std::shared_ptr<Employee> &e)
{
	std::cout << "project details ";
	e->GetProject()->ShowProjectDetails();
}
void sharingptr(void)
{
	// how shared pointer work

	std::shared_ptr<Project> proj{new Project{}};
	// there is a reference count shared between all the copies
	std::cout << "reference count " << proj.use_count() << std::endl; // 1
	proj->Set_name("Modern C++ project");

	std::shared_ptr<Employee> e1{new Employee{}};
	e1->Set_Project(proj);
	// the reference count incremented
	std::cout << "reference count " << proj.use_count() << std::endl; // 2
	std::shared_ptr<Employee> e2{new Employee{}};
	e2->Set_Project(proj);
	// the reference count incremented
	std::cout << "reference count " << proj.use_count() << std::endl; // 3

	std::shared_ptr<Employee> e3{new Employee{}};
	e3->Set_Project(proj);
	// the reference count incremented
	std::cout << "reference count " << proj.use_count() << std::endl; // 4
	proj->ShowProjectDetails();
	ShowInfo(e1);
	ShowInfo(e2);
	ShowInfo(e3);

	if (e3)
	{
		// valid
	}
	else
	{
		// not valid
	}
	// when the pointer deleted ? when  reference count become 0 when all the shared pointers become destroyed
	// by the destroying any copy the destructor will decrement the reference count by one
	// if reference count  become zero the destructor will delete the pointer

	e3.reset();
	//  ShowInfo(e3);        // error crash
	e2.reset(new Employee{});
	// ShowInfo(e2);   // error Segmentation fault (core dumped)
	e2->Set_Project(proj);

	ShowInfo(e2);
	std::cout << "reference count " << proj.use_count() << std::endl; // 3

	e1.reset();
	e2.reset();
	proj.reset();
	std::cout << "reference count " << proj.use_count() << std::endl; // 0

	// proj->ShowProjectDetails(); // runtime error
}