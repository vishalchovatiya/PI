#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question:- Two node of BST are swapped, corrent them
	
	Explanation :-
		Input Tree:
		         10
		        /  \
		       5    8
		      / \
		     2   20
		
		In the above tree, nodes 20 and 8 must be swapped to fix the tree.  
		Following is the output tree
		         10
		        /  \
		       5    20
		      / \
		     2   8

	Logic:- Do Inorder traversal and track prev element, if prev is greater than current then node found
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
	
	void Inorder(Node *Root)
	{
		if (Root == NULL)	 return;
		
		Inorder(Root->left);
		cout<<" "<<Root->data;
		Inorder(Root->right);
	}
		
	Node *Insert(Node *Root, int data)
	{
		if( Root == NULL )
		{
			Root = getNewNode(data);				
		}
		else if( data <= Root->data )
		{
			Root->left = Insert( Root->left, data);
		}
		else
		{
			Root->right = Insert( Root->right, data);
		}
		return Root;
	}

	/*-----------------------------------------------------------------------------------*/

	public:	

		void CorrectSwappedNodes(Node *Root)	
		{
			static Node *Prev = NULL, *n1 = NULL, *n2 = NULL;
			
			if (Root == NULL)	 return;
		
			CorrectSwappedNodes(Root->left);
			//cout<<" "<<Root->data;			
			if( Prev != NULL && Prev->data > Root->data )
			{
				if( n1 == NULL )
					n1 = Prev;
				else
					n2 = Root;	
				if( n1 != NULL && n2 != NULL )	

					swap( n1->data, n2->data);
			}
			
			Prev = Root;
					
			CorrectSwappedNodes(Root->right);
		}
		
		
		void test()
		{			
			root = getNewNode( 10);
			
			root->left = getNewNode( 5);
			root->right = getNewNode( 8);
			
			root->left->left = getNewNode( 2);
			root->left->right = getNewNode( 20);
			
			root->right->left = getNewNode( 11);
			
			CorrectSwappedNodes(root);		
			cout<<endl;
			
			Inorder( root);
			cout<<endl;
		//	cout<<Search( root, 128);
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}

