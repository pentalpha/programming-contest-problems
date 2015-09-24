#include <iostream>
#include <string>

using namespace std;

int numberOfBombs(string field[], int x, int y, int lines, int columns){
  int n = 0;

  int startI = x-1;
  if(startI < 0){ startI = 0;}
  int startJ = y-1;
  if(startJ < 0){ startJ = 0;}

  int endI = x+1;
  if(endI >= lines){ endI = lines-1;}
  int endJ = y+1;
  if(endJ >= columns){ endJ = columns-1;}

  for(int i = startI; i <= endI; i++){
    for(int j = startJ; j <= endJ; j++){
      if(field[i][j] == '*'){
        n++;
        //cout << "bomb at " << i << ", " << j << "\n";
      }
    }
  }

  return n;
}

int main(int argc, char const *argv[]) {

  int lines, columns;
  int count = 1;

  while(cin >> lines >> columns){
    if(lines == 0 || columns == 0){
      break;
    }

    string field[lines];
    for(int i = 0; i < lines; i++){
      cin >> field[i];
      //cout << field[i] << "\n";
    }
    if(count != 1){
      cout << "\n";
    }
    cout << "Field #" << count << ":\n";
    for(int i = 0; i < lines; i++){
      for(int j = 0; j < columns; j++){
        if(field[i][j] == '.'){
            cout << numberOfBombs(field, i, j, lines, columns);
        }else{
            cout << '*';
        }
      }
      cout << "\n";
    }

    count++;
  }

  return 0;
}
