#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class Species{
public:
  int amount;
  string name;
  Species(){
    //this->name = name;
    amount = 0;
  }
  void increase(){
    amount++;
  }
  float getPercent(float total){
    int a = amount*100;
    float b = a / total;
    return b;
  }
};

int main(int argc, char const *argv[]) {
  int cases;
  int maxSize = 31;
  cin >> cases;
  cout.setf(ios::fixed);
  char tempTreeName[maxSize];

  std::cin.getline(tempTreeName, maxSize);
  std::cin.getline(tempTreeName, maxSize);

  while(cases > 0){
    map<string, Species> treeMap;
    string treeName;
    int total = 0;
    while(true){
      std::cin.getline(tempTreeName, maxSize);
      treeName = tempTreeName;
      if(!(treeName.size() > 0)){
        break;
      }
      if(treeMap[treeName].amount == 0){
        treeMap[treeName].name = treeName;
      }
      treeMap[treeName].increase();
      total++;
    }
    vector<string> treeList;
    for(auto const& sp : treeMap){
      treeList.push_back(sp.second.name);
    }
    sort(treeList.begin(), treeList.end());
    for(string name : treeList){
      cout << name << " " << setprecision(4) << treeMap[name].getPercent(total) << "\n";
    }
    if(cases > 1){ cout << "\n";}
    cases--;

  }
  return 0;
}
