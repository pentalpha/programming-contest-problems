#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  while(cin >> n){
    if (n == 0){
      break;
    }
    queue<int> originalTrain;
    for(int i = 1; i <= n; i++){
      originalTrain.push(i);
    }

    while(true){
      queue<int> train(originalTrain);
      int a;
      cin >> a;
      if(a == 0){
        cout << "\n";
        break;
      }
      queue<int> outOrder;
      outOrder.push(a);
      for(int i = 2; i <= n; i++){
        cin >> a;
        outOrder.push(a);
      }
      stack<int> station;
      bool allRight = true;
      while(!outOrder.empty()){
        bool transferido = false;
        if(!train.empty()){
          if(outOrder.front() == train.front()){
            //cout << "Vagão " << train.front() << " vai direto\n";
            outOrder.pop();
            //int temp = train.front();
            train.pop();
            transferido = true;
          }
        }else if(!station.empty()){
          if(station.top() == outOrder.front()){
            //cout << "Vagão " << station.top() << " sai da estação\n";
            outOrder.pop();
            //int temp = station.top();
            station.pop();
            transferido = true;
          }
        }

        if(!transferido){
          if(!train.empty()){
            //cout << "Vagão " << train.front() << " vai para a estação\n";
            int temp = train.front();
            train.pop();
            station.push(temp);
          }else{
            //cout << "Erro, sem mais opções\n";
            allRight = false;
            break;
          }
        }

        /*}else if(!train.empty()){
          cout << "Vagão " << train.front() << " vai para a estação\n";
          int temp = train.front();
          train.pop();
          station.push(temp);

        }else if(train.empty()
        && station.top() != outOrder.front()){
          cout << "Erro, sem mais opções\n";
          allRight = false;
          break;
        }*/
      }
      if(allRight){
        cout << "Yes\n";
      }else{
        cout << "No\n";
      }
    }
  }
  return 0;
}
