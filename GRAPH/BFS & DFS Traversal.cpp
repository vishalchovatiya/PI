#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Graph Traversal Technique BFS & DFS for undirected graph
	
	Contents: 
		- Properties of BFS tree & DFS tree
		- Applications
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
	
	void DFSUtil(int V, bool *visited);
	
	public:
		Graph(int v);
		void AddEdge(int V, int E);
		void BFS(int S);		
		void DFS(int S);
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
	# BFS Tree Properties :- 
	
			- Uses Queue 
			- BFS Tree = Spanning Tree 
			- BFS Tree has no cycle
			
	# Application of BFS :-		
	
	- Bipartite	Test(Vertices divided into 2 sets, No edge on same level)
	
	- Shortest Path & Minimum Spanning tree
	
	- Ford–Fulkerson algorithm
	
	- Path between two vertices
	
	- BitTorrent(Peer to Peer Networks) : used to find all neighbor nodes.
	
	- Crawlers in Search Engines: Build index using BFS. The idea is to start from source page and follow all links from source and keep doing same.
	
	- Social Networking : find people within a given distance ‘k’ from a person using Breadth First Search till ‘k’ levels.
	
	- GPS Navigation systems: BFS is used to find all neighboring locations.
	
	- Broadcasting in Network: a broadcasted packet follows BFS to reach all nodes.
*/

void Graph::BFS(int S)
{
	bool *visited = new bool[V];
	memset(visited, 0, V);
	
	list<int> Q;
	Q.push_back(S);
	visited[S] = true;
	
	while(!Q.empty())
	{
		int v = Q.front();
		cout<<" "<<v;		
		Q.pop_front();
		
		list<int> :: iterator i;
		for(i=AdList[v].begin(); i!= AdList[v].end(); ++i)
		{
			if( visited[*i] == false )
			{
				Q.push_back(*i);
				visited[*i] = true;
			}	
		}		
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------- DFS ---------------------------------------------------------*/

/*

	# DFS Tree Properties :- 
	
			- Uses Stack 
			- DFS Tree = Tree Edges + Back Edges		(For Undirected Graph Only)
			- DFS Tree has no cycle
			
	# Application of DFS :-	
	
	- Cycle Detection
		
	- Topological Sorting (Only For Directed Acyclic Graphs)
	
	- Path between two vertices.
	
	- Find Strongly Connected Components of a graph, A directed graph is called strongly connected if there is a path from each vertex in the graph to every other vertex. 
	
	- Solving puzzles with only one solution, such as mazes.
*/

void Graph::DFS(int S)
{
	
	bool *visited = new bool[V];
	memset(visited, 0, V);
	
	DFSUtil(S, visited);
}

void Graph::DFSUtil(int V, bool *visited)
{
	visited[V] = true;
	cout<<" "<<V;
	
	list<int> :: iterator i;
	for(i=AdList[V].begin(); i!= AdList[V].end(); ++i)
	{
		if( visited[*i] == false )
			DFSUtil(*i, visited);
	}	
}
/*-----------------------------------------------------------------------------------------------------------------*/



int main()
{
	Graph G(5);
	
	G.AddEdge(0,1);
	G.AddEdge(1,2);
	G.AddEdge(1,3);
	G.AddEdge(2,3);
	G.AddEdge(3,4);
	
	G.DFS(0);	
	
	return 0;
}
