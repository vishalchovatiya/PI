#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Merge Sort ( Divide and Conquer algorithm)
	
	Contents: 
		- Algo
		- Time Complexity
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

/*-----------------------------------------------------------------------------------------------------------------*/


void Merge(int A[], int L[], int R[], int L_len, int R_len)
{
	int i=0, j=0, k=0;
	
	while ( i < L_len && j < R_len )
	{
		if( L[i] < R[j] )
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while ( i < L_len )
	{
		A[k] = L[i];
		i++;
		k++;
	}
	while ( j < R_len )
	{
		A[k] = R[j];
		j++;
		k++;
	}
}

/*------------------------------------------------ Merge Sort-------------------------------------------------------*/

/*

	# Merge Sort ( Divide and Conquer algorithm) :- 
	
		- Recure for left half untill array size becomes less than 2
		- Merge array with comparing element
		- Do same thing with right half
			
	# Time Complexity :-   N O(Log N) 
	
	# Space Complexity :-  O(N) 

*/

void MergeSort(int A[], int size)			// n O(Log n)
{
	if( size < 2)	return;
	
	int L_len = size/2;
	int R_len = size - L_len;
	
	int L[L_len], R[R_len];
	
	for(int i=0; i<L_len ;i++)
		L[i] = A[i];
		
	for(int i=0; i<R_len ;i++)
		R[i] = A[i+L_len];
		
	MergeSort( L, L_len);
	MergeSort( R, R_len);		
		
	Merge( A, L, R, L_len, R_len);	
}

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] = { 2, 22, 11, 4, 1, 6, 9, 10, 15, 12};
	
	printArray( "Before Sort :", A, 9);
	
	MergeSort( A, 10);
		
	printArray( "After Sort  :", A, 9);	
	
	return 0;
}
