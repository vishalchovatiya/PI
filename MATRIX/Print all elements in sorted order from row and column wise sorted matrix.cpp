#include<string.h>
#include<stdlib.h>
#include<map>
#include<stack>
#include<time.h>
#include<vector>
#include<iostream>
#include <algorithm>
#include <conio.h>
#include <windows.h>
#include <queue>
#include <iterator> 


using namespace std;

/*
	Question:- Print all elements in sorted order from row and column wise sorted matrix
	
	Solution:- Use Priority Queue
*/

#define N 4

struct
{
	bool operator()( int const &a, int const &b)
	{
		return a > b;
	}
}compare;

void printSorted(int M[][N])
{
	priority_queue< int,  vector<int>,  decltype(compare)> 	minHeap;
	
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			minHeap.push(M[i][j]);
		}		
	}
	
	while( !minHeap.empty() )
	{
		cout<<minHeap.top()<<" ";
		minHeap.pop();	
	}
}

int main()
{
    int M[N][N] = {   {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
	 				        
    printSorted( M);
 
    return 0;
}
