#include <iostream>
#include <string>

using namespace std;

void writeInverse(string x){
  for(int i = x.size()-1; i >= 0; i--){
    cout << x[i];
  }
}

int main(int argc, char const *argv[]) {
  int groups;
  string word;
  int length;
  while(true){
    cin >> groups;
    if (groups == 0){
      break;
    }
    cin >> word;
    length = word.size() / groups;
    for(int i = 0; i < groups; i++){
      writeInverse(word.substr(i*length, length));
    }
    cout << "\n";
  }
  return 0;
}
