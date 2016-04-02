#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))


/*

	Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
	Ouptut: Sum found between indexes 2 and 4
	
	Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
	Ouptut: Sum found between indexes 1 and 4
	
	Input: arr[] = {1, 4}, sum = 0
	Output: No subarray found
	
	Answer :- 
	
	Algorithm :- 
	
	- Add element starting
	- If total is greater than sum, start removing element from back untill total become less than given sum
	- Look continuos for given sum
	
*/


void printArray(int arr[], int start, int arr_size)
{
    int i;
    for (i = start; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}



void SubArrayWithGivenSum(int A[], int Size, int Sum)
{
	int Total = 0;
	int start = 0;
		
	for(int i=0; i<Size; i++)
	{
		Total = Total + A[i];
		
		if( Total == Sum )
		{
			printArray( A, start, i+1);
			return;
		}
		
		while( Total > Sum )
		{
			Total = Total - A[start];			
			
			
			start++;	
		}
	}
	
	cout<<"NO Sub-Array Present with Sum = "<<Sum<<endl;
}


int main()
{
	int arr[] = { 15, 2, 4, 8, 9, 5, 10, 23};
	
	int Sum = 23;
	
	SubArrayWithGivenSum( arr, SIZE(arr), Sum);
	
	return 0;
}


