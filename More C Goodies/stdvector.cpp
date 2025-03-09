#include"test.hpp"
#include<vector>

void stdvector_test(void)
{
	std::vector<int> data { 1,2,3,4,5 };
	for (int i = 0; i < 5; i++)
	{
		data.push_back(i * 10);
	}

	// how to access the vector ?

	//1. 
	data[0] = 100;
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
	//2. ranged for loop
	for (auto x : data)
	{
		std::cout << x << " ";
	}
	//3. using the iterator
	std::cout << std::endl;
	auto it = data.begin();
	while (it != data.end())
	{
		std::cout << *it<< " ";
		it++;
	}
	std::cout << std::endl;
	it = data.begin();
	++it;
	--it;
	it = it + 5;
	// Delete
	it = data.begin()+5 ;
	data.erase(it);
	std::cout << std::endl;
	for (auto x : data)
	{
		std::cout << x << " ";
	}
	// insert
	std::cout << std::endl;

	it = data.begin() + 5;
	data.insert(it, 500);
	for (auto x : data)
	{
		std::cout << x << " ";
	}
}