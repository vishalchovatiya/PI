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
	Question:- Print Matrix Diagonally
	
	Solution:- Print upward first & then downward
*/

#define ROW 5
#define COL 4

void diagonalPrintingOfMatrix(int M[][COL])
{
	bool isHalfPrinted = false;
	
	for(int col = 0; col<COL; col++)
	{
		isHalfPrinted = false;
		
		for(int row = 0; row<ROW && isHalfPrinted == false; row++)
		{	
			int r , c;	
			
			if( col == 0 )
				r = row, c = 0;
			else
				r = ROW-1, c = col, isHalfPrinted = true;
					
			do
			{
				cout<<" "<<M[r--][c++];
			
			}while( r >= 0 && c < COL );
			
			cout<<endl;
		}
	}
}

int main()
{
    int M[ROW][COL] =  {{1, 2, 3, 4},
				        {5, 6, 7, 8},
				        {9, 10, 11, 12},
				        {13, 14, 15, 16},
				        {17, 18, 19, 20}};
	 				        
    diagonalPrintingOfMatrix( M);
 
    return 0;
}
