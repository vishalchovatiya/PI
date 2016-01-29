#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question:- Convert Sorted Linked List to Balanced BST
	
		Input:  Linked List 1->2->3
		Output: A Balanced BST 
		     2   
		   /  \  
		  1    3 

	Logic:- Modify Inroder traversal with LL size
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
	
	class NodeLL
	{
		public:
			int data;
			NodeLL *Next;	
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
	
	NodeLL *getNewNodeLL(int data)
	{
		NodeLL *temp = new NodeLL;
		temp->data = data;
		temp->Next = NULL;
		
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


		Node* SortedLLtoBST(NodeLL **Head, int len)
		{
			if( len <= 0 )	return NULL;
			
			Node *RootLeft = SortedLLtoBST(Head, len/2);
			
			Node *Root = getNewNode( (*Head)->data);
			
			Root->left = RootLeft;
			(*Head) = (*Head)->Next;			
			
			Root->right = SortedLLtoBST(Head, len-(len/2)-1 );
			
			return Root;
		}
		
		void test()
		{			
			NodeLL *Root = getNewNodeLL( 1);
			Root->Next = getNewNodeLL( 2);
			Root->Next->Next = getNewNodeLL( 3);
			
			root = SortedLLtoBST( &Root, 3);
			
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

