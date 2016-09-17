#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <iomanip>
#include <iomanip>
#include <climits>
#include <string.h>
using namespace std;

#define N	5

/*
	Question : Knight Tour 
	
	Note: Solution Could Be Open OR Closed Tour

*/

void printBoard( int Board[][N]){
	for(int r=0;r<N;r++){
		cout<<"|";
		for(int c=0;c<N;c++){
			cout<< setw(3)<<Board[r][c]<<"|";
		}	
		cout<<endl;
		cout<<"---------------------"<<endl;
	}
	cout<<endl;
}

bool isSafeMove(int x, int y){
	
	if( x >= 0 && x < N &&
		y >= 0 && y < N )
		return true;
	return false;	
}

int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

bool SolveKnightTour(int Board[][N], int moveNo, int x, int y){
	
	if( moveNo == N*N )	return true;

	Board[x][y] = moveNo++;
    	
    for(int k=0; k<8; k++){
    	if( Board[x+xMove[k]][y+yMove[k]] == 0 && isSafeMove(x+xMove[k], y+yMove[k]) ){			
			if( SolveKnightTour( Board, moveNo, x+xMove[k], y+yMove[k] ) )
				return true;				
		}				
    }	
	Board[x][y]  = 0;
	return false;
}

int main() {
	int Board[N][N] = {  	{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0},
							{0, 0, 0, 0, 0}};	
	
	printBoard( Board);
	if(SolveKnightTour( Board, 1, 0, 0))
		printBoard( Board);
		
    return 0;
}
