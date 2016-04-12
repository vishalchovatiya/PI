#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
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
	
	Input: arr[] = {1, 0, 1, 1, 1, 0, 0}
	Output: 1 to 6 (Starting and Ending indexes of output subarray)
	
	Input: arr[] = {1, 1, 1, 1}
	Output: No such subarray
	
	Input: arr[] = {0, 0, 1, 1, 0}
	Output: 0 to 3 Or 1 to 4
	
	Solution:-
	
	1) Consider all 0 values as -1. The problem now reduces to find out the maximum length subarray with sum = 0.
	2) Create a temporary array sumleft[] of size n. Store the sum of all elements from arr[0] to arr[i] in sumleft[i]. This can be done in O(n) time.
	3) There are two cases, the output subarray may start from 0th index or may start from some other index. We will return the max of the values obtained by two cases.
	4) To find the maximum length subarray starting from 0th index, scan the sumleft[] and find the maximum i where sumleft[i] = 0.
	5) Now, we need to find the subarray where subarray sum is 0 and start index is not 0. This problem is equivalent to finding two indexes i & j in sumleft[] such that sumleft[i] = sumleft[j] and j-i is maximum. To solve this, we can create a hash table with size = max-min+1 where min is the minimum value in the sumleft[] and max is the maximum value in the sumleft[]. The idea is to hash the leftmost occurrences of all different values in sumleft[]. The size of hash is chosen as max-min+1 because there can be these many different possible values in sumleft[]. Initialize all values in hash as -1
	6) To fill and use hash[], traverse sumleft[] from 0 to n-1. If a value is not present in hash[], then store its index in hash. If the value is present, then calculate the difference of current index of sumleft[] and previously stored value in hash[]. If this difference is more than maxsize, then update the maxsize.
	7) To handle corner cases (all 1s and all 0s), we initialize maxsize as -1. If the maxsize remains -1, then print there is no such subarray.

*/

void subArrayEqual0s1s( int A[], int Size)
{
	//1, -1, 1, 1, 1, -1, -1
	int SumLeft[Size];
	int Min = A[0], Max = A[0];
	
	SumLeft[0] = ( (SumLeft[0] == 0 )? -1 : 1);
	
	for(int i=1; i<Size; i++)	
	{
		SumLeft[i] = SumLeft[i-1] + ( A[i] == 0 ? -1 : 1 );
		
		Min = min( Min, SumLeft[i]);
		
		Max = max( Max, SumLeft[i]);		
	}
	cout<<" SumLeft: ";
	printArray( SumLeft, 0, Size);
	cout<<"Min = "<<Min<<" Max = "<<Max<<endl;
	
	int hash[Max-Min+1];
  
    for (int i=0; i<Max-Min+1; i++)	// Initialize hash table
        hash[i] = -1;
        
	int maxsize = -1, startindex;
	
	for (int i=0; i<Size; i++)
    {
        // Case 1: when the subarray starts from index 0
        if (SumLeft[i] == 0)
        {
           maxsize = i+1;
           startindex = 0;
        }
  
        // Case 2: fill hash table value. If already filled, then use it
        if (hash[SumLeft[i]-Min] == -1)
            hash[SumLeft[i]-Min] = i;
        else
        {
            if ( (i - hash[SumLeft[i]-Min]) > maxsize )
            {
                maxsize = i - hash[SumLeft[i]-Min];
                startindex = hash[SumLeft[i]-Min] + 1;
            }
        }
    }
    
    cout<<"    hash: ";
    printArray( hash, 0, Max-Min+1);
    if ( maxsize == -1 )
        printf("No such subarray");
    else
        printf("%d to %d", startindex, startindex+maxsize-1);
}


int main()
{
	int A[] =  { 1, 0, 1, 1, 1, 0, 0};
	
	subArrayEqual0s1s( A, SIZE(A));
	
	return 0;
}
