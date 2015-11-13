#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  /* code */
  int heads, knights;
  while(true){
    cin >> heads >> knights;
    string doomed = "Loowater is doomed!";
    if(heads == 0 && knights == 0){
      break;
    }
    int headsSum = 0;
    deque<int> diameters;
    int temp;
    for(int i = 1; i <= heads; i++){
      cin >> temp;
      headsSum += temp;
      diameters.push_back(temp);
    }
    int knightsSum = 0;
    deque<int> heights;
    for(int i = 1; i <= knights; i++){
      cin >> temp;
      knightsSum += temp;
      heights.push_back(temp);
    }

    if(heads > knights){
      cout << doomed << "\n";
    }else{
      sort(heights.begin(), heights.end());
      sort(diameters.begin(), diameters.end());
      /*for(auto x : diameters){
        cout << "#" << x << " ";
      }
      cout << "\n";
      for(auto x : heights){
        cout << "#" << x << " ";
      }
      cout << "\n";*/
      int gold = 0;
      while(!diameters.empty() && !heights.empty())
      {
        if(heights[0] >= diameters[0]){
          gold+=heights[0];
          diameters.pop_front();
          heights.pop_front();
        }else{
          heights.pop_front();
        }
      }
      if(diameters.empty()){
        cout << gold << "\n";
      }else{
        cout << doomed << "\n";
      }
    }
  }
  return 0;
}
