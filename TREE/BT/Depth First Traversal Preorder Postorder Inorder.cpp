#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		PreOrder:-  First Parent, Then Child		
		PostOrder:- First Child, Then Parent
		InOrder:-   First Left Child, Then Parent, Then Right Child
		
		Application of DFSs:
		
		    *
		   / \
		  +   C
		 / \   
		A   B  
		
		- PreOrder traversal of above tree produce PREFIX NOTATION     * + A B C
		- PostOrder traversal of above tree produce POSTFIX NOTATION   A B + C *
		- InOrder traversal of above tree produce INFIX NOTATION       A + B * C
		
		- DU command of UNIX is PostOrder traversal which get disk usage data of its child first then come to parent; 
			
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
		
		void PostOrder(Node *Root)
		{
			if( Root == NULL)	return;
						
			PostOrder(Root->left);			
			PostOrder(Root->right);			
			cout<<" "<<Root->data;
		}
		
		void InOrder(Node *Root)
		{
			if( Root == NULL)	return;
						
			InOrder(Root->left);	
			cout<<" "<<Root->data;		
			InOrder(Root->right);			
		}


		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);
			
			PreOrder( root);
			cout<<endl;
			
			PostOrder( root);
			cout<<endl;
			
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
