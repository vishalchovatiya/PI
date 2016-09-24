#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

#define DEBUG(level) cout<<" > "<<#level<<" = "<<level<<endl

class node
{
	public:
		int data;
		node *left;	
		node *right;	
};

void top_view(node * root); 

node *getNewNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}	

int main()
{
	node *root = getNewNode(1);
	
	root->left = getNewNode(3);
	root->right = getNewNode(2);
	
	root->left->left = getNewNode(5);
	root->left->right = getNewNode(4);
	root->right->left = getNewNode(6);
	root->right->right = getNewNode(7);

	root->left->left->left  = getNewNode(9);
	root->left->left->right = getNewNode(8);	
	root->left->right->left  = getNewNode(11);
	root->left->right->right = getNewNode(13);
	
	root->right->left->left = getNewNode(12);
	root->right->left->right = getNewNode(10);
	
	root->right->right->left = getNewNode(15);
	root->right->right->right = getNewNode(14);
	

	

	
	
	top_view(root);
}

void top_view(node * root)
{
    int Min=0;
    int Max=0;
    map<int, int>   T;
    queue<node*>    Q;
    list<int>		R;
    
    Q.push(root);
    T[root->data] = 0;
    R.push_back(root->data);
    
    while(!Q.empty()){
        node *traverse = Q.front();
        int level = T[traverse->data] ;
        Q.pop();

        if( traverse->left){
            Q.push(traverse->left);
            if( level-1 < Min ){
            	Min = level-1;
            	R.push_front(traverse->left->data)  ;             
            }  
            
        	T[traverse->left->data] = level-1;  
        }
 
        if( traverse->right){
            Q.push(traverse->right);
            if( level+1 > Max ){
            	Max = level+1;
            	R.push_back(traverse->right->data)  ; 
            }              
            
            T[traverse->right->data] = level+1;  
        }	       
    }
    
    for(list<int> :: iterator it = R.begin(); it!=R.end(); it++){
    	cout<<*it<<" ";
    }
    
}
