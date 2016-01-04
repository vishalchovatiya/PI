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
	
		- Use Linear time Recursive Merge Function
	   
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
	
		Node* Merge(Node *Head1, Node *Head2)
		{
			Node *Result = NULL;
			if( Head1 == NULL )	 return Head2;
			if( Head2 == NULL )	 return Head1;
			
			if( Head1->data <= Head2->data)
			{
				Result = Head1;
				Result->link = Merge(Head1->link, Head2);
			}
			else
			{
				Result = Head2;
				Result->link = Merge(Head1, Head2->link);
			}
			return Result;
		}
		
		void DivideInTwoHalfs(Node *Head, Node **Head1, Node **Head2)
		{
			  Node* fast;
		 	  Node* slow;
			  if ( Head == NULL || Head->link == NULL)
			  {
				    /* length < 2 cases */
				    *Head1 = Head;
				    *Head2 = NULL;
			  }
			  else
			  {
				    slow = Head;
				    fast = Head->link;
				 
				    /* Advance 'fast' two nodes, and advance 'slow' one node */
				    while (fast != NULL)
				    {
					      fast = fast->link;
					      if (fast != NULL)
					      {
						        slow = slow->link;
						        fast = fast->link;
					      }
				    }
				 
				    /* 'slow' is before the midpoint in the list, so split it in two
				      at that point. */
				    *Head1 = Head;
				    *Head2 = slow->link;
				    slow->link = NULL;
			  }
		}
		
		void MergeSort(Node **Head)
		{
			Node *Head1 = NULL, *Head2 = NULL;		
			
			if( *Head == NULL || (*Head)->link == NULL) 	return;
			
			DivideInTwoHalfs(*Head, &Head1, &Head2);
			
			MergeSort(&Head1);
			MergeSort(&Head2);
			
			*Head = Merge( Head1, Head2);

		}
		
		void test()
		{						
			Head = GetNewNode(4);			
			Head->link = GetNewNode(3);
			Head->link->link = GetNewNode(1);
	
			MergeSort(&Head);
			PrintLL(Head);
			cout<<endl;
			
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
