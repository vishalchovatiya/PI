#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question:- BT to BST
	
	Explanation :-
		Input Tree:
		         27
		        /  \
		       25   2
		      / \
		     8   20
		
		Output Tree:-
		          8
		        /  \
		       2    25
			       / \
			      20  27

	Logic:- Modify any traversal of BT and insert element in BST
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
	
		Node* SortedArrayFromBST(Node *Root)
		{
			static Node *RootBST = NULL;
			
			if (Root == NULL)	 return NULL;
			
			SortedArrayFromBST(Root->left);
			
			RootBST = Insert(RootBST, Root->data);
			
			SortedArrayFromBST(Root->right);
			
			return RootBST;
		}
		
		void test()
		{			
			root = getNewNode( 27);
			
			root->left = getNewNode( 25);
			root->right = getNewNode( 2);
			
			root->left->left = getNewNode( 8);
			root->left->right = getNewNode( 20);

			Node *Root = SortedArrayFromBST(root);	
			
			Inorder( Root);
			cout<<endl;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}

