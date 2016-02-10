#include <iostream>
#include <string.h>
#include <stack>
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
	list<int> *AdList;
	
	public:
		
		Graph(int Size)	
		{
			V = Size;
			AdList = new list<int>[Size];
		}
		
		void AddEdge(int U, int V)
		{
			AdList[U].push_back(V);
			AdList[V].push_back(U);
		}

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


/*-----------------------------------------------------------------------------------------------------------------*/

		
		void DFS(int Start)
		{
			stack<int> S;
			bool visited[V];
			for(int i=0; i<V; i++)
				visited[i] = false;
			
			S.push(Start);
			visited[Start] = true;
			
			while( !S.empty())
			{
				int Crawl = S.top();
				S.pop();
				cout<<" "<<Crawl;
				
				
				list<int> :: iterator it = AdList[Crawl].begin();
				
				while( it != AdList[Crawl].end() )
				{
					if( visited[*it] == false)
					{
						S.push(*it);
						visited[*it] = true;
					}
						
					it++;
				}
			}			
		}
};




int main()
{
	Graph G(6);
	
	G.AddEdge(0,1);
	G.AddEdge(0,2);
		
	G.AddEdge(1,2);
	G.AddEdge(1,3);

	G.AddEdge(2,3);
	G.AddEdge(2,4);
	G.AddEdge(5,4);
	

	
	G.DFS(0);	
	
	return 0;
}

