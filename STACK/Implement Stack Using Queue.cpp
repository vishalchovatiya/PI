#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
	Algo:-		Use 2 Queue
	
		- If Main Queue empty push directly
		- If Main Queue not empty Put all elements to temp Queue, then Push Element to TOP
		- Again get all elements from temp Queue to Main Queue

*/

class Stack
{
	queue<int> Q;		// Main Queue
	queue<int> tempQ;	// Temp Queue

	public:
	
		void Push(int Element)
		{
			if( Q.empty())	
			{
				Q.push(Element);
			}
			else
			{		
				// Put Main Quue to Temp Queue
				while(!Q.empty())
				{
					tempQ.push(Q.front());
					Q.pop();
				}
				
				// Push Element
				Q.push(Element);
				
				// Put Temp Quue to Main Queue
				while(!tempQ.empty())
				{
					Q.push(tempQ.front());
					tempQ.pop();
				}
			}
		}		
		
		void Pop()
		{
			Q.pop();
		}
		
		int Front()
		{
			return Q.front();
		}
		
		void test()	
		{
			Push(0);
			Push(1);
			Push(2);
			Push(3);			
					
			while(!Q.empty())
			{
				cout<<" "<<Front();
				Pop();
			}	
		}
};



int main()
{
	Stack S;

	S.test();
	
	return 0;
}
