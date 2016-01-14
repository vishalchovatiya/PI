#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Logic:	Recursive
	
	NOTE : Handle Corner Cases   
	
	Test Cases :
	
		- 0 Node
		- K = 1 to < SizeofLL
		- K = SizeofLL
		- k > SizeofLL
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
		
		void ReverseKNodes( Node *Current, int K, Node **Head)
		{
			static int Count = 0;
			static int LLSize = 0;
			static Node *Prev = NULL;
			static Node *RevHead = NULL;
			
			// Base Case
			if( Current == NULL )
			{				
				return;
			}
			LLSize++;				

			ReverseKNodes(  Current->link, K, Head);
			
			// Handle case when k is > LL Size
			if( K > LLSize )
				return;
			
			// Last Node of Main LL
			if( Count == 0)
			{
				Prev = Current;	
				RevHead = Current;
			}						
			// Middle nodes of Last and first of reversed last nodes
			else if ( Count < K )
			{
				Current->link = NULL;
				Prev->link = Current;
				
				Prev = Current;							
			}
			// Link reversed LL to Main LL
			else if ( Count == K )
			{
				cout<<" Count = "<<Count<<endl;
				Current->link = RevHead;				
			}
						
			// if K = LL size
			if( LLSize == K)
			{
				*Head = RevHead;
			}						
			
			Count++;
		}
		
	
		
		void test()
		{			
			Head = GetNewNode( 1);
			Head->link = GetNewNode( 2);
			Head->link->link = GetNewNode( 3);
			Head->link->link->link = GetNewNode( 4);
			Head->link->link->link->link = GetNewNode( 5);
			
			PrintLL(Head);
			cout<<endl;
			
			ReverseKNodes( Head, 6, &Head);		
			
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

