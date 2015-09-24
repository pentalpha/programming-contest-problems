#include <iostream>
#include <string>

using namespace std;

/* LIMITE DE TEMPO*/
int main(int argc, char const *argv[]) {
   int i = 1;
   int cases;
   string sequence;
   int x, y;

   while(cin >> sequence){
      int info[sequence.size()];
      int p = 0;
      while(p < sequence.size()){
        int equalsUntil = p;

        while(sequence[p] == sequence[equalsUntil+1]
              && equalsUntil+1 < sequence.size()){
          equalsUntil++;
        }

        int totalEquals = equalsUntil - p;

        for(int j = p; j <= equalsUntil; j++){
          info[j] = totalEquals;
          totalEquals--;
        }

        p = equalsUntil+1;
      }
      cout << "Case " << i << ":\n";
      //cout << sequence << "\n";
      //for(int j = 0; j < sequence.size(); j++){
      //  cout << info[j];
      //}
      //cout << "\n";
      cin >> cases;
      while(cases > 0){
         cin >> x >> y;
         if(y < x){
           int aux = x;
           x = y;
           y = aux;
         }
         bool equals = true;

         int totalEquals = y - x;

         if(info[x] >= totalEquals){
           equals = true;
         }else{
           equals = false;
         }
         /*for(int i = x; i < y; i++){
            if(sequence[i] != sequence[i+1]){
               equals = false;
               break;
            }
         }*/
         if(equals){
            cout << "Yes\n";
         }else{
            cout << "No\n";
         }
         cases--;
      }
      i++;
   }

   return 0;
}

/* RESPOSTA ERRADA (?):
int main(int argc, char const *argv[]) {
   int i = 1;
   int cases;
   char sequence[1000000];
   int x, y;

   while(cin >> sequence){
      cout << "Case " << i << ":\n";
      //cout << sequence << "\n";
      cin >> cases;
      while(cases > 0){
         cin >> x >> y;
         bool equals = true;
         for(int i = x; i < y; i++){
            if(sequence[i] != sequence[i+1]){
               equals = false;
               break;
            }
         }
         if(equals){
            cout << "Yes\n";
         }else{
            cout << "No\n";
         }
         cases--;
      }
      i++;
   }

   return 0;
}*/
