#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Algo :- 
			- find height and run loop start from 0 to Height of tree
			- Keep Decreasing Level cout untill it reach at zero
			- When Level count reach to zero print data
			
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
	
		void heightOfTree(Node *Root, int &Height, int Level)
		{
			if( Root ==  NULL)
			{				
				Height = (Level >= Height) ? Level : Height;
				return;
			}	
			
			heightOfTree( Root->left, Height, Level+1);
			heightOfTree( Root->right, Height, Level+1);
		}
	
		void printGivenLevel(Node *Root, int Level)
		{
			if( Root ==  NULL)	return;
			
			if( Level == 0 )	cout<<" "<<Root->data;
			else
			{
				printGivenLevel( Root->left, Level-1);
				printGivenLevel( Root->right, Level-1);
			}
		}

		void BFS()
		{			
			int Height = 0;			
			heightOfTree( root, Height, -1);
			
			for(int i=0; i<=Height; i++)
			{
				cout<<" Level "<<i<<" = ";
				printGivenLevel( root, i);			
				cout<<endl;
			}
				
		}
		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);

			BFS();
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
