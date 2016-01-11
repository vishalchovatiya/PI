#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*

	Question Example:
		Input:
			M = 2, N = 2
			Linked List: 1->2->3->4->5->6->7->8
			Output:
			Linked List: 1->2->5->6
			
	Algo :-
	
		- Skip M Nodes
		- Delete N Nodes
		- Recur for next M+N cycle

	
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
		
		Node* DeleteInGroupRecursive(Node* Head, int N, int M)
		{
			int Count = 0;
			Node* Prev = NULL;
			Node* Next = NULL;
			Node* Current = Head;	

			// Skip M Nodes
			while( Current != NULL && Count++ < M)
			{
				Next = Current->link;
				Prev = Current;
				
				Current = Next;
			}
			Count = 0;
			
			// Delete N Nodes
			while( Current != NULL && Count++ < N)
			{
				Next = Current->link;
				
				delete Current;
				
				Current = Next;
			}
			
			if( Next != NULL )
				Prev->link = DeleteInGroupRecursive( Next, N, M);
			
			return Head;
		}
			
		void test()
		{						
			Head = GetNewNode(1);			
			Head->link = GetNewNode(2);
			Head->link->link = GetNewNode(3);
			Head->link->link->link = GetNewNode(4);		
			Head->link->link->link->link = GetNewNode(5);
			Head->link->link->link->link->link = GetNewNode(6);
			Head->link->link->link->link->link->link = GetNewNode(7);
			Head->link->link->link->link->link->link->link = GetNewNode(8);
			Head->link->link->link->link->link->link->link->link = GetNewNode(9);
			
			PrintLL(Head);
			cout<<endl;
					
			PrintLL(DeleteInGroupRecursive(Head, 2, 2));
			cout<<endl;	
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
