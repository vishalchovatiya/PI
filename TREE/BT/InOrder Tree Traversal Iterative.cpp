#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	InOrder:-   First Left Child, Then Parent, Then Right Child

	Algo:-	
	
		- Store all left node in stack
		- Print node when left child of node is NULL
		- If right not NULL push it in stack
				
		
*/

class Tree
{
	class Node
	{
		public:
			int data;
			Node *left;	
			Node *right;	
	};
	
	Node *root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}	

	/*-----------------------------------------------------------------------------------*/

	public:	
		void InOrder(Node *Root)
		{
			if( Root == NULL)	return;
						
			InOrder(Root->left);	
			cout<<" "<<Root->data;		
			InOrder(Root->right);			
		}
		
		void InOrderIterative(Node *Root)
		{
			stack<Node*>	S;
			
			S.push(Root);
			
			while( !S.empty())
			{	
				Node* temp = S.top();
							
				if( temp->left != NULL)
				{
					S.push(temp->left);
				}
				else
				{					
					cout<<" "<<temp->data;
					S.pop();

					// Handle Case : When right childs are NULL
					while( temp->right == NULL && !S.empty())
					{
						temp = S.top();
						S.pop();
						cout<<" "<<temp->data;
					}
					
					if( temp->right != NULL)
					{
						S.push(temp->right);
					}
				}
			}
		}


		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);

			InOrderIterative( root);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
