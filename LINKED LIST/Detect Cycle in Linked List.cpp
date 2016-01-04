#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Method 1: Using Hash Table 
	
		- Store Address of Nodes
		- Time Complexity : O(N*N)
		- Space Complexity : O(N)
	
	Method 2: Floyd’s Cycle-Finding Algorithm	(Fastest Method)
	
		- Slow Ptr and Fast Ptr
		- Time Complexity : O(N)
		- Space Complexity : O(1)
	   
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

		bool DetectCycleUsingHashTable(Node *Traverse)
		{
			map<Node*,Node*>	NodeToLink;
			
			while(Traverse->link != NULL)
			{							
				NodeToLink[Traverse] = Traverse->link;
				Traverse = Traverse->link;
				
				if( NodeToLink.find(Traverse) != NodeToLink.end() )
					return true;				
			}
			return false;
		}
		
		bool DetectCycleFloydAlgo(Node *Traverse)
		{
			Node *slow_ptr = Traverse;
			Node *fast_ptr = Traverse;
			
			while( slow_ptr && fast_ptr && fast_ptr->link)
			{
				slow_ptr = slow_ptr->link;
				fast_ptr = fast_ptr->link->link;
				
				if( slow_ptr == fast_ptr)
					return true;
			}
			
			
			return false;
		}
		

		
		void test()
		{			
			Head = GetNewNode(0);			
			Head->link = GetNewNode(1);
			Head->link->link = GetNewNode(2);
			Head->link->link->link = GetNewNode(3);
			Head->link->link->link->link = GetNewNode(4);
			Head->link->link->link->link = Head->link;	// Connect 4 to 1 and form cycle
			
			//PrintLL(Head);
						
			cout<<"DetectCycleUsingHashTable  = "<< DetectCycleUsingHashTable(Head)<<endl;
			cout<<"DetectCycleFloydAlgo       = "<<DetectCycleFloydAlgo(Head)<<endl;
		
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
