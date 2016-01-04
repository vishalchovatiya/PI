#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Logic:
	
		- Use Recursion Utility function
		- After complete reverse traversal & link settlement make first node's link to NULL
	
	NOTE: Edge Case: Look for End of LL
	   
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
	/*-----------------------------------------------------------------------------------*/

	public:	

		
		void ReverseUtil(Node *Traverse)
		{
			if( Traverse->link == NULL )
			{
				Head = Traverse;
				return;
			}	
			
			ReverseUtil(Traverse->link);
			
			Traverse->link->link = Traverse;
		}
		
		void Reverse(Node *Traverse)
		{
			ReverseUtil(Traverse);
			Traverse->link = NULL;
		}
		
		void test()
		{			
			Insert(0,0);
			Insert(1,1);
			Insert(2,2);
			Insert(3,3);
			Insert(4,4);
			
			PrintLL(Head);
			
			Reverse(Head);
			
			cout<<endl;
			
			PrintLL(Head);
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
