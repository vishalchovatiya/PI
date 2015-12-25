#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

/*
	Question: Quick Sort ( Divide and Conquer algorithm)
	
	Contents: 
		- Algo
		- Time Complexity
*/



/*-------------------------------------------- Utility Function ---------------------------------------------------*/

void printArray(char name[], int A[], int size)
{
	cout<<name;
	
	for(int i=0; i<=size; i++)
		cout<<" "<<A[i];
		
	cout<<"\n\n";
}

/*-----------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------ Quick Sort-------------------------------------------------------*/

/*

	# Quick Sort ( Divide and Conquer algorithm) :- 
	
		- Parition array such that left side elmetes of Pivot(Last element) are smaller and right sides elements are larger
		- Recure for left half untill array start less than end
		- Do same thing with Right half
			
	# Time Complexity :-   N O(Log N) 
	
	# Space Complexity :-  O(1) 

*/

int Partion(int A[], int start, int end)
{
	int Pivot = A[end];
	int pIndex = start;
	
	for(int i=start; i<end; i++)
	{
		if( A[i] < Pivot )
		{
			swap(A[i], A[pIndex]);
			pIndex++;
		}
	}
	swap(A[pIndex], A[end]);

	return pIndex;	
}

void QuickSort(int A[], int start, int end)			// N O(Log N)
{
	if( start < end )
	{
		int pIndex = Partion( A, start, end);
		QuickSort( A, start, pIndex-1);
		QuickSort( A, pIndex+1, end);	
	}	
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	QuickSort( A, 0, 9);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
