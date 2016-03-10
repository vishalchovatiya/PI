#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Factorial formula N! = N x (N-1)!
*/


int main()
{
	int N = 4;
	int Fact[N];
	int FactorialStorage[N];
	
	Fact[0] = 1;
	Fact[1] = 1;
	
	for(int n=2; n<=N; n++)
	{
		Fact[n] = n * Fact[n-1];
	}
	
	cout<<Fact[N]<<endl;
	
	return 0;
}
