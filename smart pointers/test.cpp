#include "test.hpp"
Integer::Integer()
{
	std::cout << "Integer()" << std::endl;
	m_ptr = new int(0);
}

Integer::Integer(int value)
{
	std::cout << "Integer(int value)" << std::endl;

	m_ptr = new int(value);
}

Integer::Integer(const Integer &obj)
{
	std::cout << "Integer(Integer& obj)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}

Integer::Integer(Integer &&obj)
{
	std::cout << "Integer(Integer&& obj)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

Integer &Integer::operator=(const Integer &obj)
{
	std::cout << "operator=(const Integer& obj)" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	if (m_ptr)
	{
		delete m_ptr;
	}
	m_ptr = new int(*obj.m_ptr);
	return *this;
}

Integer &Integer::operator=(Integer &&obj)
{
	std::cout << "operator=(Integer&& obj)	" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	if (m_ptr)
	{
		delete m_ptr;
	}
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
	return *this;
}

int Integer::GetValue(void) const
{

	return *m_ptr;
}

Integer &Integer::operator+(const Integer &obj)
{
	std::cout << "Integer::operator+(const Integer& obj)" << std::endl;
	*m_ptr = *m_ptr + *obj.m_ptr;
	return *this;
}

void Integer::SetValue(int value)
{
	if (m_ptr == nullptr)
		m_ptr = new int{};
	*m_ptr = value;
}

Integer &Integer::operator++()
{
	++(*m_ptr);
	return *this;
}

Integer Integer::operator++(int)
{
	Integer tmp(*this);
	++(*m_ptr);
	return tmp;
}
Integer::operator int()
{
	std::cout << "Integer::operator int()" << std::endl;

	return *m_ptr;
}
Integer::~Integer()
{
	std::cout << "~Integer()" << std::endl;
	delete m_ptr;
}
