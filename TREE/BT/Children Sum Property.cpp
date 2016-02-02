#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Algo:-	Modify Post order traversal (Because in post order first visited child, then parent )	
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
		bool ModifiedPostOrder(Node *Root)
		{
			static bool status = true;
			int Left = 0, Right = 0;
			
			if( Root == NULL)	return status;		
			
			if (Root->left == NULL && Root->right == NULL)	return status;	
						
			status = ModifiedPostOrder(Root->left);				
			status = ModifiedPostOrder(Root->right);		

			if( Root->left != NULL )
				Left = Root->left->data;
			if( Root->right != NULL )
				Right = Root->right->data;	
				
			if( (status && Root->data == (Left + Right))  )
				status = true;	
			else
				status = false;	
					
			return status;	
		}


		void test()
		{					
			root = getNewNode(5);
			root->left = getNewNode(2);
			root->right = getNewNode(3);
			root->left->left = getNewNode(1);
			//root->left->right = getNewNode(1);
		//	root->left->right->right = getNewNode(6);
			
			cout<<ModifiedPostOrder(root)<<endl;
			cout<<endl;
		
		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
