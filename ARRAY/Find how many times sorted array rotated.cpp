#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

#define IN_RANGE_MINUS(mid,Size)	(mid+Size-1)%Size

#define IN_RANGE_PLUS(mid,Size)		(mid+1)%Size

/*

	Question:- Find how many times sorted array rotated
	
	Input: arr[] = { 4, 5, 1, 2, 3} 
  	Output: 2

	Answer :- Use Binary Search ( Use Property of pivoted element (prev & next both are greater than pivot))

*/


int BinarySearch(int A[], int Size)
{
	int start = 0;
	int end = Size-1;
	int mid;
	
	if( A[start] <= A[end] )
		return -1;

	while( start <= end )
	{
		mid = (start + end) / 2;
	
		int Prev = A[IN_RANGE_MINUS(mid,Size)];
		int Next = A[IN_RANGE_PLUS(mid,Size)];
	
		if( Prev >= A[mid] && Next >= A[mid] )
			return mid;		
			
		else if( A[end] >= A[mid] )	
			end = mid - 1;
			
		else
			start = mid + 1;
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
	int arr[] = { 5, 1, 2, 3, 4};
	
	cout<<BinarySearch( arr, SIZE(arr))<<endl;

	return 0;
}


