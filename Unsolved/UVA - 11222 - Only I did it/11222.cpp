#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <deque>
#include <algorithm>

using namespace std;
pair<int, int> max(pair<int, int> a, pair<int, int> b){
  if(a.second > b.second){
    return a;
  }else{
    return b;
  }
}
pair<int, int> max(pair<int, int> a, pair<int, int> b, pair<int, int> c){
  return max(max(a, b), c);
}

int main(int argc, char const *argv[]) {
  int cases;
  string casesLine;
  getline(cin, casesLine);
  stringstream casesStream(casesLine);
  casesStream >> cases;
  //cout << cases;
  for(int nCase = 1; nCase <= cases; nCase++){
    //map<int, int> problems;
    //map<int, string> problemsByFriend[3];
    int solvedProblems[3] = {0, 0, 0};
    deque<int> solvedProblemsList[3];
    bool problems[3][10001];

    for(int i = 0; i <= 2; i++){
      for(int j = 0; j < 10001; j++){
        problems[i][j] = false;
      }
    }

    for(int i = 0; i <= 2; i++){
      string input;
      getline(cin, input);
      stringstream stream(input);
      int x;
      stream >> x;
      while(stream >> x){
        problems[i][x] = true;
        //solvedProblemsList[i].push_back(x);
      }
    }
    for(int j = 0; j < 10001; j++){
      if(problems[0][j] == true && problems[1][j] == false && problems[2][j] == false){
        solvedProblems[0]++;
        solvedProblemsList[0].push_back(j);
      }else if(problems[0][j] == false && problems[1][j] == true && problems[2][j] == false){
        solvedProblems[1]++;
        solvedProblemsList[1].push_back(j);
      }else if(problems[0][j] == false && problems[1][j] == false && problems[2][j] == true){
        solvedProblems[2]++;
        solvedProblemsList[2].push_back(j);
      }
      //problems[i][j] = false;
    }
    /*for(int i = 0; i <= 2; i++){
      string input;
      getline(cin, input);
      stringstream stream(input);
      int x;
      stream >> x;
      while(stream >> x){
        problemsByFriend[i][x] = "solved";
      }
    }
    for(int i = 0; i <= 2; i++){
      for(auto x : problemsByFriend[i]){
        problems[x.first] = 0;
      }
    }
    for(int i = 0; i <= 2; i++){
      for(auto x : problemsByFriend[i]){
        problems[x.first]++;
      }
    }
    for(auto x : problems){
      if(x.second == 1){
        for(int i = 0; i <= 2; i++){
          if(problemsByFriend[i][x.first] == "solved"){
            solvedProblems[i]++;
            solvedProblemsList[i].push_back(x.first);
          }
        }
      }
    }

    /*for(auto x : problems){
      //if(x.second == 1){
        for(int i = 0; i <= 2; i++){
          if(problemsByFriend[i][x.first] == "solved"){
            //solvedProblems[i]++;
            solvedProblemsList[i].push_back(x.first);
          }
        }
      //}
    }*/
    pair<int, int> top = max(pair<int, int>(0, solvedProblems[0]),
                            pair<int, int>(1, solvedProblems[1]),
                            pair<int, int>(2, solvedProblems[2]));
    cout << "Case #" << nCase /*<< " " << top.first << " " << top.second */<< ":\n";
    for(int i = 0; i <= 2; i++){
      if(solvedProblems[i] == top.second){
        sort(solvedProblemsList[i].begin(), solvedProblemsList[i].end());
        cout << i+1 << " " << solvedProblemsList[i].size() << " ";
        int j = 1;
        for(auto x : solvedProblemsList[i]){
           cout << x;
           if(!(j == solvedProblemsList[i].size())){
             cout << " ";
           }
           j++;
        }
        /*if(!((nCase == cases) && (i == 2))){*/cout << "\n";/*}*/
      }


    }

  }
  return 0;
}
