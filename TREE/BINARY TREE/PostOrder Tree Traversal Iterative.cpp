#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	PostOrder:-   First Child, Then Parent

	Algo:-	
		
	- Push root to first stack.
	- Loop while first stack is not empty
	   - Pop a node from first stack and push it to second stack
	   - Push left and right children of the popped node to first stack
	- Print contents of second stack
		
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
		void PostOrder(Node *Root)
		{
			if( Root == NULL)	return;
			
			PostOrder(Root->left);				
			PostOrder(Root->right);			
			cout<<" "<<Root->data;					
		}
		
		void PostOrderIterative(Node *Root)
		{
			stack<Node*>	S1;
			stack<Node*>	S2;
			
			S1.push(Root);
			
			while( !S1.empty())
			{	
				Node* temp = S1.top();	
				S1.pop();
				S2.push(temp);
				
				if( temp->left )	S1.push(temp->left);
				if( temp->right )	S1.push(temp->right);			
			}
			
			while( !S2.empty())
			{
				cout<<" "<<S2.top()->data;
				S2.pop();
			}
		}


		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->right->left = getNewNode(6);
			root->right->right = getNewNode(7);
//			root->left->right->right = getNewNode(6);

			PostOrder(root);
			cout<<endl;
			PostOrderIterative( root);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
