#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
		Use :- Goto statement
*/

class binarySearchTree;

class treeNode
{
	/*
	 *with the following friend declaration
	 *binarySearchTree can access private members of treeNode
	 */
		friend class binarySearchTree;
		
	private:
		
		int data;
		treeNode * left;
		treeNode * right;

	public:
		
		treeNode()
		{
			left=right=NULL;
		}
		
		treeNode(int key)
		{
			data=key;
			left = right = NULL;
		}
		
		int getData()
		{ 
			return data;
		}
		
		void setData(int key)
		{
			data=key;
		}
};




class binarySearchTree
{
	private:
		treeNode *root;
		
	public:

		binarySearchTree()
		{
			root=NULL;
		}
	
		void printPostOrder(treeNode * head)
		{
			if(head==NULL) return;
			
			printPostOrder(head->left);
			printPostOrder(head->right);
	        printf("%d ",head->data);
		}
		
		void print()
		{
			if(root==NULL)
			{
				printf("NULL");
				return;
			}
			
			printPostOrder(root->left);
			printPostOrder(root->right);
			printf("%d ",root->data);
		}
		
		/************************************
		 *inserts key in tree
		 *returns NULL, if the key already exists
		 */
		treeNode* insert(int key)
		{
			treeNode *Traverse = root;
			treeNode *Record = NULL;
			
			if( root == NULL )
			{
				root = new treeNode(key);
				return root;
			}
			
			while( Traverse != NULL )
			{
				Record = Traverse;
				
				if( key < Traverse->getData() )
					Traverse = Traverse->left;
				else if ( key > Traverse->getData() )
					Traverse = Traverse->right;
				else
					return NULL;
			}
	
			if( key < Record->getData() && Record->left == NULL )
			{
				Record->left = new treeNode(key);
				return Record->left;	
			}			
			else
			{
				Record->right = new treeNode(key);
				return Record->right;	
			}	
			
			return NULL;	
		}
	
		/**************************
		 *return 1 on success, else returns 0 if not found, -1 if empty
		 *removes a key from the tree
		 ***************************/
		int remove(int key)
		{
			if(root == NULL)
				return -1;
			
			treeNode *Traverse = root;
			treeNode *Record = NULL;
		
		reDelete:
			//printf("key = %d && Traverse = %d && Left = %p && Right = %p\n\n", key, Traverse->getData(), Traverse->left, Traverse->right );
			
			while( Traverse->getData() != key && Traverse != NULL )
			{
				Record = Traverse;
			
				if( key < Traverse->getData() )
					Traverse = Traverse->left;
				else
					Traverse = Traverse->right;				
			}
			
			if( Traverse==NULL )
				return false;
			
			//case 1: Leafe Node
			if( Traverse->left == NULL && Traverse->right == NULL )
			{
				if(  Traverse == root )
				{
					delete Traverse;
					Traverse = root = NULL;
					return true;
				}	
				//printf("################Leafe Node######################\n");
				delete Traverse;			
				
				if( Record != NULL &&  Record->left == Traverse )
				{
					Record->left = NULL;
				}
				else if(Record != NULL &&  Record->right == Traverse )
				{
					Record->right = NULL;
					//printf("Record = %d\n\n", Record->getData());				
				}
				
				return true;
			}
			//case 2: only one child
			else if( Traverse->left == NULL || Traverse->right == NULL )
			{
			//	printf("Record = %d && Traverse = %d\n\n", Record->getData(), Traverse->getData());
				if( Traverse->left == NULL )
				{
					//printf("Left is NULL\n");
					Traverse->setData( Traverse->right->getData() );
					key = Traverse->getData();
					Record = Traverse;
					Traverse = Traverse->right;
					goto reDelete;
				}
				else
				{
					//printf("Right is NULL\n");
					Traverse->setData( Traverse->left->getData() );
					key = Traverse->getData();
					Record = Traverse;
					Traverse = Traverse->left;
					goto reDelete;
				}				
			}
			//case 3: have both the child
			else
			{
				//printf("Node To be Deleted = %d\n\n", Traverse->getData());
				treeNode *Del = Traverse;
				Record = Traverse;
				
				Traverse = Traverse->left;
				while( Traverse != NULL && Traverse->right != NULL)
				{
					Traverse = Traverse->right;
				}
				
				//printf("Del = %d\n\n", Del->getData());
				
				Del->setData( Traverse->getData() );
				
			//	printf("Del = %d\n\n", Del->getData());
				
				key = Del->getData();
				
			//	printf("key = %d\n\n", key);
			//	printf("Traverse = %d\n\n", Traverse->getData());
				//Traverse = Traverse->left;
			
				goto reDelete;
			}	

		}
		
		
		void test()
		{			
			binarySearchTree bst;
			
			bst.insert(3);
			bst.insert(4);
			bst.insert(5);
			bst.insert(1);
			bst.insert(77);
			bst.insert(33);
			
			bst.remove(5);
			
			
			bst.print();
			
			
		}
};


int main()
{
	binarySearchTree bst;

	bst.test();
	
	return 0;
	
}


