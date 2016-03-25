#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#define SIE(A)		sizeof(A)/sizeof(A[0])

/*
	Question:- Count all possible paths from bottom left to top right of a M x N matrix.
	
	Contraints:- You can only go either Right or UP
	
	
	Answer:-
			if( i == 0 && j == 0)				Table[i][j] = 1;
			
			else if( i == 0 || j == 0)			Table[i][j] = 1;
			
			else 								Table[i][j] = Table[i-1][j] + Table[i][j-1];
			
			
	Variant:- What if there is path OR point is block like (1,1) is blocked so all paths through that also

*/


/*-------------------------------  Naive Approach  --------------------------------*/

int numberOfPaths(int M, int N, int x = 1, int y = 1)
{
	if( M == y || N == x)
		return 1;
	
	return numberOfPaths( M, N, x+1, y)		/* Going Right */
		 + numberOfPaths( M, N,  x, y+1);   /* Going UP */
}

/*---------------------------------------------------------------------------------*/




/*----------------------------   Dynamic Programming   -----------------------------*/

int numberOfPathsDynamicProgramming(int M, int N)
{
	int Table[M][N];
	
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			Table[i][j] = 0;
		}
	}
	
	for(int i=0; i<M; i++)
	{
		for(int j=0; j<N; j++)
		{
			if( i == 0 && j == 0)				Table[i][j] = 1;
			
			else if( i == 0 || j == 0)			Table[i][j] = 1;
			
			else 								Table[i][j] = Table[i-1][j] + Table[i][j-1];
		}
	}
	
	return Table[M-1][N-1];
}

/*---------------------------------------------------------------------------------*/
 
int main()
{	
	cout << numberOfPathsDynamicProgramming(3, 3);
	
	return 0;
}


