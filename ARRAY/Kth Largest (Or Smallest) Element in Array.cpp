#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*

	Input: arr[] = {7, 10, 4, 3, 20, 15}		  k = 3
	     
	Output: 7

	Answer:- Partition Logic of Quick Sort

*/

int Partition(int A[], int start, int end)
{	//7, 10, 4, 3, 20, 15
	int pIndex = start;
	int Pivot = A[end];	
	
	for( int i = start; i<end; i++)
	{
		if( A[i] < Pivot )
		{
			swap( A[i], A[pIndex]);
			pIndex++;
		}
	}
	
	swap( A[end], A[pIndex]);
	
	return pIndex;
}

int KthLargest(int A[], int Size, int K)
{
	int start = 0;
	int end = Size-1;
	K--;
	
	while( start <= end )
	{
		int pIndex = Partition( A, start, end);

		if( pIndex == K )
			return A[pIndex];
		else if( pIndex < K )	
			
			start = pIndex + 1;	
		else
			end = pIndex - 1;
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
	int arr[] = { 7, 10, 4, 15, 20, 3};
	
	int Largest = 1;

	cout<<KthLargest( arr, SIZE(arr), Largest )<<endl;
	
	return 0;
}


