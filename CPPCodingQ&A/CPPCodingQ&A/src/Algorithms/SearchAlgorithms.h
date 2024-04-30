#pragma once

#include <iostream>
#include <algorithm>

// Order of effectiveness linear < jump < binary

// Sequential Search that starts at one end and goes through each element until the element is found.
int linearSearch(int arr[], int x);

// Linear Search, however key is placed at end of array. Size of array does not need to be checked.
void sentinelSearch(int arr[], int key);

// Binary Search requires a sorted array, repeatedly divides the search interval in half. (O(log N) Time Complexity).
int binarySearch(int arr[], int l, int r, int x);

// Ternary Search requires a sorted array, separates the array in 3 parts (O(2 * log3n) Time Complexity).
int ternarySearch(int arr[], int l, int r, int key);

// Jump Search requires a sorted array, checks fewer elements then linear by jumping ahead by fixed steps. (O(? N)
int jumpSearch(int arr[], int x, int n);

// Interpolation Search requires a sorted array, works in a way we search for a word in a dictionary. The interpolation search algorithm improves the binary search algorithm.
int interpolationSearch(int arr[], int lo, int hi, int x);


