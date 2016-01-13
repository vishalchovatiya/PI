#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	
	NOTE: Edge Case: Look for End of Doubly LL
	   
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
	
		void ReverseDoublyLL(Node **Head)
		{
			Node *Current = *Head;
			Node *Next = NULL;
			Node *Prev = NULL;
			
			while( Current != NULL )
			{
				Next = Current->Next;
				Current->Next = Prev;
				Prev = Current;
				Current->Prev = Next;
				
				Current = Next;
			}
			
			*Head = Prev;
		}
			
		void test()
		{			
			Head = GetNewNode(1);
			Head->Next = GetNewNode(2);
			Head->Next->Next = GetNewNode(3);
			Head->Next->Next->Next = GetNewNode(4);
			Head->Next->Next->Next->Next = GetNewNode(5);
			
			ReverseDoublyLL( &Head);
			
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
