#include <iostream>

using namespace std;

int cycleLenght(int n){
   int i = 1;
   while(n != 1){
      if(n % 2 == 0){
         n = n/2;
      }else{
         n = 3*n + 1;
      }
      i++;
   }
   return i;
}

int maximumClycleLenght(int x, int y){
   if(y < x){
      int aux = x;
      x = y;
      y = aux;
   }

   int n = y - x + 1;
   int lenghts[n];
   int maximum = 0;
   for(int i = x; i <= y; i++){
      lenghts[i-x] = cycleLenght(i);
      if(maximum == 0 || lenghts[i-x] > maximum){
         maximum = lenghts[i-x];
      }
   }
   return maximum;
}

int main(int argc, char const *argv[]) {
   int x, y;

   while(cin >> x >> y){
      cout << x << " " << y << " "
           << maximumClycleLenght(x, y)
           << "\n";
   }

   return 0;
}
