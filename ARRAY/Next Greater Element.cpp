#include<string.h>
#include<stdlib.h>
#include<map>
#include<stack>
#include<vector>
#include<iostream>
#include <algorithm>


using namespace std;

#define SIZE(A)		sizeof(A)/sizeof(A[0])


/*
	Question:- Next Greater Element
	
	Example : [13, 7, 6, 12}, the next greater elements for each element are as follows.

	  Element         NGE
	   13      -->     NULL
	   7       -->     12
	   6       -->     12
	   12      -->     NULL

	
	Algo:
	
	1) Push the first element to stack.
	2) Pick rest of the elements one by one and follow following steps in loop.
	….a) Mark the current element as next.
	….b) If stack is not empty, then pop an element from stack and compare it with next.
	….c) If next is greater than the popped element, then next is the next greater element for the popped element.
	….d) Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
	….g) If next is smaller than the popped element, then push the popped element back.
	3) After the loop in step 2 is over, pop all the elements from stack and print NULL as next element for them.
*/

void printNGE( int A[], int Size)
{	// 3, 8, 1, 5, 11, 22, 6
	stack<int>	S;
	
	S.push( A[0] );
	
	for(int i=1; i<Size; i++)
	{
		while( !S.empty() && S.top() < A[i] )
		{
			cout<<S.top()<<" "<<A[i]<<endl;
			S.pop();		
		}
			
		S.push( A[i] );				
	}
	
	while( !S.empty() )
	{
		cout<<S.top()<<" NULL"<<endl;
		S.pop();
	}
}
 
int main()
{
	int arr[]= {3, 8, 1, 5, 11, 22, 6};
	
    printNGE(arr, SIZE(arr));

    return 0;
}

