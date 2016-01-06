#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;

======================================Pending
/*
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
	
		void test()
		{						
			Head1 = GetNewNode(7);			
			Head1->link = GetNewNode(5);
			Head1->link->link = GetNewNode(9);
			Head1->link->link->link = GetNewNode(4);
			Head1->link->link->link->link = GetNewNode(6);

			
			PrintLL(Head1);	
			cout<<endl;	
					
		}
};


int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}


