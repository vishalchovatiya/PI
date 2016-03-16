#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
using namespace std;


#define SIZE(A) 	sizeof(A)/sizeof(A[0])

int min(int x, int y, int z) 
{
   return min(min(x, y), z);
}



/*
	Question :- Given two strings str1 and str2 and below operations that can performed on str1. 
				Find minimum number of edits (operations) required to convert ‘str1' into ‘str2'.

					    Insert
					    Remove
					    Replace
							
	Application:- 
		- Display all the words in a dictionary that are near proximity to a given word\incorrectly spelled word.
		
	Examples:
		LCS for input Sequences “ABD” and “ABE” is require one operation replace.
		LCS for input Sequences “geek” and “gesek” is require insertion of 's'.
		
	We can use dynamic programming,	Because it has both property 
	1). Optimal Sub-structure & 2). Over-lapping Subproblem
	
	1). Optimal Sub-structure
	
		Examples: Consider the input strings “AB” and “AE”.
				
	   	If last characters match, Ignore last characters and get count for remaining strings. So we recur for lengths m-1 and n-1.
	    Else If last characters are not match), we consider all operations and take minimum
	        Insert: Recur for m and n-1
	        Remove: Recur for m-1 and n
	        Replace: Recur for m-1 and n-1

		So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.
			
	2). Overlapping Subproblems
	
									lcs("AB", "AE")
		                       /    		 |              \
		          lcs("AB", "A")     lcs("A", "AE")	   lcs("A", "A")
		   /          |            \                      	   |
	lcs("AB","") lcs("A","A") lcs("A", "")          	lcs("", "") 
				
			
		In the above partial recursion tree, lcs("A","A") is being solved twice, so this forms overlap			
	
*/




int EditDistance(char *str1 , char *str2 , int m ,int n, int **Table)		// Foraml Method
{
    if (n == 0 || m == 0) return 0;

    if (str1[m-1] == str2[n-1])
        return EditDistance(str1, str2, m-1, n-1, Table);

    return 1 + min ( EditDistance(str1,  str2, m,   n-1, Table),    	// Insert
                     EditDistance(str1,  str2, m-1, n,   Table),   	// Remove
                     EditDistance(str1,  str2, m-1, n-1, Table) 		// Replace                     
                   );
}



	
int EditDistanceMemoization(char *str1 , char *str2 , int m ,int n, int **Table)		// Memoization
{
    if (n == 0 || m == 0) return 0;

    if (str1[m-1] == str2[n-1])
        Table[m][n] = EditDistanceMemoization(str1, str2, m-1, n-1, Table);

	else
    	Table[m][n] = 1 + min (  EditDistanceMemoization(str1,  str2, m,   n-1, Table),    	// Insert
			                     EditDistanceMemoization(str1,  str2, m-1, n,   Table),   	// Remove
			                     EditDistanceMemoization(str1,  str2, m-1, n-1, Table) 		// Replace                     
			                   );
                   
    return Table[m][n];               
}



int EditDistanceTabulation(char *str1 , char *str2 , int m ,int n)		// Tabulation
{
	int Table[m+1][n+1];

	for(int i=0; i<=m; i++)
	{
		for(int j=0; j<=n; j++)
		{
			if (i == 0 || j == 0) 	Table[i][j] = 0;

		    else if (str1[i-1] == str2[j-1])
		        Table[i][j] = Table[i-1][j-1];
	
			else
		    	Table[i][j] = 1 +  min( Table[i][j-1],  	// Insert
					               		Table[i-1][j],    	// Remove
					               		Table[i-1][j-1]     // Replace                     
					                   );
		}	
	}
	

	return Table[m][n];
}


int main()
{
	char Str1[] = "geek";
	char Str2[] = "gesek";
	
	int Str1Len = strlen(Str1);
	int Str2Len = strlen(Str2);
	
	int **Table = new int*[Str1Len+2];
	
	for(int i=0; i <=Str1Len+2; i++)
	{
		Table[i] = new int[Str2Len+2];
		memset( Table[i], 0, sizeof(int) * (Str2Len +2) );
	}
	
	cout<<EditDistanceTabulation( Str1,  Str2, Str1Len, Str2Len)<<endl;
	
	return 0;
}


