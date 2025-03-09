#include"test.hpp"
#include<string>
#include<sstream>

void str(void)
{
	// initialize & assigne 
	std::string s1 = "hello ";
	std::string s2 = "world";
	s1 = "hello ";
	print(s1 + s2);

	// access 
	s1[0] = 'y';
	auto c = s1[2];
	print(s1);
	std::getline(std::cin, s1);
	print(s1);

	// size
	auto l = s1.length();
	print(l);

	// insert & concatenate
	std::string p1{ "hello " }, p2{ "world" };
	std::string p3 = p1 + p2;
	print(p3);
	p3 += " from c++";
	print(p3);
	p3.insert(6, "world ");       // add world in position 6 
	print(p3);
	// comparision 
	if (p3 == p2)
	{

	}
	// removal 
	std::string p4{ p3 };
	p4.erase(0, 5);       // delete from 0 to 5
	print(p4);
	p4.erase();
	print(p4);           // empty
	// we can use p3.clear();
	p2.clear();
	//p2.clear(1,2);          // error
	print(p2);           // empty

	// search 
	auto pos = p3.find("world", 0);      // start search from index 0
	print(pos);
	if (pos != std::string::npos)
	{
		// found
	}
}

std::string Combine(const std::string& first, const std::string& last)
{
	std::string full = first + last;
	return full;
}

void STRING(void)
{
	std::string first, last, fullname;
	std::getline(std::cin, first);
	std::getline(std::cin, last);
	fullname = Combine(first, last);
	print(fullname);
	printf("%s\n", fullname.c_str());  // return raw string , to be compatable with a c++ style string

	using namespace std::string_literals;
	std::string name = "abdallah ahmed "s;
	print(name);
}

void stringstream(void)
{
	int a{ 5 }, b{ 10 };
	int sum{ a + b };
	std::stringstream ss;
	ss << "sum of " << a << " and " << b << " is " << sum << std::endl;
	std::string s = ss.str();
	std::cout<< s << std::endl;
	ss.str("");
	ss << sum;
	//auto ssum = ss.str();
	auto ssum = std::to_string(sum);       // work also 
	std::cout << ssum << std::endl;

	std::string data ="10 20 30 40 ";         // we can parse the integer numbers in the sting 
	int c{};
	std::stringstream ss2;
	ss2.str(data);
	while (ss2 >> c)
	{
		std::cout << c << std::endl;
	}

	int x = std::stoi("55");
	std::cout << x << std::endl;
}

void string_test(void)
{
	//str();
	//STRING();
	stringstream();


}