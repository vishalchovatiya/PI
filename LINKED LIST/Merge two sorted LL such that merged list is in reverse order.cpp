#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question:
		Input:  a: 5->10->15->40
	      		b: 2->3->20 
		
		Output: res: 40->20->15->10->5->3->2

	Method 1: Efficient
	
		- Insert the smaller value node at the front of result.
		- Construct like stack with link building
		
	Method 2: Not Memory Efficient
	
		- Push Elements of LLs in Stacks while traversing
	   
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
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintLL(Head->link);
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node* MergeSortedLL(Node *Head1, Node *Head2)
		{
			Node *NewHead = NULL;
			Node *Next1 = NULL;
			Node *Next2 = NULL;
			
			
			while( Head1 != NULL && Head2 != NULL)
			{
				Next1 = Head1->link;
				Next2 = Head2->link;
				
				if( Head1->data <= Head2->data)
				{
					if( NewHead == NULL )
					{
						NewHead = Head1;
						NewHead->link = NULL;
					}
					else
					{
						Head1->link = NewHead;
						NewHead = Head1;							
					}	
					Head1 = Next1;					
				}
				else
				{
					if( NewHead == NULL )
					{
						NewHead = Head2;
						NewHead->link = NULL;
					}
					else
					{
						Head2->link = NewHead;
						NewHead = Head2;	
					}
					Head2 = Next2;						
				}
			}	
					
			while( Head1 != NULL )
			{
				Next1 = Head1->link;
				Head1->link = NewHead;
				NewHead = Head1;								
				Head1 = Next1;	
			}
			
			while( Head2 != NULL )
			{
				Next2 = Head2->link;
				Head2->link = NewHead;
				NewHead = Head2;								
				Head2 = Next2;	
			}
			
			return NewHead;
		}
			
		void test()
		{			
			Head1 = GetNewNode(5);			
			Head1->link = GetNewNode(10);
			Head1->link->link = GetNewNode(15);
			Head1->link->link->link = GetNewNode(40);
						
			Head2 = GetNewNode(2);			
			Head2->link = GetNewNode(3);
			Head2->link->link = GetNewNode(20);
			
			PrintLL(Head1);
			cout<<endl;
			PrintLL(Head2);
			cout<<endl;			
			
			PrintLL(MergeSortedLL(Head1, Head2));
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
