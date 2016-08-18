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
			(lenght2)   /------ MNA
			     / - - MAN----- MAN
	(lenght3)	    / 
	MAN - - - - - - -  AMN---- AMN------ANM	
			    \			   
			     \
			      \ - - NMA---- NMA
				       \--- NAM
		
	Algorithm:- (Source:https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order)
    1. Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
    2. Find the index l such that k < l & a[k] < a[l].
    3. Swap the value of a[k] with that of a[l].
    4. Reverse the sequence from a[k + 1] up to and including the final element a[n].
    
    For example, given the sequence [1, 2, 3, 4], the algo steps are as follows:

    1. Index k = 2, because 3(value at index 2) satisfies condition of being the largest index that is still less than a[k + 1] which is 4.
    2. Index l = 3, because 4(value at index 3) satisfy the condition a[k] < a[l] & k < l.
    3. The values of a[2] and a[3] are swapped to form the new sequence [1,2,4,3].
    4. The sequence after k-index a[2] to the final element is reversed. Because only one value lies after this index (the 3), the sequence remains unchanged in this instance. Thus the lexicographic successor of the initial state is permuted: [1,2,4,3].

*/

bool compare( char a, char b)
{
    return ( a < b ) ? 1 : 0;
}

 
int findL(char str[], int k, int end) 
{
	int l = end-1;
	
	for(int i=k+1; i<end; i++)
		if( str[k] < str[i] )
			l = i;
			
	return l;		
}


void sortedPermutations(char str[])
{
	int k, Size = strlen(str);
	
	stable_sort( str, str + Size, compare);
	
	bool isFinish = false;
	
	while( !isFinish)
	{
		cout<<str<<endl;		
		
		// Step 1: Find the largest index k such that a[k] < a[k + 1]
		for( k=Size-2; k>=0; k--)
			if( str[k] < str[k+1] )
				break;
		
		if( k == -1 )		
			isFinish = true;
		else
		{	// Step 2: Find the largest index l greater than k such that a[k] < a[l]
			int l = findL( str, k, Size);

			// Step 3: Swap the value of a[k] with that of a[l]
			swap( str[k], str[l] );
			
			// Step 4: Reverse the sequence from a[k + 1] up to and including the final element a[n]
			stable_sort( str+k+1, str + Size, compare);	
		}	
	}
}
 
int main()
{
    char str[] = "MAN";
    sortedPermutations( str );
    return 0;
}
