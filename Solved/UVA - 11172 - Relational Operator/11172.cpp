#include <fstream>
#include <iostream>

using namespace std;

int main(){

   //ifstream file;
   //ofstream fileOut;
   //file.open("sample.in");
   //fileOut.open("minhaSaida.out");
   int nLines;
   cin >> nLines;
   while(nLines > 0){
         int a;
         cin >> a;
         int b;
         cin >> b;

         if(a < b){
            cout << "<\n";
         }else if (a > b){
            cout << ">\n";
         }else{
            cout << "=\n";
         }
         nLines--;
   }

   //file.close();
   //fileOut.close();

   return 0;
}
