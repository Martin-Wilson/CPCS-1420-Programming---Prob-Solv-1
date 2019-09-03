//Martin Wilson and Michael Pablo

#include <iostream>
#include <cstdlib>

using namespace std;

void welcome();
void goodbye();
int numReturn();
//asks and returns the input
int summation(int num);
//calculates sum of input value

const int MIN = 5;
const int MAX = 25;
const char YES = 'y';

int main()
{
  char ans = 'y';

  welcome();
  
  while(tolower(ans) == YES){
  
    int num;
   
    num = numReturn();
    cout << endl << endl << summation(num);

    cout << endl << "Again (y/n)? ";
    cin >> ans;
  }

  goodbye();

  return 0;
}

void welcome()
{
  cout << endl << endl << "Hello and Welcome to our program!!" << endl << endl;
}

void goodbye()
{
  cout << endl << endl << "Goodbye, thanks for stopping by!!" << endl << endl;
}

int numReturn()
{
  int num = 4;

  while(num < MIN || num > MAX){

    cout << endl << endl << "Input number(" << MIN << "-" << MAX << ")";
    cin >> num;
        
  }

  return num;
  
}

int summation(int num)
{
  int sum;
  
  for (int i = 1; i <= num; i++){
    sum += i;
  }

  return sum;

}
