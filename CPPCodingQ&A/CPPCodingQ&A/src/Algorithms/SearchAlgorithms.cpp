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