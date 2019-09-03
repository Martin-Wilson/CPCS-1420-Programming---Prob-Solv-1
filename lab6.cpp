//Martin Wilson
//lab6.cpp
//Summation machine

#include <iostream>
#include <cctype>

using namespace std;

const char YES = 'y';
const int MIN = 0;

int main(){

  int num = -1;
  int sum = 0;
  char ans;
  
  cout << endl << "Would you like to compute a sum(y/n)? ";
  cin >> ans;
  
  while(tolower(ans)== YES){
  
    while(num <= MIN){
      cout << endl << endl << "Input a integer greater than " << MIN << ": ";
      cin >> num;
    }
    
    for(int i = 1; i <= num; i++)
      sum = sum + i;

    cout << endl << "The sum of the numbers from 1 to " << num << " is "
         << sum << "." << endl << endl << endl
         << "Would you like to play again(y/n)? ";
    cin >> ans;

    num = MIN;  
    sum = 0;
  
  }

  cout << endl << "Thanks for stopping by!!" << endl << endl; 

  return 0;
}
