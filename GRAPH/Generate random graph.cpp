#include <bits/stdc++.h>

using namespace std;

#define DEBUG(X)	std::cout<<__FILE__":"<<__LINE__<<":"<<#X<<" = "<<X<<std::endl

class Graph{
  bool        **m_G;
  uint32_t    m_noOfVertices;
public:

  /*
    Return probability in percentage
  */
  inline uint32_t prob() const{
    return (rand() % 100 );
  }

  /*
    noOfVertices = accept no of vertices in graph, default no of vertices is 5
    density = percentage of edges connected, default probability is 50%
  */
  explicit Graph(uint32_t noOfVertices = 5, uint32_t density = 50): m_noOfVertices(noOfVertices), m_G(new bool*[noOfVertices]){
    // Create graph memory
    for(uint32_t i=0; i<noOfVertices; ++i){
      m_G[i] = new bool[noOfVertices];
    }

    // Create graph randomly 
    srand(time(0));
    for(uint32_t u=0; u<noOfVertices; ++u){
      for(uint32_t v=u; v<noOfVertices; ++v){
        if(u==v)continue;
        m_G[u][v] = m_G[v][u] = (prob() < density);
      }
    }
  }

  ~Graph(){
    for(uint32_t i=0; i<m_noOfVertices; ++i){
      delete [] m_G[i];
    }
    delete [] m_G;
  }

  /*
    Print graph in edge list form
  */
  void print() const {
    for(uint32_t u=0; u<m_noOfVertices; ++u){
      cout<<"["<<u<<"]";
      for(uint32_t v=u; v<m_noOfVertices; ++v){
        if(u==v)continue; // Do not print self loop
        if(m_G[u][v]) cout<<" -> "<<v;
      }
      cout<<"\n";
    }
  }

};

int main() {
  Graph G;
  G.print();
}
