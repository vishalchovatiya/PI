#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Delete Case:- 1).If node is Leafe Node, 2).If node has only one child, 3).If node has both child(get max ele from left subtree or min from right subtree)
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
		
		Node *Delete(Node *Root, int data)
		{
			if( Root == NULL )	return Root;
		
			if( data < Root->data )
			{
				Root->left = Delete( Root->left, data);
			}
			else if ( data > Root->data )
			{
				Root->right = Delete( Root->right, data);
			}
			else
			{
				// Case 1: If node is Leafe Node
				if( Root->left == NULL && Root->right == NULL )
				{
					delete Root;
					Root = NULL;
				}
				// Case 2: If node has only one child
				else if( Root->left == NULL || Root->right == NULL )
				{
					if( Root->left == NULL )
					{
						Node *temp = Root;
						Root = Root->right;
						delete temp;
					}
					else
					{
						Node *temp = Root;
						Root = Root->left;
						delete temp;
					}
				}
				// Case 3: If node has both child
				else
				{
					Node *temp = Max(Root->left);
					Root->data = temp->data;
					Root->left = Delete( Root->left, Root->data);
				}
			}
			
			return Root;
		}
		
		void test()
		{			
			root = Insert(root, 5);
			
			root = Insert(root, 9);
			root = Insert(root, 3);
			
			root = Insert(root, 4);
			root = Insert(root, 7);
			root = Insert(root, 11);
			root = Insert(root, 12);
			
			Inorder(root);	
			cout<<endl;
				
			Delete( root, 3);
			Inorder(root);		
			cout<<endl;
			
			Delete( root, 4);
			Inorder(root);		
			cout<<endl;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
