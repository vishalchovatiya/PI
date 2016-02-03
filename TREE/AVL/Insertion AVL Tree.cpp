#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	class AVLNode
	{
			int data, height;
			Node *left, *right;	
	};
	
	AVL Tree:- Self-Balanced BST(Difference b/w left & right subtree can not be more than 1)
	
	Why AVL Trees? :- 
	
	- Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. 
	- The cost of these operations may become O(n) for a skewed Binary tree.
	- If we make sure that height of the tree remains O(Logn) after every insertion and deletion.
	- Then we can guarantee an upper bound of O(Logn) for all these operations
	
	AVL Tree Implementation:
	
	1) Perform the normal BST insertion.
	2) Update the height of the current node.
	3) Get the difference factor ( height left subtree – right subtree) of the current root.
	4) Do the Rotations(i.e. LL, LR, RR, RL) upon Difference & Inserted Key
*/

class AVLTree
{
	class Node
	{
		public:
			int data;
			int height;
			Node *left;	
			Node *right;	
	};
	
	Node *root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->height = 0;
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}	
	
	void PreOrder(Node *Root)
	{
		if (Root == NULL)	 return;
		
		cout<<" "<<Root->data;
		PreOrder(Root->left);		
		PreOrder(Root->right);
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node *RotateLeft(Node *Root)
		{
			Node *Right = Root->right;
			Node *Left  = Root->left;
			
			Root->right = Right->left;			
			Right->left = Root;
			
			Root->height = max( Height( Root->left), Height( Root->right)) ;
			Right->height = max( Height( Right->left), Height( Right->right)) ;
			
			return Right;
		}
		
		Node *RotateRight(Node *Root)
		{
			Node *Left  = Root->left;
			Node *Right = Root->right;
			
			Root->left = Left->right;
			Left->right = Root;
			
			Root->height = max( Height( Root->left), Height( Root->right)) ;
			Left->height = max( Height( Left->left), Height( Left->right)) ;
		
			return Left;
		}
	
		int Height(Node *Root)
		{
			if( Root == NULL )	return 0;
			
			return Root->height;
		}
		
		int GetDifference(Node *Root)
		{
			if( Root == NULL )	return 0;
			
			return Height( Root->left) - Height( Root->right);
		}

		Node *Insert(Node *Root, int Data)
		{
			// Step 1:- Insert Node as BST
			if( Root == NULL )	return getNewNode( Data);
			
			if( Data < Root->data )
				Root->left = Insert( Root->left, Data);				
			else 
				Root->right = Insert( Root->right, Data);	
				
			// Step 2:- Update Height 	
			Root->height = 	max( Height( Root->left), Height( Root->right)) + 1;
			
			// Step 3:- Get the difference factor
			int Difference = GetDifference( Root);
			
			// Step 4:- Do the Rotations upon Difference & Inserted Key
			// Case RR:
			if( Difference < -1 && Data > Root->right->data )
			{
				Root = RotateLeft( Root);
			}
			// Case RL:
			else if( Difference < -1 && Data < Root->right->data )
			{
				Root->left = RotateRight( Root->left);
				Root = RotateLeft( Root);
			}
			// Case LL:
			else if( Difference > 1 && Data < Root->left->data )
			{
				Root = RotateRight( Root);
			}
			// Case LR:
			else if( Difference > 1 && Data > Root->left->data )
			{
				Root->left = RotateLeft( Root->left);
				Root = RotateRight( Root);
			}
			
			return Root;
		}

		void test()
		{			
			root = Insert( root, 10);
			root = Insert( root, 20);
			root = Insert( root, 30);
			root = Insert( root, 40);
			root = Insert( root, 50);
			root = Insert( root, 25);
				
			PreOrder( root);
			cout<<endl;
			
			cout<<Height( root->left)<<endl;
			cout<<Height( root->right)<<endl;
		}
};






int main()
{
	AVLTree T;
	
	T.test();	
	
	return 0;
}
