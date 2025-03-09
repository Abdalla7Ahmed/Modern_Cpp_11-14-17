#include"test.hpp"
#include<initializer_list>
#include<cassert>

class Bag
{
private:
	int m_arr[10];
	int m_size{};
public:
	Bag() = default;
	Bag(std::initializer_list<int> values)
	{
		assert(values.size() < 10);
		auto it = values.begin();
		while (it != values.end())
		{
			Add(*it);
			it++;
		}
	}
	void Add(int value)
	{
		assert(m_size< 10);	
		m_arr[m_size++] = value;
	}
	void Remove(void)
	{
		m_size--;
	}
	int operator [](int index)
	{
		return m_arr[index];
	}
	int GetSize(void)
	{
		return m_size;
	}
};


void print(std::initializer_list<int> values)
{
	assert(values.size() < 10);
	auto it = values.begin();
/*	while (it != values.end())
	{
		std::cout << *it << std::endl;
		it++;
	}
	*/
	for (auto value : values)
	{
		std::cout << value << std::endl;
	}
}

void stdinitializerlist_test(void)
{
	int a{ 5 };
	float y{ 3.5f };
	int arr[5]{ 1,2,3,4,5 };
	std::string str{ "Abdallah" };
	std::initializer_list<int> data = { 1,2,3,4 };
	auto values = { 1,2,3,4 };   // the type of values is std::initializer_list

	Bag B1;

	B1.Add(5);
	B1.Add(10);
	B1.Add(6);
	B1.Add(2);
	for (int i = 0; i < B1.GetSize(); i++)
	{
		std::cout << B1[i] << std::endl;
	}
	// by the initialize list
	Bag B2{ 10,20,30,40 };
	for (int i = 0; i < B2.GetSize(); i++)
	{
		std::cout << B2[i] << std::endl;
	}

	print({ 90,80,70,60 });     // automaticly create an initialize list object


	for (auto value : {1,2,3})
	{
		std::cout << value << std::endl;
	}

}