#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		
	The diameter of a tree T is the largest of the following quantities:
	
	* the diameter of T’s left subtree
	* the diameter of T’s right subtree
	* the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T) 

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
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		int Height(Node *Root)
		{			
			if(Root==NULL)				return 0;
			
			return 1 + max(Height(Root->left), Height(Root->right));
		}

		int Diameter(Node* Root)
		{
			if(Root==NULL)				return 0;
			
			int LeftSubTreeHeight = Height( Root->left);
			int RightSubTreeHeight = Height( Root->right);
			
			int LDia = Diameter( Root->left);
			int RDia = Diameter( Root->right);
			
			return 	max( LeftSubTreeHeight+RightSubTreeHeight, max(LDia, RDia));
		}
		
		void test()
		{					
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);
			
			cout<<Diameter(root);
			cout<<endl;		
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
