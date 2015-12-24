#include <iostream>
#include <limits.h>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <map>
using namespace std;

/*
	Question: FloydWarShall's Algorithm for Single Source Shortest Path
	
	Contents: 
		- FloydWarShall's Algorithm
		- Application of FloydWarShall's Algorithm
		- Time & Space Complexity
		- Dependency Algo :
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
	int **GraphMatrix;
	list<int> *AdList;		
	list<Edge> EdgeList;	

	public:
	
		Graph(int v)
		{
			this->V = v;
			this->AdList = new list<int>[v];
			
			GraphMatrix = GetTwoDimensionalArray();	
			
			for(int i=0; i<V; i++)
				for(int j=0; j<V; j++)
					GraphMatrix[i][j] = INT_MAX;		
		}
		~Graph()
		{
			delete[] AdList;
			
			freeTwoDimensionalArray(GraphMatrix);
		}
		
		void AddEdge(int V, int E, int W)
		{
			Edge edge(V,E,W);
			EdgeList.push_back(edge);
			
			AdList[V].push_back(E);
			
			GraphMatrix[V][E] = W;
			GraphMatrix[V][V] = 0;
			//AdList[E].push_back(V);		// Comment This Line For Directed Graph
		}
		
		int **GetTwoDimensionalArray()
		{
			int **TwoDArray;
			
			TwoDArray = new int*[V];
						
			for(int i=0; i<V; i++)
				TwoDArray[i] = new int[V];
				
			return TwoDArray;	
		}
		
		void freeTwoDimensionalArray(int **A)
		{
			for(int i=0; i<V; i++)
				delete[] A[i];
			delete[] A;
		}
		
		/*			 				
			# FloydWarShall's Algorithm :-	All Pair Shortest Path 
	
			===== Works on negative edges =====
			===== Connectivity Between Vertices =====
			===== Detection Negative Edge Weight Cycles =====
			
			
				- We initialize the Distance matrix same as the input graph matrix
				- Then we update the solution matrix by picking all vertices as an intermediate vertex one by one
				- For every pair (i, j) of source and destination vertices, there are two possible cases	
						1. k is not an intermediate vertex in shortest path from i to j. We keep the value of dist[i][j] as it is
						2. k is an intermediate vertex in shortest path from i to j. We update the value of dist[i][j] as dist[i][k] + dist[k][j]
				
			# Time Complexity:-
			# Space Complexity:-	
			# Application of FloydWarShall's Algorithm :- Detect Negative Cycle, To find Transitive closure (simply a reachability)
			# Dependency Algo : - 
		*/
		int** APSP()		//All Pair Shortest Path
		{			
			int **Distance = GetTwoDimensionalArray(), **Path = GetTwoDimensionalArray(), i, j, k;
			
			 for (i = 0; i < V; i++)
		        for (j = 0; j < V; j++)
		        {
		        	Distance[i][j] = GraphMatrix[i][j];
		        	
	                if (Distance[i][j] != INT_MAX && i != j) 
	                    Path[i][j] = i;		// If there is path between Source & Destination update this with source 
	                else
	                    Path[i][j] = INT_MAX;
		        }
		            
			
			
			for (k = 0; k < V; k++)// All Intermediate Vertex	
		    for (i = 0; i < V; i++)// All Source Vertex	
		    for (j = 0; j < V; j++)// All Destination Vertex
		        if ( Distance[i][k] != INT_MAX && Distance[k][j] != INT_MAX && Distance[i][j] > Distance[i][k] + Distance[k][j] )
		        {
		        	Distance[i][j] = Distance[i][k] + Distance[k][j];
		        	Path[i][j] = Path[k][j];
		        }
		    
			//if values on diagonal of distance matrix is negative, then there is negative weight cycle in the graph.
			for(int i = 0; i < V; i++) 
			{
	            if(Distance[i][i] < 0) 
				{
	                cout<<"Negative Edge Weigth Cycle Detected"<<endl;
	            }
	        }    
		             
			PrintAPSP(Distance);
			
			cout<<endl;	
			
			PrintPath( Path, 0, 4);

			
			return Distance;
		}
		
		void PrintAPSP( int **SPaths)
		{					
			cout<<"\n\nAll Pair Shortest Path (FloydWarShall): \n"<<endl;
			
			for(int i=0; i<V; i++)
			{
				for(int j=0; j<V; j++)
				{
					if (SPaths[i][j] == INT_MAX)
		                printf("%7s", "INF");
		            else
		                printf ("%7d", SPaths[i][j]);
				}
				cout<<endl;	
			}
			
		}	
		
		void PrintPath(int **Path, int S, int D)
		{			
			PrintPathWrapper( Path, S, D);
			cout<<" "<<D;
		}
		
		void PrintPathWrapper(int **Path, int S, int D)
		{
			if( Path[S][D] == INT_MAX )
			{
				cout<<"Unreachable"<<endl;
				return;
			}
			
			if( Path[S][D] == S )
			{
				cout<<" "<<Path[S][D];
				return;
			}				
			
			PrintPathWrapper( Path, S, Path[S][D]);
			cout<<" "<<Path[S][D];
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
	
	G.APSP();
	
	return 0;
}
