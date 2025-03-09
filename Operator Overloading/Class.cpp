#include "Class.hpp"

void LCD::Set_Text(std::string text)
{
	this->text = text;
}

	std::string LCD::GetText(void)
	{
		return this->text;
	}
	/*
	std::string LCD::operator+(std::string msg)
	{
		std::cout << "LCD::operator+(std::string msg)" << std::endl;
		text = text + msg;
		return text;
	}*/

LCD& LCD::operator+(std::string msg)
{
	text = text + msg;
	return *this;
}

LCD& LCD::operator-(std::string msg)
{
	//text = text  - msg;      // error there is no operator overloading - in string class
	std::string tmp{text};
	tmp.erase(tmp.find(msg), msg.length());
	this->text = tmp;
	return *this;
}




Segment::Segment()
{
	std::cout << "Segment()" << std::endl;
}

Segment::~Segment()
{
	std::cout << "~Segment()" << std::endl;

}

//==============================================
void Segment::Set_Number(int number)
{
	m_number = number;

}

int Segment::Get_Number(void)
{
	return 	m_number;
}

void Segment::DisplayNumber(void)
{
	std::cout << m_number << std::endl;
}

bool Segment::operator<(const Segment& tmp)
{
	if (m_number < tmp.m_number)
	{
		return true;
	}
	return false;
}

bool Segment::operator>(const Segment& tmp)
{
	if (m_number > tmp.m_number)
	{
		return true;
	}
	return false;
}

bool Segment::operator==(const Segment& tmp)
{
	if (m_number == tmp.m_number)
	{
		return true;
	}
	return false;
}

bool Segment::operator!=(const Segment& tmp)
{
	if (m_number != tmp.m_number)
	{
		return true;
	}
	return false;
}

Segment& Segment::operator+=(int n)
{
	m_number += n;
	return *this;
}

Segment& Segment::operator-=(int n)
{
	m_number -= n;
	return *this;
}

Segment& Segment::operator *=(int n)
{
	m_number *= n;
	return *this;
}

Segment& Segment::operator/=(int n)
{
	if (n != 0)
	{
		m_number /= n;
	}
	else
	{
		std::cout << "Error can't devide by 0" << std::endl;
	}

	return *this;
}
Segment& Segment::operator=(int n)
{

	m_number = n;
	return *this;
}

void Segment::operator()(int x)
{
	Set_Number(x);
	DisplayNumber();
}



bool Segment::operator<(int x)
{
	if (m_number <x)
	{
		return true;
	}
	return false;
}

bool Segment::operator>(int x)
{
	if (m_number > x)
	{
		return true;
	}
	return false;
}

bool Segment::operator==(int x)
{
	if (m_number == x)
	{
		return true;
	}
	return false;
}

bool Segment::operator!=(int x)
{
	if (m_number != x)
	{
		return true;
	}
	return false;
}

int Segment::operator++()
{
	m_number++;
	return m_number;
}
int Segment::operator--()
{
	m_number--;
	return m_number;

}
int Segment::operator++(int)
{
	int tmp = m_number;
	m_number++;
	return tmp;
}
int Segment::operator--(int)
{
	int tmp = m_number;
	m_number--;
	return tmp;
}

int Segment::operator&(int x)
{
	int tmp = (m_number&x);
	return tmp;
}
int Segment::operator|(int x)
{
	int tmp = (m_number | x);
	return tmp;
}

int Segment::operator!()
{
	int tmp = !m_number;
	return tmp;
}

int Segment::operator<<(int x)
{
	int tmp;
	tmp = m_number << x;
	return tmp;
}
int Segment::operator>>(int x)
{
	int tmp;
	tmp = m_number >> x;
	return tmp;
}

std::ostream& operator<<(std::ostream& out, const Segment& tmp)
{
	out << tmp.m_number;
	return out;
}

//=============================================================
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

Integer::Integer(const Integer& obj)
{
	std::cout << "Integer(Integer& obj)" << std::endl;
	m_ptr = new int(*obj.m_ptr);
}

Integer::Integer(Integer&& obj)
{
	std::cout << "Integer(Integer&& obj)" << std::endl;
	m_ptr = obj.m_ptr;
	obj.m_ptr = nullptr;
}

Integer& Integer::operator=(const Integer& obj)
{
	std::cout << "operator=(const Integer& obj)" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	delete m_ptr;
	m_ptr = new int(*obj.m_ptr);
	return *this;

}

Integer& Integer::operator=(Integer&& obj)
{
	std::cout << "operator=(Integer&& obj)	" << std::endl;
	if (this == &obj)
	{
		return *this;
	}
	delete m_ptr;
	m_ptr = obj.m_ptr;
	return *this;
}

int Integer::GetValue(void) const
{

	return *m_ptr;
}

Integer& Integer::operator+(const Integer& obj)
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

Integer& Integer::operator++()
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

Number::Number()
{
	std::cout << "Number()" << std::endl;

}

Number::operator Integer()
{
	std::cout << "Number::operator Integer()" << std::endl;
	return m_integer;
}

Number::Number(const Integer& ref):m_integer(ref)
{

}

Number::~Number()
{
	std::cout << "~Number()" << std::endl;
}
