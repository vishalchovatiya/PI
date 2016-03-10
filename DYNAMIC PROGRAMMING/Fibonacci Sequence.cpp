#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Properties:
		Optimal Sub-structure
		Overlapping Sub-problems
	Types:
		Top-Down, Memoization
		Bottom-Up, Tabulation
*/

long fib(long N)
{
	if( N <= 1)		return N;
	
	return fib( N-1 ) + fib( N-2 );
}

long fibDynProg(long N, long Store[])	// Top-Down, Memoization
{
	if( N <= 1)		return N;
	
	if( Store[N] != -1)		return Store[N];
	
	Store[N] = fibDynProg( N-1, Store ) + fibDynProg( N-2, Store );
	
	return Store[N];
}



int main()
{
	int Seq = 43;
	
	long *Store = new long[Seq];
	
	memset(Store, -1, sizeof(long) * Seq);

	cout<<"Normal Computation of Fibonacci : "<<endl;
	for(long i=0; i<Seq; i++)
	{
		cout<<" "<<fib(i);
	}
	cout<<endl;
	
	cout<<"Dynamic Programming(Top-Down, Memoization) of Fibonacci : "<<endl;
	for(long i=0; i<Seq; i++)
	{
		Store[i] = fibDynProg(i, Store);
		cout<<" "<<Store[i];
	}
	cout<<endl;
	
	memset(Store, 0, sizeof(int)*Seq);
	cout<<"Dynamic Programming(Bottom-Up, Tabulation) of Fibonacci : "<<endl;
	Store[0] = 0;
	Store[1] = 1;
	for(long i=2; i<Seq; i++)
	{
		Store[i] = Store[i-1] + Store[i-2];
		cout<<" "<<Store[i];
	}
	cout<<endl;
	
	return 0;
}
