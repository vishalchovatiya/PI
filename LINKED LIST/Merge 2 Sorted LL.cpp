#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;


/*

	   
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
	
		Node* MergeSortedLL(Node *Head1, Node *Head2)
		{
			Node *Result = NULL;
			
			if( Head1 == NULL )		return Head2;
			if( Head2 == NULL )		return Head1;
			
			if( Head1->data <= Head2->data)
			{
				Result = Head1;
				Result->link = MergeSortedLL( Head1->link, Head2);
			}
			else
			{
				Result = Head2;
				Result->link = MergeSortedLL( Head1, Head2->link);
			}			
			
			return Result;
		}
			
		void test()
		{			
			Head1 = GetNewNode(0);			
			Head1->link = GetNewNode(2);
			Head1->link->link = GetNewNode(14);
			Head1->link->link->link = GetNewNode(15);
			Head1->link->link->link->link = GetNewNode(22);
						
			Head2 = GetNewNode(3);			
			Head2->link = GetNewNode(9);
			Head2->link->link = GetNewNode(11);
			Head2->link->link->link = GetNewNode(17);
			Head2->link->link->link->link = GetNewNode(25);
				
			PrintLL(Head1);
			cout<<endl;
			PrintLL(Head2);
			cout<<endl;
			
			
			PrintLL(MergeSortedLL(Head1, Head2));
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
