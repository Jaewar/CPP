#include <iostream>
#include "Log.h"

int main() {

	int x = 5;

	bool comparisonResult = x == 5;

	if (comparisonResult)
	{
		Log("Hello World!");
	}

	const char* ptr = nullptr;
	if (ptr)
		Log(ptr);
	else
		Log("PTR is NULL");

	std::cin.get();
}