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

	Question:- Find Element in Sorted Rotated Array
	
	Input: arr[] = {3, 4, 5, 1, 2}   x = 1
  	Output: 3

	Answer :- Use Binary Search
	
	Algo:-
	
	- If A[mid] == Element
	- If A[end] >= A[mid] 
		a). If Element lie in between mid & end, start = mid + 1
		b). else end = mid - 1
	- If A[mid] <= A[start]
		a). IF Element lie in between mid & start, end = mid - 1
		b). else start = mid + 1	
		

*/


int BinarySearch(int A[], int Size, int Element)
{
	int start = 0;
	int end = Size-1;
	int mid;
	// 4, 5, 1, 2, 3
	while( start <= end )
	{
		mid = (start + end) / 2;

		if( A[mid] == Element )
			return mid;
			
		else if( A[end] >= A[mid] )	
		{
			if( Element >= A[mid] && Element <= A[end] )
				start = mid + 1;
			else
				end = mid - 1;	
		}
		
		else if( A[mid] <= A[start] )
		{
			if( Element <= A[mid] && Element >= A[start] )
				end = mid - 1;	
			else
				start = mid + 1;
		}
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
	int arr[] = { 4, 5, 1, 2, 3};
	
	int Element = 2;
	
	cout<<BinarySearch( arr, SIZE(arr), Element)<<endl;

    //printArray(arr, SIZE(arr));
	
	return 0;
}


