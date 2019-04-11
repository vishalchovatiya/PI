

/*
  - Undirected graph, generated randomly
  - Positive edge weights, generated randomly
  - Will not generate always connected graph
*/
class Graph{
  uint32_t                          **m_G;
  uint32_t                          m_noOfVertices;
  uint32_t                          m_noOfEdges;
  uint32_t                          m_maxEdgeWeight;
  unordered_map<int, std::string>   m_nodeNameMap;

public:
  /*
    noOfVertices = accept no of vertices in graph, default no of vertices is 5
    density = percentage of edges connected, default probability is 50%
  */
  explicit Graph(uint32_t noOfVertices = 5, uint32_t density = 50, uint32_t maxEdgeWeight = 10)
  : m_noOfVertices(noOfVertices), 
  m_noOfEdges(0), 
  m_maxEdgeWeight(maxEdgeWeight), 
  m_G(new uint32_t*[noOfVertices]){

    // Create graph memory
    for(uint32_t i=0; i<noOfVertices; ++i){
      m_G[i] = new uint32_t[noOfVertices];
    }

    // Create graph randomly 
    srand(time(0));
    auto probability = [](){return (rand() % 100 );};

    for(uint32_t u=0; u<noOfVertices; ++u){
      for(uint32_t v=u; v<noOfVertices; ++v){
        m_G[u][v] = 0;
        if(u==v)continue;// No self-loop

        if(probability() <= density){ // If edge
          m_G[u][v] = m_G[v][u] = (rand() % m_maxEdgeWeight); // add weight
          m_noOfEdges++;
        }
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
    Return no of vertices
  */
  inline uint32_t getNoOfVertices() const{
    return m_noOfVertices;
  }

  /*
    Return no of edges
  */
  inline uint32_t getNoOfEdges() const{
    return m_noOfEdges;
  }

  /*
    Returns true if nodes are adjacent
  */
  inline bool isAdjacent(uint32_t u,uint32_t v) const{
    return m_G[u][v];
  }
  
  /*
    Prints all neighbors of u
  */
  vector<int> getNeighbors(uint32_t u) const{
    vector<int> neighbors;
    for(uint32_t v=0; v<m_noOfVertices; ++v){
      if(u!=v && m_G[u][v]){
        // cout<<" -> "<<v;
        neighbors.push_back(v);
      } 
    }
    // cout<<"\n";
    return neighbors;
  }

  /*
    adds edge into graph with weight
  */
  inline void addEdge(uint32_t u,uint32_t v, uint32_t weight = 0) {
    weight = (weight==0) ? (rand() % m_maxEdgeWeight) : weight ;
    m_G[u][v] = weight;
    m_noOfEdges++;
  }

  /*
    Returns the value associated to the edge (u,v).
  */
  inline uint32_t getEdgeWeight(uint32_t u, uint32_t v) const{
    return m_G[u][v];
  }

  /*
    delete edge from graph
  */
  inline void deletee(uint32_t u,uint32_t v) {
    m_G[u][v] = 0;
    m_noOfEdges--;
  }
  
  /*
    Returns the value associated with the node u.
  */
  inline std::string getNodeName(uint32_t u,uint32_t v) const{
    return (const_cast<Graph*>(this))->m_nodeNameMap[u];
  }

  /*
    Sets the value associated with the node x to nodeName.
  */
  inline void setNodeName(uint32_t u, std::string nodeName){
    m_nodeNameMap[u] = nodeName;
  }
  
  /*
    Print graph in edge list form
  */
  void printEdgeList() const {
    std::cout<<"Edge list representation:\n";
    for(uint32_t u=0; u<m_noOfVertices; ++u){
      cout<<"["<<u<<"]";
      for(uint32_t v=u; v<m_noOfVertices; ++v){
        if(u!=v && m_G[u][v]) cout<<" -> "<<v;
      }
      cout<<"\n";
    }
    cout<<"\n";
  }

  /*
    Print edges with weights
  */
  void printEdgesWithWeights() const {
    std::cout<<"Edges with weight:\n";
    for(uint32_t u=0; u<m_noOfVertices; ++u){      
      for(uint32_t v=u; v<m_noOfVertices; ++v){        
        if(u!=v && m_G[u][v]) cout<<"("<<u<<", "<<v<<")"<<" = "<<m_G[u][v]<<"\n";
      }      
    }
    cout<<"\n";
  }  
};
