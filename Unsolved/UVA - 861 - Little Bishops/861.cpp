#include <iostream>
#include <set>
#include <algorithm>
#include <deque>

using namespace std;

int positive(int x){
  if(x > 0){
    return x;
  }else{
    return -x;
  }
}

bool conflictBishops(pair<int, int> a, pair<int, int> b){
  pair<int, int> diff(positive(b.first - a.first), positive(b.second - a.second));
  return (diff.first == diff.second);
}

void bishopsRec(int n, int nBishops, int maxBishops, pair<int,int> *bishops, set<deque<pair<int, int>>> &comb){
  //int sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      pair<int, int> testPos(i, j);
      bool valid = true;
      for(int x = 0; x < nBishops; x++){
        if(conflictBishops(bishops[x], testPos)){
          valid = false;
          break;
        }
      }
      if(valid){
        nBishops++;
        bishops[nBishops-1] = pair<int, int>(i, j);
        if(nBishops == maxBishops){
          deque<pair<int, int>> newComb;
          for(int x = 0; x < maxBishops; x++){
            newComb.push_back(bishops[x]);
          }
          sort(newComb.begin(), newComb.begin());
          comb.insert(newComb);
          //sum++;
          /*for(int x = 0; x < maxBishops; x++){
            cout << "[" << bishops[x].first << "][" << bishops[x].second << "] ";
          }
          cout << "\n";*/
        }else{
          bishopsRec(n, nBishops, maxBishops, bishops, comb);
        }
        nBishops--;
      }
    }
  }

}

int main(int argc, char const *argv[]) {
  int n, k;
  while(cin >> n >> k){
    if(n == 0 && k == 0){
      break;
    }
    /*for(int x = 1; x <= 10; x++){
      for(int y = 1; y <= 10; y++){
        if(conflictBishops(pair<int, int>(x, y), pair<int, int>(n, k))){
          cout << "1 ";
        }else{
          cout << "0 ";
        }
      }
      cout << "\n";
    }*/
    pair<int, int> bishops[k];
    set<deque<pair<int, int>>> comb;
    bishopsRec(n, 0, k, bishops, comb);
    cout << comb.size() << "\n";
  }
  return 0;
}
