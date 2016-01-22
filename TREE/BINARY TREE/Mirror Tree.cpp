#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Mirror Tree:-
	
	 So the tree...		is changed to...
	       4				 4
	      / \				/ \
	     2   5			   5   2
	    / \					  / \
	   1   3			     3   1       

	Algo:-	
	
		- Call Mirror for left-subtree    i.e., Mirror(left-subtree)
		- Call Mirror for right-subtree  i.e., Mirror(right-subtree)
		- Swap left and right subtrees				
		
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
	
		void Mirror(Node *Root)
		{
			if( Root == NULL)	return;
						
			Mirror(Root->left);				
			Mirror(Root->right);	
			
			Node *temp = Root->left;
			Root->left = Root->right;
			Root->right = temp;
		}
		
		void test()
		{			
			root = getNewNode(4);
			root->left = getNewNode(2);
			root->right = getNewNode(5);
			root->left->left = getNewNode(1);
			root->left->right = getNewNode(3);
		//	root->left->right->right = getNewNode(6);

			InOrder( root);
			cout<<endl;
			
			Mirror( root);
			
			InOrder( root);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
