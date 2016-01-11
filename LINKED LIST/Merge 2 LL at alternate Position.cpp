#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*
	Question :
	
		LL1 : 5->7->17->13->11->NULL
		LL2 : 12->10->2->4->6->NULL
		
	Solution : 
	
		5->12->7->10->17->2->13->4->11->6->NULL		
	   
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *link;	
	};
	
	Node *Head1 = NULL, *Head2 = NULL;
	
	/*-------------------------------Utility Functions-------------------------------*/
	Node* GetNewNode(int data)
	{
		Node *temp = new Node;
		temp->data = data;
		temp->link = NULL;
		return temp;
	}
	void PrintLL(Node *Head)
	{
		if( Head == NULL)	return;
		cout<<" "<<Head->data;
		PrintLL(Head->link);
	}
	/*-----------------------------------------------------------------------------------*/

	public:	

		Node* MergeAlternateLL(Node *Head1, Node *Head2)
		{
			if( Head1 == NULL )	return Head2;
			if( Head2 == NULL )	return Head1;
			
			Node *Next1 = Head1->link;
			Node *Next2 = Head2->link;			

			Head1->link = Head2;
			Head2->link = Next1;
			
			MergeAlternateLL( Next1, Next2);
			
			return Head1;
		}
			
		void test()
		{			
			Head1 = GetNewNode(1);			
			Head1->link = GetNewNode(2);
			Head1->link->link = GetNewNode(3);
						
			Head2 = GetNewNode(4);			
			Head2->link = GetNewNode(5);
			Head2->link->link = GetNewNode(6);
				
			PrintLL(Head1);
			cout<<endl;
			PrintLL(Head2);
			cout<<endl;
			
			PrintLL(MergeAlternateLL( Head1, Head2));
			cout<<endl;
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
