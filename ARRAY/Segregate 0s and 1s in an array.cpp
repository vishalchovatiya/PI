#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*

	Question:- Segregate 0s and 1s in an array
	
	Input array   =  [0, 1, 0, 1, 0, 0, 1, 1, 1, 0] 
	Output array  =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1] 


	while left < right
		a) if( A[start] == 0 ), increament start index
		b) else if( A[end] == 1 ), decreament end index
		c) else swap
*/


int segregate0and1(int A[], int Size)
{
	int start = 0;
	int end = Size-1;
	
	while( start < end )
	{
		if( A[start] == 0 )
		{
			start++;
		}
		else if( A[end] == 1 )
		{
			end--;
		}
		else
		{
			swap( A[start], A[end]);
		}		
	}
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 0};
 
    segregate0and1(arr, 6);

    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
	
	return 0;
}
