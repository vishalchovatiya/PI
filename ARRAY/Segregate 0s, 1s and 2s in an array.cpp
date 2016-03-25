#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*

	Question:- Segregate 0s, 1s and 2s in an array
	
	Input array   =  [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1] 
	Output array  =  [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2] 


	while mid <= right
		a) if( A[mid] == 0 ), swap start & mid, increament start & mid index
		b) else if( A[mid] == 1 ), increament mid index
		c) else if( A[mid] == 2 ), swap end & mid, decreament end index
*/


int sort012(int A[], int Size)
{
	int start = 0;
	int mid = 0;
	int end = Size-1;
	
	
	while( mid <= end )		//0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1
	{
		switch( A[mid] )	
		{
			case 0:
					swap( A[start++], A[mid++]);
				break;
			
			case 1:
					mid++;
				break;
			
			case 2:
					swap( A[end--], A[mid]);
				break;		
		}
	}
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
	int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
 
    sort012(arr, SIZE(arr));
 
    printArray(arr, SIZE(arr));
	
	return 0;
}
