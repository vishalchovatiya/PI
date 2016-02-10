#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <queue>
#include <stack>
using namespace std;

/*
	Question: Topological Sort (for Directed Acyclic Graph Only)
	
	Contents: 
		- Use in-Degree of all vertices
		- traverse with minimum in-Degree vertex & decrease in-Degrees of its adjecent vertices
		- Repeat this process untill all vertex's in-Degree becomes zero
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

void Graph::TopologicalSort()
{
	int Weight[V];
	memset(Weight, 0, sizeof(Weight));
	for(int i=0; i<V; i++)
	{		
		list<int> :: iterator it = AdList[i].begin();
		//cout<<" i = "<<i<<"   -----";
		while( it != AdList[i].end())
		{
			Weight[*it]++;		
		//	cout<<" "<<*it;
			it++;
		}
		cout<<endl;
	}

	queue<int> Q;
	
	for(int i=0; i<V; i++)
	{
		int Crawl = findMin( Weight, V);
		Weight[Crawl] = INT_MAX;		
		Q.push(Crawl);
		
		list<int> :: iterator it = AdList[Crawl].begin();
		while( it != AdList[Crawl].end())
		{
			Weight[*it]--;		

			it++;
		}
	}
	
	while( !Q.empty())
	{
		cout<<" "<<Q.front();
		Q.pop();
	}
}

/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(8);
	
	G.AddEdge(0,1);
	G.AddEdge(0,2);
	G.AddEdge(0,3);
	
	G.AddEdge(1,4);
	G.AddEdge(1,6);
	
	G.AddEdge(2,6);
	G.AddEdge(2,7);
	
	G.AddEdge(3,4);
	
	G.AddEdge(4,5);
	
	G.AddEdge(6,7);
	
	G.AddEdge(5,7);	
	
	G.TopologicalSort();

	return 0;
}
