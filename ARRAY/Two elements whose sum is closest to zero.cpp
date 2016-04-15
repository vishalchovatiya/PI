#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>


using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Two elements whose sum is closest to zero
	
	Algorithm:-
		1) Sort all the elements of the input array.
		2) Use two index variables l and r to traverse from left and right ends respectively. Initialize l as 0 and r as n-1.
		3) sum = a[l] + a[r]
		4) If sum is -ve, then l++
		5) If sum is +ve, then r–
		6) Keep track of abs min sum.
		7) Repeat steps 3, 4, 5 and 6 while l < r Implementation
		
	Note: when you find value nearest to zero you have to take absolute value	
*/

void printArr( int A[], int n)
{
	for( int i=0; i<n; i++)
	{
		cout<<" "<<A[i];
	}
	cout<<endl;
}

bool compare(int a, int b)
{
	return a<b ? 1: 0 ;
}


void minSumPair( int A[], int n)
{
	stable_sort( A, A+n, compare);
	
	printArr( A, n);
	
	int low = 0;
	int high = n-1;
	int min = INT_MAX;
	
	pair<int,int> Pair;
	
	while( low < high )
	{
		int sum = A[low] + A[high];
		
		if( abs(sum) < abs(min) )
		{
			min = sum;
			Pair.first = A[low];
			Pair.second = A[high];			
		}
		else if( sum < 0 )
			low++;
		else
			high--;
	}
	
	cout<<" first = "<<Pair.first<<" second = "<<Pair.second<<endl;
}

 
int main()
{
	int arr[] = {1, 60, -10, 70, -80, 85};

	minSumPair(arr, SIZE(arr));
    
    return 0;
}


