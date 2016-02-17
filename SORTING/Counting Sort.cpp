#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

#define ELEMENTS(A) sizeof(A)/sizeof(A[0])

#define LIMIT 10

/*
	Question: Counting Sort 
	
	Contents: 
		- Algo
		- Time Complexity
*/



/*-------------------------------------------- Utility Function ---------------------------------------------------*/


void printArray( const char name[], int A[], int size)
{
	cout<<name;
	
	for(int i=0; i<size; i++)
		cout<<" "<<A[i];
		
	cout<<"\n\n";
}

/*-----------------------------------------------------------------------------------------------------------------*/


/*------------------------------------------------ Counting Sort---------------------------------------------------*/

/*

	# Counting Sort :- 
	
	For simplicity, consider the data in the range 0 to 9. 
	Input data: 1, 4, 1, 2, 7, 5, 2
	  1) Take a count array to store the count of each unique object.
	  Index:     0  1  2  3  4  5  6  7  8  9
	  Count:     0  2  2  0   1  1  0  1  0  0
	
	  2) Modify the count array such that each element at each index 
	  stores the sum of previous counts. 
	  Index:     0  1  2  3  4  5  6  7  8  9
	  Count:     0  2  4  4  5  6  6  7  7  7
	
	The modified count array indicates the position of each object in 
	the output sequence.
	 
	  3) Output each object from the input sequence followed by 
	  decreasing its count by 1.
	  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
	  Put data 1 at index 2 in output. Decrease count by 1 to place 
	  next data 1 at an index 1 smaller than this index.

			
	# Time Complexity :-   O(N)
	
	# Space Complexity :-  O(N + N)
	
	NOTE:
	
	- It not work for negative number
	- It works till max input range is known
	- Used as a subroutine of radix sort

*/

void CountingSort(int A[], int Size)		
{
	int OccurenceCount[LIMIT];
	memset( OccurenceCount, 0, sizeof(OccurenceCount));

	/*------------------------ Count Occurence --------------------------*/	
	for(int i=0; i<Size; i++)
		OccurenceCount[ A[i] ]++;
		
	for(int i=1; i<LIMIT; i++)
		OccurenceCount[i] = OccurenceCount[i] + OccurenceCount[i-1];
	/*-------------------------------------------------------------------*/	
		
	int Output[Size];
	
	// Sort main array in temp array
	for(int i=0; i<Size; i++)
		Output[ --OccurenceCount[A[i]] ] = A[i];
		
	// Re-settle main array	
	for(int i=0; i<Size; i++)
		A[i] = Output[i];
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 2, 1, 9, 5};
	
	printArray( "Before Sort :", A, ELEMENTS(A));
	
	CountingSort( A, ELEMENTS(A));
		
	printArray( "After Sort  :", A, ELEMENTS(A));	
	
	return 0;
}
