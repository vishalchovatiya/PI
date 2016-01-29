#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


#define SIZE(A) sizeof(A)/sizeof(A[0])

/*

	Logic :- Get Middle and recure for left part of array for left sub tree and same for right part

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
	
		Node* SortedArrayToBalancedBST(int A[], int start, int end)
		{
			if( start > end ) return NULL;
			
			int Parent = (start + end)/2;
			
			Node *Root = getNewNode( A[Parent] );
			
			Root->left = SortedArrayToBalancedBST( A, start, Parent-1);
			Root->right = SortedArrayToBalancedBST( A, Parent+1, end);
			
			return Root;
		}
		
		void test()
		{			
			int A[] = { 1, 2, 3, 4, 5, 6, 7};			

			root = SortedArrayToBalancedBST( A, 0, SIZE(A)-1);
			
			Inorder(root);			
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
