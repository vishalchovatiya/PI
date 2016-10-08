#include <iostream>
#include <cstdlib>
using namespace std;

#define DEBUG(X)	cout<<" Node = "<<X->data<<" prio = "<<X->priority<<" size = "<<X->size<<endl;

class Node{
	public:
		int data;
		int priority;
		int size;
		Node* left;
		Node* right;
};
typedef Node* NodePtr;

NodePtr getNewNode(int data, int priority = rand())
{
	NodePtr temp = new Node;
	temp->data = data;
	temp->priority = priority;
	temp->left = temp->right = NULL;
	temp->size = 1;
	
	return temp;
}	

int size(NodePtr node)
{
	return node ? node->size : 0;
}

int updateSize(NodePtr root)
{
	return size(root->left) + 1 + size(root->right);
}
		
void inorder(NodePtr root)
{
	if( root == NULL )	return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void split(NodePtr root, NodePtr &L, NodePtr &R, int pos, int add=0)
{
	if(root==NULL) 		return void(L=R=NULL);
	
	int curr_pos = size(root->left) + add;
	
	if( curr_pos <= pos ){
		split( root->right, root->right, R, pos, curr_pos+1);
		L = root;
	}
	else{
		split( root->left, L, root->left, pos, add);
		R = root;
	}
	root->size = updateSize(root);
}

NodePtr merge(NodePtr Left, NodePtr Right)
{
	if( !Left)	return Right;
	if( !Right)	return Left;
	
	if( Left->priority > Right->priority ){
		Left->right = merge(Left->right, Right);
		Left->size = updateSize(Left);
		return Left;
	}		
	else{
		Right->left = merge(Left, Right->left);
		Right->size = updateSize(Right);
		return Right;
	}	
}

NodePtr insert( NodePtr root, NodePtr newNode, int pos)
{
	if( root == NULL ){
		return newNode;
	}	
	
	if( pos > root->size ){
		cout<<"Position is out of bound for node "<<newNode->data<<endl;
		return root;
	}
		
	NodePtr Left = NULL, Right = NULL;
	
	split( root, Left, Right, pos-1);
	
	Left = merge( Left, newNode);
	root = merge( Left, Right);
	
	return root;
}

NodePtr Delete( NodePtr root, int pos)
{
	if( pos > root->size ){
		cout<<"Position is out of bound for pos "<<pos<<endl;
		return root;
	}
	
	NodePtr Left = NULL, Right = NULL;	
	split( root, Left, Right, pos-1);

	NodePtr toBeDel = NULL;	
	split( Right, toBeDel, Right, 0);

	delete toBeDel;
	
	return merge(Left, Right);
}


int main()
{	
	NodePtr root = NULL;
	
	root = insert( root, getNewNode(5), 0);
	root = insert( root, getNewNode(3), 1);
	root = insert( root, getNewNode(10), 1);
	root = insert( root, getNewNode(8), 2);
	
	inorder(root);
	cout<<endl;
	
	root = Delete( root, 1);
	root = Delete( root, 0);
	
	inorder(root);
	cout<<endl;

	return 0;
}
