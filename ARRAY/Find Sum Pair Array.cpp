#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <map>

#include <iostream>
using namespace std;


#define SIZE(A) ( sizeof(A) / sizeof(A[0]))

/*

	Linear Time Solution:- Use Hash Map

*/

bool findSumPair( int A[], int Size, int Sum)
{
	map<int, bool> Table;
	
	for( int i=0; i<Size; i++)
	{
		int integer = Sum - A[i];
		
		if( Table[integer] == true )
		{
			cout<<" "<<A[i]<<" "<<integer<<endl;
			return true;
		}			
		
		Table[A[i]] = true;
	}
	
	return false;
}


int main()
{
	int A[] =  { -3, 1, 2};
	
	findSumPair( A, SIZE(A), 5);
	
	return 0;
}
