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
	Question:- Print unique rows in a given boolean matrix
	
	Solution:- Using HashTable
	
	Limitation:- valid till 32 or 64 bit

*/

#define ROW 4
#define COL 5


void printRow(int Row[])
{
	for(int i=0; i<COL; i++)
		cout<<" "<<Row[i];
		
	cout<<endl;	
}


void setBit(int *value, int bitNumber)
{
	*value = *value|(1<<bitNumber);
}


void findUniqueRows(int M[][COL])
{
	map<int, int>	Table;

	for(int row = 0; row < ROW; row++)
	{	
		int HashTag = 0;
			
		for(int col = 0; col < COL; col++)
		{
			if( M[row][col] == 1 )
				setBit( &HashTag, col );
		}
		
		if( Table[HashTag] == 0 )	printRow( M[row]);
		
		Table[HashTag] = 1;
	}
}

int main()
{
    int M[ROW][COL] = { {0, 1, 0, 0, 1},
				        {1, 0, 1, 1, 0},
				        {0, 1, 0, 0, 1},
				        {1, 0, 1, 0, 0} };
 
    findUniqueRows( M );
 
    return 0;
}
