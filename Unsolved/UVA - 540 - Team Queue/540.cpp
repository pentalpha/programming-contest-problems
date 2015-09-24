#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class TeamQueue{
public:
  map<int, int> teamMapping;
  vector<queue<int>> fila;
  TeamQueue(map<int, int> mapping){
    teamMapping = mapping;
  }
  int size(){
    int x = 0;
    for(int a = 0; a < fila.size(); a++){
      x += fila[a].size();
    }
    return x;
  }
  void enqueue(int x){
    int groupOf = teamMapping[x];
    bool inserido = false;
    /*for(queue<int> team : fila){
      if(teamMapping[team.front()] == groupOf){
        inserido = true;
        team.push(x);
        cout << x << " inserido com seus colegas da turminha " << groupOf << "\n";
        break;
      }
    }*/
    for(int i = 0; i < fila.size(); i++){
      if(teamMapping[fila[i].front()] == groupOf){
        inserido = true;
        fila[i].push(x);
        //cout << x << " inserido com seus colegas da turminha " << groupOf << "\n";
        break;
      }
    }
    if(!inserido){
      queue<int> temp;
      temp.push(x);
      fila.push_back(temp);
      //cout << x << " da turminha " << groupOf << " foi inserido sozinho no final da fila\n";
    }
    //cout << "Agora ha " << size() << " elementos\n";
  }
  int dequeue(){
    if(!fila.empty()){
      if(!fila.front().empty()){
        int temp = fila.front().front();
        fila.front().pop();
        if(fila.front().empty()){
          fila.erase(fila.begin());
        }
        //cout << "Agora ha " << size() << " elementos\n";
        return temp;
      }else{
        //cout << "Agora ha " << size() << " elementos\n";
        return -1;
      }
    }else{
      //cout << "Agora ha " << size() << " elementos\n";
      return 0;
    }
  }
};

int main(int argc, char const *argv[]) {
  int nGroups;
  int scenario = 1;
  while(cin >> nGroups){
    if(nGroups == 0){
      break;
    }
    map<int, int> mapping;
    for(int i = 1; i <= nGroups; i++){
      int nElements;
      cin >> nElements;
      for(int j = 1; j <= nElements; j++){
        int element;
        cin >> element;
        mapping.insert(pair<int, int>(element, i));
      }
    }
    TeamQueue filaTimes(mapping);
    cout << "Scenario #" << scenario << "\n";
    string command;
    while(cin >> command){
      if(command == "STOP"){
        break;
      }else if(command == "ENQUEUE"){
        int number;
        cin >> number;
        filaTimes.enqueue(number);
      }else if (command == "DEQUEUE"){
        cout << filaTimes.dequeue() << "\n";
      }
    }
    cout << "\n";
  }
  return 0;
}
