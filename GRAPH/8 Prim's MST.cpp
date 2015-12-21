#include <iostream>
#include <limits.h>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <map>
using namespace std;


/*
	Question: Prim’s Algorithm for Minimum Spanning Tree 
	
	Contents: 
	
		- Properties of MST 
		- Prim’s Algo 
		- Application of MST	
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
			AdList[E].push_back(V);		// Comment This Line For Directed Graph
		}
		
		/*
			# Properties of MST :-
			 
				- MST Contain V-1 edges where V stands for number of vertices in a Graph
				- If Graph has distinct edge length, then MST would be unique and only one
				
			# Prim’s Algorithm :-	
			
				- Initially set all the Keys of vertices to INFINITE in Heap except first vertice. Initialize first vertex key with 0
				- While Heap doesn’t Empty
					1. Now Exctract Min Element from Heap and Traverse through its Adjecents( Traverse Edges in a "cut")
					2. For every adjacent vertex, if weight of edge is less than the previous weight of Key value, update the key value with new weight 
				- After Each single iteration we get single Minimum Spanning Tree Edge
				
			# Application of MST :- Network Design, FaceVerification, Protein Synthesis Study, Mobile Network(Cluster Analysis)
			# Time & Space Complexity :-
			# Dependency Algo : - Binary Min Heap
		*/
		list<Edge>* PrimsMST()
		{
			BinaryMinHeap<int> BMH;
			map< int, Edge>		VertextoEdge;
			list<Edge> *Result = new list<Edge>;
			bool Visited[V];
			
			memset( Visited, 0, sizeof(Visited));				
			
			for(int v=0; v<V; v++)
				BMH.Insert(v, INT_MAX);
				
			BMH.DecreaseKey( 0, 0);
			
			while( !BMH.Empty())
			{
				int V = BMH.ExtractMin();
								
				if( VertextoEdge.find(V) != VertextoEdge.end() )
				{
					Result->push_back( VertextoEdge[V]);
				}
				
				list<int> :: iterator Adjecent;
				for(Adjecent = AdList[V].begin(); Adjecent != AdList[V].end(); Adjecent++)
				{
					Edge edge = GetVertexToEdge( V, *Adjecent);	
						
					if( !Visited[*Adjecent] && edge.getWeight() < BMH.GetWeight(*Adjecent) )	
					{
						BMH.DecreaseKey( *Adjecent, edge.getWeight());
						VertextoEdge[*Adjecent] = edge;
					}
				}
				Visited[V] = 1;
			}
			return Result;
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
		
		void PrintPrimsMST()
		{
			list<Edge> *MSTEdgeList = PrimsMST();		
			list<Edge> :: iterator i;
			cout<<"\n\nPrims MST : "<<endl;
			for(i = MSTEdgeList->begin(); i != MSTEdgeList->end(); i++)
			{			
				cout<<"SRC = "<<(*i).getSrc()<<" DEST = "<<(*i).getDest()<<" Weight = "<<(*i).getWeight()<<endl;
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
	Graph G(4);
	
	G.AddEdge( 0, 1, 1);
	G.AddEdge( 0, 2, 5);
	
	G.AddEdge( 2, 1, 2);
	
	
	G.AddEdge( 3, 2, 3);
	
	G.AddEdge( 1, 3, 4);
	
	G.PrintPrimsMST();
	
	return 0;
}
