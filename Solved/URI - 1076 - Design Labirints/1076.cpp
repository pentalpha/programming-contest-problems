#include <iostream>

using namespace std;

class MatrixGraph{
public:
  bool **edges;
  bool *accessed;

  unsigned short vertices;

  MatrixGraph(int vertices){
    this->vertices = vertices;
    edges = new bool*[vertices];
    for(int i = 0; i < vertices; i++){
      edges[i] = new bool[vertices];
    }
    accessed = new bool[vertices];
    for(int i = 0; i < vertices; i++){
      for(int j = 0; j < vertices; j++){
        edges[i][j] = false;
      }
    }

    for(int i = 0; i < vertices; i++){
      accessed[i] = false;
    }
  }

  void insertEdge(int i, int j){
    edges[i][j] = edges[j][i] = true;
  }

  int DFSCount(int n){
    int count = 0;
    accessed[n] = true;
    for(int i = 0; i < vertices; i++){
      if(accessed[i] == false && edges[n][i] == true){
        count = count + DFSCount(i) + 1;
      }
    }
    return count;
  }
};

int main() {
  int cases;
  cin >> cases;
  for(int c = 1; c <= cases; c++){
    int initialVertex;
    cin >> initialVertex;
    int vertices, edges;
    cin >> vertices >> edges;

    MatrixGraph graph(vertices);
    while(edges > 0){
      int a, b;
      cin >> a >> b;
      graph.insertEdge(a, b);
      edges--;
    }
    int count = graph.DFSCount(initialVertex) * 2;
    cout << count << "\n";
  }
  return 0;
}
