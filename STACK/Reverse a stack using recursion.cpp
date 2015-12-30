#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*

	# Algorithm:
	
		- Hold all values in Function Call Stack until the stack becomes empty. 
		- When the stack becomes empty, insert all held items one by one at the bottom of the stack. 
		- Handle Case & Base Casse : If Stack Empty insert item at bottom	
		
	# Time Complexity:- O(NxN)
	
			
*/

void InsertAtBottom( stack<int> &S, int Popped)
{
	// Handle Case & Base Casse : If Stack Empty insert item at bottom	
	if( S.empty() )
	{
		S.push(Popped);
	}	
	else
	{
		// Hold all items in Function Call Stack until we reach end of the stack. When the stack becomes
    	// empty, if part is executed and the item is inserted at the bottom
		int Temp = S.top();
		S.pop();
		
		InsertAtBottom( S, Popped);
		
		// Once the item is inserted at the bottom, push all the items held in Function Call Stack 
		S.push(Temp);	
	}	
}

void ReverseStack( stack<int> &S)
{
	if( S.empty())		return;	
	
	//Hold all items in Function Call Stack until we reach end of the stack
	int temp = S.top();
	S.pop();
	
	ReverseStack( S);

	//Insert all the items (held in Function Call Stack) one by one from the bottom to top.
	InsertAtBottom( S, temp);	
}


void PrintStack( char Tittle[], stack<int> &S)
{
	cout<<Tittle;
	while( !S.empty())
	{
		cout<<" "<<S.top();
		S.pop();
	}
	cout<<endl;
}


int main()
{
	stack<int> S;

	S.push(0);
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	
	ReverseStack( S);
	
	PrintStack( "After  Reverse : ", S);
	
	return 0;
}



