#include "FindFactorial.h"

int FindFactorial::findFactorial(int num)
{
	int factorial = 1;
	while (num > 1)
	{
		factorial *= num;
		num--;
	}

	return factorial;
}
