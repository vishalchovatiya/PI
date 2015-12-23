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
			# BellmanFord's Algorithm :-	Single Source Shortest Path with Negative Edge length
			
			===== Finding shortest path between each vertex would lead to shortest path from source to any vertex =====
			===== Works only on positive or zero edge length =====
			
				- Initially set all the Keys values of vertices to INFINITE in Heap except first vertice. Initialize first vertex key value with 0
				- While Heap doesn’t Empty
					1. Now Exctract Min from Heap and Traverse through its Adjecents( Traverse Edges in a "cut")
					2. For every adjacent vertex, if (length from source to that vertex) + (weight of edge) is less than the previous weight of Key value, update the key value with new weight 
					3. Record its parent & Shortest path from source vertex to that vertex				
				
			# Time Complexity:-
			# Space Complexity:-	
			# Application of BellmanFord's Algorithm :- Google Maps, Rubik's Cube(with the minimum possible number of moves), Operation Research, Road Network, VLSI, Robotics
			# Dependency Algo : - Binary Min Heap
		*/
		int* SSSP()
		{			
			int	*Distance = new int[V];
			int Parent[V];
		
			for( int v=0; v<V; v++)
				Distance[v] = INT_MAX;

			Distance[0] = 0;
			
			list<Edge> :: iterator edge;
			//Relax edges repeatedly V - 1 times
	        for (int i = 0; i < V - 1 ; i++) 
			{
	            for (edge = EdgeList.begin(); edge != EdgeList.end(); edge++) 
				{
					//if we get better distance to v via u then use this distance and set u as parent of v.
	                //if ( Distance[(*edge).getSrc()] != INT_MAX && Distance[(*edge).getDest()] > Distance[(*edge).getSrc()] + (*edge).getWeight()) 
	                if ( Distance[(*edge).getSrc()] + (*edge).getWeight() < Distance[(*edge).getDest()]) 
					{
						Distance[(*edge).getDest()] = Distance[(*edge).getSrc()] + (*edge).getWeight();
	                    Parent[(*edge).getDest()] = (*edge).getSrc();
	                }
	            }
	        }
	        
	        //Relax all edges again. If we still get lesser distance it means, there is negative weight cycle in the graph. 
	        for (edge = EdgeList.begin(); edge != EdgeList.end(); edge++)
	        {
	        	if ( Distance[(*edge).getDest()] > Distance[(*edge).getSrc()] + (*edge).getWeight()) 
				{
	            	cout<< "Negative Cycle Found"<<endl;
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
