#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;

================================Pending

/*
	# Algo :-
	
		- Split LL in Two Halves, SlowPtr and FastPtr, Handle Case: LL is of size 1 or 2
		- Merge Two Sorted LL, Use Linear time Recursive Merge Function, Hangle case: Last Node of LLs
		- Handle Case: Handle Pointers Carefully
		
	# Time Complexity:- 	 O(NLog N)
	
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

		Node* GetEnd(Node *Head)
		{
			while(Head != NULL && Head->link != NULL)
				Head = Head->link;
			
			return Head;
		}
		
		Node *Partition(Node *Head, Node **NewHead, Node **NewEnd)
		{			
			Node *Prev = NULL;			
			Node *Traverse = Head;	
			Node *Pivot = GetEnd(Head);
			Node *End = Pivot;	
			*NewHead = Traverse;	
			
			while(Traverse != Pivot)
			{
				if( Traverse->data <= Pivot->data )
				{
					Prev = Traverse;
					Traverse = Traverse->link;
				}
				else
				{
					Node *temp = Traverse->link;
					
					if (Prev != NULL)
						Prev->link = temp;
					// First Element is Greater than Pivot then handle Prev
					else if(Prev == NULL)
						*NewHead = temp;	
						
					End->link = Traverse;
					End = End->link;
					Traverse = temp;
				}
				
			}
			
			End->link = NULL;
			*NewEnd = End;
			
			return Pivot;
		}
		
		Node* QuickSort(Node* Head, Node *End )
		{
			Node *NewHead = NULL, *NewEnd = NULL, *Pivot = NULL;

			if( Head == NULL || Head == End )	return NULL;
			
			// 2 5 3 1
			Pivot = Partition( Head, &NewHead, &NewEnd);
			// 1 2 5 3
			
			if( NewHead != Pivot )
			{
				Node *temp = NewHead;
				while( temp->link != Pivot )
					temp = temp->link;
				temp->link = NULL;
				
				NewHead = QuickSort( NewHead, temp);
			}
			
			Pivot->link = QuickSort( Pivot->link, NewEnd);
			
			PrintLL(NewHead);
			cout<<endl;
			
			return NewHead;
		}
	
		void test()
		{						
			Head = GetNewNode(1);			
			Head->link = GetNewNode(5);
			Head->link->link = GetNewNode(3);
			Head->link->link->link = GetNewNode(2);

			//PrintLL(Head);
			
			PrintLL(QuickSort( Head, GetEnd(Head) ));
			
			//cout<<endl;	
			//cout<<GetEnd(Head)->data;

			//PrintLL(Head);	
		}
		
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
