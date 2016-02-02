#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Logic :- Use Hash Map
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
	
		void TopView(Node *Root)
		{
			map<int, int> Table;

			TopViewUtil( Root, 0, Table);
			
			map<int, int> :: iterator it;			
			for(it = Table.begin(); it!=Table.end(); it++)
			{
				cout<<" "<<it->second;
			}
		}

		void TopViewUtil(Node *Root, int Level, map<int, int> &Table)
		{
			if( Root == NULL )	return;
			
			if( Table.find(Level) == Table.end() )	Table[Level] = Root->data;
			
			TopViewUtil( Root->left, Level-1, Table);
			TopViewUtil( Root->right, Level+1, Table);
		}
		
		void BottomView(Node *Root)
		{
			map<int, int> Table;

			BottomViewUtil( Root, 0, Table);
			
			map<int, int> :: iterator it;			
			for(it = Table.begin(); it!=Table.end(); it++)
			{
				cout<<" "<<it->second;
			}
		}
		
		void BottomViewUtil(Node *Root, int Level, map<int, int> &Table)
		{
			if( Root == NULL )	return;
			
			Table[Level] = Root->data;
			
			BottomViewUtil( Root->left, Level-1, Table);
			BottomViewUtil( Root->right, Level+1, Table);
		}
		
		void LeftView(Node *Root)
		{
			map<int, int> Table;

			LeftViewUtil( Root, 0, Table);
			
			map<int, int> :: iterator it;			
			for(it = Table.begin(); it!=Table.end(); it++)
			{
				cout<<" "<<it->second;
			}
		}
		
		void LeftViewUtil(Node *Root, int Level, map<int, int> &Table)
		{
			if( Root == NULL )	return;
			
			Table[Level] = Root->data;
			
			LeftViewUtil( Root->right, Level-1, Table);
			LeftViewUtil( Root->left, Level-1, Table);			
		}
		
		void RightView(Node *Root)
		{
			map<int, int> Table;

			RightViewUtil( Root, 0, Table);
			
			map<int, int> :: iterator it;			
			for(it = Table.begin(); it!=Table.end(); it++)
			{
				cout<<" "<<it->second;
			}
		}
		
		void RightViewUtil(Node *Root, int Level, map<int, int> &Table)
		{
			if( Root == NULL )	return;
			
			Table[Level] = Root->data;
			
			RightViewUtil( Root->left, Level-1, Table);			
			RightViewUtil( Root->right, Level-1, Table);			
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

			root->left->left->right = getNewNode(9);
			root->left->left->right->left = getNewNode(10);
			root->left->left->right->left->left = getNewNode(11);

			RightView( root);
			cout<<endl;
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}


