#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])

/*
	Question:- Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
	
	Examples:
	
	 Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
	 Output: 6  (j = 7, i = 1)
	
	 Input: {9, 2, 3, 4, 5, 6, 7, 8, 18, 0}
	 Output: 8 ( j = 8, i = 0)
	
	 Input:  {1, 2, 3, 4, 5, 6}
	 Output: 5  (j = 5, i = 0)
	
	 Input:  {6, 5, 4, 3, 2, 1}
	 Output: -1 
	  
	Algorithm:-
	- We construct two auxiliary arrays LMin[] and RMax[] such that LMin[i] holds the smallest element on left side of arr[i] including arr[i], and RMax[j] holds the greatest element on right side of arr[j] including arr[j]. 
	- We traverse both of these arrays from left to right. 
	- While traversing LMin[] and RMax[] if we see that LMin[i] is greater than RMax[j], then we must move ahead in LMin[] (or do i++) because all elements on left of LMin[i] are greater than or equal to LMin[i]. 
	- Otherwise we must move ahead in RMax[j] to look for a greater j – i value.

*/

void maxIndexDiff(int A[], int Size)
{
	int LMin[Size];
	LMin[0] = A[0];
	for(int i=0; i<Size; i++)
	{
		LMin[i] = min( LMin[i-1], A[i]);
	}
	
	int RMax[Size];
	RMax[Size-1] = A[Size-1];
	for(int i=Size-2; i>=0; i--)
	{
		RMax[i] = max( RMax[i+1], A[i]);
	}
	
	int i = 0, j = 0, maxDiff = -1;
    while (j < Size && i < Size)
    {
        if (LMin[i] < RMax[j])
        {
            maxDiff = max(maxDiff, j-i);
            j = j + 1;
        }
        else
            i = i+1;
    }
    
    cout<<maxDiff<<endl;
}

int main()
{
	int A[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
	
	maxIndexDiff( A, SIZE(A));
	
    return 0;
}


