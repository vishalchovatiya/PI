#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))


/*
	Question:- Given n non-negative integers representing an elevation map where the width of each bar is 1, 
				compute how much water it is able to trap after raining.
	
	Examples:
	
	Input: arr[]   = {2, 0, 2}
	Output: 2
	Structure is like below
	| |
	|_|
	We can trap 2 units of water in the middle gap.
	
	Input: arr[]   = {3, 0, 0, 2, 0, 4}
	Output: 10
	Structure is like below
	     |
	|    |
	|  | |
	|__|_| 
	We can trap "3*2 units" of water between 3 an 2,
	"1 unit" on top of bar 2 and "3 units" between 2 
	and 4.  See below diagram also.
	
	Input: arr[] = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
	Output: 6
	       | 
	   |   || |
	_|_||_||||||
	Trap "1 unit" between first 1 and 2, "4 units" between
	first 2 and 3 and "1 unit" between second last 1 and last 2 
	
	Answer:-
	
	Naive Approach:- 
	- Traverse every element and find the highest bars on left and right sides. Take the smaller of two heights. 
	- The difference between smaller height and height of current element is the amount of water that can be stored in this array element. 
	- Time complexity of this solution is O(n x n).

	Efficient Approach:- 
	- Pre-compute highest bar on left and right of every bar in O(n) time. Then use pre-computed values to find the amount of water in every element. 
	- Time complexity of this solution is O(n).
		
*/


void printArray(int arr[], int start, int arr_size)
{
    for (int i = start; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int TrappingRainWater(int A[], int n)
{	// 3, 2, 1, 2, 1
    int Left[n], Right[n];
 
    int water = 0;

	Left[0] = A[0];
	for(int i=1; i<n; i++)					// Compute Greater element on left
		Left[i] = max( Left[i-1], A[i]);
	
	Right[n-1] = A[n-1];
	for(int i=n-2; i>=0; i--)				// Compute Greater element on Right
		Right[i] = max( Right[i+1], A[i]);

	for(int i=1; i<n; i++)
		water += min( Left[i], Right[i]) - A[i];
 
    return water;
}

int main()
{
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
		
	cout<<TrappingRainWater( arr, SIZE(arr))<<endl;
	
	return 0;
}


