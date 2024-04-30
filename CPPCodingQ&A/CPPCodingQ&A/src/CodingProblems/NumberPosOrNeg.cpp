// Write a C++ Program to Check Whether a number is a Positive or Negative Number.
#include "NumberPosOrNeg.h"

void NumberPosOrNeg::PosOrNeg(int num)
{
	if (num >= 0)
	{
		std::cout << num << " is a positive number." << std::endl;
		return;
	}
	else
	{
		std::cout << num << " is a negative number." << std::endl;
		return;
	}

	std::cout << num << " is invalid." << std::endl;
}
