#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define BLACK 	0
#define RED		1

/*
	Red-Black Tree:- Self-Balancing BST(Color Scheme)
	
	Properties:-
	1) Root is always black.
	2) No two adjacent red nodes.	
	3) Every path from root to a NULL node has same number of black nodes.
	
	Why Red-Black Trees? :- 
	
	- Most of the BST operations (e.g., search, max, min, insert, delete.. etc) take O(h) time where h is the height of the BST. 
	- The cost of these operations may become O(n) for a skewed Binary tree.
	- If we make sure that height of the tree remains O(Logn) after every insertion and deletion.
	- Then we can guarantee an upper bound of O(Logn) for all these operations
	
	Comparison with AVL Tree
	
	- The AVL trees are more balanced compared to Red Black Trees, but they may cause more rotations during insertion and deletion. 
	- So if your application involves many frequent insertions and deletions, then Red Black trees should be preferred.
	- And if the insertions and deletions are less frequent and search is more frequent operation, then AVL tree should be preferred over Red Black Tree.
	
	Red-Black Tree Implementation:
	
	- If empty tree, Insert black node
	- Insert new leaf node as red
	   a). If parent is black then done
	   b). If parent is red
	       - if sibling is black or absent rotate and recolor
	       - if sibling is red recolor & check
*/

class Tree
{
	class Node
	{
		public:
			int data;
			bool color;
			
			Node *left;	
			Node *right;	
			Node *parent;
	};
	
	Node *root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(int data, Node* Parent = NULL)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->color = RED;
		
		temp->left = NULL;
		temp->right = NULL;
		temp->parent = Parent;
		
		return temp;
	}	
	
	void PreOrder(Node *Root)
	{
		if (Root == NULL)	 return;
		
		cout<<" "<<Root->data;
		PreOrder(Root->left);		
		PreOrder(Root->right);
	}

	Node *getSibling(Node *Root)
	{
		if( Root->parent == NULL )
			return NULL;
		
		Node *Parent = Root->parent;
		if( Parent->left == Root )
			return Parent->right;
		return Parent->left;	
	}
	
	bool isLeftChild(Node *Root) 
	{
        Node *Parent = Root->parent;
        if(Parent->left == Root) 
            return true;
        return false;
    }
	/*-----------------------------------------------------------------------------------*/

	public:	
	
	
		void RotateLeft(Node *Root, bool ColorChange)
		{
			Node *Parent = Root->parent;
			Root->parent = Parent->parent;
			
			Node *Left = Root->left;
			Node *Right = Root->right;
			
			if( Parent != NULL)
			{
				Parent->right = Left;
				Parent->parent = Root;
			}				
				
			if( Left !=  NULL )	
				Left->parent = Parent;				
			
			Root->left = Parent;
			
			if( ColorChange)			
			{
				Root->color = BLACK;
				Parent->color = RED;
			}
		}
		
		void RotateRight(Node *Root, bool ColorChange)
		{
			Node *Parent = Root->parent;
			Root->parent = Parent->parent;
			
			Node *Left = Root->left;
			Node *Right = Root->right;
			
			if( Parent != NULL )
			{
				Parent->left = Right;
				Parent->parent = Root;	
			}	
			
			if( Right != NULL )
				Right->parent = Parent;
								
			Root->right = Parent;
			
			if( ColorChange)			
			{
				Root->color = BLACK;
				Parent->color = RED;
			}
		}
		
		Node* Insert(Node *Root, int data, Node* Parent = NULL)
		{
			if( Root == NULL )
			{
				Root = getNewNode( data, Parent);
				if( Parent == NULL )
					Root->color = BLACK;
				return Root;				
			}
			
			bool isLeft = false;
			if( data <= Root->data)
			{
				Node *Left = Insert( Root->left, data, Root);
				
				if( Left == Root->parent )
					return Left;
				
				Root->left = Left;	
				isLeft = true;
			}
			else
			{
				Node *Right = Insert( Root->right, data, Root);
				
				if( Right == Root->parent )
					return Right;
				
				Root->right = Right;	
				isLeft = false;
			}
	
			if( isLeft)
			{
				if( Root->color == RED && Root->left->color == RED)
				{
					Node *Sibling = getSibling( Root);	
										
			
					if( Sibling == NULL || Sibling->color == BLACK )
					{
						if( isLeftChild(Root))
						{
						
							RotateRight( Root, true);
						}
						else
						{
							RotateRight( Root->left, false);
						
							Root = Root->parent;
							//cout<<"Root = "<<Root->data<<" Root->left = "<<Root->left->data<<endl;
							
							RotateLeft( Root, true);
						}
					}
					else
					{
						Root->color = BLACK;
						
						if( Sibling != NULL )
						{
							Sibling->color = BLACK;
							if( Root->parent->parent != NULL )
								Root->parent->parent->color = RED;
						}
					}
				}
			}
			else
			{			
				if( Root->color == RED && Root->right->color == RED)
				{
					Node *Sibling = getSibling( Root);				
					cout<<" Root = "<<Root->data<<" Sibling = "<<Sibling<<endl;	
					if( Sibling == NULL || Sibling->color == BLACK )
					{						
						if( !isLeftChild(Root))
						{							
							RotateLeft(Root, true);
						}
						else
						{
							RotateLeft( Root->right, false);
						
							Root = Root->parent;
							//cout<<"Root = "<<Root->data<<" Root->left = "<<Root->left->data<<endl;
							
							RotateRight( Root, true);
						}
					}
					else
					{
						Root->color = BLACK;
						
						if( Sibling != NULL )
						{
							Sibling->color = BLACK;
							if( Root->parent->parent != NULL )
								Root->parent->parent->color = RED;
						}
					}
				}
			}
			
			return Root;
		}

		void test()
		{			
			root = Insert( root, 50);
			root = Insert( root, 60);
			root = Insert( root, 55);
			root = Insert( root, 20);
			root = Insert( root, 25);
			root = Insert( root, 35);

				
#if 01				
			cout<<root->color<<endl;			
			cout<<root->left->color<<endl;			
			cout<<root->right->color<<endl;
		//	cout<<root->right->right->color<<endl;
#endif			

#if 01			
			cout<<root->data<<endl;			
			cout<<root->left->data<<endl;			
			cout<<root->right->data<<endl;
#endif			
		}
};






int main()
{
	Tree T;
	
	T.test();	
	
	return 0;
}



