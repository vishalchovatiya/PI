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
#include <iterator> 


using namespace std;

/*
	Question:- Inplace M x N size matrix transpose
	
	Solution:- Using HashTable for transposed location
*/

#define ROW 6
#define COL 6


void Print2DArray(int A[][COL])
{
    for(int r = 0; r < ROW; r++)
    {
        for(int c = 0; c < COL; c++)
           cout<<" "<<A[r][c];
        printf("\n");
    }
 
    printf("\n\n");
}

void transposeMatrix(int M[][COL])
{
	bool t[ROW][COL];
	
	for(int i = 0; i<ROW; i++)
		memset( t[i], 0, sizeof(t[i]));
	
	for(int row = 0; row<ROW; row++)
	{
		for(int col = 0; col<COL; col++)
		{
			if( t[row][col] == false )
			{
				swap( M[row][col], M[col][row] );
				t[col][row] = true;
			}
				
		}	
	}
}

int main()
{
    int M[ROW][COL] =    {{ 1,   2,   3,   4,   5,   6},
						  { 7,   8,   9,  10,  11,  12},
						  {13,  14,  15,  16,  17,  18},
						  {19,  20,  21,  22,  23,  24},
						  {25,  26,  27,  28,  29,  30},
						  {31,  32,  33,  34,  35,  36}};
	 				        
	Print2DArray( M);
 
    transposeMatrix( M);
    
    Print2DArray( M);
 
    return 0;
}
