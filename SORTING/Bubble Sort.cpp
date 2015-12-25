#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

/*
	Question: Bubble Sort 
	
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


/*------------------------------------------------ Bubble Sort---------------------------------------------------*/

/*

	# Bubble Sort :- 
	
		- Repeatedly swap adjecent elements
		- Bubble up smallest element after every iteration
					
	# Time Complexity :-   O(N*N)
	
	# Space Complexity :-  O(1) 

*/

void BubbleSort(int A[], int size)			// O(N*N)
{
	for(int i=0; i<size; i++)
	{
		 for(int j=0; j<size-1; j++)
		 {
		 	if( A[i] < A[j])
		 	{
		 		swap( A[i], A[j]);
		 	}
		 }
		 
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	BubbleSort( A, 10);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
