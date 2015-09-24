#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool anagram(string a, string b){
  if(a.size() != b.size()){
    return false;
  }else if(a == b){
    return false;
  }else{
    transform(a.begin(), a.end(), a.begin(), ::tolower);
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    map<char, int> chars;
    for(int i = 0; i < a.size(); i++){
      chars.insert(pair<char, int>(a[i], 0));
    }
    pair<map<char,int>::iterator,bool> ret;
    for(int i = 0; i < b.size(); i++){
      ret = chars.insert(pair<char, int>(b[i], 0));
      if(ret.second == true){
        return false;
      }
    }
    //if(chars2.size() != chars.size()){
    //  return false;
    //}
    for(int i = 0; i < a.size(); i++){
      chars[a[i]]++;
    }
    for(int i = 0; i < b.size(); i++){
      chars[b[i]]++;
    }
    for(auto x : chars){
      if(x.second % 2 != 0){
        return false;
      }
    }
  }
  return true;
}

int main(int argc, char const *argv[]) {
  deque<string> words;
  deque<string> ananagrams;
  while(true){
    string word;
    cin >> word;
    if(word == "#"){
      break;
    }
    words.push_front(word);
  }
  for(string word : words){
    bool haveAnagram = false;
    for(string word2 : words){
      if(anagram(word, word2)){
        haveAnagram = true;
        break;
      }
    }
    if (!haveAnagram){
      ananagrams.push_front(word);
    }
  }
  sort(ananagrams.begin(), ananagrams.end());
  for(string x : ananagrams){
    cout << x << "\n";
  }
  return 0;
}
