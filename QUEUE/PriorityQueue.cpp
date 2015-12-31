#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

/*
	Priority Queue is an extension of queue with following properties.
		1) Every item has a priority associated with it.
		2) An element with high priority is dequeued before an element with low priority. (Lower the Number higher the priority)
		
	Time Complexity:
		Insert()-------------- O(LogN)	
		ExtractMin()---------- O(1)	
		DecreasePriority()---- O(LogN)	

*/
template <class T>
class PriorityQueue
{
	class Node
	{
		public:
		int Priority;
		T Key;
	};
	vector<Node> 	Heap;
	map<T, int>		KeyToIdx;

	/*--------------------------------------- Utility Functions -----------------------------------*/
	inline int PARENT(int idx)
	{
		return ((idx-1) / 2 );
	}
	inline int LEFT(int idx)
	{
		return ( 2*idx + 1);
	}
	inline int RIGHT(int idx)
	{
		return ( 2*idx + 2);
	}
	
	void HeapifyUP(int idx)
	{
		int P = PARENT(idx);
		
		if( P >= 0 && P <= Heap.size() && Heap[P].Priority > Heap[idx].Priority )
		{
			KeyToIdx[Heap[P].Key] = idx;
			KeyToIdx[Heap[idx].Key] = P;
			swap( Heap[P], Heap[idx]);
			HeapifyUP( P);
		}
	}
	
	void HeapifyDOWN(int idx)
	{
		int L = LEFT(idx), R = RIGHT(idx), Min = idx ;		
		
		if( L <= Heap.size() && Heap[L].Priority < Heap[idx].Priority)
		{
			Min = L;
		}		
		
		if( R <= Heap.size() && L <= Heap.size() && Heap[R].Priority < Heap[L].Priority)
		{
			Min = R;
		}
		
		if( Min != idx )
		{
			KeyToIdx[Heap[idx].Key] = Min;
			KeyToIdx[Heap[Min].Key] = idx;
			swap( Heap[Min], Heap[idx]);
			HeapifyDOWN( Min);
		}		
	}
	/*----------------------------------------------------------------------------------------------*/

	public:
	
		void Insert(int Priority, T Key)
		{
			Node node;
			node.Key = Key;
			node.Priority = Priority;
			
			KeyToIdx[Key] = Heap.size();
			
			Heap.push_back(node);
			HeapifyUP( Heap.size() - 1);
		}
		
		T ExtractMin()
		{
			if( Heap.size() != 0 )
			{
				Node node = Heap[0];
				
				KeyToIdx.erase(Heap[0].Key);
				
				Heap[0] = Heap[Heap.size() - 1];
				
				KeyToIdx[Heap[0].Key] = 0;
				
				Heap.pop_back();
				
				HeapifyDOWN(0);
				
				return node.Key;	
			}
		}
		
		void DecreasePriority(T Key, int nPriority)
		{
			
			if ( Heap[ KeyToIdx[Key] ].Priority < nPriority )
			{
				Heap[ KeyToIdx[Key] ].Priority = nPriority;
				HeapifyDOWN( KeyToIdx[Key]);
			}
			else
			{
				Heap[ KeyToIdx[Key] ].Priority = nPriority;
				HeapifyUP( KeyToIdx[Key]);
			}
		}
		
		void test()	
		{
			Insert( 8,  "AAA");
			Insert( 15, "BBB");
			Insert( 4,  "CCC");
			Insert( 1, "DDD");
			Insert( 22, "EEE");
			Insert( 3, "FFF");
			
			DecreasePriority( "EEE", 0);
			
			cout<<ExtractMin()<<endl;
			cout<<ExtractMin()<<endl;
			cout<<ExtractMin()<<endl;
			
			cout<<ExtractMin()<<endl;
			cout<<ExtractMin()<<endl;
			cout<<ExtractMin()<<endl;
		}
};



int main()
{
	
	PriorityQueue<string> pQ;
	
	pQ.test();

	return 0;
}
