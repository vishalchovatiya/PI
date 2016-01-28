#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		- While Traversing Left keep track of prev node for Successor
		- While Traversing right keep track of prev node for Predecessor
		
		Handle Cases like :- Leafe node, left child null, right child null, root
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
	
	Node *Max(Node *Root)
	{		
		if( Root->right == NULL )	return Root;
		
		Root = Max( Root->right);
		return Root;
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
	
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
		
		Node *InorderSuccessor(Node *Root, int data)
		{
			Node *Traverse = Root;
			Node *Successor = NULL;
			
			while( Traverse != NULL)
			{
				if( data < Traverse->data)
				{
					Successor = Traverse;
					Traverse = Traverse->left;
				}					
				else if( data > Traverse->data)
				{
					Traverse = Traverse->right;
				}
					
				else
				{
					if( Traverse->right == NULL )
						return Successor;
					
					Traverse = Traverse->right;
			
					while( Traverse->left != NULL)
						Traverse = Traverse->left;
						
					return Traverse;
				}
			}			
			return NULL;	
		}


		Node *InorderPredecessor(Node *Root, int data)
		{
			Node *Traverse = Root;
			Node *Predecessor = NULL;
			
			while( Traverse != NULL)
			{
				if( data < Traverse->data)
				{
					Traverse = Traverse->left;
				}					
				else if( data > Traverse->data)
				{
					Predecessor = Traverse;
					Traverse = Traverse->right;
				}
					
				else
				{
					if( Traverse->left != NULL)
					{
						Predecessor = Traverse->left;
						
						if( Predecessor->left == NULL && Predecessor->right == NULL)
							return Predecessor;
						
						if( Predecessor->left == NULL )
						{
							while( Traverse->right != NULL)
								Traverse = Traverse->right;
								
							return 	Traverse;
						}
					}					
					
					return Predecessor;
				}
			}			
			return NULL;	
		}
		
		void test()
		{			
			root = Insert(root, 5);
			
			root = Insert(root, 9);
			root = Insert(root, 4);
			root = Insert(root, 2);
			root = Insert(root, 3);
			
			root = Insert(root, 7);
			root = Insert(root, 11);
			root = Insert(root, 12);
			
			Inorder(root);	
			cout<<endl;
				
			cout<<endl<<"InorderPredecessor = "<<InorderPredecessor( root, 7)->data<<endl;	
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
