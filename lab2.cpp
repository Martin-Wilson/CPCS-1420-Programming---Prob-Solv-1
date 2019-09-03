// Martin Wilson
// lab2.cpp
// a program that asks the user for basic input


#include <iostream>

using namespace std;

int main()
{
  int itemNum;
  string item;
  
  //prompt
  cout << endl << "Hello and welcome to my input output program!!" << endl
       << "Enter in a number followed by an item that you want: ";
  cin >> itemNum >> item;

  cout << endl << endl << "If you give me your credit card I will get you "
       << itemNum << " " << item << "." << endl << endl;
  
  return 0;
}
