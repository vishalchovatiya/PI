#include <iostream>
using namespace std;

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

void MorrisTraversal(node* root){
	if(root==NULL)	return;
	
	node *successor = root->right;
	
	while(true){
		if( root->left ){
			cout<<root->data<<" ";
			node *temp = root->left;
			while(temp->right)	temp = temp->right;
			temp->right = root->right;
			temp->isThreaded = true;
			root = root->left;
		}else{
			cout<<root->data<<" ";
			if(!root->left && !root->right)	return;
			
			while(root->right && root->isThreaded){
				cout<<root->right->data<<" ";
				root = root->right;
			}
			
			root = root->right;
		}	
	}
}

int main(){
	
	node *root = new node(1);
	root->left        = new node(2);
	root->right       = new node(3);
	root->left->left  = new node(4);
	root->right->right = new node(5);
	
	MorrisTraversal(root);

	return 0;
}
