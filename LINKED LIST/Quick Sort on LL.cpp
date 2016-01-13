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
	
		- Form Parition function which will return Pivot element and Move all greater node right to Pivot element
		- Recur for left LL of Pivot, and merge befor recuring for Right LL of Pivot
		
		- Handle Case:- 
			1). Head == NULL & Head == End
			2). Divide LL in two separate LL with before and after Pivot if left exist
			
		Note:- Handle Links of every moving node and Corner Cases	
	
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
					// First Element is Greater than Pivot then update Prev & Newhead
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
			// Base Case
			if( Head == NULL || Head == End )	return Head;			
			
			Node *NewHead = NULL, *NewEnd = NULL;
			
			Node *Pivot = Partition( Head, &NewHead, &NewEnd);
			
			// If Pivot is first element then there is no left LL
			if( NewHead != Pivot )
			{
				// Construct Left LL by making link of node before Pivot
				Node *temp = NewHead;
				while( temp->link != Pivot )
					temp = temp->link;
				temp->link = NULL;
				
				NewHead = QuickSort( NewHead, temp);
				
				// Again merge Left Sorted LL to Pivot
				temp = GetEnd(NewHead);
        		temp->link =  Pivot;
			}
			
			// recure for right LL
			Pivot->link = QuickSort( Pivot->link, NewEnd);	
			
			return NewHead;
		}
	
		void test()
		{						
			Head = GetNewNode(1);			
			Head->link = GetNewNode(5);
			Head->link->link = GetNewNode(3);			
			Head->link->link->link = GetNewNode(2);
			Head->link->link->link->link = GetNewNode(4);

			//PrintLL(Head);
			
			PrintLL(QuickSort( Head, GetEnd(Head) ));
		}
		
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
