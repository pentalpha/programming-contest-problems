#include <iostream>
#include <string>
#include <list>

using namespace std;

struct XY{
  int x1, x2;
  int y1, y2;
}

list<int> *blocks;
int n;

/*bool listContainsInt(int x, list<int> &l){
  for (int i : l){
    if (i == x){
      return true;
    }
  }
  return false;
}*/

XY find(int a, int b){
  XY place;
  for(int i = 0; i < n; i++){
    for (int j = 0; j < blocks[i].size(); j++){
      if(blocks[i][j] == a){
        place.x1 = i;
        place.x2 = j;
      }
    }
  }

  for(int i = 0; i < n; i++){
    for (int j = 0; j < blocks[i].size(); j++){
      if(blocks[i][j] == b){
        place.y1 = i;
        place.y2 = j;
      }
    }
  }

  return place;
}

void moveOnto(int a, int b){
  int aList, bList;
  int aIndex, bIndex;
  XY result = find(a, b);
  aList = result.x1; aIndex = result.x2;
  bList = result.y1; bIndex = result.y2;
  //move blocks over a to original positions;
  for(int i = aIndex + 1; i < blocks[aList].size(); i++){
    element = blocks[aList][i];
    blocks[element].push_front(element);
  }
  if(aIndex+1 < blocks[aList].size()){
    it = blocks[aList].begin();
    toAdvance = aIndex+1;
    
  }
}

void moveOver(int a, int b){

}

void pileOnto(int a, int b){
  int aList, bList;
  XY result = find(a, b);
  aList = result.x;
  bList = result.y;
}

void pileOver(int a, int b){
  int aList, bList;
  XY result = find(a, b);
  aList = result.x;
  bList = result.y;
}

void createWorld(){
  blocks = new list<int>[n];
  for (int i = 0; i < n; i++){
    blocks[i].push_back(i);
  }
}

void writeWorld(){
  for(int i = 0; i < n; i++){
    cout << i << ":";
    for(auto block : blocks[i]){
      cout << " " << block;
    }
    cout << "\n";
  }
}

int main(int argc, char const *argv[]) {
  cin >> n;
  createWorld();
  //writeWorld(n);
  //cout << listContainsInt(1, blocks[1]) << "\n";
  string c1, c2;
  int p1, p2;
  while(true){
    cin >> c1;
    if(c1 == "quit"){
      break;
    }else if (c1 == "move"){
      cin >> p1;
      cin >> c2;
      cin >> p2;
      if(c2 == "onto"){
        moveOnto(p1, p2);
      }else if (c2 == "over"){
        moveOver(p1, p2);
      }
    }else if (c1 == "pile"){
      cin >> p1;
      cin >> c2;
      cin >> p2;
      if(c2 == "onto"){
        pileOnto(p1, p2);
      }else if (c2 == "over"){
        pileOver(p1, p2);
      }
    }

  }
  writeWorld();
  return 0;
}
