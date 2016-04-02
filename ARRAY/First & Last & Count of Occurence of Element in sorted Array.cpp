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

/*

	Question:- Find the First( Or Last Or Count of) Occurence of given number
	
	Input: arr[] = {1, 1, 2, 2, 2, 2, 3, 4}   x = 2
  	Output: 2

	Answer :- Use Binary Search

*/


int Occurence(int A[], int Size, int Element, bool isFirst)
{
	int start = 0;
	int end = Size-1;
	int mid;
	int result = -1;

	while( start <= end )
	{
		mid = (start + end) / 2;
		
		if( A[mid] == Element )
		{
			result = mid;
			
			if( isFirst)
				end = mid - 1;
			else
				start = mid + 1;
		}
		else if( A[mid] > Element )
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
	
	return result;
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
	int arr[] = {1, 1, 2, 2, 2, 2, 3, 4};
	
	int Element = 1;
 
	cout<< "First Occurence = "<< Occurence( arr,  SIZE(arr), Element, FIRST) << endl;
	cout<< "Last  Occurence = "<< Occurence( arr,  SIZE(arr), Element, LAST) << endl;
	cout<< "Count = "<< Occurence( arr,  SIZE(arr), Element, LAST) - Occurence( arr,  SIZE(arr), Element, FIRST) + 1<<endl;
 
    //printArray(arr, SIZE(arr));
	
	return 0;
}


