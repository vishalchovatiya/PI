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
			
		NOTE:- Handle Links of every moving node and Corner Cases	
	
*/

class List
{
	class Node
	{
		public:
			
			int data;
			Node *Prev;	
			Node *Next;	
	};
	
	Node *Head = NULL;
	
	/*-------------------------------Utility Functions-------------------------------*/
	Node* GetNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->Next = NULL;
		temp->Prev = NULL;
		return temp;
	}
	void PrintLL(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintLL(Head->Next);
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node *GetTail(Node *Head)
		{
			while( Head->Next != NULL)
			{
				Head = Head->Next;
			}
			return Head;
		}

		// Returns Pivot Element
		Node* Partition(Node *Head, Node *End, Node **NewHead, Node **NewEnd)
		{
			Node *Current = Head;			
			Node *Prev = NULL;
			Node *Next = NULL;
			
			Node *Pivot = End;

			*NewHead = Head;
			
			while( Current != Pivot)
			{
				Next = Current->Next;
	
				if( Current->data <= Pivot->data )
					Prev = Current;					
				else
				{
					// Head Data is smaller than pivot then updata NewHead
					if( Prev == NULL )
					{					
						*NewHead = Next;
						(*NewHead)->Prev = NULL;
					}
					else
					{
						Prev->Next = Next;
						Next->Prev = Prev;		
						
						Prev = Current;						
					}	
					
					End->Next = Current;
					Current->Prev = End;		
					End = Current;
					End->Next = NULL;				
				}		
				Current = Next;	
			}
			
			*NewEnd = End;			
			
			return Pivot;
		}

		Node* QuickSort(Node *Head, Node *End)
		{
			if( Head == NULL || Head == End )	return Head;
			
			Node *NewHead = NULL, *NewEnd = NULL;
			
			Node* Pivot = Partition( Head, End, &NewHead, &NewEnd);	
			
			// If Left Part is available
			if( Pivot != NewHead)
			{
				Node *temp = NewHead;
				while( temp->Next != Pivot)
					temp = temp->Next;
				temp->Next = NULL;
				
				NewHead = QuickSort( NewHead, temp);
									
				GetTail( NewHead)->Next = Pivot;				
			}
							
			Pivot->Next = QuickSort( Pivot->Next, NewEnd);
			
			return NewHead;
		}
		
	
		void test()
		{						
			Head = GetNewNode(2);
			Head->Next = GetNewNode(1);
			Head->Next->Next = GetNewNode(3);
			Head->Next->Next->Next = GetNewNode(4);
			Head->Next->Next->Next->Next = GetNewNode(0);
			
			PrintLL(QuickSort( Head, GetTail( Head)));			
			cout<<endl;
		}
		
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
