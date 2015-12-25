#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Selection Sort 
	
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


/*------------------------------------------------ Selection Sort---------------------------------------------------*/

/*

	# Selection Sort :- 
	
		- Assume first Element is smaller and traverse array for smaller than first element
		- As soon as we get smaller element swap it with first
		- Do same thing for rest of elements	
			
	# Time Complexity :-   O(N*N)
	
	# Space Complexity :-  O(1) 

*/

void SelectionSort(int A[], int size)			// O(N*N)
{
	for(int i=0; i<size-1; i++)
	{
		 int Imin = i;
		 for(int j=i+1; j<size; j++)
		 {
		 	if( A[Imin] > A[j])
		 	{
		 		Imin = j;
		 	}
		 }
		 swap( A[Imin], A[i]);
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	SelectionSort( A, 10);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
