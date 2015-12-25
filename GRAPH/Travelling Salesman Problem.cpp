#include <iostream>
#include <string.h>
#include <list>
#include <map>
#include <stack>
using namespace std;

/*			
	Question: Travelling Salesman Problem				Pending
	
	Contents: 
		- Properties of MST 
		- Prim’s Algo 
		- Application of MST	
		- Time & Space Complexity
		- Dependency Algo : - Binary Min Heap
*/

class Graph
{
	int V;
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list
		
		
	public:
		Graph(int v);
		void AddEdge(int V, int E);


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
	

*/



/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{


	return 0;
}
