#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

/*
	Question: Insertion Sort 
	
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


/*------------------------------------------------ Insertion Sort---------------------------------------------------*/

/*

	# Insertion Sort :- 
	
		- Start with index 1, extract element and make hole
		- Shift elements having lesser value than extracted element
		- Repeat this process for all element
					
	# Time Complexity :-   O(N*N)
	
	# Space Complexity :-  O(1) 

*/

void InsertionSort(int A[], int size)			// O(N*N)
{
	for(int i=1; i<size; i++)
	{
		int hole = i;
		int element = A[hole];
		
		while( hole > 0 && A[hole-1] > element)		 
		{
			A[hole] = A[hole-1];
			hole--;
		}
		A[hole] = element;
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	InsertionSort( A, 10);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
