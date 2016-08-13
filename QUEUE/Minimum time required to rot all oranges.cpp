#include <iostream>
#include <queue>
using namespace std;

#define C 5
#define R 3

#define DEBUG(X)	cout<<"> "<<#X<<" 	= "<<X<<endl;

/*
Given a matrix of dimension m*n where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0: Empty cell
1: Cells have fresh oranges
2: Cells have rotten oranges 
So we have to determine what is the minimum time required so that all the oranges become rotten. 
A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right). 
If it is impossible to rot every orange then simply return -1.

Examples:
Input:  arr[][C] = { {2, 1, 0, 2, 1},
                     {1, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
Output:
All oranges can become rotten in 2 time frames.

Input:  arr[][C] = { {2, 1, 0, 2, 1},
                     {0, 0, 1, 2, 1},
                     {1, 0, 0, 2, 1}};
Output:
All oranges cannot be rotten.
*/

bool isLimitReach( queue<pair<int,int> >	&Q){
	return (Q.front().first == -1 && Q.front().second == -1 ) ? true : false;
}

void rotAdjecentOra(int arr[][C], int r, int c, queue<pair<int,int> >	&Q){	
	/*Rot Upper Orange*/
	if( r && arr[r-1][c] == 1 ){
		arr[r-1][c] = 2;
		Q.push(make_pair(r-1,c));
	}
	
	/*Rot Lower Orange*/
	if( r < R-1 && arr[r+1][c] == 1 ){
		arr[r+1][c] = 2;
		Q.push(make_pair(r+1,c));
	}
	
	/*Rot Left Orange*/
	if( c && c < C && arr[r][c-1] == 1 ){
		arr[r][c-1] = 2;
		Q.push(make_pair(r,c-1));
	}
	
	/*Rot Right Orange*/
	if( c < C-1 && arr[r][c+1] == 1 ){
		arr[r][c+1] = 2;
		Q.push(make_pair(r,c+1));
	}		
}

int timeToRotOrange(int arr[][C]){
	int time = -1;
	queue<pair<int,int> >	Q;
	
	for(int r = 0; r<R; r++)
		for(int c = 0; c<C; c++)
			if( arr[r][c] == 2 )
				Q.push(make_pair(r,c));
				
	while( !Q.empty()){		
		Q.push(make_pair(-1,-1));	// Limit Inserted
		while( !isLimitReach(Q)){	
			rotAdjecentOra( arr, Q.front().first, Q.front().second, Q);
			Q.pop();
		}		
		Q.pop();		
		time++;	
	}
	
	return time;
}

int main(){
	int arr[R][C] = { {2, 1, 0, 2, 1},
                      {1, 0, 1, 2, 1},
                      {1, 0, 0, 2, 1}};
                     
	cout<<timeToRotOrange( arr );

	return 0;
}
