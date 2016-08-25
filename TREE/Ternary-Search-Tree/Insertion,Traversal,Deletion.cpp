#include <iostream>
using namespace std;


/*
  Anatomy:
  Node ContainS 5 Things
  1. Data	: Data to be store
  2. isEnd	: Flag to check is string end
  3. Left	: Stores lower value sub-tree rooted data as compared to input string data
  4. Equal	: Stores Same value sub-tree rooted data as compared to input string data
  5. Right	: Stores higher value sub-tree rooted data as compared to input string data

  Advantages Over Trie Tree:
  - Memory Effiecient
  - Ternary Search Trees are better when data share common prefixes like Find all telephone numbers starting with 9342.
  
  Application :
  - Used in spell checks
  - Web browser OR Search Engine Auto-Complete Feature
  
  Note: Following Implentation includes Insert, Traverse & Search Operation in TST

*/

class node{
	public:
		char data;
		bool isEnd;
		
		node *lo,*eq,*hi;
		node(char data){
			this->data = data;
			isEnd = hi = lo = eq = NULL;
		}
};

class TernarySearchTree{
	public:
		node *root;
		
		TernarySearchTree() : root(NULL){};
		
		void traverse(node*root){
			char arr[100];
			traverseUtil(root,0,arr);
		}
				
		void traverseUtil(node* root, int index, char arr[]){
			if(root == NULL)	return;
			
			traverseUtil( root->lo, index, arr);
			
			arr[index] = root->data;
			
			if(root->isEnd==true){
				arr[index+1] = '\0';
				cout<<arr<<endl;
			}
			
			traverseUtil( root->eq, index+1, arr);
			traverseUtil( root->hi, index, arr);
		}
	
		node *insert(node *root, char word[]){
			if(root==NULL){						// Base Case: Root is NULL
				if( *word == '\0' )	return NULL;
				root = new node(*word);
			}
			
			if( (*word) < root->data ){			// Lesser
				root->lo = insert( root->lo, word);
			}else if( (*word) > root->data ){	// Greater 
				root->hi = insert( root->hi, word);
			}else{								// Equal
				root->eq = insert( root->eq, word+1);
				if(root->eq==NULL)	root->isEnd = true;
			}
			
			return root;
		}

		bool search(node *root, char word[]){
			if(root==NULL || (*(word))=='\0' )	return false;
			
			if( (*word) < root->data ){			// Lesser
				return search( root->lo, word);
			}else if( (*word) > root->data ){	// Greater 
				return search( root->hi, word);
			}else{								// Equal
				if( root->data == (*(word)) && root->isEnd == true && (*(word+1)) == '\0' )
					return true;
				else
					return search( root->eq, word+1);
			}	
			return false;
		}
};

int main() {
    TernarySearchTree T;
    
    
    T.root = T.insert(T.root, "CAT");
    T.root = T.insert(T.root, "CATS");
    T.root = T.insert(T.root, "BUG");
    T.root = T.insert(T.root, "UP");
    
    T.traverse(T.root);
    
    cout<<T.search(T.root,"CATS")<<endl;
}
