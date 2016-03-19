#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#define MAX(a,b) ( a > b ? a : b)

#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*
	Answer:- 
		1). Brute Force O(NxNxN) (3 Loop(or 2 Loop), subArraySize Loop, Array traverse loop, sum of sub array loop)
		2). Divide & conquer ( Modified Quick Sort, while traversing reverse(for left sub array) & forward(for right sub array))
		3). Kadane's Algo (Assumption: Atleast one positive number, Logic :- sum up elements, record max of all positive sum
	
	Question:-
		Write an efficient C program to find the largest sum of contiguous subarray within an one-dimensional array of integers.  
		A contiguous subarray of an array is defined as the sequence of elements that are in any continuous set of indices that are valid within an array.
	
	Lets take an example of an array {5,-3, 4}. 
	Possible contiguous subarray combinations are {5}, {-3}, {4}, {5,-3}, {-3,4} and {5,-3,4}. 
	Note that {5,4} is not a valid subarray as the indices of 5 and 4 are not continuous.
	
	The contiguous subarray  {5,-3,4} has the largest sum 6. 	
	
	Input Constraints:
	
		First line : array size (N), where 1<= N<=100
	
		Second line : N integers separated by spaces 
	
		where each number Ni satisfies
	
		-10000 <= Ni <=10000
	
	Output Constraints:
	
		Single integer SUM which is the largest sum of all possible contiguous subarrays.
*/

/*---------------------------------------Brute Force Method-----------------------------------------*/

long long MaxSumSubarrayBruteForce(int A[], int ArrSize)		// O(NxNxN)
{
	// -2, -3, 4, -1, -2, 1, 5, -3
	long long ans = -10000;
	int subArraySize = 0;
	int i = 0, j = 0;
	
	for( subArraySize = 1; subArraySize<=ArrSize; subArraySize++)
	{		
		for( i = 0; i<ArrSize; i++)
		{			
			if( i + subArraySize > ArrSize )	
				break;
				
			long long sum = 0;	
			for( j = i; j<(i+subArraySize); j++)	
				sum = sum + A[j];
				
			if( sum > ans )
				ans = sum;
		}
	}
	
	return ans;
}

long long MaxSumSubarrayOptimizedBruteForce(int A[], int ArrSize)		// O(NxN)
{
	long long ans = INT_MIN;
	
	for(int i=0; i<ArrSize; i++)
	{
		long long sum = 0;
		for(int SubArrSize = 1; SubArrSize<=ArrSize; SubArrSize++)
		{
			if( i + SubArrSize > ArrSize )
				break;
			
			sum = sum + A[SubArrSize + i - 1];
			
			ans = MAX( ans, sum);
		}
	}
	
	return ans;
}


/*---------------------------------------Divide & Conquer-----------------------------------------------*/


long long MaxSumSubarrayDivideAndConquer(int A[], int ArrSize)		// O(N Log N)
{	//-2, -3, 4, -1, -2, 1, 5, -3
	if( ArrSize == 1 )	return A[0];

	int Middle = ArrSize/2;		
	
	long long L_Max = MaxSumSubarrayDivideAndConquer( A, Middle);		
	long long R_Max = MaxSumSubarrayDivideAndConquer( A+Middle, ArrSize-Middle);		
	
	int LeftSum = INT_MIN, RightSum = INT_MIN;
	long long sum = 0;
	
	// Find Max sum from Left Sub array, by traversing backward
	for(int i=Middle; i>=0; i--)
	{
		sum = sum + A[i];
		LeftSum = MAX( LeftSum, sum);
	}
	
	// Find Max sum from Right Sub array, by traversing forward
	sum = 0;
	for(int i=Middle+1; i<=ArrSize; i++)
	{
		sum = sum + A[i];
		RightSum = MAX( RightSum, sum);
	}
	
	return MAX(  MAX( L_Max , R_Max ) ,  (LeftSum + RightSum) );
}


/*---------------------------------------------Kadane's Algo----------------------------------------------*/


long long MaxSumSubarrayKadaneAlgo(int A[], int ArrSize)		// O(N)
{
	int i=0;
	long long sum = 0, ans = 0;
	
	for(i=0; i<ArrSize; i++)
	{
		if( sum + A[i] > 0)
			sum += A[i];
		else
			sum = 0;
		
		ans = MAX( sum, ans);
	}
	
	return ans;
}

/*---------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------Optimal Solution--------------------------------------------*/


long long MaxSumSubarrayKadaneAlgo(int input[], int size)		// O(N)
{
	int i=0;
	
	long long max_so_far = input[0];
	
	long long curr_max = input[0];
	
	for (i = 1; i < size; i++)
	{
		curr_max = ( input[i] > curr_max+input[i] ) ? input[i] : curr_max+input[i];
		
		max_so_far =( max_so_far > curr_max ) ? max_so_far : curr_max;
	}
	
	return max_so_far;
}

/*---------------------------------------------------------------------------------------------------------*/



int main()
{
	int A[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
	
	printf("SIZE(A) = %d\n %d ", SIZE(A)-1, MaxSumSubarrayOptimizedBruteForce( A, SIZE(A)));
	
	return 0;
}
