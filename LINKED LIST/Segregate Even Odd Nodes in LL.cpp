#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	# Examples:
		Input: 17->15->8->12->10->5->4->1->7->6->NULL
		Output: 8->12->10->4->6->17->15->5->1->7->NULL
		
	# Algo :-
	
		- Recursively call for all nodes
		- Split the linked list into two: one containing all even nodes and other containing all odd nodes
		- Maintain Head Pointers of Even & Odd LL
		- When main LL ends, merge Even & Odd LL
		
	# Time Complexity: O(N)
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
	
		Node* SegregateEvenOdd( Node *Head, 
								Node *EvenLL = NULL, 	// Mentain Even Nodes LL
								Node *OddLL = NULL, 	// Mentain  Odd Nodes LL
								Node *EvenHead = NULL, 	// Head for Even Nodes LL
								Node *OddHead = NULL)	// Head for Odd Nodes LL
		{
			// Base Case
			if( Head == NULL )
			{
				EvenLL->link = OddHead;
				OddLL->link = NULL;				
				return EvenHead;
			}	
			
			// Even Nodes
			if( Head->data % 2 == 0 )
			{
				// Maintain First Head Node
				if (EvenHead == NULL )	
				{
					EvenLL = Head;
					EvenHead = Head;
					return SegregateEvenOdd( Head->link, EvenLL, OddLL, EvenHead, OddHead);
				}	
				// Maintain Even Linked List
				else				
				{
					EvenLL->link = Head;
					return SegregateEvenOdd( Head->link, EvenLL->link, OddLL, EvenHead, OddHead);
				}				
			}
			// Odd Nodes
			else
			{
				// Maintain First Head Node
				if (OddHead == NULL )	
				{
					OddLL = Head;
					OddHead = Head;
					return SegregateEvenOdd( Head->link, EvenLL, OddLL, EvenHead, OddHead);			
				}	
				// Maintain Odd Linked List
				else			
				{
					OddLL->link = Head;		
					return SegregateEvenOdd( Head->link, EvenLL, OddLL->link, EvenHead, OddHead);				
				}				
			}								
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
	
			PrintLL(Head);
			cout<<endl;	
			
			Node *EvenHead = NULL, *OddHead = NULL;
			
			PrintLL(SegregateEvenOdd( Head));
			cout<<endl;	
					
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}


