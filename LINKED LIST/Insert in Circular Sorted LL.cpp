#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	Care About Corner Case 
		 Handle Case 1: Insertion at Head
		 Handle Case 2: Insertion at Tail	
		 Handle Case 3: Insert Element with same value present in LL
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *link;	
	};
	
	Node *Head1 = NULL, *Head2 = NULL;
	
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
		Node *traverse = Head;
		
		do
		{
			cout<<" "<<traverse->data;
			traverse = traverse->link;
		}while( traverse != Head);
		
		cout<<endl;
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node* GetTail(Node *Head)
		{
			Node *Traverse = Head;
			
			while( Traverse->link != Head )
			{
				Traverse = Traverse->link;
			}
			
			return Traverse;
		}
	
		void InsertCircularLL(Node **Head, int Data)
		{
			Node *Current = *Head;
			Node *Prev = Current->link;
			Node *Tail = GetTail(Current);
			
			// Handle Case 1 & 3: Insertion at Head
			if( Data <= Current->data )
			{
				*Head = GetNewNode( Data);
				(*Head)->link = Current;
				
				Tail->link = *Head;		// Rearrange Tail Address
			}
			else
			{
				// Handle Case 3 : Insert Element with same value present in LL
				while( Current->data <= Data && Current->link != *Head )
				{
					Prev = Current;		
					
					Current = Current->link;
				}
				// Handle Case 2: Insertion at Tail
				if( Current == Tail )
				{
					Current->link = GetNewNode( Data);
					Current = Current->link;
					Current->link = *Head;
				}
				else
				{					
					Prev->link = GetNewNode( Data);
					Prev = Prev->link;
					Prev->link = Current;
				}
			}
		}
	
		void test()
		{						
			Head1 = GetNewNode(10);			
			Head1->link = GetNewNode(20);
			Head1->link->link = GetNewNode(30);
			Head1->link->link->link = GetNewNode(40);
			Head1->link->link->link->link = GetNewNode(50);	
			Head1->link->link->link->link->link = Head1;
			
			InsertCircularLL(&Head1, 1);
			InsertCircularLL(&Head1, 120);
			InsertCircularLL(&Head1, 120);
			
			PrintLL(Head1);		
			cout<<endl;						
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}


