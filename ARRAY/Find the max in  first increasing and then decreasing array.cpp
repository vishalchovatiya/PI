#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

#define FIRST	1
#define LAST	0

#define MINUS(mid,Size)	(mid+Size-1) % Size

#define PLUS(mid,Size)		(mid+1) % Size

/*

	Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
	Output: 500
	
	Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
	Output: 50
	
	Corner case (No decreasing part)
	Input: arr[] = {10, 20, 30, 40, 50}
	Output: 50
	
	Corner case (No increasing part)
	Input: arr[] = {120, 100, 80, 20, 0}
	Output: 120

	Answer :- Use Modified Binary Search
	
	Algorithm :- 
	i) If the mid element is greater than both of its adjacent elements, then mid is the maximum.
	ii) If mid element is greater than its next element and smaller than the previous element then max lies on left side of mid
	iii) If mid element is smaller than its next element and greater than the previous element then max lies on right side of mid

*/


int BinarySearch(int A[], int Size)
{	// 10, 20, 30, 40, 50
	int start = 0;
	int end = Size-1;
	int mid;

	while( start <= end )
	{
		mid = (start + end) / 2;

		if( A[mid] > A[MINUS(mid,Size)] && A[mid] > A[PLUS(mid,Size)])
			return A[mid];
		
		else if ( A[mid] > A[MINUS(mid,Size)] && A[mid] < A[PLUS(mid,Size)] )	
			start = mid + 1;
			
		else 
			end = mid - 1;	
	}
	
	return -1;
}


void printArray(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


int main()
{
	int arr[] = { 120, 100, 80, 20, 0};
	
	cout<<BinarySearch( arr, SIZE(arr))<<endl;
	
	return 0;
}


