#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	# Examples:
		Input:
		  First List: 5->6->3  		// represents number 365
		  Second List: 8->4->2 		//  represents number 248
		Output:
		  Resultant list: 3->1->6 	// represents number 613
			
	# Algo :-
	
		- Recursively call one by one node of both LL
		- Calculate the sum and carry
		- Maintain Head Pointers of Resulted LL and rest of Resulted LL
		- Handle Case : Different size of LL
		
	# Time Complexity: O(N)
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
	
		Node* AddNumberByLL( Node *Head1, Node *Head2, int Carry = 0, Node *ResultLL = NULL, Node *ResultHead = NULL)
		{
			// Base Case
			if (Head1 == NULL && Head2 == NULL)
				return ResultHead;
			
			int Head1data = 0, Head2data = 0;
			Node *Head1Next = NULL, *Head2Next = NULL, *node = NULL;
 			
 			// Handle Case : Different size of LL
			if( Head1 != NULL)
			{
				Head1data = Head1->data;
				Head1Next = Head1->link;
			}		
			if( Head2 != NULL)	
			{
				Head2data = Head2->data;
				Head2Next = Head2->link;
			}
				
			// Adding Digits represented by nodes	
			int Result = Head1data + Head2data + Carry;			
			if( Result > 9 )
			{
				node = GetNewNode(Result%10);	
				Carry = 1;
			}				
			else
			{
				node = GetNewNode(Result);	
				Carry = 0;
			}	
			
			// Maintain First Head Node of Result Linked List
			if( ResultLL == NULL )
			{
				ResultLL = node;
				ResultHead = ResultLL;
				return AddNumberByLL( Head1Next, Head2Next, Carry, ResultLL, ResultHead);
			}
			// Maintain Result Linked List
			else
			{
				ResultLL->link = node;
				return AddNumberByLL( Head1Next, Head2Next, Carry, ResultLL->link, ResultHead);
			}
		}
	
		void test()
		{						
			Head1 = GetNewNode(7);			
			Head1->link = GetNewNode(5);
			Head1->link->link = GetNewNode(9);
			Head1->link->link->link = GetNewNode(4);
			Head1->link->link->link->link = GetNewNode(6);
			
			Head2 = GetNewNode(8);			
			Head2->link = GetNewNode(4);	
			
			PrintLL(Head1);		// 64957
			cout<<endl;	
			PrintLL(Head2);		// 48
			cout<<endl;	
		
			PrintLL(AddNumberByLL( Head1, Head2));	// 65005 = 5->0->0->5->6->NULL
			cout<<endl;						
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}


