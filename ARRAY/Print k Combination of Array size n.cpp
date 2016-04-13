#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Print k Combination of Array size n
	
	Algorithm:- (Source:https://en.wikipedia.org/wiki/Combination#Enumerating_k-combinations
				 & http://stackoverflow.com/questions/29910312/algorithm-to-get-all-the-combinations-of-size-n-from-an-array-java)
				 
	- The idea is to have array of size k keeping sequence of indices of elements from the input array (which are numbers from 0 to n - 1) in increasing order. 
	- Combinations then can be created by taking items by these indices from the initial array. So we need to generate all such index sequences.
	
	- First index sequence will be [0, 1, 2, ... , k - 1], 
	- On the second step it switches to [0, 1, 2,..., k], 
	- Then to [0, 1, 2, ... k + 1] and so on. 
	- The last possible sequence will be [n - k - 1, n - k - 2, ..., n - 1].

	- On each step, algorithm looks for the closest to the end item which can be incremented, increments it and fills up items right to that item. 
	
	Example:- Array = {A,B,C}, Here	n = 3, k = 2
	
	A B C
	0 1 2
	
	- First index sequence will be [0,1] as i said [0, 1, 2, ... , k - 1].
	- On the second step it switches to [0,2] as i said [0, 1, 2,..., k] increament last index.
	- The last possible sequence will be [1,2] as i said [n - k - 1, n - k - 2, ..., n - 1] increament last index which exceeds limit of n so we go to index last - 1 & increament on goint index by one.
	
*/


void printArrByIdx(char str[], int IdxRec[], int SizeIdx)
{
	for(int i=0; i<SizeIdx; i++)
	{
		cout<<str[IdxRec[i]];
	}
	cout<<endl;
}

void Combination(char str[], int n, int k)
{
	int i, IdxRec[k], count = 0;
	
	for(int i=0; (IdxRec[i] = i) < k - 1; i++);	// Initial indices 0,1
	
	bool isFinish = false;
	
	while( !isFinish )
	{
		printArrByIdx( str, IdxRec, k);
	
		for (i = k - 1; i >= 0 && IdxRec[i] == n - k + i; i--); 
	
		if( i < 0 )	
			isFinish = true;
		else
		{
			IdxRec[i]++;				// Increament last index
			
			for (++i ; i < k; i++);		// Increament sub sequent indices by 1
				IdxRec[i] = IdxRec[i-1] + 1;
		}			
		count++;
	}
	
	cout<< "Total Combination is "<<count<<endl;
}
 
 
int main()
{
    char str[] = "ABC";
    Combination( str, strlen(str), 2);
    return 0;
}
