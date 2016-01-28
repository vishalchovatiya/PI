#include <stdio.h>
#include <string.h>


/*

	Question :- 
	A string is given which has letters from English alphabet and parentheses. 
	The depth of a letter is defined as the number of balanced parentheses it is surrounded by. 
	Write a  C program to find the depth of each letter in the input string.
	
	Explanation: 	(a(b)((cd)e)f)g
	
		g is at depth 0
		a and f are at depth 1
		b and e are at depth 2
		c and d are at depth 3
	
	Input Constraints:
	
		1) Input string can be of length 1 to 100.
		2) The input will have only ‘(‘ , ‘)’ and letters from English alphabet.
		3) There will be no repetition of letters.
		4) Only lowercase letters are used.
		5) The letters can be in any sequence.  
		6) The parentheses are always well balanced. Every '(' has a matching ')' that follows it later in the string. Every ')' has a matching '(' before it in the input string.
		7) Notice that there are no space in the string.
	
	Input: An array of characters
	Output: 
		1) The depth of each letter separated by a space.
		2) The order of the depth of the letters should be the same  order in which the letters appear in the input.
		3)To mark the end of the output it should end with a space and a ‘#’ character.
	
	Example 1:
		Input: (a(b)((cd)e)f)g
		Output: 1 2 3 3 2 1 0 #
	
	Example 2:
		Input: p(r(q))(s)
		Output: 0 1 2 1 #
	
	In this example, letters are appearing in the order p followed by r followed by q and s. They have depth of 0, 1, 2 and 1 respectively. Note that the depth is not printed in the order p,q,r,s (the alphabetical order) but p,r,q,s (the order in which they appear in the input string).
				
*/

void PrintDepth(char Str[])
{
	int idx = 0;
	int Braces = 0;
	
	while( Str[idx] != '\0')
	{
		if ( Str[idx] == '(' )
			Braces++;
		else if ( Str[idx] == ')' )	
			Braces--;
		else
			printf(" %d",Braces);
			
		idx++;
	}
	printf(" #");
}


int main()
{
	char String[101];
	
	scanf("%s", String);
	
	PrintDepth(String);
	
	
	return 0;
}



