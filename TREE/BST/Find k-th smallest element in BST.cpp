#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Algo:- Modify inorder traversal by using static member count and find node


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
		
		Node *SearchKthSmallest(Node *Root, int k)
		{
			static Node *SearchNode = NULL;
			static int K = k;
			
			if( Root == NULL )	return Root;
			
			SearchKthSmallest( Root->left, k);
			
			if( --K==0 )
				SearchNode = Root;
			
			SearchKthSmallest( Root->right, k);
			
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
			cout<<endl;	
			cout<<SearchKthSmallest( root, 5)->data;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
