// Pointers target a specific memory address allowing manipulation and control over the target memory space.
#include <iostream>

#define LOG(x) std::cout << x << std::endl

// STEP THROUGH IN DEBUG TO SEE ACTUAL ALLOCATIONS
int main() {

	// created in the stack
	int var = 8;
	
	// pulling the memory address from int var.
	int* ptr = &var;

	// accessing the data at the memory address and modifying its value
	*ptr = 10;

	LOG(var);

	// requesting 8 bytes of memory on the heap
	char* buffer = new char[8];

	//fills a block of memory with the data specificed.
	memset(buffer, 0, 8);

	// creating a pointer to a pointer
	char** ptr = &buffer;

	// deleting the memory that was allocated.
	delete[] buffer;

	std::cin.get();
}
