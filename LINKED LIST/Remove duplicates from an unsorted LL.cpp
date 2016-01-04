#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	Algo:- 	Using Hash Table
	
		- We traverse the link list from head to end. For every newly encountered element, 
		- we check whether it is in the hash table: if yes, we remove it; otherwise we put it in the hash table.
	   
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
	
		void RemoveDuplicatesFromLLUtil(Node *Current, Node *Next, Node *Prev, map<int, Node*>  &Duplicate)
		{
			// Base Case
			if( Current == NULL )	return;
			
			// If Duplicate found, the delete it
			if( Duplicate.find(Current->data) != Duplicate.end() )
			{
				delete Current;
				Prev->link = Next;
				Current = Next;			
				if( Next != NULL )
				{					
					Next = Next->link;	
				}
			}		
			else
			{
				// Add to Map
				Duplicate[Current->data] = Current;
				
				Prev = Current;
				Current = Next;
				Next = Next->link;				
			}						
			
			RemoveDuplicatesFromLLUtil( Current, Next, Prev,  Duplicate);
		}
		
		void RemoveDuplicatesFromLL(Node *Head)
		{
			map<int, Node*> Duplicate;
			RemoveDuplicatesFromLLUtil( Head, Head->link, NULL, Duplicate);
		}
			
		void test()
		{						
			Head = GetNewNode(0);			
			Head->link = GetNewNode(5);
			Head->link->link = GetNewNode(2);
			Head->link->link->link = GetNewNode(5);
			Head->link->link->link->link = GetNewNode(14);
			Head->link->link->link->link->link = GetNewNode(6);
						
			RemoveDuplicatesFromLL(Head);	
				
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
