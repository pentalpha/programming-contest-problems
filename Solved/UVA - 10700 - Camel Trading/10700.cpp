#include <iostream>
#include <string>
#include <deque>
#include <climits>

using namespace std;

string resolveOperator(string expression, int i){
  int aBegin, aEnd, bBegin, bEnd;
  aEnd = aBegin = i-1;
  bEnd = bBegin = i+1;
  while(aBegin > 0){
    if(expression[aBegin] == '+' || expression[aBegin] == '*'){
      aBegin++;
      break;
    }
    aBegin--;
  }
  while(bEnd < expression.size()-1){
    if(expression[bEnd] == '+' || expression[bEnd] == '*'){
      bEnd--;
      break;
    }
    bEnd++;
  }
  long double a = stod(expression.substr(aBegin, aEnd - aBegin + 1));
  long double b = stod(expression.substr(bBegin, bEnd - bBegin + 1));
  long double result;
  if(expression[i] == '+'){
    result = a + b;
  }else{
    result = a * b;
  }
  expression.replace(aBegin, bEnd-aBegin + 1, to_string(result));
  return expression;
}

void getMinAndMax(string &expression, int &min, int &max){
  deque<int> operators;
  for(int i = 0; i < expression.size(); i++){
    if(expression[i] == '+' || expression[i] == '*'){
      operators.push_back(i);
    }
  }
  if(operators.size() == 0){
    int result = stoi(expression);
    if(result < min){
      min = result;
    }
    if(result > max){
      max = result;
    }
  }else{
    for(int i : operators){
      string newExpression = resolveOperator(expression, i);
      getMinAndMax(newExpression, min, max);
    }
  }
}

void resolveOperator(string &expression, char c){
  while(true){
    int op = -1;
    for(int i = 0; i < expression.size(); i++){
      if(expression[i] == c){
        op = i;
        break;
      }
    }
    if(op == -1){
      break;
    }else{
      expression = resolveOperator(expression, op);
    }
  }
}

long double getMax(string expression){
  resolveOperator(expression, '+');
  resolveOperator(expression, '*');
  return stod(expression);
}
long double getMin(string expression){
  resolveOperator(expression, '*');
  resolveOperator(expression, '+');
  return stod(expression);
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  for(int a = 1; a <= n; a++){
    string expression;
    //int max = 0, min = INT_MAX;
    //for(int i = 1; i <= 11; i++){
    //  min = min * 20;
    //}
    //cout << min << "\n";
    cin >> expression;
    //getMinAndMax(expression, min, max);
    cout << "The maximum and minimum are " << (long unsigned int)getMax(expression) << " and " << (long unsigned int)getMin(expression) << ".\n";
    /*for(int  i = 0; i < expression.size(); i++){
      if(expression[i] == '+' || expression[i] == '*'){
        cout << resolveOperator(expression, i) << "\n";
      }
    }*/
  }
  return 0;
}
