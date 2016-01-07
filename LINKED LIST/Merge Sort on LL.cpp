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
	
		Node* Merge(Node* Head1, Node* Head2)	// O( M + N )
		{
			Node *Result = NULL;
			if( Head1 ==  NULL)	 return Head2;
			if( Head2 ==  NULL)	 return Head1;
			
			if( Head1->data <= Head2->data)
			{
				Result = Head1;
				Result->link = Merge( Head1->link,  Head2);
			}
			else
			{
				Result = Head2;
				Result->link = Merge( Head1,  Head2->link);
			}
			return Result;
		}
		
		void SplitInTwoHalves(Node *Head, Node** Head1, Node** Head2)	// O( N )
		{
			Node* SlowPtr = Head;
			*Head1 = Head;
			
			// If LL is of size 1 or 2 
			if( Head->link == NULL || Head->link->link == NULL )
			{
				*Head2 = Head->link;
				(*Head1)->link = NULL;
			}
			// If LL is of size Greater than 2
			else
			{
				while( Head != NULL && Head->link != NULL)
				{
					SlowPtr = SlowPtr->link;
					Head = Head->link->link;
				}
				
				*Head2 = SlowPtr->link;
				SlowPtr->link = NULL;	
			}			
		}
		
		void MergeSort(Node **Head)		// O(NLogN)
		{
			Node *Head1 = NULL,*Head2 = NULL;
			
			// Base Case : If LL is of size 1 then return
			if( *Head == NULL || (*Head)->link == NULL )	return;
			
			SplitInTwoHalves(*Head, &Head1, &Head2);

			MergeSort(&Head1);
			MergeSort(&Head2);
			
			*Head = Merge(Head1, Head2);
		}
		
		void test()
		{						
			Head = GetNewNode(4);			
			Head->link = GetNewNode(3);
			Head->link->link = GetNewNode(1);
			Head->link->link->link = GetNewNode(9);
			Head->link->link->link->link = GetNewNode(7);
	
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
