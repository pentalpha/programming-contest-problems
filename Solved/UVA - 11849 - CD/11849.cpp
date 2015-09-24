#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[]) {
  while(true){
    int n1, n2;
    cin >> n1 >> n2;
    if(n1 == 0 || n2 == 0){
      break;
    }
    deque<int> cdsJack, cdsJill;
    for(int i = 1; i <= n1; i++){
      int x;
      cin >> x;
      cdsJack.push_front(x);
    }
    for(int i = 1; i <= n2; i++){
      int x;
      cin >> x;
      cdsJill.push_front(x);
    }
    int nEquals = 0;
    while(cdsJill.size() > 0 && cdsJack.size() > 0){
      if(cdsJill.back() == cdsJack.back()){
        nEquals++;
        cdsJack.pop_back();
        cdsJill.pop_back();
      }else if(cdsJill.back() > cdsJack.back()){
        cdsJack.pop_back();
      }else{
        cdsJill.pop_back();
      }
    }
    cout << nEquals << "\n";
  }
  return 0;
}
