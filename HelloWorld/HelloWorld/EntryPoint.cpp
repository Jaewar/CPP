#include <iostream>
// Author: Jacob Stewart
// Date: 04/26/2024
// Purpose: Displays Hello World to the console and waits for user input before closing.

// Declarations
void Log(const char* message);

int main()
{
	Log("Hello World!");
	std::cin.get();
}