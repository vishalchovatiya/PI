#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;

/*
	# Algo:-
	
		- Traverse LL with Prev Curr & Next node info & LL Size Variable
		- Recor Beginning Kth node data	like Prev Curr & Next	
		- When Backtracking look for Kth node from End 		
		- If K is less than half of LL size then swap and adjust Next Prev link
		
	# Test Case OR Handle Case:
		
		- K > LLsize/2
		- K = 1
	
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
	
		void SwapKthNodeFromBegToEnd(Node **Head, Node *tCurrent, Node *tPrev, Node *tNext, int K)
		{
			static int Count = 1, LLSize = 0;
			
			static Node *KthNode = NULL;
			static Node *KthPrev = NULL;
			static Node *KthNext = NULL;
			
			// Base Case
			if( tCurrent == NULL )
			{
				if( K > LLSize/2 )
					Count = LLSize;
				else
					Count = 1;	
				return;
			}

			tNext = tCurrent->Next;
							
			// Getting Beginning Kth node data				
			if( Count++ == K)
			{
				Count++;
				KthNode = tCurrent;
				KthPrev = tPrev;
				KthNext = tNext;				
			}
							
			tPrev = tCurrent;
			tCurrent = tNext;	
			
			LLSize++;	
			
			SwapKthNodeFromBegToEnd( Head, tNext, tPrev, tNext, K);
			
			
			if( Count == K )
			{			
				// End's Kth Node data
				Node *Prev = tPrev->Prev;
				Node *Next = tPrev->Next;				

				// Link Kth End Node with Kth Beginning node
				if( KthPrev != NULL )
					KthPrev->Next = tPrev;
				KthNext->Prev = tPrev;	
				tPrev->Next = KthNext;
				tPrev->Prev = KthPrev;
				
				// Link Kth Beginning Node with Kth End node
				Prev->Next = KthNode;
				if( Next != NULL)
					Next->Prev = KthNode;
				KthNode->Next = Next;
				KthNode->Prev = Prev;
				
				// Update Head if Head and End node is swapped
				if( K == 1)
					*Head = tPrev;
			}

			Count++;	
		}
	

		void test()
		{						
			Head = GetNewNodeForHead(1);
			
			Head->Next = GetNewNodeForHead(2);

			Head->Next->Next = GetNewNodeForHead(3);
			
			Head->Next->Next->Next = GetNewNodeForHead(4);
			
			Head->Next->Next->Next->Next = GetNewNodeForHead(5);
						
			PrintLL(Head);			
			cout<<endl;
			
			SwapKthNodeFromBegToEnd( &Head, Head, NULL, Head->Next, 1);
			
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


