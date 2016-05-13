#include<iostream>
#include <queue>
#include <map>

using namespace std;

/*
	Question:- In Place rotation of Matrix by 90 degree

	Example:- 
	
	A = {1,2,3,
	     4,5,6,
	     7,8,9}
	
	then after 90 degree rotation A becomes:
	
	A = {7,4,1,
	     8,5,2,
	     9,6,3}
	     
	Solution:
	
	Step 1) transpose
	
	1 4 7
	2 5 8
	3 6 9
	
	Step 2) or change columns to rotate right

	7 4 1
	8 5 2
	9 6 3

*/

#define N	3


void printMatrix(int M[][N])
{
	for(int i=0; i<N; i++)
    {
    	for(int j=0; j<N; j++)
        	cout << M[i][j] << " ";
    	cout << endl;
    }
    cout << endl;
    cout << endl;
}

void rotateMatrixBy90Degree( int M[][N])
{
	// Step 1) transpose
	for(int i=0; i<N; i++)
    {
    	for(int j=i; j<N; j++)
        {
        	swap( M[i][j], M[j][i] );
    	}
    }	
    
    // Step 2) or change columns to rotate right
    for(int i=0; i<N/2; i++)
    {
    	for(int j=0; j<N; j++)
        {
        	swap( M[j][i], M[j][N-i-1] );
    	}
    }
}

int main()
{
	int M[][N] ={{1,2,3},
		         {4,5,6},
     			 {7,8,9}};
     			 
	printMatrix( M);
				    
	rotateMatrixBy90Degree( M);   
	
	printMatrix( M);
 
    return 0;
}
