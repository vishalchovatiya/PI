#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	Algo :-
	
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *link;	
	};
	
	Node *Head = NULL;
	
	/*-------------------------------Utility Functions-------------------------------*/
	Node* GetNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->link = NULL;
		return temp;
	}
	void PrintLL(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintLL(Head->link);
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
		
		Node* ReverseInGroup(Node* Head, int GroupSize)
		{
			int Count = 0;
			Node *Current = Head;
			Node *Prev = NULL;
			Node *Next = NULL;
			
			// Reverse first GroupSize
			while( Current != NULL && Count < GroupSize)
			{
				Next = Current->link;
				Current->link = Prev;
				Prev = Current;
				
				Current = Next;
				Count++;
			}
			
			// Recur for reversing next GroupSize
			if( Next != NULL)
				Head->link = ReverseInGroup( Next, GroupSize);
				
			return Prev;	// Return last node which link to first node of previous groupsize	
		}
		
		void test()
		{						
			Head = GetNewNode(1);			
			Head->link = GetNewNode(2);
			Head->link->link = GetNewNode(3);
			Head->link->link->link = GetNewNode(4);
			Head->link->link->link->link = GetNewNode(5);
			Head->link->link->link->link->link = GetNewNode(6);
			Head->link->link->link->link->link->link = GetNewNode(7);
			Head->link->link->link->link->link->link->link = GetNewNode(8);
			Head->link->link->link->link->link->link->link->link = GetNewNode(9);
			
			PrintLL(Head);
			cout<<endl;
			
			PrintLL(ReverseInGroup( Head, 3));		
			cout<<endl;			
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
