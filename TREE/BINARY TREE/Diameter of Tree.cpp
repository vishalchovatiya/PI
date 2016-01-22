#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Diameter of Tree:- The longest path between leaves that goes through the root of Tree
		
		Diameter of Tree = Height of Left Subtree + Height of Right Subtree
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
	
		int Height(Node *Root, int Level = 0)
		{
			static int HeightOftree;
			
			if(Root==NULL)
			{
				HeightOftree = ( Level > HeightOftree) ? Level : HeightOftree ;
				return HeightOftree;
			}
			
			Height( Root->left, Level+1);
			Height( Root->right, Level+1);
			
			return HeightOftree;
		}

		int Diameter(Node* Root)
		{
			int LeftSubTreeHeight = Height( Root->left, -1);
			int RightSubTreeHeight = Height( Root->right, -1);
			
			return 	LeftSubTreeHeight + RightSubTreeHeight;
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
