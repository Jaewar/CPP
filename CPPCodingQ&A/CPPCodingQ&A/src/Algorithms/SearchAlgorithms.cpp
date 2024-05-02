#include "SearchAlgorithms.h"

int linearSearch(int arr[], int x)
{
	for (int i = 0; i < sizeof(arr); i++)
	{
		if (arr[i] == x) return i;
	}
	return -1;
}

void sentinelSearch(int arr[], int key)
{
	int size = sizeof(arr);
	int last = arr[size - 1];

	arr[size - 1] = key;
	int i = 0;

	while (arr[i] != key) i++;

	arr[size - 1] = last;

	if ((i < size - 1) || (arr[size - 1] == key))
	{
		std::cout << key << " is present at index " << i << std::endl;
	}
	else
	{
		std::cout << "Element Not Found" << std::endl;
	}
}

int binarySearch(int arr[], int l, int r, int x)
{
	
	while (l <= r)
	{
		int m = l + (r - l) / 2;

		// is x present at middle
		if (arr[m] == x) return m;

		// is x greater at mid (ignore left)
		if (arr[m] < x) l = m + 1;

		// is x smaller (ignore right)
		else r = m - 1;
	}
	// element not present
	return -1;
}

int ternarySearch(int arr[], int l, int r, int key)
{
	if (r >= l)
	{
		// find mid1 and mid2
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		// check if key is present at any mid
		if (arr[mid1] == key)
		{
			return mid1;
		}
		if (arr[mid2] == key)
		{
			return mid2;
		}
		// key not present at mid, checking regions and repeating search
		if (key < arr[mid1])
		{
			// key lies between l and mid1
			return ternarySearch(arr, l, mid1 - 1, key);
		}
		else if (key > arr[mid2])
		{
			// key lies in between mid 2 and r
			return ternarySearch(arr, mid2 + 1, r, key);
		}
		else
		{
			// key lies in between mid1 and mid2
			return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
		}
	}

	// key not found;
	return -1;
}

int min(int a, int b)
{
	if (b > a) return a;
	else return b;
}

int jumpSearch(int arr[], int x, int n)
{
	// Finding block size to be jumped
	int step = sqrt(n);

	// Finding the block where element is
	// present (if it is present)
	int prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += sqrt(n);
		if (prev >= n)
			return -1;
	}

	// Doing a linear search for x in block
	// beginning with prev.
	while (arr[prev] < x)
	{
		prev++;

		// If we reached next block or end of
		// array, element is not present.
		if (prev == min(step, n))
			return -1;
	}
	// If element is found
	if (arr[prev] == x)
		return prev;

	return -1;
}

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int lo, int hi, int x)
{
	int pos;

	// Since array is sorted, an element present
	// in array must be in range defined by corner
	if (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{

		// Probing the position with keeping
		// uniform distribution in mind.
		pos = lo
			+ (((double)(hi - lo) / (arr[hi] - arr[lo]))
				* (x - arr[lo]));

		// Condition of target found
		if (arr[pos] == x)
			return pos;

		// If x is larger, x is in right sub array
		if (arr[pos] < x)
			return interpolationSearch(arr, pos + 1, hi, x);

		// If x is smaller, x is in left sub array
		if (arr[pos] > x)
			return interpolationSearch(arr, lo, pos - 1, x);
	}
	return -1;
}

int exponentialSearch(int arr[], int n, int x)
{
	// check is x is at first location
	if (arr[0] == x) return 0;

	// find range for binary search by repeated doubling.
	int i = 1;
	while (i < n && arr[i] <= x)
		i = i * 2;

	// with found range call binary search
	return binarySearch(arr, i / 2, min(i, n - 1), x);
}

int fibonacciSearch(int arr[], int x, int n)
{
	// Initializing Fibonacci numbers.
	int fibMMm2 = 0; // (m-2)'th Fib No.
	int fibMMm1 = 1; // (m-1)'th Fib No.
	int fibM = fibMMm2 + fibMMm1; // (m'th Fib)

	// fibM stores the smallest fib no. great than or equal to n.
	while (fibM < n)
	{
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}

	// marks teh eliminated range from front.
	int offset = -1;

	// Comparing arr[fibMMm2] with x.
	while (fibM > 1)
	{
		// check that fibMMm2 is valid
		int i = min(offset + fibMMm2, n - 1);

		// if x is greater cut the subarray array from offset to i.
		if (arr[i] < x)
		{
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		}

		// is x is greater than the value at findex fibMMm2, cut the subarray after i + 1
		else if (arr[i] > x)
		{
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		}

		// element not found;
		else return i;
	}

	// checking last element
	if (fibMMm1 && arr[offset + 1] == x)
		return offset + 1;

	return -1;
}