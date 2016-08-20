#include <iostream>
using namespace std;

/*
- Inorder traversal of a Binary tree is either be done using recursion or with the use of a auxiliary stack. The idea of threaded binary trees is to make inorder traversal faster and do it without stack and without recursion. A binary tree is made threaded by making all right child pointers that would normally be NULL point to the inorder successor of the node (if it exists).
There are two types of threaded binary trees.
- Single Threaded: Where a NULL right pointers is made to point to the inorder successor (if successor exists)
- Double Threaded: Where both left and right NULL pointers are made to point to inorder predecessor and inorder successor respectively. The predecessor threads are useful for reverse inorder traversal and postorder traversal.
The threads are also useful for fast accessing ancestors of a node.

Here is Single Threaded Binary Tree
*/

class node{
	public:
	int data;
	node *left, *right;
	bool isThreaded;
	
	node(int data){
		this->data = data;		
		isThreaded = left = right = NULL;
	}
};

void inorderThreaded(node* root){
	if(root==NULL)	return;
	
	while(true){
		if(root->left!=NULL){
			root = root->left;
		}
		else{
			cout<<root->data<<" ";
			
			if(!root->left && !root->right)	return;
			
			if(root->right){
				do{
					root = root->right;	
					cout<<root->data<<" ";
				}while(root->isThreaded);
				root = root->right;	
			}
		}
		
	}
}


int main(){

	node* root = new node(2);
	root->left = new node(1);
	root->right = new node(3);
	
	root->left->left = new node(0);
	
	/*Setting Threads of node having value 1*/
	root->left->right = root;
	root->left->isThreaded = true;

	/*Setting Threads of node having value 0*/
	root->left->left->right = root->left;
	root->left->left->isThreaded = true;

	inorderThreaded(root);

	return 0;
}
