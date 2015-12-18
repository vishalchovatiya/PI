#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Find Cycle in Undirected Graph
	
	Contents: 
		- Use Algorithm Union-find or Disjoint Set
		- Application of Disjoint-Set Algorithm
*/

/*-----------------------------------------Disjoint Set Algorithm-------------------------------------------*/

/*
	Operations:
	
		1. Make-Set
		2. Find
		3. Union

	Application:
		
		- Maze generation (using a modified Kruskal's algorithm)
		- To find cycle in undirected graph
		- Keep track of connected component
		- Used by the Boost Graph Library to implement its Incremental Connected Components functionality
		- Used for implementing Kruskal's algorithm to find the minimum spanning tree of a graph

*/
class DisjointSet 
{
	public:
	class	node
	{
		public:
			long data;
			int rank;
			node *parent;		
	};
	
	map< long, node*>	 Table;
	
	protected:
		void MakeSet(long data)
		{
			node *temp = new node();
			temp->data = data;
			temp->rank = 0;
			temp->parent = temp;
			Table[data] = temp;
		}
		
		node* find(node* Node)
		{
			if( Node == Node->parent )
				return Node->parent;
			Node->parent = 	find( Node->parent);
			return Node->parent;
		}
		
		long find(long data)
		{
			return find(Table[data])->data;
		}
		
		void Union(long data1, long data2)
		{
			node *Node1 = Table[data1];
			node *Node2 = Table[data2];
			
			node *parent1 = find( Node1);
			node *parent2 = find( Node2);
			
			if( parent1->data == parent2->data )	// is of same union already
				return;
				
			if( parent1->rank >= parent2->rank )	
			{
				parent1->rank = (parent1->rank == parent2->rank) ? ++parent1->rank : parent1->rank;
				parent2->parent = parent1;
			}
			else
			{
				parent1->parent = parent2;
			}
		}
};


/*------------------------------------------------------Graph-----------------------------------------------------------*/


class Graph : public DisjointSet
{
	class Edge
	{
		public:
			int Src;
			int Dest;	
	};
	int V;				// No. of vertices
	list<int> *AdList;	// Pointer for Dynamic Allocation of Adjecency list	
	list<Edge> EdgeList;

	public:
		Graph(int v);
		void AddEdge(int V, int E);
		bool DetectCycle();
		
		void testDisjointSet();			
};



Graph::Graph(int v)
{
	this->V = v;
	this->AdList = new list<int>[v];	
}

void Graph::AddEdge(int V, int E)
{
	Edge edge;
	edge.Src = V;
	edge.Dest = E;
	EdgeList.push_back(edge);
	
	AdList[V].push_back(E);
	AdList[E].push_back(V);		// Comment This Line For Directed Graph
}


void Graph::testDisjointSet()	
{		
	for(int u=0; u<this->V; u++)
		MakeSet(u);	
	
	Union(0,1);
	Union(2,1);
	Union(3,4);
	Union(3,2);

	cout<<find((long)0)<<endl;
	cout<<find((long)1)<<endl;

	cout<<Table[1]->parent->data<<endl;
	cout<<Table[0]->parent->data<<endl;
	
	cout<<"Table[0]->rank : "<<Table[0]->rank<<endl;
	cout<<"Table[1]->rank : "<<Table[1]->rank<<endl;
	cout<<"Table[2]->rank : "<<Table[2]->rank<<endl;
	cout<<"Table[3]->rank : "<<Table[3]->rank<<endl;
	cout<<"Table[4]->rank : "<<Table[4]->rank<<endl;
	
}




/*-----------------------------------------Detect Cyle in UNDirected Graph-------------------------------------------*/

/*
	
	Algo ::
		- Take each edge one-by-one and Find set on them, if Set-Representative is different then Union them
		- Repeat this process until all edges or vertices are visited
		- if there is an cylce present in a graph then Find set on edge of those vertices(which form cylce) would have same Set-Representative
	
*/
bool Graph::DetectCycle()
{
	for(int u=0; u<this->V; u++)		MakeSet(u);		
	
	Edge edge;
	list<Edge> :: iterator E;	

	for(E = EdgeList.begin(); E != EdgeList.end(); E++)
	{
		edge = *E;
		int Set1 = find(edge.Src);
		int Set2 = find(edge.Dest);				
		//cout<<"edge.Src = "<<edge.Src<<" edge.Dest "<<edge.Dest<< " Set1 "<<Set1<<" Set2 "<<Set2<<endl;		
		if( Set1 == Set2)	return true;
		
		Union( Set1, Set2);
	}		
	return false;			
}


/*-----------------------------------------------------------------------------------------------------------------*/

int main()
{
	Graph G(5);
	
	G.AddEdge(0,1);
	G.AddEdge(0,3);
	G.AddEdge(1,3);		//This Edge Form Cycle
	G.AddEdge(1,2);
	G.AddEdge(2,4);
	
	
	cout<<G.DetectCycle();
	
	//G.testDisjointSet();	

	return 0;
}
