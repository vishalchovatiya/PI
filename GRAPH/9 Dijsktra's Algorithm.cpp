#include <iostream>
#include <limits.h>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <map>
using namespace std;


/*
	Question: Dijsktra’s Algorithm for Single Source Shortest Path
	
	Contents: 
		- Dijsktra’s Algorithm 
		- Application of Dijsktra’s Algorithm	
		- Time & Space Complexity
		- Dependency Algo : - Binary Min Heap
*/


/*-----------------------------------Edge Manipulation------------------------------------------*/		
class Edge
{
	private:
		int Src;
		int Dest;	
		int Weight;

	public:	
		
		Edge(int V = 0, int E = 0, int W = 0)
		{
			this->Src = V;
			this->Dest = E;
			this->Weight = W;	
		}
			
		int getWeight()
		{
			return	this->Weight;
		}
			
		int getSrc()
		{
			return	this->Src;
		}
			
		int getDest()
		{
			return	this->Dest;
		}			
};
/*-----------------------------------------------------------------------------------------------*/		

/*----------------------------------------BinaryMinHeap------------------------------------------*/

template<class T>
class BinaryMinHeap
{
	class Node
	{
		public:
			T Key;
			int Priority;
	};
	vector<Node> 	Heap;
	map< T, int> 	KeyToPriority;
	
	private:
	
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
		
		void HeapifyUP(int idx)
		{
			int P = PARENT(idx);
			
			if( P >= 0 && Heap[P].Priority > Heap[idx].Priority)
			{
				KeyToPriority[Heap[P].Key] = idx;
				KeyToPriority[Heap[idx].Key] = P;
				swap( Heap[idx], Heap[P]);
				HeapifyUP( P);
			}
		}
		
		void HeapifyDOWN(int idx)
		{
			int R = RIGHT(idx), Min = LEFT(idx);
			
			if( Min <= Heap.size() && R <= Heap.size() && Heap[R].Priority < Heap[Min].Priority)
			{
				Min = R;
			}
			if( Min <= Heap.size() && Heap[idx].Priority > Heap[Min].Priority)
			{
				KeyToPriority[Heap[Min].Key] = idx;
				KeyToPriority[Heap[idx].Key] = Min;
				swap( Heap[idx], Heap[Min]);
				HeapifyUP( Min);
			}
		}
	
	public:
		void Insert(T Key, int Priority)
		{
			Node node;
			node.Key = Key;
			node.Priority = Priority;
			
			KeyToPriority[Key] =  Heap.size();
			Heap.push_back(node);
			HeapifyUP(Heap.size()-1);
		}	
			
		T ExtractMin()
		{
			if( Heap.size() != 0)
			{
				Node node = Heap.front();
				KeyToPriority.erase(node.Key);
				Heap[0] = Heap[Heap.size()-1];
				KeyToPriority[Heap[0].Key] = 0;
				Heap.pop_back();
				HeapifyDOWN(0);
				return node.Key;
			}				
		}
		
		void DecreaseKey(T Key, int nPriority)
		{
			if (Contain(Key) == true)
			{
				if( nPriority < Heap[KeyToPriority[Key]].Priority)
				{
					Heap[KeyToPriority[Key]].Priority = nPriority;
					HeapifyUP(KeyToPriority[Key]);
				}
				else
				{
					Heap[KeyToPriority[Key]].Priority = nPriority;
					HeapifyDOWN(KeyToPriority[Key]);
				}					
			}			
		}
		
		bool Contain(T Key)
		{
			return ( KeyToPriority.find(Key) == KeyToPriority.end()) ? 0 : 1 ;
		}
		
		bool Empty()
		{
			return (Heap.size() == 0) ? 1 : 0 ;
		}
		
		int GetWeight(T Key)
		{
			return Heap[ KeyToPriority[Key] ].Priority;
		}
		
		void DisplayHeap()
		{
			typename vector<Node> :: iterator i = Heap.begin();
			while( i != Heap.end())
			{
				cout<<" "<<i->Key<<" "<<i->Priority<<endl;
				i++;
			}
			cout<<endl;
		}
		
		void DisplayMap()
		{
			typename map<T, int> :: iterator i = KeyToPriority.begin();
			cout<<endl;
			while( i != KeyToPriority.end())
			{
				cout<<" "<<i->first<<" "<< i->second<<endl;
				i++;
			}
			cout<<endl;
		}
		
		void test()
		{
			
		}
};

/*-----------------------------------------------------------------------------------------------*/



/*-----------------------------------Graph Manipulation------------------------------------------*/		
		
class Graph
{	
	int V;					// No. of vertices
	list<int> *AdList;		// Pointer for Dynamic Allocation of Adjecency list		
	list<Edge> EdgeList;	// Edge List

	public:
	
		Graph(int v)
		{
			this->V = v;
			this->AdList = new list<int>[v];
		}
		
		void AddEdge(int V, int E, int W)
		{
			Edge edge(V,E,W);
			EdgeList.push_back(edge);
			
			AdList[V].push_back(E);
			//AdList[E].push_back(V);		// Comment This Line For Directed Graph
		}
		
		/*			 				
			# Dijsktra’s Algorithm :-	Single Source Shortest Path (SSSP)
			
			===== Finding shortest path between each vertex would lead to shortest path from source to any vertex =====
			===== Works only on positive or zero edge length =====
			
				- Initially set all the Keys values of vertices to INFINITE in Heap except first vertice. Initialize first vertex key value with 0
				- While Heap doesn’t Empty
					1. Now Exctract Min from Heap and Traverse through its Adjecents( Traverse Edges in a "cut")
					2. For every adjacent vertex, if (length from source to that vertex) + (weight of edge) is less than the previous weight of Key value, update the key value with new weight 
					3. Record its parent & Shortest path from source vertex to that vertex				
				
			# Time Complexity:-
			# Space Complexity:-	
			# Application of Dijsktra's Algorithm :- Google Maps, Rubik's Cube(with the minimum possible number of moves), Operation Research, Road Network, VLSI, Robotics
			# Dependency Algo : - Binary Min Heap
		*/
		map<int, int>* SSSP()
		{
			BinaryMinHeap<int> H;
			bool Set[V] ;
			
			memset( Set, 0, sizeof(Set));
			
			map<int, int> 		*Distance = new map<int, int>;
			map<int, int> 		Parent;
		
			for( int v=0; v<V; v++)
				H.Insert(v, INT_MAX);
				
			H.DecreaseKey( 0, 0);
			(*Distance)[0] = 0;
			
			while( !H.Empty())
			{
				int V = H.ExtractMin();
				
				list<int> :: iterator Adjecent;
				for( Adjecent = AdList[V].begin(); Adjecent != AdList[V].end(); Adjecent++)
				{
					Edge edge = GetVertexToEdge(V, *Adjecent);
					
					int nDistance = (*Distance)[V] + edge.getWeight();
					
					if( !Set[*Adjecent] && nDistance < H.GetWeight(*Adjecent) )
					{
						H.DecreaseKey(*Adjecent, edge.getWeight());
						Parent[*Adjecent] = V;
						(*Distance)[*Adjecent] = nDistance;
					}
				}
				Set[V] = 1;
			}			
			
			return Distance;
		}
		
		
		Edge GetVertexToEdge(int V, int Adjecent)
		{
			list<Edge> :: iterator i ;
            for(i = EdgeList.begin(); i != EdgeList.end(); i++)
            {
            	if( (i->getSrc() == V && i->getDest() == Adjecent) || (i->getSrc() == Adjecent && i->getDest() == V))
            	{
            		return *i;
            	}
            }
		}
		
		void PrintSSSP()
		{
			map<int, int> *SPaths = SSSP();		
			map<int, int> :: iterator i;
			cout<<"\n\nSingle Source Shortest Path : "<<endl;
			for(i = SPaths->begin(); i != SPaths->end(); i++)
			{			
				cout<<"Distance from 0 to "<<i->first<<" = "<<i->second<<endl;
			}
		}

		void test()
		{	
			BinaryMinHeap<string> BMH;
			BMH.Insert( "Visha", 3);
			BMH.Insert( "jaman", 15);
			BMH.Insert( "gaman", 1);
			BMH.Insert( "vahuu", 7);
			
			BMH.Insert( "saman", 9);
			BMH.Insert( "vaman", 12);
			BMH.Insert( "koooo", 25);
			BMH.Insert( "joooo", 22);
			
			BMH.DisplayHeap();
			
			//BMH.ExtractMin();
			BMH.DecreaseKey("joooo", 0);
			BMH.DisplayHeap();
			
			cout<<BMH.GetWeight("joooo")<< endl;
			
			BMH.DisplayMap();
			
		}
};	

/*-------------------------------------------------------------------------------------------------*/	


int main()
{
	Graph G(5);
	
	
	G.AddEdge( 0, 1, 1);
	G.AddEdge( 1, 2, -3);
	G.AddEdge( 2, 0, -5);
	G.AddEdge( 2, 3, 2);
	
	G.AddEdge( 0, 4, 4);
	G.AddEdge( 3, 4, 1);
	
	G.AddEdge( 4, 3, 5);
	
	G.PrintSSSP();
	
	return 0;
}
