#include "EntryPoint.h"

/*
* To call a specific problem from CodingProblems dir follow format:
* {FileName} identifier
* Class names are identical to the File name.
*/

void Log(const char*);

int main()
{

	int arr[] = { 5, 8, 7, 3, 9, 1, 2, 4, 6, 10 };
	int sortedArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sizeSortedArr = sizeof(sortedArr) / sizeof(sortedArr[0]);
	
	Log("Linear Search");
	int x = 7;
	int resultLS = linearSearch(arr, x);
	(resultLS == -1)
		? std::cout << "Element not in array." << std::endl 
		: std::cout << "Element present at index " << resultLS << std::endl;

	Log("=========================");

	Log("Sentinel Linear Search");
	int key = 5;
	sentinelSearch(arr, key);

	Log("=========================");

	Log("Binary Search");
	int sX = 8;
	int resultBS = binarySearch(sortedArr, 0, sizeSortedArr - 1, x);
	(resultBS == -1) 
		? std::cout << "Element not in array." << std::endl
		: std::cout << "Element present at index " << resultBS << std::endl;

	Log("=========================");

	Log("Ternary Search");
	int keyTS = 8;
	int resultTS = ternarySearch(sortedArr, sortedArr[0], sizeSortedArr, keyTS);

	std::cout << "Index of " << keyTS << " is " << resultTS << std::endl;

	Log("=========================");
	Log("Jump Search");
	int jsX = 7;
	int resultJS = jumpSearch(sortedArr, jsX, sizeSortedArr);

	std::cout << "Number " << x << " is at index " << resultJS << std::endl;

	Log("=========================");
	Log("Interpolation Search");
	int isX = 4;
	int resultIS = interpolationSearch(sortedArr, 0, sizeSortedArr - 1, isX);
	(resultIS == -1)
		? std::cout << "Element not in array." << std::endl
		: std::cout << "Element present at index " << resultIS << std::endl;
}

void Log(const char* message)
{
	std::cout << message << std::endl;
}