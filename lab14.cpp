//Martin Wilson
//lab14.cpp

#include<iostream>
#include<iomanip>

using namespace std;

const int CSIZE = 4;
const int RSIZE = 5;
const int MIN = 0;
const int WIDTH = 3;
const int VMAX = 999;
const int VMIN = -999;
const char YES = 'y';

void printer(int list[][CSIZE]);

int main()
{
  char ans = 'y';
  int row = -1;
  int col = -1;
  int val = 1001;
  int total = 0;
  int list[RSIZE][CSIZE] = {0};

  cout << endl << endl;
  printer(list);
  
  while(tolower(ans) == YES){
    while(row > RSIZE-1 || row < MIN){
      cout << endl << "Please input a row number(" << MIN << " - "
           << RSIZE - 1 << "): ";
      cin >> row;
    }
    while(col>CSIZE-1 || col < MIN){
      cout << endl << "Please input a column number(" << MIN << " - "
           << CSIZE - 1 << "): ";
      cin >> col;
    }
    while(val > VMAX || val < VMIN){
      cout << endl << "Input an integer with three digits or less to put into"
           << "that cell: ";
      cin >> val;
    }
    
    list[row][col] = val;
    printer(list);
    cout << "Row: " << row << " Column: " << col <<  " Value: " << val << endl;
    cout << endl << "Would you like to input another number?(y/n) ";
    cin >> ans;
    
    row = -1;
    col = -1;
    val = 1001;
  }

  for(int i = 0; i < RSIZE; i++){
    for(int j = 0; j < CSIZE; j++){
      total += list[i][j];
    }
  }

  cout << endl << "The total for all the elements in the array is "
       << total << endl;
  
  return 0;
}

void printer(int list[][CSIZE])
{
  cout << endl << "         Columns" << endl <<"Rows";
  for(int i = 0; i < CSIZE; i++)
    cout << "  " << i << ". ";
  cout << endl;
  for(int i = 0; i < RSIZE; i++){
    cout << i << ".  ";
    for(int j = 0;j < CSIZE; j++){
      cout << setw(WIDTH) << list[i][j] << "  ";
    }
    cout << endl;
  }
}
