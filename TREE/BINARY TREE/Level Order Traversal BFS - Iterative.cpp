#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Use Queue
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

		void BFS()
		{
			queue<Node*>	Q;
			
			Q.push(root);
			
			while( !Q.empty())
			{
				Node *temp = Q.front();
				Q.pop();
				
				cout<<" "<<temp->data;
				
				if(temp->left != NULL)	Q.push(temp->left);
				if(temp->right != NULL)	Q.push(temp->right);
			}			
		}
		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			
			BFS();
			
		}
};






int main()
{
	Tree T;
	
	T.test();
	
	
	return 0;
}
