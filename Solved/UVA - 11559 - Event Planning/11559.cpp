#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
   int participants, budget, nHotels, nWeeks;
   while(cin >> participants >> budget >> nHotels >> nWeeks){
      bool hotelAdequated[nHotels];
      int hotelPrice[nHotels];

      for(int i = 0; i < nHotels; i++){
         cin >> hotelPrice[i];
         hotelPrice[i] = hotelPrice[i] * participants;
         bool adequatedPrice = (hotelPrice[i] <= budget);
         bool adequatedBedNumber = false;
         for(int j = 0; j < nWeeks; j++){
            int bedsNumber;
            cin >> bedsNumber;
            if(bedsNumber >= participants){
               adequatedBedNumber = true;
            }
         }

         hotelAdequated[i] = (adequatedPrice && adequatedBedNumber);
      }

      int minPrice = 0;
      for(int i = 0; i < nHotels; i++){
         if(hotelAdequated[i]){
            if(hotelPrice[i] < minPrice || minPrice == 0){
               minPrice = hotelPrice[i];
            }
         }
      }

      bool atLeastOne = false;
      for(int i = 0; i < nHotels; i++){
         if(hotelAdequated[i]){
            atLeastOne = true;
         }
      }

      if(atLeastOne){
         cout << minPrice << "\n";
      }else{
         cout << "stay home\n";
      }
   }
   return 0;
}
