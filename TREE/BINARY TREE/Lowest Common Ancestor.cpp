#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Method 1:- 
		
		1) Find path from root to n1 and store it in a vector or array.
		2) Find path from root to n2 and store it in another vector or array.
		3) Traverse both paths till the values in arrays are same. Return the common element just before the mismatch
		
		Method 2:-
		
		- Traverse the tree, If any of the given keys (n1 and n2) matches with root, then root is LCA (assuming that both keys are present). 
		- If root doesn’t match with any of the keys, we recur for left and right subtree. 
		- The node which has one key present in its left subtree and the other key present in right subtree is the LCA. 
		- If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right subtree.
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
	
	void InOrder(Node *Root)
	{
		if( Root == NULL)	return;
					
		InOrder(Root->left);	
		cout<<" "<<Root->data;		
		InOrder(Root->right);			
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
		
		Node *LCA(Node *Root, int n1, int n2)
		{
			if( Root == NULL )	return Root;
			
			if( Root->data == n1 || Root->data == n2 )
				return Root;
			
			Node *LeftLCA = LCA( Root->left, n1, n2);
			Node *RightLCA = LCA( Root->right, n1, n2);
			
			if( LeftLCA != NULL && RightLCA != NULL)	return Root;
			
			if( LeftLCA != NULL )	return LeftLCA;
				
			return RightLCA;
		}
		
		void test()
		{		
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			
			root->right->left = getNewNode(6);
			root->right->right = getNewNode(7);
	
			cout<<LCA( root, 2, 7)->data;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
