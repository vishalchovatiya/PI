#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Find a sorted subsequence of size 3 in linear time
	
	Examples:

	Input:  arr[] = {12, 11, 10, 5, 6, 2, 30}
	Output: 5, 6, 30
	
	Input:  arr[] = {1, 2, 3, 4}
	Output: 1, 2, 3 OR 1, 2, 4 OR 2, 3, 4
	
	Input:  arr[] = {4, 3, 2, 1}
	Output: No such triplet


	Algorithm:- 
	
	1) Create an auxiliary array smaller[0..n-1]. 
		smaller[i] should store the index of a number which is smaller than arr[i] and is on left side of arr[i]. smaller[i] should contain -1 if there is no such element.
	2) Create another auxiliary array greater[0..n-1]. 
		greater[i] should store the index of a number which is greater than arr[i] and is on right side of arr[i]. greater[i] should contain -1 if there is no such element.
	3) Finally traverse both smaller[] and greater[] and find the index i for which both smaller[i] and greater[i] are not -1.
	
	
*/


void printArr(int str[], int start, int end)
{
	for(int i=start; i<end; i++)
	{
		cout<<" "<<str[i];
	}
	cout<<endl;
}

void find3Numbers(int A[], int n)
{
	int smaller[n], greater[n];
	
	// Step 1:	
	smaller[0] = -1;
	int min = 0;
	for(int i=1; i<n; i++)
	{
		if( A[i] <= A[min] )
		{
			min = i;
			smaller[i] = -1;
		}
		else
			smaller[i] = min;
	}
	
	// Step 2:
	greater[n-1] = -1;
	int max = n-1;
	for(int i=n-2; i>=0; i--)
	{
		if( A[i] > A[max] )
		{
			max = i;
			greater[i] = -1;		
		}
		else
			greater[i] = max;
	}
	
	// Step 3:
	for (int i = 0; i < n; i++)
	{
	   if (smaller[i] != -1 && greater[i] != -1)
	   {
	      printf("%d %d %d", A[smaller[i]],
	             A[i], A[greater[i]]);
	      return;
	   }
	}	
	
	printf("No such triplet found");
}
 
int main()
{
    int arr[] = {1, 2, 3, 4};

    find3Numbers(arr, SIZE(arr));

    return 0;
}

