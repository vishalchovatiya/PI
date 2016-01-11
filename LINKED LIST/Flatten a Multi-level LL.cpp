#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question : You need to flatten the list in way that all nodes at first level should come first, then nodes of second level, and so on.
       
	   5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
       
    Solution: 5->10->19->28->7->20->22->35->8->50->40->30->45 
       
		# Algo:- 
			- Traverse level by level and add next level nodes in queue
       		- Append all next level node to previous level
       		- repeat this process until all level append completely
       		
       	# Time Complexity:- O(N)	
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *Down;
			Node *link;	
	};
	
	Node *Head = NULL;
	
	/*-------------------------------Utility Functions-------------------------------*/
	Node* GetNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->link = NULL;
		temp->Down = NULL;
		return temp;
	}
	void PrintDown(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintDown(Head->Down);
	}
	
	void PrintLL(Node *Head, bool withDown)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		if(withDown == true)
		{
			PrintDown(Head->Down);
			cout<<endl;
		}
		
		PrintLL(Head->link, withDown);
	}
	
	
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node* Flatten(Node *Head)
		{
			Node *LevelTraverse = Head;
			Node *MainLL = Head;
			queue<Node*> Q;
			
			while( MainLL !=  NULL)
			{
				LevelTraverse = MainLL;		
				
				// Traverse level and push all next level nodes in queue
				while( LevelTraverse !=  NULL )
				{	
					if( LevelTraverse->Down != NULL )			
						Q.push(LevelTraverse->Down);			
					
					// Record every last node of level
					MainLL = LevelTraverse;				
					
					LevelTraverse = LevelTraverse->link;									
				}				
				
				// Append all next level node after previous level
				while( !Q.empty() )
				{
					Node *Temp = Q.front();
					Q.pop();
					
					LevelTraverse->link = Temp;
					LevelTraverse = LevelTraverse->link;	
				}
				
				// Start with next level
				MainLL = MainLL->link;
			}
			return Head;
		}
			
		void test()
		{			
			Head = GetNewNode(5);	
			Head->Down = GetNewNode(7);	
			Head->Down->Down = GetNewNode(8);	
			Head->Down->Down->Down = GetNewNode(30);
					
			Head->link = GetNewNode(10);
			Head->link->Down = GetNewNode(20);	
			
			Head->link->link = GetNewNode(19);
			Head->link->link->Down = GetNewNode(22);
			Head->link->link->Down->Down = GetNewNode(50);			
			
			Head->link->link->link = GetNewNode(28);
			Head->link->link->link->Down = GetNewNode(35);
			Head->link->link->link->Down->Down = GetNewNode(40);
			Head->link->link->link->Down->Down->Down = GetNewNode(45);			
			
			PrintLL(Head, true);
			cout<<endl;
			
			PrintLL(Flatten( Head), false);
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
