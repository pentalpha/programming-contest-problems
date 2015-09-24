#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
   while(true){
      int nInputs;
      cin >> nInputs;
      if(nInputs == 0){
         break;
      }

      int divX, divY;
      cin >> divX >> divY;

      for(int i = 0; i < nInputs; i++){
         int x, y;
         cin >> x >> y;

         if(x == divX || y == divY){
            cout << "divisa\n";
         }else{
            bool north = (y < divY);
            bool west = (x < divX);

            if(north && west){
               cout << "SO\n";
            }else if(north && !west){
               cout << "SE\n";
            }else if(!north && west){
               cout << "NO\n";
            }else{
               cout << "NE\n";
            }
         }
      }
   }
   return 0;
}
