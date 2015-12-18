#include <iostream>
#include <string.h>
#include <list>
#include <map>
using namespace std;


/*
	Question: Kruskal’s Algorithm for Minimum Spanning Tree 
	
	Contents: 
		- Properties of MST 
		- Kruskal’s Algo 
		- Application of MST	
		- Time & Space Complexity
		- Dependency Algo : - Disjoint Set
*/

/*---------------------------------------Disjoint Set---------------------------------------------*/	
class DisjointSet
{
	
	class node
	{
		public: 
			long data;
			int  rank;	
			node* parent;
	};
	
	map<long, node*> Table;
	
	public:
		void MakeSet(long data)
		{
			node *temp = new node();
			temp->data = data;
			temp->rank = 0;
			temp->parent = temp;
			Table[data] = temp;
		}
		
		long FindSet(long data)
		{
			return FindSet(Table[data])->data;
		}
		
		node* FindSet(node *Node)
		{
			if( Node == Node->parent)
				return Node->parent;
			Node->parent = 	FindSet(Node->parent);
			return Node->parent;
		}
		
		void Union(long data1, long data2)
		{
			node *parent1 = FindSet( Table[data1]);
			node *parent2 = FindSet( Table[data2]);
			
			if( parent1->data == parent2->data )
				return;
			
			if( parent1->rank >= parent2->rank )	
			{
				parent1->rank = (parent1->rank == parent2->rank) ? parent1->rank+1 : parent1->rank;
				parent2->parent = parent1;
			}
			else
			{
				parent1->parent = parent2;
			}
		}
};
/*-----------------------------------------------------------------------------------------------*/


/*-----------------------------------Edge Manipulation------------------------------------------*/		
class Edge
{
	private:
		int Src;
		int Dest;	
		int Weight;

	public:	
		Edge()
		{
		}
				
		Edge(int V, int E, int W)
		{
			this->Src = V;
			this->Dest = E;
			this->Weight = W;	
		}
			
		int getWeight()
		{
			return	this->Weight;
		}
			
		int getSrc()
		{
			return	this->Src;
		}
			
		int getDest()
		{
			return	this->Dest;
		}			
};

// Linked List Sorting parameter function
bool compareWeight(Edge &edge1, Edge &edge2)
{
	return edge1.getWeight() < edge2.getWeight();
}
/*-----------------------------------------------------------------------------------------------*/		


/*-----------------------------------Graph Manipulation------------------------------------------*/		
		
class Graph : public DisjointSet
{	
	int V;					// No. of vertices
	list<int> *AdList;		// Pointer for Dynamic Allocation of Adjecency list		
	list<Edge> EdgeList;
	
	public:
	
		Graph(int v)
		{
			this->V = v;
			this->AdList = new list<int>[v];
			for(int i=0; i<v; i++)	
				MakeSet(i);
		}
		
		void AddEdge(int V, int E, int W)
		{
			Edge edge(V,E,W);
			EdgeList.push_back(edge);
			
			AdList[V].push_back(E);
			AdList[E].push_back(V);		// Comment This Line For Directed Graph
		}
		
		/*
			# Properties of MST :-
			 
				- MST Contain V-1 edges where V stands for number of vertices
				- If Graph has distinct edge length, then MST would be unique and only one
				
			# Kruskal’s Algorithm :-	
			
				- Sort Edges in increasing order
				- Start picking smallest edge, Check for edge not forming cycle by Disjoint Set Algo
				- If edge not form cycle add that to MST.
				
			# Application of MST :-	
				
				- Network design : You have a business with several offices; 
									you want to lease phone lines to connect them up with each other; 
									and the phone company charges different amounts of money to connect different pairs of cities. 
									You want a set of lines that connects all your offices with a minimum total cost. 
									It should be a spanning tree, since if a network isn’t a tree you can always remove some edges and save money.
				– learning salient features for real-time face verification
				– reducing data storage in sequencing amino acids in a protein					
				- Cluster analysis for mobile network implementation
			
			# Time & Space Complexity :-
			# Dependency Algo : - Disjoint Set
		*/
		list<Edge> KrushkalMST()
		{
			list<Edge> MSTEdgeList;
			list<Edge> :: iterator i;	
			
			EdgeList.sort(compareWeight);		// Sort Edges in increasing order			
			
			for(i = EdgeList.begin(); i != EdgeList.end(); i++)
			{	
				long Set1 = FindSet( (*i).getSrc());
				long Set2 = FindSet( (*i).getDest());				
			
				// if edge are on same set then there must be another way to connect them MEAN CYCLE
				if( Set1 == Set2)	
					continue;
				else
				{
					MSTEdgeList.push_back((*i));
					Union( Set1, Set2);
				}
			}
			return MSTEdgeList;
		}
		
		void PrintKrushkalMST()
		{
			list<Edge> MSTEdgeList = KrushkalMST();		
			list<Edge> :: iterator i;
			
			for(i = MSTEdgeList.begin(); i != MSTEdgeList.end(); i++)
			{			
				cout<<"SRC = "<<(*i).getSrc()<<" DEST = "<<(*i).getDest()<<" Weight = "<<(*i).getWeight()<<endl;
			}
		}

		void test()
		{	
			EdgeList.sort(compareWeight);			
			list<Edge> :: iterator i;
			
			for(i = EdgeList.begin(); i != EdgeList.end(); i++)
			{
				cout<<(*i).getWeight()<<endl;
			}
		}
};	

/*-------------------------------------------------------------------------------------------------*/	


int main()
{
	Graph G(9);
	
	G.AddEdge( 0, 1, 4);
	G.AddEdge( 0, 7, 8);
	
	G.AddEdge( 1, 7, 11);
	G.AddEdge( 1, 2, 8);
	
	G.AddEdge( 2, 3, 7);
	G.AddEdge( 2, 5, 4);
	G.AddEdge( 2, 8, 2);
	
	G.AddEdge( 3, 4, 9);
	G.AddEdge( 3, 5, 14);
	
	G.AddEdge( 4, 5, 10);
	
	G.AddEdge( 5, 6, 2);
	
	G.AddEdge( 6, 8, 6);
	G.AddEdge( 6, 7, 1);
	
	G.AddEdge( 7, 8, 7);	
	
	//G.test();
	G.PrintKrushkalMST();
	
	return 0;
}
