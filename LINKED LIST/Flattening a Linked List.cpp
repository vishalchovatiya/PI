#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question : Right list and Down list are sorted, form single LL which is also sorted
       
	   5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
       
      Solution: 5->7->8->10->19->20->22->28->30->35->40->45->50 
       
		# Algo:- 
			- Merge any 2 Down LL 
			- For instance if we Merge first and last down LL, We have like this
	   5 -> 10 -> 19 
       |    |     |     
       V    V     V     
       7    20    22    
       |          |     
       V          V     
       8          50    
       |                
       V                
       28              
       |
       V
       30
       |
       V
       35
       |
       V
       40
       |
       V
       45	   
       		- Repeat this process until we have sorted linked list
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *Down;
			Node *link;	
	};
	
	Node *Head = NULL;
	
	/*-------------------------------Utility Functions-------------------------------*/
	Node* GetNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->link = NULL;
		temp->Down = NULL;
		return temp;
	}
	void PrintDown(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintDown(Head->Down);
	}
	
	void PrintLL(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintDown(Head->Down);
		cout<<endl;
		PrintLL(Head->link);
	}
	/*-----------------------------------------------------------------------------------*/

	public:	
	
		Node* MergeSortedLL( Node* Head1, Node* Head2 )
		{
			Node* result = NULL;
			
		    if (Head1 == NULL)	        return Head2;
		    if (Head2 == NULL)	        return Head1;
		    
		    if (Head1->data < Head2->data)
		    {
		        result = Head1;
		        result->Down = MergeSortedLL( Head1->Down, Head2 );
		    }
		    else
		    {
		        result = Head2;
		        result->Down = MergeSortedLL( Head1, Head2->Down );
		    }
		 
		    return result;
		}
				
		Node* FlattenRecursive(Node* Head)
		{		    
		    if (Head == NULL || Head->link == NULL)
		        return Head;

		    return MergeSortedLL( Head, FlattenRecursive(Head->link) );
		}
 
		Node* FlattenIterative(Node* Head)
		{		    
		    if (Head == NULL || Head->link == NULL)
		        return Head;

			Node* Main = Head;
			Head = Head->link;
			
		    while( Head != NULL)
		    {
		    	Main = MergeSortedLL( Main, Head );
		    	Head = Head->link;
		    }
		    return Main;
		}
			
		void test()
		{			
			Head = GetNewNode(5);	
			Head->Down = GetNewNode(7);	
			Head->Down->Down = GetNewNode(8);	
			Head->Down->Down->Down = GetNewNode(30);
					
			Head->link = GetNewNode(10);
			Head->link->Down = GetNewNode(20);	
			
			Head->link->link = GetNewNode(19);
			Head->link->link->Down = GetNewNode(22);
			Head->link->link->Down->Down = GetNewNode(50);			
			
			Head->link->link->link = GetNewNode(28);
			Head->link->link->link->Down = GetNewNode(35);
			Head->link->link->link->Down->Down = GetNewNode(40);
			Head->link->link->link->Down->Down->Down = GetNewNode(45);			
			
			PrintLL(Head);
			cout<<endl;
			PrintDown(FlattenIterative(Head));
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
