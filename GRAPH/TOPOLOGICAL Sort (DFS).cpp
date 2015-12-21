#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*
	Question: Topological Sort (for Directed Acyclic Graph Only)
	
	Contents: 
		- Use Properties of DFS 
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
		
	void TopologicalSortUtil(int V, bool visited[], stack<int> &S);
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);

		void TopologicalSort();
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

/*-----------------------------------------Topological Sort-------------------------------------------*/

/*
	
	Algo ::
		- We modify DFS traversal with using Stack
		- Choose arbitary vertex and recur for its adjecent vertecies until reach vertex which has no adjecent vertex remain unexplored then start pushing it to stack
		- Finally print stack
*/

void Graph::TopologicalSort()
{
	bool *visited = new bool[V];
	memset(visited, 0, V);
	
	stack<int> S;
	
	for(int i=0; i<V; i++)
		if( visited[i] == false )
			TopologicalSortUtil(i, visited, S);
		
	for(int i=0; i<V; i++)
	{
		cout<<" "<<S.top();
		S.pop();
	}		
	
}


void Graph::TopologicalSortUtil(int V, bool visited[], stack<int> &S)
{
	visited[V] = true;

	list<int> :: iterator i;
	for(i = AdList[V].begin(); i!= AdList[V].end(); i++)
	{
		if( visited[*i] == false )
			TopologicalSortUtil(*i, visited, S);	
	}
	S.push(V);
}

/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(9);
	
	G.AddEdge(0,2);
	G.AddEdge(1,2);
	G.AddEdge(2,4);
	G.AddEdge(2,3);
	G.AddEdge(3,5);
	G.AddEdge(4,8);
	G.AddEdge(8,5);
	G.AddEdge(5,6);
	G.AddEdge(5,7);
	
	
	G.TopologicalSort();


	return 0;
}
