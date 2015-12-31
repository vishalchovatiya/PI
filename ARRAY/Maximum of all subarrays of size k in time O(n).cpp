#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define SIZE(A) ( sizeof(A) / sizeof(A[0]))


int main()
{
	int A[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int k = 3;
	int Max = A[0];
	
	for(int i=0; i<SIZE(A); i++)
	{		
		if( A[i] >= Max)	
		{
			Max = A[i];
		}
		
		if( i >= k-1 )
		{
			cout<<" "<<Max<<endl;	
		}		
	}
	
	
	return 0;
}
