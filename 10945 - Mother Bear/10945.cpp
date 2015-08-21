#include <iostream>
#include <string>

using namespace std;

void simplifyPhrase(string &str){
  string newStr = "";
  for(int i = 0; i < str.size(); i++){
    if((int)str[i] >= 97 && (int)str[i] <= 122){
      newStr = newStr + str[i];
    }else if((int)str[i] >= 65 && (int)str[i] <= 90){
      int newChar = (int)str[i] + 32;
      newStr = newStr + (char)newChar;
    }
  }
  str = newStr;
}

int main(int argc, char const *argv[]) {
  string phrase;
  while (true){
    getline(cin, phrase);
    if(phrase == "DONE"){
      break;
    }
    simplifyPhrase(phrase);
    //cout << phrase << "\n";
    int allinverse = true;
    for(int i = 0; i < phrase.size()/2; i++){
      if(phrase[i] != phrase[phrase.size()-1-i]){
        allinverse = false;
        break;
      }
    }
    if(allinverse){
      cout << "You won't be eaten!\n";
    }else{
      cout << "Uh oh..\n";
    }
  }
  return 0;
}
