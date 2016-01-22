#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
		- Preorder sequence: A B D E C F
		- Inorder sequence:  D B E A F C
		
		         A
               /  \
          D B E    F C
          
		         A
               /  \
              B   F C          
            /  \
		  D     E
		  
		  	   A
            /    \
           B      C          
         /  \    /
	   D     E  F
	   
	   Algo:- 
	   	- Pick Element of Preorder traversal from start to end, one by one
	   	- Find Root in Inorder traversal and figure out left & right subtree
	   	- repeat this process untill all element finish
*/

class Tree
{
	class Node
	{
		public:
			char data;
			Node *left;	
			Node *right;	
	};
	
	Node *root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(char data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		
		return temp;
	}	
	
	void PreOrder(Node *Root)
	{
		if( Root == NULL)	return;
		
		cout<<" "<<Root->data;
		PreOrder(Root->left);			
		PreOrder(Root->right);			
	}
	/*-----------------------------------------------------------------------------------*/

	int Search(char Arr[], int start, int end, char Value)
	{
		for(int i = start; i<=end; i++ )
		{
			if( Arr[i] == Value )
				return i;
		}
		return -1;
	}
	
	
	Node* BuildTree( char PreOrder[], char InOrder[], int InStart, int InEnd)
	{
		static int PreIndex = 0;
		if( InStart > InEnd )	return NULL;
		
		Node *Root = getNewNode( PreOrder[PreIndex++]);
		
		int InIndex = Search( InOrder, InStart, InEnd, PreOrder[PreIndex]);
		if ( InIndex == -1)	return Root;

		Root->left = BuildTree( PreOrder, InOrder, InStart, InIndex - 1 );
		Root->right = BuildTree( PreOrder, InOrder, InIndex + 1, InEnd);
		
		return Root;
	}
	
	public:	
		
		void test()
		{	
			char PreOrderTraversal[] = {'A', 'B', 'D','E', 'C', 'F'};	
			char InOrderTraversal[] = {'D', 'B', 'E', 'A', 'F', 'C'};  			
			//char PreOrderTraversal[] = {'A', 'B', 'C'};	
			//char InOrderTraversal[] = {'B', 'A', 'C'}; 		
  		
		  	PreOrder(BuildTree( PreOrderTraversal, InOrderTraversal, 0, 5));	
  		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
