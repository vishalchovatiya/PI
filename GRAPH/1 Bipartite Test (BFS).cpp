#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

#define BLACK 		0
#define WHITE 		1
#define NO_COLOR 	-1

/*
	Question: Check whether given graph is bipartite or not
	
	Contents: 
		- Bipartite Garph Property
		- Algorithm
		- Applications
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
	
	public:
		Graph(int v);
		void AddEdge(int V, int E);
		bool BipartiteTest(int S);		

};

Graph::Graph(int v)
{
	this->V = v;
	this->AdList = new list<int>[v];
}

void Graph::AddEdge(int V, int E)
{
	AdList[V].push_back(E);
	AdList[E].push_back(V);		// Comment This Line For Directed Graph
}

/*--------------------------------------------------- BFS ---------------------------------------------------------*/

/*
	# Property :- 
	
		- A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U.
		- Bipartite graph doesn't contain cycle on same level (Odd Edge Cycle)
		- Bipartite graph have cycle with only even edges
		
	# Algorithm :- 
	 
	 	- Do BFS
	 	- Mark the visited vertices(or Mark vertices which are in queue) with same color
	 	- Check handle cases
	 	 	1. Do not have cycle forming edge on same level
	 	 	2. Check for edge on same level
	 	 - Mark poped element with different color				
			
	# Application of Bipartite Graphs :-		
		
		- According to Bipartite Graph's property, it has two set of vertices. So we can you this type of graph in
		- Where two set's vertices are connected like boys and girls in class.
		- Jobs and Applicants.

*/

bool Graph::BipartiteTest(int S)
{
	int Level[V];
	int colors[V];
	int LevelCounter = 0;
	memset(Level, 0, sizeof(Level));
	memset(colors, NO_COLOR, sizeof(colors));
	
	list<int> Q;
	Q.push_back(S);
	colors[S] = WHITE;
	Level[S] = LevelCounter;
	
	while(!Q.empty())
	{
		int noOfVertices = Q.size();
		
		while(noOfVertices > 0)	
		{
			int v = Q.front();
			Q.pop_front();			
			
			list<int> :: iterator i;
			for(i=AdList[v].begin(); i!=AdList[v].end(); i++)
			{
				// Mark visited vertices with same color
				if( colors[*i] == NO_COLOR )
				{
					Q.push_back(*i);
					Level[*i] = LevelCounter;
					colors[*i] = WHITE;
				}
				// Handle case 1 & 2
				else if( colors[*i] == WHITE && Level[v] == Level[*i] )
				{
					return true;
				}				
			}
			colors[v] = BLACK;			
			
			noOfVertices--;
		}
		LevelCounter++;
	}
	
	return false;
}

/*-----------------------------------------------------------------------------------------------------------------*/


int main()
{
	Graph G(8);
	
	G.AddEdge(0,1);
	G.AddEdge(0,3);
	G.AddEdge(1,7);
	G.AddEdge(2,3);
	G.AddEdge(2,5);
	//G.AddEdge(4,5);
	G.AddEdge(4,7);
	G.AddEdge(6,7);
	
	
	cout<<G.BipartiteTest(0);
	
	return 0;
}
