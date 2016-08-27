#include <iostream>
#include <stack>
using namespace std;


/*
  Logic : Fill Left View Of Tree in Stack & Print if not found more left View nodes

*/
class node{
	public:
	int data;
	node *left, *right;

	node(int data){
		this->data = data;		
		left = right = NULL;
	}
};

void PostOrderIterativeSingleStack(node* root,int K){
	if(root==NULL)	return;
	
	stack<node*>	S;
	node *lastPrinted = root;
	
	while(true){
		/* Step 1: Fill All Left Nodes of Tree in Stack */
		if(root){
			S.push(root);
			root = root->left;
		}else{
			/* Step 2: Check if left bottom node has right node, if yes then repeat Step 1 */
			if(!S.empty() && S.top()->right)	root = S.top()->right;
			/* Step 3: Print Stack until new right tree not found */
			else{
				while(!S.empty() && (S.top()->right == NULL || S.top()->right == lastPrinted)){
					cout<<S.top()->data<<" ";
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
	
	PostOrderIterativeSingleStack(root,4);

	return 0;
}
