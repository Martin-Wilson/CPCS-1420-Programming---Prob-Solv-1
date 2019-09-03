// Martin Wilson
// lab4.cpp
// a program that asks the user for two ints and finds if ones a factor


#include <iostream>

using namespace std;

const char YES = 'y';


int main()
{
  char ans;
  int firstInt, secondInt, factorOfNums;

  cout << endl << "Hello and welcome to my multiple decider program!!" << endl
       << endl << "Would you like to play (y/n): ";
  cin >> ans;

  while(tolower(ans) == YES){
  
    //prompts for output and input
    cout << endl << endl <<"Enter in the first of two integers: ";
    cin >> firstInt;
    
    cout << "Good, now enter in the second one: ";
    cin >> secondInt;
    
    //if statement checks to see if the inputed variables are multiples
    if((firstInt%secondInt)==0){
      factorOfNums = firstInt/secondInt;
      cout << endl <<"Yes and the other factor is " << factorOfNums << endl
           << endl;
      
    } else
      cout << endl <<"No the second number is not a factor of the first."
           << endl << endl;

    cout << "Would you like to play again (y/n):";
    cin >> ans;
  }

  cout << endl << endl << "Thank you for stopping by!!" << endl << endl;
  
  return 0;
}
