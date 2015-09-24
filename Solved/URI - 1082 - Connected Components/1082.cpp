#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

enum Color{
  BLACK = 0,
  GRAY = 1,
  WHITE = 2
};

int nameToIndex(char a){
  return ((int)a) - 97;
}

char indexToName(int i){
  return (char)(i+97);
}

struct Vertice{
  char name;
  Color color;
  short group;
  vector<char> neighbours;
};

class Graph{
public:
  vector<Vertice> vertices;
  Graph(int n){
    for(int i = 0; i < n; i++){
      Vertice temp;
      temp.name = indexToName(i);
      temp.color = WHITE;
      temp.group = 0;
      vertices.push_back(temp);
    }
  }

  void insertEdge(char u, char v){
    int uIndex = nameToIndex(u);
    int vIndex = nameToIndex(v);

    vertices[uIndex].neighbours.push_back(v);
    vertices[vIndex].neighbours.push_back(u);
  }

  void BFS(char s, int groupID = 0){
    for(Vertice v : vertices){
        v.color = WHITE;
    }
    vertices[nameToIndex(s)].color = GRAY;

    queue<char> q;
    q.push(s);
    while(!q.empty()){
      char u = q.front();
      q.pop();
      for(char v : vertices[nameToIndex(u)].neighbours){
        if(vertices[nameToIndex(v)].color == WHITE){
          vertices[nameToIndex(v)].color = GRAY;

          q.push(v);
        }
      }
      vertices[nameToIndex(u)].group = groupID;
      vertices[nameToIndex(u)].color = BLACK;

    }
  }

  deque<string> getComponents(){
    for(auto v : vertices){
      v.group = 0;
    }
    for(int i = 1; i < vertices.size(); i++){
      if(vertices[i-1].group == 0){
        BFS(indexToName(i-1), i);
      }
    }
    map<int,deque<char>> componentsMap;
    for(auto v : vertices){
      componentsMap[v.group].push_back(v.name);
    }
    for(auto v : vertices){
      v.group = 0;
    }
    deque<string> components;
    for(auto x : componentsMap){
      string temp = "";
      for(auto y : x.second){
        temp = temp + y + ",";
      }
      components.push_back(temp);
    }
    sort(components.begin(), components.end());

    return components;
  }
};

int main(int argc, char const *argv[]) {
  int cases;
  cin >> cases;
  for(int c = 1; c <= cases; c++){
    cout << "Case #" << c << ":\n";
    int vertices, edges;
    cin >> vertices >> edges;
    Graph graph(vertices);
    while(edges > 0){
      char a, b;
      cin >> a >> b;
      graph.insertEdge(a, b);
      edges--;
    }
    deque<string> components = graph.getComponents();
    for(auto x : components){
      cout << x << "\n";
    }
    cout << components.size() << " connected components\n\n";
    /*if(c != cases){
      cout << "\n";
    }*/
  }
  return 0;
}
