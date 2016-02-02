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
                        
     - Time Complexity:- O(key_length), 
	 
	 Logic:- Use bool variable in trie node structure to find key end or not
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
	/*-----------------------------------------------------------------------------------*/

	public:	
				
		bool isFreeNode(Node *node)
		{
			for(int i=0; i<ALPHABET_SIZE; i++)
				if ( node->Child[i] )
					return false;
			return true;		
		}
		
		Node* Delete(Node *Root, const char String[])
		{
			// Base Case
			if( *String == '\0' )	
			{
				if( isFreeNode( Root) && Root->isKeyEnd )
				{
					delete Root;
					return NULL;
				}
				else if ( Root->isKeyEnd )
				{
					Root->isKeyEnd = false;
				}
			}
			
			// Crawl for rest of tree with key
			if( Root != NULL && 
				Root->Child[CHAR_TO_INDEX(*String)] != NULL  )
			{
				Root->Child[CHAR_TO_INDEX(*String)] = Delete(  Root->Child[CHAR_TO_INDEX(*String)],  String+1);
				
				// When backtracking delete all free node
				if( isFreeNode( Root) )
				{
					delete Root;
					Root = NULL;
				}
			}	
				
			return Root;
		}
	
		void test()
		{			
			char keys[][8] = {"she", "sells", "sea", "shore", "the", "by", "sheer"};
			
			char output[][32] = {"Not present in trie", "Present in trie"};
			
			for( int i=0; i<ARRAY_SIZE(keys); i++)
				Root = Insert( Root, keys[i]);		
				
			
			Root = Delete( Root, "sea");
	
			//cout<<Root->Child[CHAR_TO_INDEX('t')]->Child[CHAR_TO_INDEX('h')]->Child[CHAR_TO_INDEX('e')]->isKeyEnd<<endl;
						
		    cout<<"she ---"<< output[Search(Root, "she")] <<endl;
		    cout<<"shore ---"<< output[Search(Root, "shore")] <<endl;
		    cout<<"asfasf ---"<< output[Search(Root, "asfasf")] <<endl;
		    cout<<"sea ---"<<  output[Search(Root, "sea")] <<endl;
		   
		}
};






int main()
{
	TRIETree T;
	
	T.test();	
	
	return 0;
}
