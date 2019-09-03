//Martin Wilson
//lab10.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

float sum(const float a[],int numElements);
//IN: an array of floats and an integer that should be the number
//of the elements within the array
//MODIFY: it adds all the elements of the array together
//OUT: returns the sum of all the elements

void printer(const float a[],int numElements);
//IN: an array of floats and an integer that should be the number of
//the elements within the array
//OUT prints the elements of the array with their respective indexs

const string FNAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
const int SIZE = 50;
const int WIDTH = 8;
const int PRECISION = 3;
const int COL = 3;

int main()
{
  
  int aSize = 0;
  float list[SIZE] = {0};

  ifstream infile;
  
  infile.open(FNAME.c_str());
  if(infile.fail()){
    cout << "Error with file ";
    cin.get();
    return 0;
  }

  while(infile >> list[aSize]){
   
    aSize++;
  }

  infile.close();

  cout << endl << endl;
  
  printer(list, aSize);
  cout << endl << "This is the total: " << sum(list, aSize) << endl
       << endl;

  return 0;
} 

float sum(const float a[],int numElements)
{
  int sum = 0;
  
  for(int i = 0; i < numElements; i++){
    sum += a[i];
  }
  return sum;

}

void printer(const float a[], int numElements)
{

  cout << setw(WIDTH) << left << "Index     " << setw(WIDTH)
       << left << "Value   " << endl;


  for(int i = 0; i < numElements; i++){

    cout << setw(COL) << left << i << "       " << fixed
         << setprecision(PRECISION) << setw(WIDTH)
         << a[i] << endl;
  }

}
