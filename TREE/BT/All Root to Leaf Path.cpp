#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		- Store each node in array 
		- When you find leaf node (whose right & left child are null) print array		
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
				
	void PrintArray(int A[], int Size)
	{
		for(int i=0; i<Size; i++)
			cout<<" "<<A[i];
		cout<<endl;	
	}	

	/*-----------------------------------------------------------------------------------*/

	public:	
		void InOrder(Node *Root)
		{
			if( Root == NULL)	return;
						
			InOrder(Root->left);	
			cout<<" "<<Root->data;		
			InOrder(Root->right);			
		}

		void AllRootToLeaf(Node *Root, int Path[], int Index)
		{
			if( Root == NULL)	return;
			
			Path[Index] = Root->data;
			
			if( Root->left == NULL && Root->right == NULL )
				PrintArray( Path, Index+1);				
										
			AllRootToLeaf(Root->left, Path, Index+1);				
			AllRootToLeaf(Root->right, Path, Index+1);	
		}
		
		void test()
		{		
			int NoOfNodes = 6;	
			int Path[NoOfNodes];
			memset( Path, 0, sizeof(Path));
			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);
			
			AllRootToLeaf( root, Path, 0);
		
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
