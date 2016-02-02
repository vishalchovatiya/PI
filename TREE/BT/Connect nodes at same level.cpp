#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Naive Approach :- Use Queue and while poping link those nodes
		
		Efficient Approach :-
		
			- Traverse Tree right to left & link nodes (By reverse traversal of Preorder)
			
*/

class Tree
{
	class Node
	{
		public:
			int data;
			Node *left;	
			Node *right;	
			Node *nextRight;;
	};
	
	Node *root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		temp->nextRight = NULL;
		
		return temp;
	}	

	void PrintLevelNodes(Node *Root)
	{
		cout<<" "<<Root->data;
		if( Root->nextRight == NULL)	return;		
		PrintLevelNodes(Root->nextRight);
	}
	
	void InOrder(Node *Root)
	{
		if( Root == NULL)	return;
					
		InOrder(Root->left);	
		cout<<" "<<Root->data;		
		InOrder(Root->right);			
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
		void Connect(Node *Root)
		{
			// Base Case
			if( Root == NULL)	return;				
			
			// Check for left child first
			if( Root->left != NULL)
			{
				// If Both Child are present then link them
				if(Root->right != NULL)	
				{
					Root->left->nextRight = Root->right;
					
					Root->right->nextRight = FindNextNodeOnSameLevel( Root);
				}
				// If right is NULL then find next node on same level by nextRight pointer already setted when come from right to left
				else
					Root->left->nextRight = FindNextNodeOnSameLevel( Root);
			}
			// If left is NULL find next node on same level by nextRight pointer already setted when come from right to left
			else if( Root->right != NULL)
			{
				Root->right->nextRight = FindNextNodeOnSameLevel( Root);
			}
			
			// This is main logic : Traverse right to left 
			Connect( Root->right);
			Connect( Root->left);
		}
		
		Node *FindNextNodeOnSameLevel(Node *Root)
		{
			while( Root->nextRight != NULL )
			{
				if( Root->nextRight->left !=  NULL )	return Root->nextRight->left;
				if( Root->nextRight->right !=  NULL )	return Root->nextRight->right;
				
				Root = Root->nextRight;
			}
			
			return NULL;			
		}

		void test()
		{					
			root = getNewNode(0);
			root->left = getNewNode(2);
			root->right = getNewNode(1);
			root->left->left = getNewNode(3);			
			
			root->right->left = getNewNode(5);
			root->right->right = getNewNode(6);
	
			root->right->left->left = getNewNode(9);
			
			root->left->left->left = getNewNode(7);						
			
			Connect( root);
			
			PrintLevelNodes(root);
			cout<<endl;
			
			PrintLevelNodes(root->left);
			cout<<endl;
			
			PrintLevelNodes(root->left->left);
			cout<<endl;
			
			PrintLevelNodes(root->left->left->left);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
