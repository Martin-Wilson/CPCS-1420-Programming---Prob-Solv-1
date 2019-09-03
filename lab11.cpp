//Martin Wilson
//lab11.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//returns an index for a string in an array 
int searchString(const string arr[], string target, int arrSize);

const string FNAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";
const int SIZE = 75;
const char YES = 'y';

int main()
{
  string arr[SIZE];
  string searchThis;
  int lastIndex = 0;
  int index;
  char ans = 'y';
  
  ifstream infile;

  infile.open(FNAME.c_str());

  if(infile.fail()){
    cout << endl << "File error";
    cin.get();
    return 0;
  }

  while(infile >> arr[lastIndex]){
    lastIndex++;
  }
  
  
  infile.close();

  while(tolower(ans) == YES){
    
    cout << endl << "Input a string to search for. ";
    cin >> searchThis;
    
    index = searchString(arr, searchThis, lastIndex);
    
    if(index >= 0){
      cout << endl << endl
           << index << ". " << arr[index]
           << " is in the list of strings." << endl;
    } else {
      cout << endl << endl << "There was no string in the array." << endl;
    }
    cout << "Again(y/n)? ";
    cin >> ans;
  }

  cout << "Thanks for stopping by!!" << endl << endl;
  
  return 0;
}


int searchString(const string arr[], string target, int lastIndex)
{
  int index = 0;

  while((index < lastIndex) && (arr[index] != target)){
    index++;
  }

  if(index < lastIndex)
      return index;
    else
      return -1;
  
}
