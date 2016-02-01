#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	AVL Tree:- Self-Balanced BST(Difference b/w left & right subtree can not be more than 1)
	
	AVL Tree Deletion Steps:
	
	1) Perform the normal Deletion as do in BST.
	2) Update the height of the current node.
	3) Get the difference factor ( height left subtree – right subtree) of the current root.
	4) Do the Rotations(i.e. LL, LR, RR, RL) upon Difference & Inserted Key
*/

class Tree
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
	
	Node *Max(Node *Root)
	{		
		if( Root->right == NULL )	return Root;

		return Max( Root->right);
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
		
		
		Node *Delete(Node *Root, int Data)
		{
			if( Root == NULL )	return Root;
			
			// Step 1:- Delete Node as BST
			if( Data < Root->data )
				Root->left = Delete( Root->left, Data);				
			else if( Data > Root->data )
				Root->right = Delete( Root->right, Data);	
			else
			{				
				// Deletion Case 1: Leaf Node
				if( Root->left == NULL && Root->right == NULL)
				{
					cout<<" Root->data = "<<Root->data<<endl;
					delete Root;
					return NULL;
				}
				// Deletion Case 2: Only one child
				else if( Root->left == NULL || Root->right == NULL)
				{
					
					if( Root->left == NULL)
					{
						Node *temp = Root->right;
						delete Root;
						Root = temp;
					}
					else
					{
						Node *temp = Root->left;
						delete Root;
						Root = temp;
					}
				}
				// Deletion Case 3: Both Child Present
				else
				{
					
					Node *temp = Max(Root->left);
					Root->data = temp->data;
					Root->left = Delete( Root->left, Root->data);
				}
			}	
				
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
			root = Insert( root, 9);
			root = Insert( root, 5);
			root = Insert( root, 10);
			root = Insert( root, 0);
			root = Insert( root, 6);
			root = Insert( root, 11);
			root = Insert( root, -1);
			root = Insert( root, 1);
			root = Insert( root, 2);
			
				
			PreOrder( root);
			cout<<endl;
			
			root = Delete(root, 10);
			cout<<endl;
			
			PreOrder( root);
			cout<<endl;
			//cout<<Height( root->left)<<endl;
			//cout<<Height( root->right)<<endl;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
