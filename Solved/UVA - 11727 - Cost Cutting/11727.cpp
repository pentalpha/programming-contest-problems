#include <iostream>

using namespace std;

int max(int a, int b, int c){
   int maxAB;
   if(a > b){
      maxAB = a;
   }else{
      maxAB = b;
   }

   if(maxAB > c){
      return maxAB;
   }else{
      return c;
   }
}

int min(int a, int b, int c){
   int minAB;
   if(a < b){
      minAB = a;
   }else{
      minAB = b;
   }

   if(minAB < c){
      return minAB;
   }else{
      return c;
   }
}

int main(){
   int nCases;
   int cas;
   cin >> nCases;
   cas = 1;
   while(cas <= nCases){
         int employ[3];
         cin >> employ[0] >> employ[1] >> employ[2];

         int minimum = min(employ[0], employ[1], employ[2]);
         int maximum = max(employ[0], employ[1], employ[2]);

         int res;

         for(int i = 0; i < 3; i++){
            if(employ[i] != minimum && employ[i] != maximum){
               res = i;
            }
         }

         cout << "Case " << cas << ": " << employ[res] << "\n";

         cas++;
   }

   return 0;
}
