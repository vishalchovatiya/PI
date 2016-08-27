#include <iostream>
#include <stack>
using namespace std;

/*
  Logic Here is Use Post Traversal Iterative & Look For Node to Appear. If Node Found Print Stack
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

void printStack(stack<node*>	&S){
	while(!S.empty()){
		cout<<S.top()->data<<" ";
		S.pop();
	}
}

void AncestorOfNodeK(node* root,int K){
	if(root==NULL)	return;
	
	stack<node*>	S;
	node *lastPrinted = root;
	
	while(true){
		/* Step 1: Fill All Left Nodes of Tree in Stack */
		if(root){
			S.push(root);
			root = root->left;
		}else{
			if(!S.empty() && S.top()->right)	root = S.top()->right;
			else{
				while(!S.empty() && (S.top()->right == NULL || S.top()->right == lastPrinted)){
					
					//cout<<S.top()->data<<" ";
					if( S.top()->data == K){
						printStack(S);
						return;
					}
					
					lastPrinted = S.top();
					S.pop();
				}				
			}
			if(S.empty())	return;
			root = S.top()->right;
		}
	}
	
	
}
int main(){
	
	node *root = new node(1);
	root->left        = new node(2);
	root->right       = new node(3);
	root->left->left  = new node(4);
	root->right->right = new node(5);
	
	AncestorOfNodeK(root,3);

	return 0;
}
