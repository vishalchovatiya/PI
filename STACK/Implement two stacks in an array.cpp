#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*

Naive Method: Divide the space in two halves (arr[0] to arr[n/2] for stack1, and arr[n/2+1] to arr[n-1] for stack2)

Efficient Approach:
	
	- This method efficiently utilizes the available space
	- Stack1 starts from the leftmost element and Stack2 starts from the rightmost corner
	- Handle Case: both stack's top match
*/

class Stack
{
	int size;
	int *stack;
	int top1;
	int top2;
	
	public:
		
		void InitializeStack(int Size);
		void Push1(int Element);
		void Pop1();
		int Front1();
		
		void Push2(int Element);
		void Pop2();
		int Front2();
	
};

void Stack::InitializeStack(int Size)
{
	top1 = 0;
	top2 = Size-1;
	size = Size;
	stack = new int[Size];
	memset(stack, -1, sizeof(int)*Size);
}

void Stack::Push1(int Element)
{
	if( top1-1 == top2)
		cout<<"Stack Full"<<endl;
	else
	{
		stack[top1++] = Element;
	}	
}


void Stack::Pop1()
{
	if( top1 == 0)
		cout<<"Stack Empty"<<endl;
	else
	{
		stack[top1--] = -1;
	}
}

int Stack::Front1()
{
	if( top1 == 0)
		cout<<"Stack Empty"<<endl;
	else
	{
		return stack[top1];
	}
}


void Stack::Push2(int Element)
{
	if( top1-1 == top2)
		cout<<"Stack Full"<<endl;
	else
	{
		stack[top2--] = Element;
	}	
}


void Stack::Pop2()
{
	if( top2 == size)
		cout<<"Stack Empty"<<endl;
	else
	{
		stack[top2++] = -1;
	}
}

int Stack::Front2()
{
	if( top2 == size)
		cout<<"Stack Empty"<<endl;
	else
	{
		return stack[top2];
	}
}

int main()
{
	Stack S;
	
	S.InitializeStack(10);
	
	S.Push1(0);//top1 = 0
	S.Push1(0);//top1 = 1
	S.Push1(0);//top1 = 2
	S.Push1(0);//top1 = 3
	S.Pop1();  //top1 = 2
	S.Push1(0);//top1 = 3
	S.Push1(0);//top1 = 4
	
	
	S.Push2(0);//top2 = 9
	S.Push2(0);//top2 = 8
	S.Push2(0);//top2 = 7
	S.Push2(0);//top2 = 6
	S.Pop2();  //top2 = 7
	S.Push2(0);//top2 = 6
	S.Push2(0);//top2 = 5
	
	
	return 0;
}
