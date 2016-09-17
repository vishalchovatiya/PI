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

#define N	4

/*
	Question : Rat in maze
	
	Note: DFS

*/

void printMaze( int Maze[][N]){
	for(int r=0;r<N;r++){
		cout<<"|";
		for(int c=0;c<N;c++){
			cout<< setw(3)<<Maze[r][c]<<"|";
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

bool isSafeMove(int Maze[][N], int x, int y){
	
	if( x >= 0 && x < N &&
		y >= 0 && y < N &&
		Maze[x][y] == 0)
		return true;
	return false;	
}

int xDirection[4] = {  -1, 1,  0, 0 };
int yDirection[4] = {  0,  0, -1, 1 };

bool FindWay(int Maze[][N], int x, int y, int destX, int destY){
	
	Maze[x][y] = 2;
	if( x == destX && y == destY ) return true;	

	for(int k=0; k<4; k++){
		if( isSafeMove( Maze, x+xDirection[k], y+yDirection[k]) ){
			if( FindWay( Maze, x+xDirection[k], y+yDirection[k], destX, destY) )
				return true;
		}
	}
	Maze[x][y] = 0;
	
	return false;
}

int main() {
	int Maze[N][N]  =  { 	{0, 0, 0, 0},
					        {1, 1, 0, 1},
					        {0, 1, 0, 0},
					        {1, 1, 1, 1}};
	int sourceX = 0;
	int sourceY = 0;
	
	int destX = 2;
	int destY = 3;	
		
	printMaze( Maze);
	if(FindWay( Maze, sourceX, sourceY, destX, destY))
		printMaze( Maze);
		
    return 0;
}
