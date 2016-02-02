#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Recursive :- Modify printGivenLevel method with bool variable
	
	Iterative 1 :- Modify iterative BF traversal Using Stack & bool variable (Queue + Stack)
	
	Iterative 2 :- Use 2 Stack 
				- Do until both stack not empty
				- Pop from Stack1, and add next level nodes to Stack2
				- Pop from Stack2, and add next level nodes to Stack1
			
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
	
	void PrintStack(stack<int> &S)
	{
		while( !S.empty())
		{
			cout<<" "<<S.top();
			S.pop();
		}
	}

	/*-----------------------------------------------------------------------------------*/

	public:	
	
		void HeightOfTree(Node *Root, int &Height, int Level)
		{
			if( Root == NULL )
			{
				Height = ( Level > Height) ? Level-1 : Height;
				return;
			}
			
			HeightOfTree( Root->left, Height, Level+1);
			HeightOfTree( Root->right, Height, Level+1);	
		}

		void printGivenLevel(Node *Root, int Level, bool flip)
		{
			if( Root == NULL )		return;
			
			if( Level == 0 )		cout<<" "<<Root->data;
			
			if( flip)
			{
				printGivenLevel(Root->left, Level-1, flip);
				printGivenLevel(Root->right, Level-1, flip);	
			}				
			else
			{
				printGivenLevel(Root->right, Level-1, flip);	
				printGivenLevel(Root->left, Level-1, flip);
			}	
		}
		
		void LevelOrderSpirallyRecursive( Node *Root)
		{
			int Height = 0;
			bool flip = 1;
			
			HeightOfTree( Root,  Height, 0);

			for( int i=0; i<=Height; i++)
			{
				printGivenLevel( Root, i, flip);
				flip = !flip;
				cout<<endl;
			}
		}
		
		void LevelOrderSpirallyIterative( Node *Root)
		{
			bool flip = true;
			Node *temp = NULL;
			queue<Node*>	Q;
			stack<int>	S;
			
			Q.push(Root);
			
			while( !Q.empty() )
			{
				int NoOfNodes = Q.size();
				
				while( NoOfNodes > 0 )						
				{
					temp = Q.front();
					Q.pop();
					
					// ----------------Spiral  Printing
					if( flip)
						cout<<" "<<temp->data;
					else
					{
						S.push(temp->data);
						if( NoOfNodes == 1)		PrintStack(S);
					}	
					// ---------------------------------
					
					if( temp->left )  Q.push(temp->left);
					if( temp->right ) Q.push(temp->right);	
					NoOfNodes--;	
				}	
				flip = !flip;			
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
			root->right->left = getNewNode(6);
			root->right->right = getNewNode(7);
			root->right->left->left = getNewNode(8);
			root->right->left->right = getNewNode(9);			
			
			LevelOrderSpirallyIterative(root);
			cout<<endl;
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}



