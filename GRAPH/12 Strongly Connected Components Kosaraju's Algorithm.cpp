#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*
	Question: Kosaraju's Algorithm for Strongly Connected Components(SCC)
	
	Contents: 
		- Kosaraju's Algorithm(SCC)
		- Application of Kosaraju's Algorithm
		- Time & Space Complexity
		- Dependency Algo :
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
		
	void DFSwithStack(int V, bool visited[], stack<int>	&Stack);
	void DFS(int V, bool visited[]);
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);

		void SSC(int S);
		Graph getTranspose();
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
	- Strongly Connected (Only for Directed Graph) - Path between every pair of vertices 
	- Naive Method - Do DFS for Every vertices if in each DFS every vertices are visited than graph is strongly connected
	- Optimize method is Kosaraju's Algorithm
	
	# Kosaraju's Algorithm(SCC) : - 
	
			- Do DFS(like Topological Sort) and populate stack
			- Reverse Direction of all edges
			- Pop a vertex from Stack and do DFS which prints strongly connected components
		
*/

void Graph::SSC(int S)
{
	bool *visited = new bool[V];
	memset(visited, 0, V);
	
	stack<int>	Stack;
	
	// DFS(like Topological Sort) and populate stack
	for(int v=0; v<V; v++)
		if( !visited[v])
			DFSwithStack(v, visited, Stack);	
	
	//Reverse Direction of all edges
	Graph G = getTranspose();
	
	memset(visited, 0, V);
	
	while ( !Stack.empty())
    {
        // Pop a vertex from stack
        int v = Stack.top();
        Stack.pop();

        // Do DFS which prints strongly connected components
        if ( !visited[v])
            G.DFS(v, visited);
        
		cout << endl;
    }
}


Graph Graph::getTranspose()
{
    Graph g(V);
    for (int v = 0; v < V; v++)
    {
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = AdList[v].begin(); i != AdList[v].end(); ++i)
        {
            g.AdList[*i].push_back(v);
        }
    }
    return g;
}


void Graph::DFSwithStack(int V, bool visited[], stack<int>	&Stack)
{
	visited[V] = true;

	list<int> :: iterator i;
	for(i = AdList[V].begin(); i!= AdList[V].end(); i++)
	{
		if( !visited[*i] )
			DFSwithStack(*i, visited, Stack);	
	}
	
	Stack.push(V);
}

void Graph::DFS(int V, bool visited[])
{
	visited[V] = true;
	
	cout<<" "<< V;

	list<int> :: iterator i;
	for(i = AdList[V].begin(); i!= AdList[V].end(); i++)
	{
		if( !visited[*i] )
			DFS(*i, visited);	
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(5);
    G.AddEdge(1, 0);
    G.AddEdge(0, 2);
    G.AddEdge(2, 1);
    G.AddEdge(0, 3);
    G.AddEdge(3, 4);
	
	
	G.SSC(0);


	return 0;
}
