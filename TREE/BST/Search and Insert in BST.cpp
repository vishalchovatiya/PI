#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*



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
		
		Node *Search(Node *Root, int data)
		{
			static Node *SearchNode = NULL;
			if( Root == NULL )	return Root;
			if( data < Root->data )
			{
				Search( Root->left, data);
			}
			else if( data > Root->data )
			{
				Search( Root->right, data);
			}
			else
			{
				SearchNode = Root;
			}
			return SearchNode;
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
			cout<<Search( root, 128);
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
