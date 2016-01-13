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
	
		- Split LL in Two Halves, SlowPtr and FastPtr, Handle Case: LL is of size 1 or 2
		- Merge Two Sorted LL, Use Linear time Recursive Merge Function, Hangle case: Last Node of LLs & All Prev Link of nodes
		- Handle Case: Dont forget to handle Prev link of First Element
		
	# Time Complexity:- 	 O(NLog N)
	
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
	Node* GetNewNodeForHead(int data)
	{
		static Node* Prev = NULL;
		
		Node *temp = new Node;
		temp->data = data;
		temp->Next = NULL;
		temp->Prev = Prev;
		
		Prev = temp; 
		
		return temp;
	}

	void PrintLL(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintLL(Head->Next);
	}
	
	void PrintLLWithPrev(Node *Head)
	{
		while( Head !=  NULL)
		{
			cout<<" "<<Head->data;	
			Head = Head->Prev;
		}
	}
	
	Node *GetTail(Node *Head)
	{
		while( Head->Next != NULL)
		{
			Head = Head->Next;
		}
		return Head;
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node* Merge(Node *Head1, Node *Head2)
		{
			Node *Result = NULL;
			static Node* Prev = NULL;

			if( Head1 == NULL)	
			{
				Head2->Prev = Prev;
				return Head2;	
			}
			if( Head2 == NULL)
			{
				Head1->Prev = Prev;
				return Head1;
			}	
			
			if( Head1->data <= Head2->data )
			{
				Result = Head1;
				Result->Prev = Prev;
				Prev = Result;
				Result->Next = Merge(Head1->Next, Head2) ;
			}
			else			
			{				
				Result = Head2;
				Result->Prev = Prev;
				Prev = Result;
				Result->Next = Merge(Head1, Head2->Next) ;
			}		
		
			
			return Result;
		}
		
		void SplitInTwoHalves(Node *Head, Node **Head1, Node **Head2)
		{
			*Head1 = Head;
			if( Head == NULL || Head->Next == NULL )
			{
				*Head2 = NULL;
			}
			else
			{
				Node *SlowPtr = Head;
				Node *FastPtr = Head->Next;
				
				while( SlowPtr && FastPtr && FastPtr->Next)
				{
					SlowPtr = SlowPtr->Next;
					FastPtr = FastPtr->Next->Next;
				}
				*Head2 = SlowPtr->Next;
				SlowPtr->Next = NULL;
				
				(*Head1)->Prev = NULL;
				(*Head2)->Prev = NULL;
			}
		}
	
		void MergeSort(Node **Head)
		{
			// Base Case
			if( *Head == NULL || (*Head)->Next == NULL )	return;
			
			Node *LeftSubList = NULL, *RightSubList = NULL;
			
			SplitInTwoHalves( *Head, &LeftSubList, &RightSubList);
			
			MergeSort(&LeftSubList);
			MergeSort(&RightSubList);
			
			*Head = Merge(LeftSubList, RightSubList);
			// Dont forget to handle Prev link of First Element
			(*Head)->Prev = NULL;
		}
		
	
		void test()
		{						
			Head = GetNewNodeForHead(3);
			
			Head->Next = GetNewNodeForHead(1);

			Head->Next->Next = GetNewNodeForHead(5);
						
			PrintLL(Head);			
			cout<<endl;
			
			MergeSort(&Head);
			
			PrintLL(Head);	
			cout<<endl;		

			// Check For Prev Link
			PrintLLWithPrev(GetTail(Head));	
			cout<<endl;	
			
			
		}
		
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}

