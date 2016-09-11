#include <iostream>
#include <algorithm>
#include <list>
#include <stack>
#include <string.h>
using namespace std;

/*
What is a Mother Vertex?
A mother vertex in a graph G = (V,E) is a vertex v such that all other vertices in G can be reached by a path from v.

Logic: Do DFS & Maintain Arrival Time
*/

class Graph{
	list<int>	*Adlist;
	int V;
	
	public:
	Graph(int V){
		this->V = V;
		Adlist = new list<int>[V];
	}
	
	void AddEdge( int U, int V){
		Adlist[U].push_back(V);
	}
	
	int DFS(int V, bool Visited[], int arrival[], stack<int>	&S, int &arr){
		
		arrival[V] = arr++;
		Visited[V] = true;
		
		for(list<int> :: iterator i=Adlist[V].begin(); i!=Adlist[V].end(); i++ ){
			if( !Visited[*i] )
				DFS( *i, Visited, arrival, S, arr);
			else
				arr = min( arr, arrival[*i]);	
		}
		
		S.push(V);
		
		return arr;
	}
	
	void MotherVertex(){
		int arr = 0;
		bool Visited[this->V];
		int arrival[this->V];
		stack<int>	S;
		memset( Visited, 0, sizeof(Visited));
		memset( arrival, 0, sizeof(arrival));		
		
		for(int i=0; i<V; i++){
			if( !Visited[i] )
				DFS( i, Visited, arrival, S, arr);
		}
		
		while( !S.empty()){
			cout<<S.top()<<" "<<arrival[S.top()]<<endl;
			S.pop();
		}		
	}
};



int main() {
	Graph	G(6);
	
	G.AddEdge(0,2);
	
	G.AddEdge(1,0);
	G.AddEdge(1,4);
	
	G.AddEdge(3,2);
	G.AddEdge(3,1);
	G.AddEdge(3,4);
	
	G.AddEdge(5,3);
	
	G.MotherVertex();
	
	return 0;
}
