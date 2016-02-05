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
	
	void swapColor(bool &data1, bool &data2)
	{
		bool temp = data1;
		data1 = data2;
		data2 = temp;
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
	
		Node *RotateLeft(Node *Root, bool changeColor)
		{			
			Node *Parent = Root->parent;
	        Root->parent = Parent->parent;
	        
	        if( Parent->parent != NULL ) 
			{
	            if( Parent->parent->right == Parent) 
	                Parent->parent->right = Root;
	            else 
	                Parent->parent->left = Root;
	        }
	        
	        Node *Left = Root->left;
	        Root->left = Parent;
	        Parent->parent = Root;
	        Parent->right = Left;
	        
	        if( Left != NULL ) 
	            Left->parent = Parent;

	        if( changeColor) 
			{
	            Root->color = BLACK;
	            Parent->color = RED;
	        }
		}
		
		
		
		Node *RotateRight(Node *Root, bool changeColor)
		{
			Node *Parent = Root->parent;
			Node *Right = Root->right;
			
			if( Parent->parent != NULL ) 
			{
	            if( Parent->parent->right == Parent) 
	                Parent->parent->right = Root;
	            else 
	                Parent->parent->left = Root;
	        }
			
			Root->right = Parent;
			
			Root->parent = Parent->parent;
			Parent->parent = Root;
			Parent->left = Right;
			
			if( Right != NULL )
				Right->parent = Parent;
			
			if( changeColor)
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
				if( Parent == NULL)
					Root->color = BLACK;
				return Root;
			}
			
			bool isLeft = false;
			
			if( data <= Root->data)
			{
				Node *Left = Insert( Root->left, data, Root);
				
				if(Left == Root->parent) 
				{
                	return Left;
            	}
            	
            	Root->left = Left;
            
				isLeft = true;
			}
			else
			{
				Node *Right = Insert( Root->right, data, Root);
				
				if(Right == Root->parent) 
				{
                	return Right;
            	}
            	
            	Root->right = Right;
            	
				isLeft = false;
			}
			
			
			
			if( isLeft)
			{				
				if( Root->color == RED && Root->left->color == RED )
				{					
					Node *Sibling = getSibling( Root);

					if( Sibling == NULL || Sibling->color == BLACK )
					{
						if( isLeftChild(Root)) 
                        	RotateRight( Root, true);
                        else
						{
							RotateRight( Root->left, false);
							
							Root = Root->parent;
							
							RotateLeft( Root, true);
						}	
					}
				}
				else
				{
					Root->color = BLACK;
					if( getSibling( Root) != NULL )
					{
						getSibling( Root)->color = BLACK;
						if( Root->parent->parent != NULL )
							Root->parent->color = RED;
					}					
				}
			}
			else
			{				
				if( Root->color == RED && Root->right->color == RED )
				{
					Node *Sibling = getSibling( Root);					
					
					if( Sibling == NULL || Sibling->color == BLACK )
					{
						if( !isLeftChild(Root)) 
						{
							RotateLeft( Root, true);
						}                        	
                        else
						{
							RotateLeft( Root->right, false);
							
							Root = Root->parent;
							
							RotateRight( Root, true);
						}
					}
					else
					{
						Root->color = BLACK;
						getSibling( Root)->color = BLACK;
					
	                    if( Root->parent->parent != NULL )
						Root->parent->color = RED;
					}
				}
			}
			
			return Root;
		}

		void test()
		{			
			root = Insert( root, 30);
			root = Insert( root, 40);
			root = Insert( root, 35);
			root = Insert( root, 45);
			root = Insert( root, 50);		
			root = Insert( root, 55);
			root = Insert( root, 5);
			root = Insert( root, 7);
			root = Insert( root, 4);
			root = Insert( root, 9);
				
#if 01				
			cout<<root->parent<<endl;			
			cout<<root->left->color<<endl;			
			cout<<root->right->color<<endl;
			cout<<root->right->right->color<<endl;
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



