#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*
	Question: Articulation Points (or Cut Vertices) 
	
	Contents: 
		- Algo 
		- Time & Space Complexity
		- Dependency Algo : - DFS
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
		
	int ArticulationPointsUtil(int V, int parent, bool visited[], int arr[]);	
	public:
		Graph(int v);
		void AddEdge(int V, int E);

		void ArticulationPoints(int S);
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

/*-----------------------------------------Topological Sort-------------------------------------------*/

/*
	# Algorithm:-
	
		- Check for Deapest Back edge
		- if back edge(u,v) found then vertices between u and v would never be Articulation Points
			Handle Case 1: V is root with two independent childs
			Handle Case 2: If V is not root, and one of its child have whose deepest back edge is greater or equal to arrival time of that vertex 
			
	# Time Complexity:-
	# Space Complexity:-	

*/

void Graph::ArticulationPoints(int S)
{
	bool *visited = new bool[V];
	int *arr = new int[V];
	
	memset(visited, 0, V*sizeof(bool));
	memset(arr, -1, V*sizeof(int));
	
	ArticulationPointsUtil(S, S, visited, arr);
}

int Graph::ArticulationPointsUtil(int V, int parent, bool visited[], int arr[])
{
	static int time = 0;
	int child = 0;
	arr[V] = time++;
	visited[V] = true;
	int dbe = arr[V];	// Deapest Back Edge

	list<int> :: iterator adjecent;
	for(adjecent = AdList[V].begin(); adjecent!=AdList[V].end(); adjecent++)
	{
		if( !visited[*adjecent])
		{
			child++;
			
			dbe = ArticulationPointsUtil( *adjecent, V, visited, arr);
			
			// Handle Case 1: V is root with two independent childs
			if( arr[V] == 0 && child > 1 )
				cout<<V<<endl;
				
			// Handle Case 2: If V is not root, and one of its child have whose 
			//deepest back edge is greater or equal to arrival time of that vertex 
			if( arr[V] != 0 && dbe >= arr[V] )
				cout<<V<<endl;
		}
		//if Adjecent is parent, Back Edge found
		else if( *adjecent != parent)
		{
			dbe = min(dbe, arr[*adjecent]);
		}
	}


		
	return dbe;
}


/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(5);
	
	G.AddEdge(0, 1);
	G.AddEdge(1, 2);
	G.AddEdge(2, 3);
	G.AddEdge(3, 4);
	G.AddEdge(3, 1);
	
	G.ArticulationPoints(0);


	return 0;
}
