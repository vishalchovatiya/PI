#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Naive Approach:- Do level order traversal and use queue to store all nodes, pop all one by one & adjust links
	
	Memory Efficient Approach:-
	
		- Do indorder traversal and adjust left link of all nodes
		- Goto right most node which is tail of DLL
		- Fix right pointers of all node by traversing already set left links
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
	
	void PrintDLL( Node *Root)
	{
		if(Root == NULL)	return;
		cout<<" "<<Root->data;
		PrintDLL( Root->right);
	}
				
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		void SetLeftLink(Node *Root)
		{
			static Node* Prev = NULL;
			if( Root == NULL )	return;
			
			SetLeftLink( Root->left);
			
			Root->left = Prev;
			Prev = Root;
			
			SetLeftLink( Root->right);	
		}
		
		Node* SetRightLink(Node *Root)
		{
			Node *Prev = NULL;
			
			while( Root && Root->right != NULL)
				Root = Root->right;
				
			while( Root && Root->left != NULL)
			{				
				Prev = Root;
				Root = Root->left;
				Root->right = Prev;
			}
			
			return Root;	
		}

		Node* BinaryTeeToDLL(Node *Root)
		{
			SetLeftLink( Root);
			
			return SetRightLink( Root);			
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
			
			PrintDLL(BinaryTeeToDLL(root));
			cout<<endl;
		
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}

