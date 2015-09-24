
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[]) {
  while(true){
    int cases;
    string textline;
    getline(cin, textline);
    stringstream stream(textline);
    stream >> cases;
    //cout << cases;
    if(cases == 0){
      break;
    }
    map<string, int> options;
    for(int nCase = 1; nCase <= cases; nCase++){
      deque<string> courses;
      getline(cin, textline);
      stringstream stream(textline);
      string course;
      while(stream >> course){
        courses.push_front(course);
      }
      sort(courses.begin(), courses.end());
      string option = "";
      for(string a : courses){
        option = option + " " + a;
      }
      pair<map<string,int>::iterator,bool> ret = options.insert(pair<string, int>(option, 1));
      if(ret.second == false){
        options[option]++;
      }

    }
    int maximum = 0;
    for(auto x : options){
      //cout << "\n" << x.first << "\n";
      if(x.second > maximum){
        maximum = x.second;
      }
    }
    //cout << maximum;
    int result = 0;
    for(auto x : options){
      if(x.second == maximum){
        result += maximum;
      }
    }
    cout << result << "\n";
  }


  return 0;
}
