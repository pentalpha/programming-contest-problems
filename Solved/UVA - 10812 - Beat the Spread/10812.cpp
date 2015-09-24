#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  while(n > 0){
    int sum, dif;
    cin >> sum >> dif;
    bool possible = false;
    for(int i = sum; i >= dif; i--){
      if((i + i-dif) == sum){
        possible = true;
        cout << i << " " << i-dif << "\n";
        break;
      }
    }
    if(!possible){
      std::cout << "impossible" << std::endl;
    }
    n--;
  }
  return 0;
}
