#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Find Cycle in Undirected Graph
	
	Contents: 
		- Use DFS tree Properties to detect cycle (Back Edge)
*/

class Graph
{
	int V;				// No. of vertices
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
		
	bool DetectCycleUtil(int V, bool visited[], int Parent);
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);

		bool DetectCycle(int S);
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


/*-----------------------------------------Detect Cyle in UNDirected Graph-------------------------------------------*/

/*
	
	Algo ::
		- Check for Back Edge in DFS Tree
		- Back Edge: Edge between vertex and one of its ancestor (NOT PARENT)
		- Handle case: edge between current recurring vertex and its parent
	
*/


bool Graph::DetectCycle(int S)
{
	bool visited[V];
	
	memset(visited, 0, sizeof(visited));
	
	if(DetectCycleUtil(S, visited, S))
		return true;
	
	return false;			
}


bool Graph::DetectCycleUtil(int V, bool visited[], int Parent)
{
	visited[V] = true;	
	
	list<int> :: iterator i;
	for(i=AdList[V].begin(); i!= AdList[V].end(); i++)
	{
		// Recur if Adjecent Vertex not visited
		if( visited[*i] == false )
		{
			if(DetectCycleUtil( *i, visited, V))
				return true;
		}
		// Back Edge
		// Handle case: Check vertex is visited but not form edge with its parent vertex(same edge as it comes from) (Directed Graph contain edge in both direction)			
		else if( *i != Parent)		
		{
			return true;
		}
			
	}
	
	return false;
}

/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(5);
	
	G.AddEdge(0,1);
	G.AddEdge(0,3);
	G.AddEdge(1,2);
	G.AddEdge(2,4);
	G.AddEdge(4,0);
	
	cout<<"Detect Cycle: "<<G.DetectCycle(0);

	return 0;
}
