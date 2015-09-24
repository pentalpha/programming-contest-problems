#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  while(cin >> n){
    if(n == 0){
      break;
    }
    deque<int> cards;
    for(int i = 1; i <= n; i++){
      cards.push_back(i);
    }
    cout << "Discarded cards: ";
    int temp;
    while(cards.size() > 1){
      temp = cards.front();
      cards.pop_front();
      cout << temp;
      if(cards.size() > 1){
        cout << ", ";
      }
      temp = cards.front();
      cards.pop_front();
      cards.push_back(temp);
    }
    cout << "\nRemaining card: " << cards.front() << "\n";
  }
  return 0;
}
