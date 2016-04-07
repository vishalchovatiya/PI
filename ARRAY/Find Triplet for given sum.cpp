#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
#include <algorithm>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

void printArray( int A[], int start, int end)
{
	for(int i=start; i<end; i++)
		cout<<" "<<A[i];
	cout<<endl;	
}
/*
	Question:- {12, 3, 4, 1, 6, 9} & given sum is 24
	Output:-  Triplet (12, 3 and 9)
	
	Algo:-
	
	- Sort array, iterate with three indexes, left, right & 0 to N

*/

bool sortCompare(int a, int b)
{
	return (a<b);
}

bool findTripletSum( int A[], int Size, int Sum)
{
	stable_sort( A, A+Size, sortCompare);

	for(int i=0; i<Size; i++)
	{
		int Left = 0;
		int Right = Size-1;
		
		while( Left < Right )
		{
			int Total = A[i] + A[Left] + A[Right];
			
			if( Total == Sum )
			{
				cout<<" "<<A[i]<<" "<<A[Left]<<" "<<A[Right]<<endl;
				return true;
			}	
			else if( Total > Sum )	
				Right--;
			else
				Left++;	
		}
	}
	
	return false;
}


int main()
{
	int A[] =  { 12, 3, 4, 1, 6, 9};
	
	findTripletSum( A, SIZE(A), 24);
	
	return 0;
}
