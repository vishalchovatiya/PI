#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])
/*
	Question :- Find minimum number of coins that make a given value.
	
	Input: coins[] = {9, 6, 5, 1}, V = 11
	Output: Minimum 2 coins required 6 & 5 
	
	Formula:- Deno(n) = min( Deno(n), 1 + Deno( n - All_Coin)) 
	
	Algo:- 
	
		Example:- Coins[] = { 1, 7, 10}  & Amount  = 15
		
									15(n)
								/	  |          \		
						         14(n-1)	8(n-7)	    5(n-10)	
					         	/		|		\
					(n-1)    (n-7)	(n-10)		|	(n-1)   (n-7)	(n-10)	
									|
									|
							   7(n-1)    1(n-7)	X(n-10)	
									|
									|
									|
						              0(n-1)   X(n-7)   X(n-10)		Here Final Value Become 0(Zero)																		
												So, Count height of tree & that would be our answer
										
*/

int minCoinMemoization(int Coins[], int Size, int Amount, int Table[])	// Memoization (Top-Down)
{
	if( Amount == 0 )	return 0;
	
	if( Table[Amount] == INT_MAX )
	{
		for(int i=0; i<Size; i++)
		{
			if( Amount - Coins[i] >= 0)
				Table[Amount] = min( Table[Amount], 1 + minCoinMemoization( Coins, Size, Amount-Coins[i], Table) );
		}	
	}
	
	return Table[Amount];
}


int minCoinTabulaion(int Coins[], int Size, int Amount, int Table[])	// Tebulation (Down-Top)
{
	Table[0] = 0;

	for(int Amt=1; Amt<=Amount; Amt++)	
	{
		for(int Coin=0; Coin<Size; Coin++)
		{
			if( Amt - Coins[Coin] >= 0)
				Table[Amt] = min( Table[Amt], Table[ Amt - Coins[Coin]] + 1 );
		}	
	}
	
	return Table[Amount];
}

int main()
{
	int Coins[] = { 1, 7, 10};
	int Amount = 15;
	
	int Table[Amount+1];
	
	for(int i=0; i<=Amount; i++)
		Table[i] = INT_MAX;
		
	Table[Amount] = minCoinTabulaion( Coins, SIZE(Coins), Amount, Table);	
	
	cout<<" 0 = "<<Table[1]<<endl;	
	
	cout<<Table[Amount]<<endl;	
	
	return 0;
}
