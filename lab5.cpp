//Martin Wilson
//lab5.cpp


#include <iostream>
#include <iomanip>

using namespace std;


const int MIN = 1;
const int MAX = 9;
const char SPACE = ' ';

int main(){

  int num = 0;

  cout << endl;
  while(num < MIN || num > MAX){
    cout << "Hello, input a number(" << MIN << " - " << MAX << "): ";
    cin >> num;
  }

  cout << endl;

  //simple 1 line print
  for(int i = 0; i < num; i++){
    cout << num;
  }

  cout << endl << endl;

  //x line print of 1
  for(int i = 0; i < num; i++)
    cout << 1 << endl;

  cout << endl << SPACE << endl << SPACE << SPACE;

  
  for(int i = 1; i <= num; i++)

    cout << SPACE << SPACE << setw(1) << i;

  cout << endl;
  
  for(int i = 1; i <= num; i++){
    cout << i << SPACE;
    for(int j = 1; j <= num; j++)
      cout << setw(3) << i*j;
    cout << endl;
  }
  cout << endl;
  
  for(int i = 1; i <=  num; i++){
    for(int j = 0; j < i; j++)
      cout << i << SPACE;
    cout << endl;
  }

  cout << endl;

  for(int i = 1; i <= num; i++){
    for(int j = 0; j < i; j++)
      cout << SPACE;
    cout << i << endl;
  }

  for(int i = num - 1; i > 0; i--){
    for(int j = 0 ; j < i; j++)
      cout << SPACE;
    cout << i << endl;
  }
    
  return 0;
}
