#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*

	Logic :- Use Queue

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
		static Node *Prev = NULL;
		Node *temp = new Node;
		temp->data = data;
		temp->left = Prev;
		temp->right = NULL;
		Prev = temp;
		return temp;
	}	
	
	void InOrder( Node *Root)
	{
		if(Root == NULL)	return;
		
		cout<<" "<<Root->data;
		InOrder( Root->left);
		InOrder( Root->right);
	}
	
	void PrintDLLToRight( Node *Root)
	{
		if(Root == NULL)	return;
		cout<<" "<<Root->data;
		PrintDLLToRight( Root->right);
	}
	
	void PrintDLLToLeft( Node *Root)
	{
		if(Root == NULL)	return;
		cout<<" "<<Root->data;
		PrintDLLToLeft( Root->left);
	}
				
	/*-----------------------------------------------------------------------------------*/

	public:	


		Node* DLLToBinaryTee(Node *RootDLL)
		{
			queue<Node*>	Q;
			Q.push(RootDLL);

			Node *Traverse = RootDLL->right;
			
			while( !Q.empty())
			{
				Node *Parent = Q.front();
				Q.pop();
				
				if( Traverse != NULL)
				{	
					Parent->left = Traverse;	
					Traverse = Traverse->right;									
					
					Parent->left->left = Parent->left->right = NULL;
					Q.push(Parent->left);					
				}
				
				if( Traverse != NULL)
				{
					Parent->right = Traverse;	
					Traverse = Traverse->right;									
					
					Parent->right->left = Parent->right->right = NULL;
					Q.push(Parent->right);
				}		
			}
			return RootDLL;
		}

		void test()
		{					
			root = getNewNode(1);			
			root->right = getNewNode(2);		
			root->right->right = getNewNode(3);
			root->right->right->right = getNewNode(4);
			root->right->right->right->right = getNewNode(5);
			root->right->right->right->right->right = getNewNode(6);
			root->right->right->right->right->right->right = getNewNode(7);
			
			//PrintDLLToRight( root);
			//PrintDLLToLeft( root->right->right->right->right->right->right);
			InOrder(DLLToBinaryTee(root));
			//DLLToBinaryTee(root);
			cout<<endl;		
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}

