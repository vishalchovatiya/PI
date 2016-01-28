#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;


/*

		Logic:- Set Boundary limits of min and max(initially INT_MIN & INT_MAX), traverse and set limits.

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
		
		
		
		bool CheckForBST(Node* Root, int min, int max)
		{
			if( Root==NULL )	return true;
			
			if( Root->data >= min && Root->data <= max && CheckForBST( Root->left, min, Root->data) && CheckForBST( Root->right, Root->data, max) )
				return true;		
			
			return false;
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
			
			cout<<CheckForBST( root, INT_MIN, INT_MAX)<<endl;
			
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
