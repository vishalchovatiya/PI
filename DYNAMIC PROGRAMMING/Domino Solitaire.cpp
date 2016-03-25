#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

/*
	=> Question
	
	
	 - In Domino Solitaire, you have a grid with two rows and many columns. Each square in the grid contains an integer. 
	 - You are given a supply of rectangular 2 × 1 tiles, each of which exactly covers two adjacent squares of the grid. 
	 - You have to place tiles to cover all the squares in the grid such that each tile covers two squares and no pair of tiles overlap.

	- The score for a tile is the difference between the bigger and the smaller number that are covered by the tile. 
	- The aim of the game is to maximize the sum of the scores of all the tiles.
	
	- Here is an example of a grid, along with two different tilings and their scores.
							  Tiling 1										Tiling 2
	--------------		----   -------   ----						------    --------
	|8 |6 |2 |3 |		|8 |   |6 |2 |   |3 |						|8 |6 |    |2 |3 |
	--------------		----   -------   ----						------    --------
	|9 |7 |1 |2 |		|9 |   |7 |1 |   |2 |						|9 |7 |    |1 |2 |
	--------------		----   -------   ----						------    --------
	
	                Tiling 1 is 12 = (9-8)+(6-2)+(7-1)+(3-2) 		Tiling 2 is 6 = (8-6)+(9-7)+(3-2)+(2-1).
	                
	- There are other tilings possible for this grid, but you can check that Tiling 1 has the maximum score among all tilings.	                
	- Your task is to read the grid of numbers and compute the maximum score that can be achieved by any tiling of the grid.
	
	=> Solution hint
	
	Recursively find the best tiling, from left to right. You can start the tiling with one vertical tile or two horizontal tiles. Use dynamic programming to evaluate the recursive expression efficiently.
	
	=> Input format
	
	The first line contains one integer N, the number of columns in the grid. This is followed by 2 lines describing the grid. Each of these lines consists of N integers, separated by blanks.
	
	=> Output format
	
	A single integer indicating the maximum score that can be achieved by any tiling of the given grid.
	
	=> Test Data:
	
	For all inputs, 1 = N = 105. Each integer in the grid is in the range {0,1,...,104}.
	
	=> Sample Input:
	
	4
	8 6 2 3
	9 7 1 2
	
	=> Sample Output:
	
	12

*/


int main() 
{
	int n, A[100001][2], B[100001], i, j;
	
    cin>>n;
    for(i=0;i<2;i++)
    {
        for(j=0;j<n;j++)
            cin>>A[j][i];
    }

    B[0] = abs(A[0][0] - A[0][1]);
    
    B[1] = max( B[0] + abs(A[1][0]-A[1][1]) , abs(A[1][0]-A[0][0])+abs(A[1][1]-A[0][1]) );
    
    for(i=2;i<n;i++)
    {
    	B[i] = max( B[i-1] + abs(A[i][0]-A[i][1]) , B[i-2] + abs(A[i][0]-A[i-1][0]) + abs(A[i][1]-A[i-1][1]) );
    }
        

    cout<<B[n-1]<<endl;
	
	return 0;
}


