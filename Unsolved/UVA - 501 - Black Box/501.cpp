#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Blackbox{
public:
  int i;
  std::vector<int> data;
  Blackbox(int x){
    //data = vector<int>(x+1);
    i = 0;
  }
  void add(int x){
    data.push_back(x);
    sort(data.begin(), data.end());
  }
  int get(){
    i++;
    return data[i-1];
  }
};

int main(int argc, char const *argv[]) {
  int cases;
  cin >> cases;
  while(cases >= 0){
    int m, n;
    cin >> m >> n;
    Blackbox blackbox(m);
    deque<int> toAdd, operations;
    int x;
    for(int i = 1; i <= m; i++){
      cin >> x;
      toAdd.push_front(x);
    }
    for(int i = 1; i <= n; i++){
      cin >> x;
      operations.push_front(x);
    }

    while(!(toAdd.empty())){
      x = toAdd.back();
      toAdd.pop_back();
      blackbox.add(x);
      if(operations.back() == blackbox.data.size()){
        operations.pop_back();
        cout << blackbox.get() << "\n";
      }
    }

    cases--;
    if(cases > 0){
      cout << "\n";
    }
  }
  return 0;
}
