#include<cstdio>

#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<map>
#include<queue>
#include<vector>
using namespace std;

/*

	- Huffman coding is a lossless data compression algorithm with variable-legth codes.
	- Lengths of the assigned codes are based on the frequencies of corresponding characters. 
	- The most frequent character gets the smallest code and the least frequent character gets the largest code.
	- No Prefix Codes, means the codes (bit sequences) are assigned in such a way that the code assigned to one character is not prefix of code assigned to any other character. This is how Huffman Coding makes sure that there is no ambiguity when decoding the generated bit stream.
	
	There are mainly two major parts in Huffman Coding
		1) Build a Huffman Tree from input characters.
		2) Traverse the Huffman Tree and assign codes to characters.
		
	Algo:-
	 - Insert all the nodes(pair with frequency & char)	
	 - Extract 2 minimum nodes & combine them to form tree of frequency sum of them
	 - repeat this process until single node remains in tree which is root
	 
	Application:
	 - JPEG
	 - MP3 
*/

class Node
{
	public:
		char data;		
		int Freq;
		
		Node *left;
		Node *right;	

		Node(char data = '\0', int Freq = 0, Node *left = NULL , Node *right = NULL)	
		{
			this->data = data;
			this->Freq = Freq;
			this->left = left;
			this->right = right;
		}
};	

class Compare
{
	public:
	bool operator()(Node X, Node Y)	
	{
		return X.Freq > Y.Freq;
	}
};


Node buildHuffmanTree( Node node[], int Size)
{
	priority_queue< Node, vector<Node>, Compare> minHeap;
	
	for(int i=0; i<Size; i++)
		minHeap.push(node[i]);
	
	while( minHeap.size() != 1)	
	{
		Node Left = minHeap.top();
		minHeap.pop();
		
		Node *LeftTemp = new Node;
		LeftTemp->data = Left.data;
		LeftTemp->Freq = Left.Freq;
		LeftTemp->left = Left.left;
		LeftTemp->right = Left.right;		
		
		Node Right = minHeap.top();
		minHeap.pop();
		
		Node *RightTemp = new Node;
		RightTemp->data = Right.data;
		RightTemp->Freq = Right.Freq;
		RightTemp->left = Right.left;
		RightTemp->right = Right.right;	
		
		Node *Root = new Node;
		Root->data = '\0';
		Root->Freq = LeftTemp->Freq + RightTemp->Freq;
		Root->left = LeftTemp;
		Root->right = RightTemp;	

		minHeap.push(*Root);
	}
	
	return minHeap.top();
}

void traverseTree(Node *Root, int Arr[], int top=0)
{
	if( Root->left )
	{
		Arr[top] = 0;
		traverseTree( Root->left, Arr, top+1);
	}
	
	if( Root->right )
	{
		Arr[top] = 1;
		traverseTree( Root->right, Arr, top+1);
	}
	
	if( Root->left == NULL && Root->right == NULL)
	{
		cout<<" "<<Root->data<<" : ";
		for(int i=0; i<top; i++)
			cout<<" "<<Arr[i];
		cout<<endl;	
	}
}


int main()
{
	Node node[6];
	
	node[0].data = 'A';
	node[1].data = 'B';
	node[2].data = 'C';
	node[3].data = 'D';
	node[4].data = 'E';
	node[5].data = 'F';
	
	node[0].Freq = 5;
	node[1].Freq = 9;
	node[2].Freq = 12;
	node[3].Freq = 13;
	node[4].Freq = 16;
	node[5].Freq = 45;
	
	Node Root = buildHuffmanTree( node, 6);

	int Arr[20];
	traverseTree( &Root, Arr);
	
	return 0;
}
