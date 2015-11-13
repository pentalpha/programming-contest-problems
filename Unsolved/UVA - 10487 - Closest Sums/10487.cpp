#include <iostream>
#include <vector>

using namespace std;

vector<int> integers;

int difference(int a, int b){
  if(a > b){
    return a - b;
  }else{
    return b - a;
  }
}

void findClosest(int i, pair<int, int> aAndB, int &closest, int x){
  if(aAndB.first != -1 && aAndB.second != -1){
    int actualTotal = aAndB.first + aAndB.second;
    if(difference(x, actualTotal) < difference(x, closest)){
      closest = actualTotal;
    }
  }else if (i < integers.size()){
    int num = integers[i];
    pair<int, int> aAndB2 = aAndB;
    if(aAndB.first == -1){
      aAndB.first = num;
    }else if(aAndB.second == -1){
      aAndB.second = num;
    }
    findClosest(i+1, aAndB, closest, x);
    findClosest(i+1, aAndB2, closest, x);
  }

}

int main(int argc, char const *argv[]) {
  int actualCase = 1;
  while(true){
    integers.clear();
    int n;
    cin >> n;
    if(n == 0){
      break;
    }
    //deque<int> integers;
    for(int i = 1; i <= n; i++){
      int temp;
      cin >> temp;
      integers.push_back(temp);
    }
    int m;
    cin >> m;
    cout << "Case " << actualCase << ":\n";
    /*for(auto z : integers){
      cout << z << " ";
    }
    cout << "\n";*/
    for(int i = 1; i <= m; i++){
      int query;
      cin >> query;
      int closest;
      pair<int, int> aAndB(-1, -1);
      findClosest(0, aAndB, closest, query);
      cout << "Closest sum to " << query << " is " << closest << ".\n";
    }

    actualCase++;
  }
  return 0;
}
