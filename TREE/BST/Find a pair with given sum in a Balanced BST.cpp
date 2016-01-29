#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question:- Find a pair with given sum in a Balanced BST

			Input Tree:
		           10
		        /      \
		       5        12
		      / \     /  \
		     2   8  11    15
		

	Logic:- Do fill array with inorder traversal and find pair with use of sorted array property
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


		int SortedArrayFromBST(Node *Root, int A[])
		{
			static int ArrSize = 0;
			
			if (Root == NULL)	 return ArrSize;
			
			SortedArrayFromBST(Root->left, A);
			
			//cout<<" "<<Root->data;
			A[ArrSize++] = Root->data;
			
			SortedArrayFromBST(Root->right, A);
			
			return ArrSize;
		}
		
		bool FindPairSum(int SortedArr[], int size, int sum)
		{	// 2 5 8 10 9 12 15
			int start = 0;
			int end = size-1;
			
			while(start<end)	
			{
				if( SortedArr[start]+SortedArr[end] < sum )
				{
					start++;
				}
				else if( SortedArr[start]+SortedArr[end] > sum )
				{
					end--;
				}
				else
					return true;
			}
			return false;			
		}
		
		void test()
		{			
			root = Insert(root,  10);
			
			root = Insert(root,  5);
			root = Insert(root,  8);
			
			root = Insert(root,  2);
			root = Insert(root,  9);
			root = Insert(root,  12);
			root = Insert(root,  15);
			
			int A[10];
			
			Inorder( root);
			cout<<endl;
			
			int ASize = SortedArrayFromBST( root,  A);
			cout<<FindPairSum( A, ASize, 45)<<endl;
		
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}

