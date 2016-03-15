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

/*
	Qyuestion :- Longest Common Sub-sequence(LCS)
	
	Application:- 
		- UNIX diff command give you difference between two text files
		- DNA genes comparison analysis of ATGS proteins structures,
		- Version control systems like Git, CVS, etc.
		
	Examples:
		LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
		LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
		
	We can use dynamic programming,	Because it has both property 
	1). Optimal Sub-structure & 2). Over-lapping Subproblem
	
	1). Optimal Sub-structure
	
		Examples: Consider the input strings “AGGTAB” and “GXTXAYB”.
		
			- If Last characters match, So length of LCS can be written as:
			L(“AGGTAB”, “GXTXAYB”) = 1 + L(“AGGTA”, “GXTXAY”), Now solve for “AGGTA” & “GXTXAY”
			
			- If Last characters do not match, So length of LCS can be written as:
			L(“AGGTA”, “GXTXAY”) = MAX ( L(“AGGT”, “GXTXAY”), L(“AGGTA”, “GXTXA”) ), Now solve for L(“AGGT”, “GXTXAY”) & L(“AGGTA”, “GXTXA”)
			
			So the LCS problem has optimal substructure property as the main problem can be solved using solutions to subproblems.
			
	2). Overlapping Subproblems
	
								lcs("ABD", "ADE")
	                       /    		               \
	         lcs("AB", "ADE")            	 		 lcs("ABD", "AD")
	         /            \                         	   |
	lcs("A", "ADE") lcs("AB", "AD")          		1 + lcs("AB", "A") 		
	 				/            \					/               \
			lcs("A", "AD")  lcs("AB", "A")	   lcs("A", "A")        lcs("AB", NULL)	
			
			
			In the above partial recursion tree, lcs("AB", "A") is being solved twice, so this forms overlap			
	
*/


int LongestCommonSubsequenceMemoization(char *Str1, char *Str2, int Str1Len, int Str2Len, int **Table)		// Memoization
{
	if( Str1Len == 0 || Str2Len == 0 )
		return 0;

	if( Table[Str1Len-1][Str2Len-1] == 0)
	{
		if( Str1[Str1Len-1] == Str2[Str2Len-1] )	
			Table[Str1Len-1][Str2Len-1] = 1 + LongestCommonSubsequenceMemoization( Str1,  Str2, Str1Len-1, Str2Len-1, Table);
		else
			Table[Str1Len-1][Str2Len-1] = max( LongestCommonSubsequenceMemoization( Str1,  Str2, Str1Len-1, Str2Len, Table), 
												LongestCommonSubsequenceMemoization( Str1,  Str2, Str1Len, Str2Len-1, Table));		
	}

	return 	Table[Str1Len-1][Str2Len-1];
} 


int LongestCommonSubsequenceTabulation(char *Str1, char *Str2, int Str1Len, int Str2Len, int **Table)		// Tabulation
{
	for(int i=0; i<=Str1Len; i++)
	{
		for(int j=0; j<=Str2Len; j++)
		{
			if( i==0 || j==0 )
				Table[i][j] = 0;
			else if( Str1[i-1] == Str2[j-1] )	
				Table[i][j] = Table[i-1][j-1] + 1;
			else
				Table[i][j] = max( Table[i-1][j], Table[i][j-1]);
		}
	}
	
	return Table[Str1Len][Str2Len];
}


int main()
{
	char Str1[] = "ABD";
	char Str2[] = "ADE";
	
	int Str1Len = strlen(Str1);
	int Str2Len = strlen(Str2);
	
	int **Table = new int*[Str1Len+1];
	
	for(int i=0; i <=Str1Len; i++)
	{
		Table[i] = new int[Str2Len+1];
		memset( Table[i], 0, sizeof(int) * (Str2Len +1) );
	}
	
	cout<<LongestCommonSubsequenceTabulation( Str1,  Str2, Str1Len, Str2Len, Table)<<endl;
	
	return 0;
}


