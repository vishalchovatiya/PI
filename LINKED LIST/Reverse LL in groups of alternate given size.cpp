#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*

	Question Example:
		Inputs:   1->2->3->4->5->6->7->8->9->NULL and k = 3
		Output:   3->2->1->4->5->6->9->8->7->NULL. 

	Algo :-
	
	1) Reverse the first sub-list of given size. While reversing keep track of the next and previous node.
	2) Skip Next GroupSize Nodes with maintaining Head, Prev and Next Pointers
	3) Recursively call next sub-list and link that with previous sub-lists
	4) Prev becomes the new head of the sub-list
	
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
		
		Node* ReverseInGroupRecursive(Node* Head, int GroupSize)
		{
			int Count = 0;
			Node* Prev = NULL;
			Node* Next = NULL;
			Node* Current = Head;			
			// Reverse first GroupSize
			while( Current != NULL && Count++ < GroupSize)
			{
				Next = Current->link;
				Current->link = Prev;
				Prev = Current;				
				
				Current = Next;				
			}
		
			// Link Alternate GroupSize Nodes with previous sublist 			
			Head->link = Next;
			
			// Skip Next GroupSize Nodes with maintaining Head, Prev and Next Pointers
			Count = 0;	
			Current = Next;
			Next = NULL;				
			while( Current != NULL && Count++ < GroupSize)
			{
				Next = Current->link;				
				Head = Current;						
				Current = Next;				
			}			
			
			// Recur for reversing next GroupSize
			if( Next != NULL )
				Head->link = ReverseInGroupRecursive( Next, GroupSize);	
					
			return Prev;	// Return last node which will link to first node of previous groupsize	
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
					
			PrintLL(ReverseInGroupRecursive(Head, 3));
			cout<<endl;			
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
