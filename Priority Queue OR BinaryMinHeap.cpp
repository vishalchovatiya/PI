#include <iostream>
#include <string>
#include <limits>
#include <list>
#include <map>
#include <vector>
using namespace std;

/*
	Question: Priority Queue OR BinaryMinHeap
	
	Contents: 
		- Priority Queue’s Algo 
		- Application Priority Queue OR BinaryMinHeap	
		- Time & Space Complexity
		- Dependency Algo : - Min & Max Heap Property
*/



/*------------------------------------------------BinaryMinHeap-------------------------------------------------------*/

template<class T>
class BinaryMinHeap
{
	class Node
	{
		public:
			T Key;
			int Weight;	
	};
	
	vector<Node> Heap;
	map<T /*KEY*/, int/*INDEX*/>  Table;
	
	private:
		/*--------------------------------Utility Functions-----------------------------------*/
		inline int RIGHT(int X)
		{
			return (X*2+2);	
		}
		inline int LEFT(int X)
		{
			return (2*X+1);
		}
		inline int PARENT(int X)
		{
			return ((X-1)/2);
		}
		
		void HeapifyUP( int idx)		
		{
			int P = PARENT(idx);
			
			if( P >= 0 && Heap[P].Weight > Heap[idx].Weight )
			{
				Table[Heap[P].Key] = idx;
				Table[Heap[idx].Key] = P;
				swap( Heap[idx], Heap[P]);
				HeapifyUP( P);
			}	
		}

		void HeapifyDOWN( int idx)		
		{			
			int R = RIGHT(idx), min = LEFT(idx);
				
			if( min <= Heap.size() && R <= Heap.size() && Heap[R].Weight < Heap[min].Weight)	
			{
				min = R;
			}
			if( min <= Heap.size() && Heap[min].Weight < Heap[idx].Weight)
			{
				Table[Heap[min].Key] = idx;
				Table[Heap[idx].Key] = min;
				swap( Heap[idx], Heap[min]);
				HeapifyDOWN( min);
			}
		}
		/*-------------------------------------------------------------------------------------*/
			
	public:
		
		void Insert(T Key, int Weight)
		{
			Node node;
			node.Key = Key;
			node.Weight = Weight;
			
			Table[Key] = Heap.size();
			Heap.push_back(node);
			HeapifyUP( Heap.size()-1);		
		}
	
		T ExtractMin()
		{
			if( Heap.size() != 0)
			{
				Node Min = Heap.front();
				Table.erase( Min.Key);

				Heap[0] = Heap[ Heap.size() - 1 ];
				Heap.pop_back();
				
				Table[Heap[0].Key] = 0;
				HeapifyDOWN( 0);
				return Min.Key;
			}       
		}
		
		void Decrease(T Key, int nWeight)
		{			
			if( nWeight < Heap[ Table[Key] ].Weight )
			{
				Heap[ Table[Key] ].Weight = nWeight;
				HeapifyUP( Table[Key]);
			}
			else
			{
				Heap[ Table[Key] ].Weight = nWeight;
				HeapifyDOWN( Table[Key]);
			}
		}
		
		bool Empty()
		{
			return (Heap.size() == 0) ? 1 : 0 ;
		}
		
		bool Contain(T Key)
		{
			return (Table.find(Key) == Table.end()) ? 0 : 1 ;
		}
		
		int GetWeight(T Key)
		{
			return Heap[ Table[Key] ].Weight;
		}
		
		void DisplayHeap()
		{
		    typename vector <Node> :: iterator i = Heap.begin();
		
		    while ( i != Heap.end() )
		    {
		        cout<<" "<<(i)->Key<<" "<<(i)->Weight<<endl;
		        i++;
		    }
		    cout<<endl;
		}
		
		void DisplayIndexMapped()
		{
		    typename map <T, int> :: iterator i = Table.begin();
			cout<<endl;
		    while ( i != Table.end() )
		    {
		        cout<<"  "<<i->first<<"  "<<i->second<<endl;
		        i++;
		    }
		    cout<<endl;
		}
		/*
		# Priority Queue’s Algo :-
			- Insert every element with Key & Priority
			- HeapifyUP that Key
			- Extract element, Copy last vertex to first, mend map table
			- HeapifyDOWN 	
			
		# Application  :-	
		
			 - Priority  Queue
			 - Scheduling algorithms
			 - Graph algorithms like Prim’s Algorithm and Dijkstra’s algorithm 	
			 
		# Time Complexity :-  
		# Dependency Algo :- Min & Max Heap Property
		*/
		void test()
		{
			Insert( 0, 0);		
			Insert( 1, 5);
			Insert( 2, 12);
			Insert( 3, 25);
			
			Insert( 4, 6);
			Insert( 5, 22);

			DisplayHeap();
			
			cout<<" ExtractMin = "<<ExtractMin()<<endl;
			Decrease(2 , 2);
			DisplayHeap();
			
			cout<<" ExtractMin = "<<ExtractMin()<<endl;
			
			DisplayHeap();
			
			cout<<" ExtractMin = "<<ExtractMin()<<endl;
			DisplayHeap();
			DisplayIndexMapped();	
		}	
};

/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	BinaryMinHeap<int> Bmh;
	
	Bmh.test();
	
	return 0;
}
