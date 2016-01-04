#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <set>
#include <queue>
using namespace std;


/*
	Algo :-	Use Hash Map Property
	
		- When there is no element present in map with given key, map create null element with that key
		
		
	# Time Complexity :- O(m) or O(n) whicever is greater
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
	
		Node *MergePointOfTwoLL(Node *Head1, Node *Head2)
		{
			map<Node*, bool> AddressToStatus;
			
			while( Head1 != NULL || Head2 != NULL)
			{			
				if( AddressToStatus[Head1] == true )	
					return Head1;

				AddressToStatus[Head1] = true;
				
				if( AddressToStatus[Head2] == true )	
					return Head2;
		
				AddressToStatus[Head2] = true;
				
				if(Head1 !=  NULL)
					Head1 = Head1->link;
				if(Head2 !=  NULL)
					Head2 = Head2->link;							
			}		
		}
		
		void test()
		{						
			Head1 = GetNewNode(4);			
			Head1->link = GetNewNode(3);
			Head1->link->link = GetNewNode(1);
			Head1->link->link->link = GetNewNode(9);
			Head1->link->link->link->link = GetNewNode(7);
	
			PrintLL(Head1);
			cout<<endl;		
			
			Head2 = GetNewNode(0);			
			Head2->link = GetNewNode(22);
			Head2->link->link = GetNewNode(11);
			Head2->link->link->link = Head1->link->link;
	
			PrintLL(Head2);
			cout<<endl;
			
			PrintLL(MergePointOfTwoLL( Head1, Head2));
			cout<<endl;			
		}
};






int main()
{
	List LL;
	
	LL.test();
	
	return 0;
}
