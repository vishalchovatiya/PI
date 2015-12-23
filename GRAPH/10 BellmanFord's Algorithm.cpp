#include <iostream>
#include <limits.h>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <map>
using namespace std;


/*
	Question: BellmanFord's Algorithm for Single Source Shortest Path
	
	Contents: 
		- BellmanFord's Algorithm
		- Application of BellmanFord's Algorithm
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
			# BellmanFord's Algorithm :-	Single Source Shortest Path with Negative Edge Weight Cycle Detection
			
			===== Finding shortest path between each vertex would lead to shortest path from source to any vertex =====
			===== Works on negative edge length & can detect negative weight cycle =====
			
				- Initially set all vertex's distance to INFINITE except first vertice. Initialize first vertex distance with 0
				- For Round |V| - 1 time
					- Relax all edges
						1. For every adjacent vertex of v, if (Distance from source to v) + (weight of edge(v,u)) is less than the label of u, then update the label of v with new weight 
						2. Record parent of v & Shortest path from source vertex to vertex u
				- Relax all edges once, if still one of the edge relaxed, then graph has negative weight cycle
				
			# Time Complexity:-
			# Space Complexity:-	
			# Application of BellmanFord's Algorithm :- Google Maps, Rubik's Cube(with the minimum possible number of moves), Operation Research, Road Network, VLSI, Robotics
			# Dependency Algo : - 
		*/
		int* SSSP()
		{			
			int *Distance = new int[V];
			int Parent[V];
			
			for(int i=0; i<V; i++)
				Distance[i] = INT_MAX;
			
			Distance[0] = 0;
			
			list<Edge> :: iterator edge;
			
			for(int Round=0; Round<(V-1); Round++)
			{
				for(edge = EdgeList.begin(); edge != EdgeList.end(); edge++)
				{
					
					if( Distance[(*edge).getSrc()] != INT_MAX && Distance[(*edge).getDest()] > (*edge).getWeight() + Distance[(*edge).getSrc()] )
					{
						Distance[(*edge).getDest()] = (*edge).getWeight() + Distance[(*edge).getSrc()];
						Parent[(*edge).getDest()] = (*edge).getSrc();
					}
				}
			}
			
			for(edge = EdgeList.begin(); edge!=EdgeList.end(); edge++)
			{
				if( Distance[(*edge).getDest()] > (*edge).getWeight() + (*edge).getSrc() )
				{
					cout<< "Negative Weight Cycle Detected"<< endl;
				}
			}
			
			return Distance;
		}
		
		void PrintSSSP()
		{
			int *SPaths = SSSP();		
			
			cout<<"\n\nSingle Source Shortest Path (Bellman-Ford): "<<endl;
			for( int v=0; v<V; v++)
			{			
				cout<<"Distance from 0 to "<<v<<" = "<<SPaths[v]<<endl;
			}
			delete[] SPaths;
		}

		void test()
		{	
			
			
		}
};	

/*-------------------------------------------------------------------------------------------------*/	


int main()
{
	Graph G(5);
	
	//	G.AddEdge( 2, 0, -5);

	G.AddEdge( 2, 3, 2);
	
	G.AddEdge( 0, 4, 4);
	G.AddEdge( 3, 4, 1);
	
	G.AddEdge( 4, 3, 5);
	
	G.AddEdge( 0, 1, 1);
	G.AddEdge( 1, 2, -3);	
	
	G.PrintSSSP();
	
	return 0;
}
