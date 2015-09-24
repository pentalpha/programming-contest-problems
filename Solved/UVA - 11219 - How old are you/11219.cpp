#include <iostream>
#include <string>

using namespace std;

class Date{
public:
  int day, month, year;
  int totalDays;
  Date(){

  }
  Date(int newTotalDays, int newYear){
    totalDays = newTotalDays;
    year = newYear;
    month = dayToMonths(totalDays, year);
    day = totalDays - monthToDays(month, year);
  }

  Date(string str){
    string strDay = "", strMonth = "", strYear = "";
    strDay = strDay + str[0] + str[1];
    strMonth = strMonth + str[3] + str[4];
    strYear = strYear + str[6] + str[7] + str[8] + str[9];
    day = stoi(strDay);
    month = stoi(strMonth);
    year = stoi(strYear);
    totalDays = day;
    totalDays += monthToDays(month, year);
  }

  int monthToDays(int m, int y){
    int totalDays = 0;
    switch (m) {
      case 2:
        totalDays += 31;
        break;
      case 3:
        totalDays += 31*1 + 28;
        break;
      case 4:
        totalDays += 31*2 + 30*0 + 28*1;
        break;
      case 5:
        totalDays += 31*2 + 30*1 + 28*1;
        break;
      case 6:
        totalDays += 31*3 + 30*1 + 28*1;
        break;
      case 7:
        totalDays += 31*3 + 30*2 + 28*1;
        break;
      case 8:
        totalDays += 31*4 + 30*2 + 28*1;
        break;
      case 9:
        totalDays += 31*5 + 30*2 + 28*1;
        break;
      case 10:
        totalDays += 31*5 + 30*3 + 28*1;
        break;
      case 11:
        totalDays += 31*6 + 30*3 + 28*1;
        break;
      case 12:
        totalDays += 31*6 + 30*4 + 28*1;
        break;
      case 13:
        totalDays += 365;
    }
    if (leapYear(y) && m >= 3){
      totalDays++;
    }
    return totalDays;
  }

  static bool leapYear( int year )
  {
  	/* Check if the year is divisible by 4 or
  	is divisible by 400 */
  	if ( (year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0))
  		return true;
  	else
  		return false;
  }

  int dayToMonths(int d, int y){
    for (int i = 12; i >= 0; i--){
      if(d >= monthToDays(i, y)){
        return i;
      }
    }
  }

  Date operator-(const Date &other){
    int resultYear = year - other.year;
    int resultTotalDays = this->totalDays - other.totalDays;
    if(resultTotalDays < 0){
      resultTotalDays = monthToDays(13, resultYear) + resultTotalDays;
      resultYear--;
    }
    Date result(resultTotalDays, resultYear);
    return result;
  }

};

bool operator> (const Date &a, const Date &b){
  if(a.year > b.year){
    return true;
  }else if(a.year == b.year){
    if(a.totalDays > b.totalDays){
      return true;
    }else{
      return false;
    }
  }else{
    return false;
  }
}

bool operator== (const Date &a, const Date &b){
  return (a.year == b.year && a.totalDays == b.totalDays);
}

bool operator<(const Date &a, const Date &b){
  return (!(a > b) && !(a == b));
}

int main(int argc, char const *argv[]) {
  int cases;
  cin >> cases;
  int i = 1;
  while (i <= cases){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    Date date1(str1), date2(str2);
    Date result = date1 - date2;
    cout << "Case #" << i << ": ";
    if(date2 > date1){
      cout << "Invalid birth date\n";
    }else if(date2 == date1){
      cout << "0\n";
    }else{
      Date age = date1 - date2;
      if(age.year > 130){
        cout << "Check birth date\n";
      }else{
        cout << age.year << "\n";
      }
    }
    i++;
  };
  return 0;
}
