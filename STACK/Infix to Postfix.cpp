#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*
	# Algorithm:
	
		-	Use Stack to store breakets & Operators	
		-	4 Possibilies of characters in string 1. (, 2. ), 3. Operators(+,-,*,/,^), 4. Other
*/

bool IsOperator(char Operator)
{
	if( Operator == '+' || Operator == '-' || Operator == '*' || Operator == '/'|| Operator == '^')
		return true;
	return false;	
}

int Precedence(char Op)
{
	switch (Op)
    {
	    case '+':
	    case '-':
	        return 1;
	 
	    case '*':
	    case '/':
	        return 2;
	 
	    case '^':
	        return 3;
	}
	
	return -1;
}

bool HasHigherPrecedence(char Op1, char Op2)
{
    if ( Precedence(Op1) >= Precedence(Op2))
    	return true;
    return false;	
}

char* InfixToPostfix(char String[])
{
	stack<char> S;
	int idx = 0;
	char *ResStr = new char[strlen(String)];
	
	for(int i=0; i<strlen(String); i++)
	{
		if( String[i] == '(')
		{
			S.push(String[i]);
		}
		else if( String[i] == ')' )
		{
			while( S.top() != '(')
			{
				ResStr[idx++] = S.top();
				S.pop();
			}
			S.pop();
		}
		else if( IsOperator(String[i]) )
		{
			if ( !S.empty()  &&  HasHigherPrecedence(S.top(), String[i]) )
			{
				ResStr[idx++] = S.top();
				S.pop();
			}	
			S.push(String[i]);
		}
		else
		{
			ResStr[idx++] = String[i];
		}			
	}
	
	while( !S.empty())
	{
		ResStr[idx++] = S.top();
		S.pop();
	}
	
	return ResStr;
}

int main()
{
	char String[] = "(A+B-C)^V";	//(A+B-C)^V = AB+C-V^
	
	cout<<InfixToPostfix( String)<<endl;
	
	return 0;
}



