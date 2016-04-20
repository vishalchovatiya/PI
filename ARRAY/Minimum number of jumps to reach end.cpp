#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>


using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Minimum number of jumps to reach end

	Example:
	
	Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
	Output: 3 (1-> 3 -> 8 ->9)
	
	First element is 1, so can only go to 3. Second element is 3, so can make at most 3 steps eg to 5 or 8 or 9.
	
	
	Naive & Linear Time Approach
	
*/

void printArr( int A[], int n)
{
	for( int i=0; i<n; i++)
	{
		cout<<" "<<A[i];
	}
	cout<<endl;
}


int minJumpsToEnd(int A[], int End, vector<int> &v)
{	// 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9
	v.push_back(A[0]);
	if( A[0] > End )
		return 1;
	
	int maxJump = A[0];
	int maxJumpIndex = 0;
	
	for(int i=1; i<=A[0]; i++)
	{
		if( A[i] >= maxJump )
		{
			maxJump = A[i];
			maxJumpIndex = i;
		}
	}
	
	return 1 + minJumpsToEnd( A+maxJumpIndex, End-maxJump, v);
}

 
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	vector<int> result;
	
	cout<<minJumpsToEnd( arr, SIZE(arr), result)<<endl;
	
	for(vector<int> :: iterator it = result.begin(); it!=result.end(); it++)
	{
		cout<<" "<<*it;
	}
	cout<<endl;
	   
    return 0;
}


