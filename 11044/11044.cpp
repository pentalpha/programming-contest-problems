#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
   int x, y;
   int cases;
   cin >> cases;
   while(cases > 0){
      cin >> x >> y;

      cout << (((int)x/3) * ((int)y/3)) << "\n";

      cases--;
   }
   return 0;
}
