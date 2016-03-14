#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <climits>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


#define SIZE(A)		sizeof(A)/sizeof(A[0])

/*
	Question:- Given a sequence of matrices, find the most efficient way to multiply these matrices together 
				OR Parenthesization of matrix multiplication to improve calculation speed
	
	- There are three Matrix say A, B, C with dimension of 1x2, 2x3, 3x4 respectively
	
	- if Multiply (AB)C = (1x2x3) x C = 6 + (1x3) x C = 6 + (1x3) x (3x4) = 6 + (1x3x4) = 6 + 12 =, gives 18
	
	- if Multiply A(BC) = A x (2x3x4) = A x 24(2x4) = 24 + (1x2) x (2x4) = 24 + (1x2x4) = 24 + 8 =, gives 32
	
	- By above different parenthesization, we conclude that (AB)C is best way to parenthesize
	
	- This problem has both DP Properties Optimal Sub-structure & Overlapping Sub-problem
	
	- M[i,j] = M[i,k] + M[k+1,j] + P[i-1]*P[k]*P[j]
*/




/*----------------------Naive Method( Brute Force)------------------------------------------------------------------*/

int MatrixChainOrder(int P[], int i, int j)
{
	if( i==j )	return 0;
	
	int Min = INT_MAX;
	
	for(int k=i; k<j; k++)
	{
		Min = min( Min, MatrixChainOrder( P, i, k) + MatrixChainOrder( P, k+1, j) + P[i-1] * P[k] * P[j] );
	}
	
	return Min;
}

/*------------------------------------------------------------------------------------------------------------------*/





/*------------------- Memoization OR Top-Down ---------------------------------------------------------------------*/

int MatrixChainOrderDynamic(int P[], int i, int j, int **Table)
{
	if( i==j )	return 0;
	
	if( Table[i][j] == INT_MAX )
	{	
		for(int k=i; k<j; k++)
		{
			Table[i][j] = min( Table[i][j] , MatrixChainOrderDynamic( P, i, k, Table) + MatrixChainOrderDynamic( P, k+1, j, Table) + P[i-1] * P[k] * P[j] );
		}
	}
	
	return Table[i][j];
}

/*------------------------------------------------------------------------------------------------------------------*/






int main()
{
	int A[] = { 1, 2, 3, 4};
	
	int **Table;
	
	Table = new int*[SIZE(A)];
	
	for(int Row=0; Row<SIZE(A); Row++)
	{
		Table[Row] = new int[SIZE(A)];
		for(int Column=0; Column<SIZE(A); Column++)
		{
			Table[Row][Column] = INT_MAX;
		}
	}
	
	cout<<MatrixChainOrder( A, 1, SIZE(A)-1);
	
	return 0;
}
