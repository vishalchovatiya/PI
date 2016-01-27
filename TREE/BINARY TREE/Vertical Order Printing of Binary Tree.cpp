#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Logic :- Use Hash Map of int key and vector of int data
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
	
		void Traverse(Node *Root, map<int, vector<int> >	&LevelNodes, int Level)
		{
			if(Root==NULL)	return;
			
			LevelNodes[Level].push_back(Root->data);
			
			Traverse( Root->left,  LevelNodes,  Level-1);
			Traverse( Root->right,  LevelNodes,  Level+1);
		}
	
		void VerticalOrderPrinting(Node *Root)
		{
			map<int, vector<int> >	LevelNodes;
			
			Traverse( Root, LevelNodes, 0);
			
			map<int, vector<int> > :: iterator it;
			
			for(it = LevelNodes.begin(); it!=LevelNodes.end(); it++)
			{
				for(int i=0; i<it->second.size();i++)
					cout<<" "<<it->second[i];
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

		//	root->left->left->right = getNewNode(9);
		//	root->left->left->right->left = getNewNode(10);
		//	root->left->left->right->left->left = getNewNode(11);
			VerticalOrderPrinting( root);
			
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}


