#include <iostream>
#include "GreatestOf3Num.h"
// Write a Program to Find the Greatest of the Three Numbers.


void GreatestOf3Num::GreatestOf3(int num1, int num2, int num3)
{
	std::cout << "The greatest among the three numbers is: " << std::endl;

	if (num1 > num2 && num1 > num3)
	{
		std::cout << num1 << std::endl;
	}

	if (num2 > num1 && num2 > num3)
	{
		std::cout << num2 << std::endl;
	}

	if (num3 > num1 && num3 > num2)
	{
		std::cout << num3 << std::endl;
	}

	if (num1 == num2 && num1 == num3)
	{
		std::cout << "All numbers are equal: " << num1 << std::endl;
	}
}
