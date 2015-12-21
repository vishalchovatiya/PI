#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

#define LEFT(X)		(2*X+1)
#define RIGHT(X)	(2*X+2)

/*
	Question: Heap Sort
	
	Contents: 
		- Time Complexity
		- Applications
*/



/*-------------------------------------------- Utility Function ---------------------------------------------------*/

void swap(int &a, int &b)
{
	a = a ^ b ;
	b = a ^ b ;
	a = a ^ b ;
}

void printArray(char name[], int A[], int size)
{
	cout<<name;
	
	for(int i=0; i<=size; i++)
		cout<<" "<<A[i];
		
	cout<<"\n\n";
}

void Heapify(int A[], int size, int idx)		// O(Log n)
{
	int L = LEFT(idx), R = RIGHT(idx), max = idx;
	
	if( L <= size && A[L] > A[idx] )
		max = L;
		
	if( R <= size && A[R] > A[max] )
		max = R;	
		
	if( max != idx )	
	{
		swap( A[idx], A[max]);
		Heapify( A, size,  max);
	}	
}

void BuildMaxHeap(int A[], int size)
{
	for(int i=size/2; i>=0; i--)
		Heapify( A, size,  i);		
}

/*-----------------------------------------------------------------------------------------------------------------*/



/*------------------------------------------------ Heap Sort-------------------------------------------------------*/

/*

	# Time Complexity :- 
	
		
			
	# Application  :-	
	
		 - Priority  Queue
		 - Graph algorithms like Prim’s Algorithm and Dijkstra’s algorithm 

*/

void HeapSort(int A[], int size)		// n O(Log n)
{
	BuildMaxHeap( A, size);
	
	while(size != 0)
	{
		swap( A[0], A[size]);
		Heapify( A, --size,  0);		
	}
}
/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	HeapSort( A, 9);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
