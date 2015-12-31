#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
#include <queue>
using namespace std;

/*
	Key Things:
	
		- Handle Edge cases carefully, There are lot of edge cases
		- Use two separate variables for Queue size and capacity
		- Role over rear and front of queue when reaches to capacity by modulo operation
*/

class Queue
{
	int *Q;
	int front;
	int rear;
	int capacity;
	int size;
	
	public:	
		Queue()
		{
			front = 0;
			rear = 0;
			size = 0;	
		}
	
		void InitialiseQueue(int capacity )
		{
			Q = new int[capacity];
			this->capacity = capacity;
		}
		
		void Enqueue(int Element)
		{
			if ( isFull())
			{
				cout<<" Queue is Full"<<endl;
				return;
			}				
				
			if( rear+1 >= capacity )
			{			
				Q[rear++] = Element;
				rear = (rear) % capacity;
			}
			else
			{
				Q[rear++] = Element;	
			}		
			size++;
		}

		bool isFull()
		{		
			if( size  == capacity ) return true;
			else 					return false; 
		}
		
		bool isEmpty()
		{
			if( size == 0 ) return true; 
			else 			return false; 
		}
				
		int Dequeue()
		{
		//	cout<<"rear  = "<<rear<<" front = "<<front<<endl;
			if ( isEmpty())
			{
				cout<<" Queue is Empty" << endl;
				return -1;
			}				
				
			int Element = Q[front++];
			if( front+1 >= capacity )
			{
				front = (front) % capacity;				
			}
			size--;
			return	Element;
		}
		
		void test()	
		{
			InitialiseQueue( 5);
			Enqueue( 0);
			Enqueue( 1);
			Enqueue( 2);
			Enqueue( 3);
			Enqueue( 4);
			
			cout<<Dequeue()<<endl;
			cout<<Dequeue()<<endl;
			cout<<Dequeue()<<endl;
			cout<<Dequeue()<<endl;
			cout<<Dequeue()<<endl;

			Enqueue( 5);
			
			cout<<Dequeue()<<endl;
			
			cout<<Dequeue()<<endl;
		}
};



int main()
{
	Queue Q;

	Q.test();
	
	return 0;
}
