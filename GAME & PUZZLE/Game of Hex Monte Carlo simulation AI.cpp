/*
Homework 5 expectations:
1. The computer should be able to play Hex intelligently against a human on an 11 by 11 board.
2. Efficiently determine within no more than 2 minutes what the computer's move is.
*/

#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define DEBUG(X)  std::cout<<__FILE__":"<<__LINE__<<":"<<#X<<" = "<<X<<std::endl

#define NO_EDGE (0xFFFFFFFF)
#define EDGE    (0x12345678)

template<uint32_t size>
class hexGraph{
  uint32_t                          **m_G; // Graph
  uint32_t                          **m_B; // Board
  uint32_t                          m_noOfVertices;
  uint32_t                          m_r;
  uint32_t                          m_c;
  uint32_t                          m_noOfMovesDone;

public:
  // C++11 style enum class
  enum class PLAYER:uint32_t {HUMAN=0x87654321, COMPUTER, NOBODY};

  /*
    Create graph & add edges
  */
  hexGraph():m_r(size), m_c(size), m_noOfMovesDone(0){
    m_noOfVertices = m_r * m_c;

    // Create graph memory
    m_G = new uint32_t*[m_noOfVertices]{0};
    for(uint32_t i=0; i<m_noOfVertices; ++i){
      m_G[i] = new uint32_t[m_noOfVertices]{NO_EDGE};
    }

    // Add edges
    m_B = new uint32_t*[m_r]{0};
    for(uint32_t r=0; r<m_r; ++r){
      m_B[r] = new uint32_t[m_c]{0};
      for(uint32_t c=0; c<m_c; ++c){

        if(r==0 && c==0){// top left
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
        }
        else if(r==(m_r-1) && c==(m_c-1)) {// bottom right
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
        }
        else if(r==0 && c==(m_c-1)){// top right
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c-1));
        }
        else if(r==(m_r-1) && c==0){// bottom left
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r-1, c+1));
        }
        else if(r==0 && c>0){// top edge side nodes
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c-1));
        }
        else if(c==(m_c-1) && r>0){// right edge side nodes
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c-1));
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
        }
        else if(c==0 && r>0){// left edge side nodes
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
          addEdge(nodeNo(r,c), nodeNo(r-1, c+1));
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
        }
        else if(r==(m_r-1) && c>0){// bottom edge side nodes
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r-1, c+1));
        }
        else{
          addEdge(nodeNo(r,c), nodeNo(r, c-1));
          addEdge(nodeNo(r,c), nodeNo(r, c+1));
          addEdge(nodeNo(r,c), nodeNo(r-1, c));
          addEdge(nodeNo(r,c), nodeNo(r+1, c));
          addEdge(nodeNo(r,c), nodeNo(r-1, c+1));
          addEdge(nodeNo(r,c), nodeNo(r+1, c-1));
        }
      }
    }
  }

  /*
    Free acquired resources
  */
  ~hexGraph(){
    for(uint32_t i=0; i<m_noOfVertices; ++i){
      delete [] m_G[i];

      if(i<m_r)
        delete [] m_B[i];
    }
    delete [] m_G;
    delete [] m_B;
  }

  /*
    Compute node no from coordinates
  */
  inline uint32_t nodeNo(uint32_t i, uint32_t j)const {
    return (i*m_r + j);
  }

  /*
    Compute node no using coordinates
  */
  inline void getCoordinates(uint32_t &i, uint32_t &j, uint32_t nodeNo)const {
    i = (nodeNo/m_r);
    j = (nodeNo%m_c);
  }

  /*
    Check for boundaries & overwrite to make legal move
  */
  inline bool isLegalMove(uint32_t i, uint32_t j) {
    if(i<m_r && j<m_c
      && m_B[i][j] != static_cast<uint32_t>(PLAYER::HUMAN)
      && m_B[i][j] != static_cast<uint32_t>(PLAYER::COMPUTER)){
      m_noOfMovesDone++;
      return true;
    }
    return false;
  }

  /*
    Make safe move
  */
  inline bool makeMove(uint32_t i, uint32_t j, PLAYER player) {
    if(isLegalMove(i,j)){
      m_B[i][j] = static_cast<uint32_t>(player);
      return true;
    }
    return false;
  }

  /*
    Check whether move available or not
  */
  inline bool isAllMoveExhausted()const {
    if(m_noOfMovesDone == m_noOfVertices) return true;
    return false;
  }

  /*
    Prints all neighbors of u
  */
  vector<int> getNeighbors(uint32_t u) const{
    vector<int> neighbors;
    for(uint32_t v=0; v<m_noOfVertices; ++v){
      if(m_G[u][v] == EDGE){
        neighbors.push_back(v);
      }
    }
    return std::move(neighbors);
  }

  /*
    Adds edge into graph with weight
  */
  inline void addEdge(uint32_t u,uint32_t v, uint32_t weight = EDGE){
    try{
      if(u>=m_noOfVertices){
        throw u;
      }
      if(v>=m_noOfVertices){
        throw v;
      }

      m_G[u][v] = /*m_G[v][u] =*/ weight;
    }
    catch(uint32_t vertex){
      cout<<"Index error: "<<vertex<<"\n";
    }
  }

  /*
    Determine who won the game
    Used disjoint-set(union-find) algorithm to achieve minimum time complexity(i.e. O(6*N))
  */
  PLAYER whoWon(uint32_t **twoDArr=NULL) const {

    if(twoDArr==NULL) twoDArr = m_B;

    // Do the union of connected component
    uint32_t unionTable[m_noOfVertices];
    memset(unionTable, 0xFF, sizeof(uint32_t) * m_noOfVertices);

    for(uint32_t u=0; u<m_noOfVertices; ++u){
      uint32_t i=0;
      uint32_t j=0;
      getCoordinates(i,j,u);

      if(unionTable[u] == UINT_MAX){// Self node union id
        unionTable[u] = u;
      }

      PLAYER PLAYER_t(PLAYER::NOBODY);
      if(twoDArr[i][j] == static_cast<uint32_t>(PLAYER::HUMAN))           PLAYER_t = PLAYER::HUMAN;
      else if(twoDArr[i][j] == static_cast<uint32_t>(PLAYER::COMPUTER))   PLAYER_t = PLAYER::COMPUTER;

      for(auto adjecent : getNeighbors(u)){ // all node adjecent to u
        uint32_t x=0;
        uint32_t y=0;
        getCoordinates(x,y,adjecent);
        if(twoDArr[x][y] == static_cast<uint32_t>(PLAYER_t)){
          if(unionTable[adjecent] == UINT_MAX){// new node / not explored
            unionTable[adjecent] = unionTable[u];
          }
          else{// Found already explored node
            unionTable[u] = unionTable[adjecent];
          }
        }
      }
    }

    // Computer winning check -----------------------------------------------------------
    uint32_t unionTableC[m_noOfVertices];
    memset(unionTableC, 0xFF, sizeof(uint32_t) * m_noOfVertices);
    for(uint32_t c=0; c<m_c; ++c){
      uint32_t nodeLeftSide = nodeNo(c, 0);
      if(twoDArr[c][0] == static_cast<uint32_t>(PLAYER::COMPUTER) ){
        unionTableC[unionTable[nodeLeftSide]] = 1;
      }
    }

    for(uint32_t c=0; c<m_c; ++c){
      uint32_t nodeRightSide = nodeNo(c, (m_r-1));
      if(twoDArr[c][m_r-1] == static_cast<uint32_t>(PLAYER::COMPUTER) ){
        if(unionTableC[unionTable[nodeRightSide]] != UINT_MAX){
          return PLAYER::COMPUTER;
        }
      }
    }

    // Human winning check -----------------------------------------------------------
    uint32_t unionTableH[m_noOfVertices];
    memset(unionTableH, 0xFF, sizeof(uint32_t) * m_noOfVertices);
    for(uint32_t r=0; r<m_r; ++r){
      uint32_t nodeTopSide = nodeNo(0, r);
      if(twoDArr[0][r] == static_cast<uint32_t>(PLAYER::HUMAN) ){
        unionTableH[unionTable[nodeTopSide]] = 1;
      }
    }

    for(uint32_t r=0; r<m_r; ++r){
      uint32_t nodeBottomSide = nodeNo((m_r-1), r);
      if(twoDArr[(m_r-1)][r] == static_cast<uint32_t>(PLAYER::HUMAN) ){
        if(unionTableH[unionTable[nodeBottomSide]] != UINT_MAX){
          return PLAYER::HUMAN;
        }
      }
    }

    return PLAYER::NOBODY;
  }

  /*
    Print graph in edge list form
  */
  void printEdgeList() const {
    std::cout<<"\nEdge list representation:\n";
    for(uint32_t u=0; u<m_noOfVertices; ++u){
      cout<<"["<<u<<"]";
      for(uint32_t v=0; v<m_noOfVertices; ++v){
        if(m_G[u][v] == EDGE) cout<<" -> "<<v;
      }
      cout<<"\n";
    }
    cout<<"\n";
  }


  /*
    Print board
  */
  void printBoard(bool isNodeNo=false, uint32_t **twoDArr=NULL) const {

    if(twoDArr==NULL) twoDArr = m_B;

#define SPACES(n) (string( n, ' ' ))

    cout<<m_r<<" x "<<m_c<<" board :\n\n";

    string header((m_r*2), 'H');
    header = std::regex_replace(header, std::regex("H"), "H ");
    cout<<SPACES(10)<<header+"\n";

    string dashLine((m_r*2), '-');
    dashLine = std::regex_replace(dashLine, std::regex("-"), "- ");
    cout<<SPACES(10)<<dashLine+"\n\n";

    for(uint32_t r=0; r<m_r; ++r){

      cout<<SPACES(r*2)<<"C\\\\"<<SPACES(7); // Prefix player name
      string slashes;

      for(uint32_t c=0; c<m_c; ++c){

        if(twoDArr[r][c] == static_cast<uint32_t>(PLAYER::HUMAN)){
          cout<<setw(2)<<"H";
        }
        else if(twoDArr[r][c] == static_cast<uint32_t>(PLAYER::COMPUTER)){
          cout<<setw(2)<<"C";
        }
        else{ // EDGE
          if(isNodeNo) cout<<setw(2)<<nodeNo(r,c);
          else cout<<setw(2)<<'o';
        }

        cout<<((c==(m_c-1)) ? SPACES(7) + "\\\\C\n" : " - ");// Post fix player name
        slashes += string(" \\ ") + ((c==(m_c-1)) ? SPACES(6) + "\\\\C\n": "/ ");// Post fix player name
      }

      cout<<((r==(m_r-1)) ? "" : SPACES(r*2+1) + "C\\\\"); // Prefix player name
      cout<<SPACES(7)<<((r==(m_r-1)) ? "\n": slashes);
    }

    cout<<SPACES((m_c*2)+10)<<dashLine+"\n";
    cout<<SPACES((m_c*2)+10)<<header+"\n\n";
  }


  /*
    Select best move by using Monte-Carlo Simulation
  */
  uint32_t getBestMove(uint32_t iteration=1000, PLAYER PLAYER_t=PLAYER::COMPUTER){
    auto start = chrono::steady_clock::now();

    // Copy board for Monte Carlo Evaluation -------------------------------------------
    uint32_t **tempBoard = new uint32_t*[m_r];
    for(uint32_t r=0; r<m_r; ++r){
      tempBoard[r] = new uint32_t[m_c];
      memcpy(tempBoard[r], m_B[r], sizeof(uint32_t) * m_c);
    }

    // Calculate remaning move-------------------------------------------
    const uint32_t      remainingMoveCnt = m_noOfVertices - m_noOfMovesDone;
    vector<uint32_t>    remainMoves; remainMoves.reserve(remainingMoveCnt);

    for(uint32_t r=0; r<m_r; ++r){
      for(uint32_t c=0; c<m_c; ++c){
        if(tempBoard[r][c] == 0){
          remainMoves.push_back(nodeNo(r,c));
        }
      }
    }

    // See winning probability for each remaining move & pick best --------------------
    uint32_t maxWinMove = UINT_MAX;
    uint32_t maxWinCnt = 0;

    for(uint32_t pick=0; pick<remainMoves.size(); ++pick){// all remaining move
      uint32_t winCnt=0;

      // Make initial move
      uint32_t x=0;
      uint32_t y=0;
      getCoordinates(x,y, remainMoves[pick]);
      tempBoard[x][y] = static_cast<uint32_t>(PLAYER_t);

      swap(remainMoves[0], remainMoves[pick]);// Pick move

      vector<uint32_t>  makeMove(remainMoves.begin()+1, remainMoves.end());

      for(uint32_t i=0; i<iteration; ++i){// Run simulation for given iterations

        // Shuffle all except picked move
        unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
        shuffle(makeMove.begin(), makeMove.end(), std::default_random_engine(seed));

        bool isHumanTurn = !(PLAYER_t == PLAYER::HUMAN);
        for(uint32_t move=0; move<makeMove.size(); ++move){// Make shuffled move
          uint32_t i=0;
          uint32_t j=0;
          getCoordinates(i,j, makeMove[move]);

          if(isHumanTurn){
            tempBoard[i][j] = static_cast<uint32_t>(PLAYER::HUMAN);
          }
          else{
            tempBoard[i][j] = static_cast<uint32_t>(PLAYER::COMPUTER);
          }

          isHumanTurn=!isHumanTurn;
        }

        if(whoWon(tempBoard) == PLAYER_t){// See who won
          winCnt++;

          if(winCnt > maxWinCnt){// Store max winning move
            maxWinCnt = winCnt;
            maxWinMove = remainMoves[0];
          }
        }
      }

      // Reset board & move for next simulation
      swap(remainMoves[0], remainMoves[pick]);
      for(uint32_t r=0; r<m_r; ++r){
        memcpy(tempBoard[r], m_B[r], sizeof(uint32_t) * m_c);
      }

    }

    auto end = chrono::steady_clock::now();
    cout<<"Time for best move selection : "<<chrono::duration_cast<chrono::milliseconds>(end-start).count()<<" milli second\n";

    return maxWinMove;// Return max winning move
  }
};



int main()
{
  bool isHumanTurn = true;
  string str;
  constexpr uint32_t boardSize = 3;
  hexGraph<boardSize>  hg;

  do{
    cout << "Is Human first(Y/N) : ";
    getline(cin, str);
  }while((str.find("Y") == std::string::npos)
    && (str.find("N") == std::string::npos));

  isHumanTurn = (str.find("Y") != std::string::npos);

  // Play
  while(!(hg.isAllMoveExhausted())){
    uint32_t i=0;
    uint32_t j=0;
    hexGraph<boardSize>::PLAYER player_t;

    if(isHumanTurn){
      cout << "Enter Move : ";
      cin >> i>>j;
      player_t = hexGraph<boardSize>::PLAYER::HUMAN;
    }
    else{
      uint32_t node = hg.getBestMove(1000, hexGraph<boardSize>::PLAYER::COMPUTER);

      if(node == UINT_MAX)
        break;

      hg.getCoordinates(i,j, node);
      player_t = hexGraph<boardSize>::PLAYER::COMPUTER;
    }

    // make move
    if(hg.makeMove(i, j, player_t) == false){
      cout<<"Illegal Move\n";
      continue;
    }

    // Print board
    hg.printBoard();

    isHumanTurn=!isHumanTurn;
  }

  // Check for winning
  hexGraph<boardSize>::PLAYER player = hg.whoWon();
  if(player == hexGraph<boardSize>::PLAYER::HUMAN){
    cout<<"Human Won\n";
  }
  else if(player == hexGraph<boardSize>::PLAYER::COMPUTER){
    cout<<"Computer Won\n";
  }
  else{
     cout<<"NOBODY Yet\n";
  }

  cout<<"\n\n\n";
  return 0;
}

/* Sample Output:

clang version 7.0.0-3~ubuntu0.18.04.1 (tags/RELEASE_700/final)
 clang++-7 -pthread -std=c++11 -o main main.cpp
 ./main
Is Human first(Y/N) : Y
Enter Move : 1 1
3 x 3 board :

          H H H H H H
          - - - - - -

C\\        o -  o -  o       \\C
 C\\        \ /  \ /  \       \\C
  C\\        o -  H -  o       \\C
   C\\        \ /  \ /  \       \\C
    C\\        o -  o -  o       \\C

                - - - - - -
                H H H H H H

Time for best move selection : 95 milli second
3 x 3 board :

          H H H H H H
          - - - - - -

C\\        o -  o -  C       \\C
 C\\        \ /  \ /  \       \\C
  C\\        o -  H -  o       \\C
   C\\        \ /  \ /  \       \\C
    C\\        o -  o -  o       \\C

                - - - - - -
                H H H H H H

Enter Move : 0 1
3 x 3 board :

          H H H H H H
          - - - - - -

C\\        o -  H -  C       \\C
 C\\        \ /  \ /  \       \\C
  C\\        o -  H -  o       \\C
   C\\        \ /  \ /  \       \\C
    C\\        o -  o -  o       \\C

                - - - - - -
                H H H H H H

Time for best move selection : 61 milli second
3 x 3 board :

          H H H H H H
          - - - - - -

C\\        o -  H -  C       \\C
 C\\        \ /  \ /  \       \\C
  C\\        o -  H -  o       \\C
   C\\        \ /  \ /  \       \\C
    C\\        C -  o -  o       \\C

                - - - - - -
                H H H H H H

Enter Move : 2 1
3 x 3 board :

          H H H H H H
          - - - - - -

C\\        o -  H -  C       \\C
 C\\        \ /  \ /  \       \\C
  C\\        o -  H -  o       \\C
   C\\        \ /  \ /  \       \\C
    C\\        C -  H -  o       \\C

                - - - - - -
                H H H H H H

Time for best move selection : 40 milli second
Human Won




*/
