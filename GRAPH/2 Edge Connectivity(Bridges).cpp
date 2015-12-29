#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*			
	Question: 2 Edge Connectivity(Bridges)
	
	Contents: 
		- Algo 
		- Time & Space Complexity
		- Dependency Algo : - DFS
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
	
	int TwoEdgeConnectivityUtil(int V, int parent, bool visited[], int arr[]);
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);
		
		void TwoEdgeConnectivity(int S);

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

/*--------------------------------------2 Edge Connectivity(Bridges)--------------------------------------*/

/*
	# Algorithm:-
	
		- Check for Deapest Back edge
		- if back edge(u,v) found then edges between u and v would never be bridge edges
		- print bridge edges when backtracking
		
	# Time Complexity:-
	# Space Complexity:-
	
*/

void Graph::TwoEdgeConnectivity(int S)
{
	bool *visited = new bool[V];
	int *arr = new int[V];
	
	memset(visited, 0, V*sizeof(bool));
	memset(arr, -1, V*sizeof(int));
	
	TwoEdgeConnectivityUtil(S, S, visited, arr);
}

int Graph::TwoEdgeConnectivityUtil(int V, int parent, bool visited[], int arr[])
{
	static int time = 0;
	arr[V] = time++;
	visited[V] = true;
	int dbe = arr[V];	// Deapest Back Edge

	list<int> :: iterator adjecent;
	for(adjecent = AdList[V].begin(); adjecent!=AdList[V].end(); adjecent++)
	{
		if( !visited[*adjecent])
		{
			dbe = min(dbe, TwoEdgeConnectivityUtil( *adjecent, V, visited, arr));
		}
		//if Adjecent is parent, Back Edge found
		else if( *adjecent != parent)
		{
			dbe = min(dbe, arr[*adjecent]);
		}
	}
	// Print Bridge Edges when Backtracking
	if( arr[V] != 0 && dbe == arr[V])
		cout<<parent<<" "<<V<<endl;
		
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
	G.AddEdge(4, 1);
	
	G.TwoEdgeConnectivity(4);

	return 0;
}
