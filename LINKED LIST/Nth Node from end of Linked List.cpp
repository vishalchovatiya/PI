#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Naive Method: Calculate size of LL and traverse to (size - n)
	
	Efficient Method: 
	
		- Maintain two pointers – reference pointer and main pointer. 
		- First move reference pointer to n nodes from head. 
		- Now move both pointers until reference pointer reaches end. 
		- Now main pointer will point to nth node from the end. Return main pointer.
	
	Test cases:
	   - 0th Element
	   - (size of LL)th Element
	   - Negative Number
	   - Out of range of LL
	   
*/


class Node
{
	public:
		int data;
		Node *link;	
};

Node *Head = NULL;


Node* PrintNthNodeFromTheEnd(Node *Head, int n)
{
	Node *MainPtr = Head;	
	Node *RefePtr = Head;
	int count = 0;
	
	while( Head->link != NULL)
	{
		if( count == n)
			break;
		
		RefePtr = RefePtr->link;
		Head = Head->link;
		count++;
	}
	
	// Edge Case for Out of range of LL & Negative Number
	if( n > count || n < count )
		return NULL;
	
	while( RefePtr->link != NULL)
	{
		RefePtr = RefePtr->link;
		MainPtr = MainPtr->link;
	}
	
	return MainPtr;
}

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

void Insert(int data, int position)
{
	Node *node = GetNewNode(data);
	
	if( position == 0 )
	{
		node->link = Head;
		Head = node;
		return;
	}
	
	Node *traverse = Head;
	
	for(int i=0; i<position-1; i++)
	{
		traverse = traverse->link;
	}
	
	node->link = traverse->link;
	traverse->link = node;
}


int main()
{
	Insert(0,0);
	Insert(1,1);
	Insert(2,2);
	Insert(3,3);
	Insert(4,4);
	
	PrintLL(Head);
	
	cout<<endl;
	
	cout<<PrintNthNodeFromTheEnd(Head, 0)->data<<endl;
	
	return 0;
}
