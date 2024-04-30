#include <iostream>
#include "NumberEvenOrOdd.h"
// C++ Program To Check Whether Number is Even Or Odd

void NumberEvenOrOdd::EvenOrOdd(int num)
{
	if (num % 2 == 0)
	{
		std::cout << num << " is even." << std::endl;
	}
	else
	{
		std::cout << num << " is odd." << std::endl;
	}
}
