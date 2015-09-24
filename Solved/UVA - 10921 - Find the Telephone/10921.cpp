#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[]) {
  map<char, char> charToNumber;
  charToNumber['1'] = '1';
  charToNumber['0'] = '0';
  charToNumber['-'] = '-';
  charToNumber['A'] = charToNumber['B'] = charToNumber['C'] = '2';
  charToNumber['D'] = charToNumber['E'] = charToNumber['F'] = '3';
  charToNumber['G'] = charToNumber['H'] = charToNumber['I'] = '4';
  charToNumber['J'] = charToNumber['K'] = charToNumber['L'] = '5';
  charToNumber['M'] = charToNumber['N'] = charToNumber['O'] = '6';
  charToNumber['P'] = charToNumber['Q'] = charToNumber['R'] = charToNumber['S'] = '7';
  charToNumber['T'] = charToNumber['U'] = charToNumber['V'] = '8';
  charToNumber['W'] = charToNumber['X'] = charToNumber['Y'] = charToNumber['Z'] = '9';

  string expression;

  while(cin >> expression){
    for(int i = 0; i < expression.size(); i++){
      char x = expression[i];
      x = charToNumber[x];
      expression[i] = x;
    }
    cout << expression << "\n";
  }
  return 0;
}
