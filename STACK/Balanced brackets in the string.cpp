#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*

	Q: Given a string with unbalanced brackets how do you remove minimum number
  		of extra brackets so that you are left with balanced brackets in the string
  		
  	e.g )( -> empty string
       (a) -> (a)
       ((mnq)abc))) -> ((mna)abc)
       (abc)(( -> (abc)	
		
	Test cases:
	   - empty string
	   - String with )(
	   - String with all opening brackets
	   - String with all closing brackets
	   - String with mix of open close brackets and characters between them
	   - String with already balanced parenthesis
	   
	NOTE:- Handle Edge cases carefully, There are lot of edge cases
 		
*/

int RemoveUnbalancedBrackets(char String[])
{
	stack<int> S;
	int count = 0;
	
	for(int i=0; i<strlen(String); i++)
	{
		if( String[i] != '('  &&  String[i] != ')' )
			continue;	
			
		if( String[i] == '(' )	
		{
			S.push(i);
		}			
		else if( !S.empty() && String[S.top()] == '(' && String[i] == ')')
		{
			S.pop();
		}			
		else
		{
			S.push(i);				
		}
			
	}

	while( !S.empty())
	{
		String[S.top()] = ' ';
		S.pop();
		count++;				
	}
			
	return count;
}




int main()
{
	char S[] = "(A)(B)(C)";
	
	cout<<" " <<RemoveUnbalancedBrackets( S)<<" Backet Removed "<<endl;
	
	cout<<S<<endl;
	
	return 0;
}



