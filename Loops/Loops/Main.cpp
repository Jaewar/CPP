#include <iostream>
#include "Log.h"

// VISUAL STUDIOS: Format Doc (Ctrl + K, D) Format Selection (Ctrl + K, F)

int main() {

	#pragma region LoopControl

	for (int i = 0; i < 5; i++) {
		if (i % 2 == 0)
			continue;
		std::cout << i << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		if ((i + 1) % 2 == 0)
			break;
		std::cout << i << std::endl;
	}

	//for (int i = 0; i < 5; i++) {
	//	if ((i + 1) % 2 == 0)
	//		return 0;
	//	std::cout << i << std::endl;
	//}

	#pragma endregion

	#pragma region ForLoop
	/*
	// Var, Condition, Incremental
	for (int i = 0; i < 5; i++) {
		Log("Hello World!");
	}
		// Same as above loop
		int i = 0;
		bool condition = true;

		for (; condition;) {
			Log("Hello World!!");
			i++;
			if (!(i < 5))
				condition = false;
		}
	*/
	#pragma endregion

	#pragma region WhileLoop
	/*
	int j = 0;
	// while "Condition"
	while (j < 5) {
		Log("Hello World!");
		j++;
	}
	*/
	#pragma endregion

	#pragma region DoWhile
	/*
	int k = 0;
	do {
		Log("Hello World!");
		k++;
	} while (k < 5);
	*/
	#pragma endregion


	std::cin.get();
}