#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
	public:
		int data;
		int priority;
		Node* left;
		Node* right;
};
typedef Node* NodePtr;

NodePtr root = NULL;

NodePtr getNewNode(int data, int priority = rand())
{
	NodePtr temp = new Node;
	temp->data = data;
	temp->priority = priority;
	temp->left = temp->right = NULL;
	return temp;
}	
		
void inorder(NodePtr root)
{
	if( root == NULL )	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void split(NodePtr root, int data, NodePtr &L, NodePtr &R)
{			
	NodePtr traverse = root;
	NodePtr Left = NULL, Right = NULL;
		
	while( traverse)
	{				
		if( traverse->data <= data){					
			if( Left == NULL )
				Left  = traverse;
			else
				Left->right  = traverse;
			
			if( L == NULL )
				L = traverse;
			
			NodePtr temp = traverse;
			traverse = traverse->right;			
			temp->right = NULL;
		}
		else{					
			if( Right == NULL )
				Right = traverse;
			else
				Right->left = traverse;
			
			if( R == NULL )
				R = traverse;
			
			NodePtr temp = traverse;					
			traverse = traverse->left;			
			temp->left = NULL;
		}
	}
}

NodePtr merge(NodePtr Left, NodePtr Right)
{
	NodePtr root = NULL;
	NodePtr *traverse = &root;
	
	while(Left && Right){
		if( Left->priority > Right->priority ){
			
			(*traverse) = Left;
			traverse = &Left->right;
			Left = Left->right;				
		}
		else{
			
			(*traverse) = Right;
			traverse = &Right->left;
			Right = Right->left;				
		}				
	}
	
	if( Left)
		(*traverse) = Left;
	else
		(*traverse) = Right;

	return root;		
}

NodePtr insert( NodePtr root, NodePtr newNode)
{
	if(root==NULL)
		return newNode;
	
	NodePtr traverse = root;
	NodePtr prev = NULL;
	
	while( traverse)
	{
		if( traverse->priority < newNode->priority ){					
			split( traverse, newNode->data, newNode->left, newNode->right);
			if(prev == NULL)
				root = newNode;
			else
				break;	
			return root;
		}
					
		if( traverse->data <= newNode->data){					
			prev = traverse;
			traverse = traverse->right;					
		}
		else{					
			prev = traverse;
			traverse = traverse->left;					
		}
	}
	
	if( prev->data <= newNode->data )
		prev->right = newNode;
	else
		prev->left = newNode;
	return root;		
}

NodePtr Delete( NodePtr root, int data)
{
	if( root == NULL )
		return root;
		
	NodePtr *prev = NULL;
	NodePtr traverse = root;
	
	while(traverse){
		
		if( traverse->data == data ){
			NodePtr top = merge( traverse->left, traverse->right);
			
			delete traverse;
			
			if( prev == NULL )
				return top;
			else{
				(*prev) = top;
			}							
			break;
		}				
		
		if( traverse->data < data ){
			prev = &traverse->right;	
			traverse = traverse->right;				
		}
		else{
			prev = &traverse->left;
			traverse = traverse->left;				
		}				
	}
	return root;					
}


int main()
{	
	NodePtr root = NULL;
	root = insert( root, getNewNode(1));
	root = insert( root, getNewNode(2));
	root = insert( root, getNewNode(3));
	root = insert( root, getNewNode(4));
	root = insert( root, getNewNode(5));
		
	inorder(root);
	cout<<endl;
	
	root = Delete(root, 3);
		
	inorder(root);
	cout<<endl;
	
	return 0;
}
