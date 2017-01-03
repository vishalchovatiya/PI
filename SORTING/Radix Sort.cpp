#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

#define ELEMENTS(A) sizeof(A)/sizeof(A[0])

#define LIMIT 10

/*
	Question: Radix Sort 
	
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


/*------------------------------------------------ Radix Sort---------------------------------------------------*/

/*

	# Radix Sort :- 

	# Time Complexity :-   O(N * digit)
	
	# Space Complexity :-  O(N + N)
	
	NOTE:
	
	- It not work for negative number
	- It works till max input range is known

*/

inline int nthDigit(int Number, int Digit)
{
	int result = 0;
	
	while( Number > 0 && Digit > 0)
	{
		result = Number % 10;
		Number /= 10;
		
		Digit--;
	}
	
	if( Digit)
		return 0;
	
	return result;
}



void CountingSort(int A[], int Size, int Digit)		
{
	int OccurenceCount[LIMIT];
	memset( OccurenceCount, 0, sizeof(OccurenceCount));

	/*------------------------ Count Occurence --------------------------*/	
	for(int i=0; i<Size; i++)
		OccurenceCount[ nthDigit( A[i], Digit) ]++;
		
	for(int i=1; i<LIMIT; i++)
		OccurenceCount[i] = OccurenceCount[i] + OccurenceCount[i-1];
	/*-------------------------------------------------------------------*/	
		
	int Output[Size];
	
	// Sort main array in temp array
	for(int i=Size-1; i >= 0; i--)
		Output[ --OccurenceCount[ nthDigit( A[i], Digit)] ] = A[i];
		
	// Re-settle main array	
	for(int i=0; i<Size; i++)
		A[i] = Output[i];
}

void RadixSort(int A[], int Size)
{
	int noOfDigit = 3;
	
	for(int i=1; i<=noOfDigit; i++)
	{
		CountingSort( A, Size, i);
	}
}


/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
	
	printArray( "Before Sort :", A, ELEMENTS(A));
	
	RadixSort( A, ELEMENTS(A));
		
	printArray( "After Sort  :", A, ELEMENTS(A));	
	
	return 0;
}
