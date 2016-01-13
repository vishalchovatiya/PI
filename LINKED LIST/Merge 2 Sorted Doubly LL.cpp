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
	
		- Handle Corner cases and Prev link of every nodes
		
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
	
	Node *Head = NULL, *Head1 = NULL;
	
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
	
	Node* GetNewNodeForHead1(int data)
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
	
	
		void test()
		{						
			Head = GetNewNodeForHead(1);
			
			Head->Next = GetNewNodeForHead(3);

			Head->Next->Next = GetNewNodeForHead(5);
			
			Head1 = GetNewNodeForHead1(2);
			
			Head1->Next = GetNewNodeForHead1(4);

			Head1->Next->Next = GetNewNodeForHead1(6);
			
				
			PrintLL(Head);			
			cout<<endl;
			PrintLL(Head1);			
			cout<<endl;
				
			PrintLLWithPrev(GetTail(Head));	
			cout<<endl;
			PrintLLWithPrev(GetTail(Head1));	
			cout<<endl;	
			
			Node *Result = Merge(Head, Head1);
			
			PrintLL(Result);			
			cout<<endl;	
			
			// Check for every Prev Link of nodes
			PrintLLWithPrev(GetTail(Result));	
			cout<<endl;			
		}
		
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
