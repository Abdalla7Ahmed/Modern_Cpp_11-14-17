#include"header.hpp"

void print_Char(char ch, int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << ch;
	}
	std::cout<<std::endl;
}

void End_message(void)
{
	std::cout << " End of program" << std::endl;
}
void Function_Pointers_test(void)
{
	void (*ptr)(char, int);
	ptr = print_Char;
	ptr('*', 8);
	
	atexit(End_message);


}