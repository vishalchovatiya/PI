#include<iostream>
#include <queue>

using namespace std;

/*
	Question:- Count number of islands where every island is row-wise and column-wise separated
	
	Solution:- Count all 'X' situated on top-leftmost corners of given matrix. We can check if a ‘X’ is top left or not by checking following conditions.

	1) ‘X’ is top of rectangle if the cell just above it is a ‘O’
	2) ‘X’ is leftmost of rectangle if the cell just left of it is a ‘O’
*/

#define R	6
#define C	3

bool checkForAdjucent(char M[][C], int r, int c)
{
	
}

int NoOfIseland(char M[][C])
{
	int count = 0;
	
	for(int r=0; r<R; r++)
	{
		for(int c=0; c<C; c++)
		{
			if( M[r][c] == 'X' )
			{
				if( ( r == 0 || M[r-1][c] == 'O' ) 
				 && ( c == 0 || M[r][c-1] == 'O' ) )
					count++;
			}
		}	
	}
	
	return count;
}

int main()
{
	char M[R][C] = {{'O', 'O', 'O'},
	                {'X', 'X', 'O'},
	                {'X', 'X', 'O'},
	                {'O', 'O', 'X'},
	                {'O', 'O', 'X'},
	                {'X', 'X', 'O'}};
	                
	cout<<NoOfIseland( M);                
 
    return 0;
}
