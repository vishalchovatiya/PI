#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;

/*
	Question: Find Cycle in Directed Graph
	
	Contents: 
		- Use DFS tree Properties to detect cycle (Back Edge & Self Loop)
*/


class Graph
{
	int V;
	list<int> *AdList;			// Pointer for Dynamic Allocation of Adjecency list
		
		bool DetectCycleUtil(int V, bool visited[], int Parent);
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);

		bool DetectCycle();
};

Graph::Graph(int v)
{
	this->V = v;
	this->AdList = new list<int>[v];
}

void Graph::AddEdge(int V, int E)
{
	AdList[V].push_back(E);
	//AdList[E].push_back(V);		// Comment This Line For Directed Graph
}


/*-----------------------------------------Detect Cyle in Directed Graph-------------------------------------------*/

/*

	- DFS tree(for Directed Graph) = Tree Edge + Back Edge + Forward Edge + Cross Edge
		
	Algo ::
		- Check for Back Edge in DFS Tree
		- Back Edge: Edge between vertex and one of its ancestor (NOT PARENT)
		- Self Loop: edge to vertex itself
		- Handle case 1: Self Loop
		- Handle case 2: edge between current recurring vertex and its parent(ITS PARENT NOT ANCESTOR)	
		- Handle case 3: Cross edge:
	
*/

bool Graph::DetectCycle()
{
	bool visited[V];
	
	memset(visited, 0, sizeof(bool)*V);
	
	for(int i=0; i<V; i++)
		if(visited[V] == false)
			if( DetectCycleUtil(i, visited, i))
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
		// Handle case 1: Self Loop
		else if( V == *i )			
		{
			return true;
		}
		// Handle case 2 & 3: Cross edge & Back Edge
		// Check vertex is visited but not form edge with its parent vertex(same edge as it comes from) (Directed Graph contain edge in both direction)			
		else if( *i != Parent && V != Parent)		
		{
			//cout<<*i<<" "<<Parent<<endl;
			return true;
		}
		
	}	
	return false;
}

/*-----------------------------------------------------------------------------------------------------------------*/


int main()
{
	Graph G(6);
	
	G.AddEdge(0,1);
	G.AddEdge(4,0);
	G.AddEdge(5,1);
	//G.AddEdge(3,4);	// Cylce
	G.AddEdge(2,3);
	G.AddEdge(1,2);
	//G.AddEdge(2,2);	//	Self Loop
	
	cout<<"Detect Cycle: "<<G.DetectCycle();

	return 0;
}
