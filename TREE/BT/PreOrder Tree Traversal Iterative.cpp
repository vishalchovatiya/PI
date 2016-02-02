#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	PreOrder:-   First Parent, Then Child

	Algo:-	
		- Do until stack empty
		- Fetch stack top and print;
		- Push right child first, then left
	
		
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
		void PreOrder(Node *Root)
		{
			if( Root == NULL)	return;
			
			cout<<" "<<Root->data;					
			PreOrder(Root->left);				
			PreOrder(Root->right);			
		}
		
		void PreOrderIterative(Node *Root)
		{
			stack<Node*>	S;
			
			S.push(Root);
			
			while( !S.empty())
			{	
				Node* temp = S.top();	
				S.pop();
				cout<<" "<<temp->data;		
				
				if( temp->right)	S.push(temp->right);
				if( temp->left)		S.push(temp->left);
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

			PreOrder(root);
			cout<<endl;
			PreOrderIterative( root);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
