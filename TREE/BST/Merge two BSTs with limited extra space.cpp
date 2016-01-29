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
	
	Node *root1 = NULL, *root2 = NULL;
	
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

		Node* MergeTwoBST(Node *Root1, Node *Root2)
		{
			if( Root1 == NULL && Root2 == NULL )	return NULL;
			
			Node *Root = NULL;
			
			if( Root1 == NULL )
			{
				
				Root = Root2;
				cout<<" Root1->data = "<<Root1<<" Root2 = "<<Root2->data<<" Root = "<<Root->data<<endl;
				Root->left = MergeTwoBST( Root1, Root2->left);
				Root->right = MergeTwoBST( Root1, Root2->right);
			}
			else if( Root2 == NULL )
			{
				
				Root = Root1;
				cout<<" Root1->data = "<<Root1->data<<" Root2 = "<<Root2<<" Root = "<<Root->data<<endl;
				Root->left = MergeTwoBST( Root1->left, Root2);
				Root->right = MergeTwoBST( Root1->right, Root2);
			}
			else if( Root1->data > Root2->data )
			{
				
				Root = Root1;
				cout<<" Root1->data = "<<Root1->data<<" Root2->data = "<<Root2->data<<" Root = "<<Root->data<<endl;
				Root->left = MergeTwoBST( Root1->left, Root2);
				Root->right = MergeTwoBST( Root1->right, Root2);
			}
			else if( Root2->data >= Root1->data )
			{
				
				Root = Root2;
				cout<<" Root1->data = "<<Root1->data<<" Root2->data = "<<Root2->data<<" Root = "<<Root->data<<endl;
				Root->left = MergeTwoBST( Root1, Root2->left);
				Root->right = MergeTwoBST( Root1, Root2->right);
			}
			
			return Root;
		}
		
		void test()
		{			
			root1 = Insert(root1, 3);
			
			//root1 = Insert(root1, 1);
			//root1 = Insert(root1, 5);
			
			root2 = Insert(root2, 4);
			//root2 = Insert(root2, 2);
			//root2 = Insert(root2, 6);
			
			Node *Root = MergeTwoBST( root1, root2);
			Inorder(Root);		
			
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
