#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <algorithm>
using namespace std;


/*
	Question: Hamiltonian Path & Cycle
	
	Contents: 
		- Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once.
		- A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in graph) from the last vertex to the first vertex of the Hamiltonian Path.
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
	
	bool DFSUtil(int S, int V, bool visited[], int path[], int idx);
	void printArr(int path[]);
	public:
		Graph(int v);
		void AddEdge(int V, int E);	
		bool DFS(int S);
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

void Graph::printArr(int path[])
{
	cout<<endl;
	for(int i=0; i<V; i++)
		cout<<path[i]<<" ";
}

bool Graph::DFS(int S)
{
	int HamiltonianPath[V];
	bool visited[V];
	
	memset(visited, 0, sizeof(visited));
	memset(HamiltonianPath, -1, sizeof(HamiltonianPath));
	
	if( DFSUtil(S, S, visited, HamiltonianPath, 0) )
		printArr(HamiltonianPath);
}

bool Graph::DFSUtil(int S, int V,  bool visited[], int path[], int idx)
{
	if( idx == this->V-1 && find(AdList[V].begin(), AdList[V].end(), S) != AdList[V].end() ){
		path[idx] = V;
		return true;
	}

	visited[V] = true;
	path[idx] = V;
	
	list<int> :: iterator i;
	for(i=AdList[V].begin(); i!= AdList[V].end(); ++i)
	{
		if( visited[*i] == false )
			if( DFSUtil(S, *i, visited, path, idx+1) )
				return true;
	}	
	
	visited[V] = false;
	
	return false;
}

int main()
{
	Graph G(4);
	
	G.AddEdge(0,1);
	G.AddEdge(0,2);
	G.AddEdge(0,3);
	
	G.AddEdge(1,3);
	G.AddEdge(1,2);
	
	G.AddEdge(3,2);
	
	G.DFS(0);	
	
	return 0;
}
