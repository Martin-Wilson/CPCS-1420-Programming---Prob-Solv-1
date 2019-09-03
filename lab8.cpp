//Martin Wilson
//lab8.cpp

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void input(string& first, string& second);
//asks the user for two strings and returns them to main

void swapStr(string& first, string& second); // switches the values of the strings

void output(string first, string second); // outputs both strings with a space between

int main()
{

  string str1;
  string str2;
   
  input(str1, str2);
  
  output(str1, str2);
  
  swapStr(str1, str2);

  output(str1, str2);

  
  return 0;
}

void input(string& first, string& second)
{
  
  cout << endl << endl << "Input a string: ";
  cin >> first;
  cout << endl << "Another one: ";
  cin >> second;
}

void swapStr(string& first, string& second)
{
  string temp = first;
  first = second;
  second = temp;
  
}

void output(string first, string second)
{
  cout << endl << first << " " << second << "." << endl << endl;
}
