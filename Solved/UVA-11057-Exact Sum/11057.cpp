#include <algorithm>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int modulo(int a){
  if( a < 0){
    a = -a;
  }
  return a;
}

int binSearch(int inicio, int fim,
                vector<int> &v, int ele){
  if (inicio > fim){
    return -1;
  }
  int meio = (inicio + fim) / 2;
  if (v[meio] == ele){
    return meio;
  }else if (v[meio] > ele){
    return binSearch(inicio, meio - 1, v, ele);
  }else{
    return binSearch(meio + 1, fim, v, ele);
  }
}

int main(int argc, char const *argv[]) {
  int nBooks;
  while(cin >> nBooks){
    string textline;

    vector<int> bookPrices;
    for(int i = 0; i < nBooks; i++){
      int temp;
      cin >> temp;
      bookPrices.push_back(temp);
    }

    sort(bookPrices.begin(), bookPrices.end());
    getline(cin, textline);
    int halfNBooks = (int)nBooks/2;

    while(true){
      getline(cin, textline);
      if(textline.size() == 0){
        break;
      }
      int money = stoi(textline);
      int bookA = -1, bookB = -1;
      for(int i = 0; i < nBooks; i++){
        int price = bookPrices[i];
        int j = binSearch(0, bookPrices.size()-1, bookPrices, money-price);
        int priceB = bookPrices[j];
        if(priceB != -1 && priceB != 0 && i != j){
          if((bookA == -1 && bookB == -1) || (modulo(bookA-bookB) > modulo(price-priceB))){
            bookA = price;
            bookB = priceB;
          }
        }
      }
      cout << "Peter should buy books whose prices are " << bookA << " and " << bookB << ".\n\n";
    }
  }
  return 0;
}
