#include<string.h>
#include<stdlib.h>
#include<map>
#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Write All Permutation of String or Array
	
	Example:- Permutation N * (N-1)
	
								(lenght1)
				    (lenght2)/- MNA
			     / - - MAN----- MAN
	(lenght3)	/ 
	MAN - - - - - - -  AMN----- AMN
			   \			    ANM	
			    \
				 \ - - NMA---- NMA
				 		    \- NAM

*/

void Permutations(char str[], int start, int end)
{
	if( start == end )
		cout<<str<<endl;
	else
	{
		for( int i=start; i<=end; i++)
		{
			swap( str[i], str[start]);
			Permutations( str, start+1, end);
			swap( str[i], str[start]);
		}
	}	
}
 
int main()
{
    char str[] = "MAN";
    Permutations( str, 0, strlen(str)-1 );
    return 0;
}
