#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define MAX(A,B) ( (A>B)? A:B)

/*

	Algo:- 
	
	- Take all elements of first BST one by one, and insert them into the second BST. 
	- Inserting an element to a self balancing BST takes LogN time where n is size of the BST. 
	- So time complexity of this method is Log(n) + Log(n+1) … Log(m+n-1). 

*/

class Tree
{
	class Node
	{
		public:
			int data, height;
			Node *left;	
			Node *right;	
	};
	
	Node *root1 = NULL, *root2 = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->height = 1;
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}	
	
	int Height(Node *Root)
	{
		if (Root == NULL)	 return 0;
		
		return MAX( Height(Root->left), Height(Root->right)) + 1;
	}
	
	void Inorder(Node *Root)
	{
		if (Root == NULL)	 return;
		
		Inorder(Root->left);
		cout<<" "<<Root->data;
		Inorder(Root->right);
	}
	
	int getDifference(Node *Root)
	{
		if( Root == NULL )	return 0;
		
		return Height(Root->left) - Height(Root->right);
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node *RotateRight(Node *Root)
		{
			Node *Left = Root->left;
			Node *Right = Root->right;
			
			Root->left = Left->right;
			Left->right = Root;			
			
			Root->height = MAX( Height(Root->left), Height(Root->right)) + 1;
			Left->height = MAX( Height(Left->left), Height(Left->right)) + 1;
			
			return Left;
		}
		
		Node *RotateLeft(Node *Root)
		{
			Node *Left = Root->left;
			Node *Right = Root->right;
			
			Root->right = Right->left;
			Right->left = Root;
	
			Root->height = MAX( Height(Root->left), Height(Root->right)) + 1;
			Right->height = MAX( Height(Right->left), Height(Right->right)) + 1;
			
			return Right;
		}
	
		Node *Insert(Node *Root, int data)
		{
			if( Root == NULL )
			{
				Root = getNewNode(data);	
				return Root;			
			}
			else if( data <= Root->data )
			{
				Root->left = Insert( Root->left, data);
			}
			else
			{
				Root->right = Insert( Root->right, data);
			}
			
			Root->height = MAX( Height(Root->left), Height(Root->right)) + 1;
			
			int Difference = getDifference( Root);
			
			//cout<<" Difference = "<<Difference<<" Root->data = "<<Root->data<<endl;
			// Case :- Left-Left
			if( Difference > 1 && data < Root->left->data )
			{
				//cout<<"(Left Left) Difference = "<<Difference<<" Root->data = "<<Root->data<<endl;
				Root = RotateRight(Root);
			}
			// Case :- Right-Right
			else if( Difference < -1 && data > Root->right->data )
			{
				//cout<<"(Right Right) Difference = "<<Difference<<" Root->data = "<<Root->data<<endl;
				Root = RotateLeft(Root);
			}
			// Case :- Left-Right
			else if( Difference > 1 && data > Root->left->data )
			{
				//cout<<"(Left Right) Difference = "<<Difference<<" Root->data = "<<Root->data<<endl;
				Root->left = RotateLeft(Root->left);
				Root = RotateRight(Root);
			}
			// Case :- Right-Left
			else if( Difference < -1 && data < Root->right->data )
			{
				//cout<<"(Right Left) Difference = "<<Difference<<" Root->data = "<<Root->data<<endl;
				Root->right = RotateRight(Root->right);
				Root = RotateLeft(Root);
			}
			
			return Root;
		}

		void MergeTwoBST(Node *&Root1, Node *Root2)
		{
			if( Root2 == NULL )		return ;
			
			MergeTwoBST( Root1, Root2->left);

			Root1 = Insert(Root1, Root2->data);	
			
			MergeTwoBST( Root1, Root2->right);			
		}
		
		void test()
		{			
			root1 = Insert(root1, 2);			
			root1 = Insert(root1, 1);
			root1 = Insert(root1, 3);

			root2 = Insert(root2, 5);
			root2 = Insert(root2, 6);
			root2 = Insert(root2, 4);
	
			MergeTwoBST( root1, root2);
			cout<<endl;
			
			Inorder( root1);			
		}
};


int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
