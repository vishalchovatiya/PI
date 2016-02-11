#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

#define MAX(a,b) ( (a>b) ? a:b)

/*
	Question: Longest path for Directed Acyclic Graph Only
	
*/

class Edge
{
	public:
	int U;
	int V;
	int Weight;
	
	
	Edge()	
	{
		U = V = Weight = 0;
	}
	Edge(int u, int v, int weight)	
	{
		U = u;
		V = v;
		Weight = weight;
	}
};

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
	list<Edge> EdgeList;	// Pointer for Dynamic Allocation of Adjecency list
		
	void TopologicalSortUtil(int V, bool visited[], stack<int> &S);
	Edge getEdge(int U, int V)	;
	
		
	public:
		Graph(int v);
		void AddEdge(int U, int V, int Weight);
		void LongestPathDAG();
};

Graph::Graph(int v)
{
	this->V = v;
	this->AdList = new list<int>[v];
}

void Graph::AddEdge(int U, int V, int Weight)
{
	Edge edge(U, V, Weight);
	EdgeList.push_back(edge);
	
	AdList[U].push_back(V);
	//AdList[E].push_back(V);		// Comment This Line For Directed Graph
}

Edge Graph::getEdge(int U, int V)
{
	list<Edge> :: iterator it = EdgeList.begin();
	
	while( it != EdgeList.end() )
	{
		if( U == (*it).U && V == (*it).V )
			return (*it);
		it++;
	}
}


int findMin(int A[], int Size)
{
	int min = 0;
	for(int i=0; i<Size; i++)
	{
		if( A[i] < A[min] )
		{
			min = i;
		}			
	}
	return min;
}



/*-----------------------------------------Longest Path in DAG-------------------------------------------*/

/*
	
	- Use iterative Topological Sort & Keep track of Distance
*/

void Graph::LongestPathDAG()
{
	int Degree[V];
	int Distance[V];
	
	for(int i=0; i<V; i++)
		Distance[i] = INT_MIN;
	
	Distance[0] = 0;	
	
	memset(Degree, 0, sizeof(Degree));	
	
	for(int i=0; i<V; i++)
	{
		list<int> :: iterator it = AdList[i].begin();
	
		while( it != AdList[i].end())
		{
			Degree[*it]++;
			
			it++;
		}
	}
	
	for(int i=0; i<V; i++)
	{
		int Min = findMin( Degree, V);
		Degree[Min] = INT_MAX;
		
		list<int> :: iterator it = AdList[Min].begin();
	
		while( it != AdList[Min].end())
		{
			Degree[*it]--;
			
			Distance[*it]  = MAX( Distance[*it], Distance[Min] + getEdge( Min, *it).Weight );
			
			it++;
		}
	}
	
	for(int i=0; i<V; i++)
	{
		cout<<" Distance from 0 to "<<i<<" is "<<Distance[i]<<endl;
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(8);
	
	G.AddEdge(0,1,2);
	G.AddEdge(0,2,77);
	G.AddEdge(0,3,9);
	
	G.AddEdge(1,5,5);
	G.AddEdge(1,6,12);
	
	G.AddEdge(2,6,29);
	
	G.AddEdge(3,4,3);
	
	G.AddEdge(4,5,7);
	
	G.AddEdge(5,7,30);	
	
	G.AddEdge(6,5,17);
	G.AddEdge(6,7,21);
	
	G.LongestPathDAG();

	return 0;
}
