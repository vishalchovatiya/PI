#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
	Algo:-		Use 2 Stack
	
		- If Main Stack empty push directly
		- If Main Stack not empty Put all elements to temp Stack, then Push Element to Main Stack
		- Again get all elements from temp Stack to Main Stack

*/

class Queue
{
	stack<int> S;		// Main Stack
	stack<int> tempS;	// Temp Stack

	public:
	
		void Push(int Element)
		{
			if( S.empty())	
			{
				S.push(Element);
			}
			else
			{		
				// Put Main Stack to Temp Stack
				while(!S.empty())
				{
					tempS.push(S.top());
					S.pop();
				}
				
				// Push Element
				S.push(Element);
				
				// Put Temp Stack to Main Stack
				while(!tempS.empty())
				{
					S.push(tempS.top());
					tempS.pop();
				}
			}
		}		
		
		void Pop()
		{
			S.pop();
		}
		
		int Top()
		{
			return S.top();
		}
		
		void test()	
		{
			Push(0);
			Push(1);
			Push(2);
			Push(3);			
					
			while(!S.empty())
			{
				cout<<" "<<Top();
				Pop();
			}	
		}
};



int main()
{
	Queue Q;

	Q.test();
	
	return 0;
}
