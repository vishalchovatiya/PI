#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

// No of Alphabets
#define ALPHABET_SIZE 26

// Convert char into index
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// Calculate size of array
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

/*
	keys = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	
                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r
     - Time Complexity:- Insert & search = O(key_length), 
	 - Space Complexity:- O(ALPHABET_SIZE * key_length * N) where N is number of keys in trie. 
	 - There are efficient representation of trie nodes (e.g. compressed trie, ternary search tree, etc.) to minimize memory requirements of trie.                   
*/

class TRIETree
{
	class Node
	{
		public:
			bool isKeyEnd;		// This Variable is used to delete or search key /* Used to mark key leaf nodes */
			Node *Child[ALPHABET_SIZE];
	};
	
	Node *Root = NULL;
	
	/*-------------------------------Utility Functions----------------------------------*/
	Node *getNewNode(bool KeyEnd=false)
	{
		Node *node = new Node;
		
		node->isKeyEnd = KeyEnd;
		
		for(int i=0; i<ALPHABET_SIZE; i++)
			node->Child[i] = NULL;
		
		return node;
	}	
	/*-----------------------------------------------------------------------------------*/

	public:	
				
				
		Node* Insert(Node *Root, const char String[])
		{			
			if( *String == '\0' )	return getNewNode(true);
							
			if( Root == NULL )
			{
				Root = getNewNode(false);
			}
							
			Root->Child[CHAR_TO_INDEX(*String)] = Insert( Root->Child[CHAR_TO_INDEX(*String)], String+1);			

			return Root;
		}
		
		bool Search(Node *Root, const char String[])
		{
			if( *String == '\0' && Root->isKeyEnd )	return true;

			if( Root != NULL && 
				Root->Child[CHAR_TO_INDEX(*String)] != NULL && 
				Search(  Root->Child[CHAR_TO_INDEX(*String)],  String+1) )
				return true;
			
			return false;
		}
	
		void test()
		{			
			char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
			
			char output[][32] = {"Not present in trie", "Present in trie"};
			
			for( int i=0; i<ARRAY_SIZE(keys); i++)
				Root = Insert( Root, keys[i]);		
						
		    cout<<"the ---"<< output[Search(Root, "the")] <<endl;
		    cout<<"these ---"<< output[Search(Root, "these")] <<endl;
		    cout<<"their ---"<< output[Search(Root, "their")] <<endl;
		    cout<<"thaw ---"<<  output[Search(Root, "thaw")] <<endl;
		}
};






int main()
{
	TRIETree T;
	
	T.test();	
	
	return 0;
}
