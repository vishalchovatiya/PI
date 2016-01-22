#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
		- Postorder sequence: D E B F C A
		- Inorder sequence:   D B E A F C
		
		         A
               /  \
          D B E    F C
          
		         A
               /  \
           D B E   C          
           		  /
           		 F 
		  
		  	   A
            /    \
           B      C          
         /  \    /
	   D     E  F
	   
	   Algo:-
	   	- Pick Element of Postorder traversal from end to start, one by one
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
	
	void PostOrder(Node *Root)
	{
		if( Root == NULL)	return;
				
		PostOrder(Root->left);			
		PostOrder(Root->right);			
		cout<<" "<<Root->data;
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
	
	
	Node* BuildTree( char PostOrder[], char InOrder[], int InStart, int InEnd)
	{
		static int PostIndex = strlen(PostOrder);
		if( InStart > InEnd )	return NULL;
		
		Node *Root = getNewNode(PostOrder[--PostIndex]);

		int InIndex = Search( InOrder, InStart, InEnd, PostOrder[PostIndex]);
		if ( InIndex == -1)	return Root;
	
		Root->right = BuildTree( PostOrder, InOrder, InIndex+1, InEnd);
		Root->left  = BuildTree( PostOrder, InOrder, InStart, InIndex-1);		
		
		return Root;		
	}
	
	public:	
		
		void test()
		{	
			char PostOrderTraversal[] = {'D', 'E', 'B', 'F', 'C', 'A'};	
			char InOrderTraversal[] = {'D', 'B', 'E', 'A', 'F', 'C'};  			
			//char PostOrderTraversal[] = {'B', 'C', 'A'};	
			//char InOrderTraversal[] = {'B', 'A', 'C'}; 		
  		
		  	PostOrder(BuildTree( PostOrderTraversal, InOrderTraversal, 0, strlen(PostOrderTraversal)-1));	
  		}
};





int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}
