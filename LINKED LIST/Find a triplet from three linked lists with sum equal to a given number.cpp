#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	# Algo :- 			3SUM Algo

	# Naive Method: 
		- Run three nested loops. The outermost loop picks an element from list a, 
		- The middle loop picks an element from b and the innermost loop picks from c. 
		- The innermost loop also checks whether the sum of values of current nodes of a, b and c is equal to given number. 
		- The time complexity of this method will be O(n^3).
		
	# Effecient Method:  Sorting can be used to reduce the time complexity to O(n*n)
		- Sort list b in ascending order, and list c in descending order.
		- After the b and c are sorted, one by one pick an element from list a and find the pair by traversing both b and c. 
		- See isSumSorted() in the following code. The idea is similar to Quadratic algorithm of 3 sum problem.	
*/

class List
{
	class Node
	{
		public:
			int data;
			Node *link;	
	};
	
	Node *Head1 = NULL, *Head2 = NULL, *Head3 = NULL;
	
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
		/*--------------------------------- Merge Sort ------------------------------------*/
		Node* Merge(Node* Head1, Node* Head2)	// O( M + N )
		{
			Node *Result = NULL;
			if( Head1 ==  NULL)	 return Head2;
			if( Head2 ==  NULL)	 return Head1;
			
			if( Head1->data >= Head2->data)
			{
				Result = Head1;
				Result->link = Merge( Head1->link,  Head2);
			}
			else
			{
				Result = Head2;
				Result->link = Merge( Head1,  Head2->link);
			}
			return Result;
		}
		
		void SplitInTwoHalves(Node *Head, Node** Head1, Node** Head2)	// O( N )
		{
			Node* SlowPtr = Head;
			*Head1 = Head;
			
			// If LL is of size 1 or 2 
			if( Head->link == NULL || Head->link->link == NULL )
			{
				*Head2 = Head->link;
				(*Head1)->link = NULL;
			}
			// If LL is of size Greater than 2
			else
			{
				while( Head != NULL && Head->link != NULL)
				{
					SlowPtr = SlowPtr->link;
					Head = Head->link->link;
				}
				
				*Head2 = SlowPtr->link;
				SlowPtr->link = NULL;	
			}			
		}
		
		void MergeSort(Node **Head)		// O(NLogN)
		{
			Node *Head1 = NULL,*Head2 = NULL;
			
			// Base Case : If LL is of size 1 then return
			if( *Head == NULL || (*Head)->link == NULL )	return;
			
			SplitInTwoHalves(*Head, &Head1, &Head2);

			MergeSort(&Head1);
			MergeSort(&Head2);
			
			*Head = Merge(Head1, Head2);
		}
		/*-----------------------------------------------------------------------------------------*/
		
		bool IsTriplet(Node *&Head1, Node *&Head2, Node *&Head3, int GivenNumber)
		{
			Node *a = Head1;
			
			// For every node of list a, pick two nodes from lists b abd c
			while( a != NULL )
			{
				Node *b = Head2;
				Node *c = Head3;
				
				while( b != NULL && c != NULL )
				{
					int sum = a->data + b->data + c->data;
					
					if( sum == GivenNumber )
						return true;
					else if( sum < GivenNumber )	// If sum of this triplet is smaller, look for greater values in b
						b = b->link;
					else							// If sum is greater, look for smaller values in c
						c = c->link;						
				}				
				a = a->link;  						// Move ahead in list a
			}
			return false;
		}
	
	
		void test()
		{						
			Head1 = GetNewNode(7);			
			Head1->link = GetNewNode(5);
			Head1->link->link = GetNewNode(9);
			
			PrintLL(Head1);	
			cout<<endl;	

			Head2 = GetNewNode(1);			
			Head2->link = GetNewNode(2);
			Head2->link->link = GetNewNode(3);
						
			PrintLL(Head2);	
			cout<<endl;
			
			Head3 = GetNewNode(7);			
			Head3->link = GetNewNode(4);
			Head3->link->link = GetNewNode(1);	
						
			PrintLL(Head3);	
			cout<<endl;	
			
			cout<<IsTriplet(Head1, Head2, Head3, 12)<<endl;	
					
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}


