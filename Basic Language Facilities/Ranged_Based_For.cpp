#include"header.hpp"

void Ranged_Based_For_test(void)
{
	int arr[]{ 56,21,3,46,79 };
	for (auto& x : arr)
	{
		if (x == 56)
		{
			x--;
		}
		std::cout << x << std::endl;
		
	}

	for (const auto& x : arr)
	{
		if (x == 56)
		{
			//x--;  error
		}
		std::cout << x << std::endl;
		/*
		For vs Range-Based For
		*For
			• Index based iteration
			• Requires end condition
			• Index variable needs to be incremented or decremented
			• Error-prone e.g. wrong end condition, overflow, underflow, incorrect iteration expression
			• More control over iteration
			• Use for finer control
		 *Range-Based For
			• Does not use index to iterate
			• End condition is provided by the range
			• No need to increment or decrement
			• Lesser chances of errors
			• No control over iteration
			• Use with ranges
		*/
	}
	// how ranged for work ?
	int array[]{ 11,22,33,44,55,66 };
	auto&& range = array;         // && allowes you to use l values (array) and R values(list) 
	auto begine = std::begin(range);
	auto end = std::end(range);

	for (; begine != end; begine++)
	{
		std::cout << *begine << " " << std::endl;
	}


}