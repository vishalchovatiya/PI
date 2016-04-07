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
	Question:- 
	
	Input:- [10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60]
	Output:- indexes 3 and 8.

	Input:- [0, 1, 15, 25, 6, 7, 30, 40, 50]
	Output:- indexes 2 and 5
	
	Algorithm:-
	
	1) Find the candidate unsorted subarray
		a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element. In the above example 1, s is 3 (index of 30).
		b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order). Let e be the index of such an element. In the above example 1, e is 7 (index of 31).
	
	2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray.
		a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max. min and max for [30, 25, 40, 32, 31] are 25 and 40 respectively.
		b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element. There is no such element in above example 1.
		c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element. In the above example 1, e is changed to 8 (index of 35)
	
	3) Print s and e.	

*/

void MinimumLengthUnsorted( int A[], int Size)
{
	// Step 1.a
	int Left = 0;
	for(int i=0; i<Size-1; i++)
	{
		if( A[i] > A[i+1] )
		{
			Left = i;
			break;
		}			
	}
	
	// Step 1.b
	int Right = 0;
	for(int i=Size-1; i>0; i--)
	{
		if( A[i-1] > A[i] )
		{
			Right = i;
			break;
		}			
	}
	
	// Step 2.1
	int min = A[Left], max = A[Left];	
	for(int i=Left; i<=Right; i++)
	{
		if( A[i] < min )	
			min = A[i];
		
		if( A[i] > max )	
			max = A[i];			
	}
	
	// Step 2.b
	for(int i=0; i<Left; i++)
	{
		if( A[i] > min )
		{
			Left = i;
			break;
		}			
	}	
	
	// Step 2.c
	for(int i=Size-1; i>=Right+1; i--)
	{
		if( A[i] < max )
		{
			Right = i;
			break;
		}			
	}
	
	cout<<" Left = "<<Left<<" Right = "<<Right<<endl;
}


int main()
{
	int A[] =  { 10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	
	MinimumLengthUnsorted( A, SIZE(A));
	
	return 0;
}
