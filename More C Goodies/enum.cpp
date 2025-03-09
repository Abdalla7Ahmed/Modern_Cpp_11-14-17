#include"test.hpp"
void print(std::string s)
{
	std::cout << s << std::endl;
}
void print(int x)
{
	std::cout << x << std::endl;
}
// scoped enum
enum class color : int { RED, GREEN, BLUE };

void Fillcolore(color c)
{
	switch (c)
	{
	case color::RED:
		print("the color is RED");
		break;
	case color::GREEN:
		print("the color is GREEN");
		break;
	case color::BLUE:
		print("the color is BLUE");
		break;
	default:
		break;
	}
}

enum class traffic : char { RED = 'c', GREEN, YELLOW };
void enum_test(void)
{
	color c = color::RED;
	Fillcolore(c);
	Fillcolore(color::GREEN);
	Fillcolore(color::BLUE);

	traffic r = traffic::YELLOW;
	//color c = 5;   // error 
	//int y = RED; // if we not has scoped enum this expression is valid
	int y =static_cast<int>(color::RED);
	std::cout <<"the size of color enum is " << sizeof color << std::endl;      // 4 byte
	std::cout << "the size of traffic enum is " << sizeof traffic << std::endl;      // 1 byte

}