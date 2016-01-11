#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	# Algo :-
	
		- Create function sorted insert
		- One by one insert every not in function SortedInsert

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
	Node *Current = NULL;
	Node *temp = NULL;
	
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
	
		void SortedInsert(Node *&Head, Node *Node)
		{				
			Node->link = NULL;
			
			// If first Node
			if( Head == NULL )
			{
				Head = Node;
				Head->link = NULL;				
			}
			else
			{
				Current = Head;

				// Find Appropriate position to insert node
				while( Current->link != NULL && Current->link->data < Node->data )
				{
					Current = Current->link;
				}

				// if node insert at beginning
				if( Current == Head )
				{
					Node->link = Head;
					Head = Node;
				}
				else
				{
					Node->link = Current->link;
					Current->link = Node;
				}			
			}
		}
	
		Node *InsertionSort( Node *Head)
		{
			Node *Sorted = NULL;			
			
			while( Head != NULL)
			{
				Node *Next = Head->link;
				
				SortedInsert( Sorted, Head);		
					
				Head = Next;
			}
			
			return Sorted;
		}
		
		void test()
		{						
			Head = GetNewNode(4);			
			Head->link = GetNewNode(3);
			Head->link->link = GetNewNode(1);
			Head->link->link->link = GetNewNode(9);
			Head->link->link->link->link = GetNewNode(7);

			PrintLL(InsertionSort( Head));
			cout<<endl;			
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
