#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question : Find Height of Binary tree Iterative & Recursive
		Iterative Height :- Use Queue Size 	
		Recursive Height :- Keep track of level Count
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
	
		void heightOfTreeRecursive(Node *Root, int &Height, int Level)
		{
			if( Root ==  NULL)
			{				
				Height = (Level >= Height) ? Level : Height;
				return;
			}	
			
			heightOfTreeRecursive( Root->left, Height, Level+1);
			heightOfTreeRecursive( Root->right, Height, Level+1);
		}
		
		int heightOfTreeIterative(Node *Root)
		{
			int Height = -1;
			
			queue<Node*>	Q;
			Q.push(Root);
			
			while( ! Q.empty())
			{
				int NoOfNodes = Q.size();
				
				while( NoOfNodes > 0)
				{
					Node *temp = Q.front();
					Q.pop();
					
					if( temp->left != NULL )	Q.push(temp->left);
					if( temp->right != NULL )	Q.push(temp->right);
					//cout<<" "<<temp->data;
					NoOfNodes--;					
				}
				//cout<<endl;
				Height++;
			}
			
			return Height;
		}
		
		

		
		void test()
		{			
			root = getNewNode(1);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(5);
			root->left->right->right = getNewNode(6);

			int Height = 0;
			
			heightOfTreeRecursive( root, Height, -1);
			cout<<endl;
			
			cout<<" Height Of Tree(Recursive) = "<<Height<<endl;
		
		
			cout<<" Height Of Tree(Iterative) = "<<heightOfTreeIterative( root)<<endl;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
