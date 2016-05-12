#include<iostream>
#include <queue>

using namespace std;

/*
	Question:- Given a matrix of ‘O’ and ‘X’, replace ‘O’ with ‘X’ if surrounded by ‘X’
	
	Solution:- This is mainly an application of Flood-Fill algorithm. 

	Step 1) Traverse four edges of given matrix and replace all ‘O’ with a special character ‘-‘ by calling floodFill Algo.
	
	Step 2) Replace all 'O' with 'X' & '-' with 'O'

*/

#define N	6

void printMatrix(char M[][N])
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

void floodFill( char M[][N], int x, int y, char oColor, char nColor )
{
	if( x >= N || y >= N || x < 0 || y < 0 )	return;
	
	if( M[x][y] != oColor )	return;
	else
		M[x][y] = nColor;
	
	floodFill( M, x-1, y, oColor, nColor );
	floodFill( M, x+1, y, oColor, nColor );
	floodFill( M, x, y-1, oColor, nColor );
	floodFill( M, x, y+1, oColor, nColor );
}


void ReplaceOwithX(char M[][N])
{
	// Step 1: Replace all 'O' with '-' 
	// Top Line
	for(int i=0; i<N; i++)
		if( M[0][i] == 'O' )
			floodFill( M, 0, i, 'O', '-');
	
	// Left Line		
	for(int i=0; i<N; i++)
		if( M[i][0] == 'O' )
			floodFill( M, i, 0, 'O', '-');		
			
	// Bottom Line
	for(int i=0; i<N; i++)
		if( M[N-1][i] == 'O' )
			floodFill( M, N-1, i, 'O', '-');
	
	// Right Line		
	for(int i=0; i<N; i++)
		if( M[i][N-1] == 'O' )
			floodFill( M, i, N-1, 'O', '-');		
			
	// Step 2: Replace all 'O' with 'X' & '-' with 'O'
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			if ( M[i][j] == '-')
				M[i][j] = 'O';
			else if( M[i][j] == 'O' )		
				M[i][j] = 'X';	
}

int main()
{
	char M[][N] =   {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'}};
	            
	printMatrix( M);
				    
	ReplaceOwithX( M);   
	
	printMatrix( M);             
 
    return 0;
}
