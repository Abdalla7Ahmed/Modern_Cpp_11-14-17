#include"test.hpp"

class Distance
{
private :
	long double m_kilometres;
public:
	Distance(long double m_kilometres):m_kilometres(m_kilometres){}
	long double GetKM(void)
	{
		return m_kilometres;
	}
	void SetKM(long double m_kilometres)
	{
		this->m_kilometres = m_kilometres;
	}


};

Distance operator"" _mi(long double val)
{
	return Distance{ val * 1.6 };
}

Distance operator"" _kmetr(long double val)
{
	return Distance{ val / 1000};
}


void User_Define_Literals(void)
{

	/*
	• operator "" defines a literal operator function
	• <return type> : can be any type, including void
	•_<literal> : always starts with _ (underscore) followed by a name
	•<arguments> : can be of following types
		•integer unsigned long long
		•floating point - long double
		•character char, wchar_t, char16_t, char32_t -
		•string - const char *
	*/
	/*
	Important Points
	• Custom literals should begin with underscore
	• literals without underscore are reserved for the standard library
	• You cannot redefine the meaning of built-in literal suffixes
	• Only following types can be suffixed to make a user-defined literal
	• unsigned long long, long double, const char *, char
	• Literal operator functions cannot be member functions
	*/
	Distance dist1{ 32.0_mi };
	std::cout << dist1.GetKM() << std::endl;
	Distance dist2{ 1000.0_kmetr };
	std::cout << dist2.GetKM() << std::endl;

}