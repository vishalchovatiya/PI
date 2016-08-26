#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

/*
	Question: Given nxn board place n queen on this board so that they dont attack each other. One solution is to find any placement of queens which do not attack each other. Other solution is to find all placements of queen on the board.
	
	Algo: Backtracking
	Step 1: We start putting queens row-by-row
	Step 2: We check if current place is safe to place queen,
			2.a : If yes then recur for next row to place queen on iterator
			2.b : Else we return false
	Step 3: If we unablt to place next queen, then we backtrack last placed queen & find new way		
*/

#define QUEENS			4
#define PLACE_QUEEN		'Q'
#define UNPLACE_QUEEN	'0'

void printBoard(char Board[][QUEENS]){
	for(int r=0;r<QUEENS;r++){
		cout<<"|";
		for(int c=0;c<QUEENS;c++){
			cout<< setw(3)<<Board[r][c]<<"|";
		}	
		cout<<endl;
		cout<<"-----------------"<<endl;
	}
	cout<<endl;
}

bool isSafe(int r, int c, list<pair<int,int>>	&l){
	if(l.empty())	return true;
	else{
		for(list<pair<int,int>> :: iterator i=l.begin(); i!=l.end(); i++){
			/* Check Row OR Column Not Under Attack */
			if( (*i).first == r || (*i).second == c )	
				return false;
			/* Check South-West to North-East Diagonal Not Under Attack */	
			if( r + c == ((*i).first + (*i).second) )	 
				return false;
			/* Check Noth-West to South-East Diagonal Not Under Attack */	
			if( r - c == ((*i).first - (*i).second) )	 
				return false;	
		}
	}
	return true;
}

/* Step 1: We start putting queens row-by-row */
bool SolveNQueens(char Board[][QUEENS], list<pair<int,int>>	&l, int Row=0){
	for(int r=Row;r<QUEENS;r++){
		for(int c=0;c<QUEENS;c++){
			/* Step 2: We check if current place is safe to place queen */
			if( isSafe(r, c, l) ){
				Board[r][c] = PLACE_QUEEN;
				l.push_back(make_pair(r,c));
				
				/* Check if all Queens are placed or not */
				if( l.size() == QUEENS )	
						return true;
						
				if(SolveNQueens( Board, l, r+1)){
					return true;
				}
				/* Step 3: Backtrack: Unable to put next Queen, Unplace last queen */
				else{
					pair<int,int> lastPlacedQueen = l.back();
					Board[lastPlacedQueen.first][lastPlacedQueen.second] = UNPLACE_QUEEN;
					l.pop_back();
				}
			}
		}
	}
	return false;
}

int main() {
	char Board[QUEENS][QUEENS] = {  {'0', '0', '0', '0'},
							        {'0', '0', '0', '0'},
							        {'0', '0', '0', '0'},
							        {'0', '0', '0', '0'}};	
	list<pair<int,int>>	l;
	
	printBoard( Board);
	if(SolveNQueens( Board, l))
		printBoard( Board);
		
    return 0;
}
