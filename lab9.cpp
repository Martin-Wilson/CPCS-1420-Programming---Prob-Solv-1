//Juliette Simonds and Martin Wilson
//lab9.cpp

#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

const string FILEN = "/home/fac/sreeder/class/cs1420/lab9input.dat";
const int SIZE = 30;
const int FOUR = 4;

int main()
{
  int evenNum[SIZE] = {0};
  int oddNum[SIZE] = {0};
  int negNum[SIZE] = {0};

  int posEvenPosition = 0;
  int posOddPosition = 0;
  int negPosition = 0;

  int num = 0;

  ifstream infile;

  infile.open(FILEN.c_str());

  if (infile.fail()){
    cout << "file error...press enter";
    cin.get();
    return 0;
  }

  while(infile >> num){
    
    if (num > 0){

      if (num % 2 == 0){
        //pos even
        evenNum[posEvenPosition] = num;
        posEvenPosition++;
      }else {
        //pos odd
        oddNum[posOddPosition] = num;
        posOddPosition++;
      }
    }else if (num < 0){
      //neg
      negNum[negPosition] = num;
      negPosition++;
    }
  }

  infile.close();

  cout << endl << endl << "Even Positive Numbers:" << endl;

  for(int i = 0; i < posEvenPosition; i++)
    cout << setw(FOUR) << i << ' ' << setw(FOUR) << evenNum[i] << endl;

  cout << endl << "Odd Positive Numbers:" << endl;

  for(int i = 0; i < posOddPosition; i++)
    cout << setw(FOUR) << i << ' ' << setw(FOUR) << oddNum[i] << endl;

  cout << endl << "Negative Numbers" << endl;

  for(int i = 0; i < negPosition; i++)
    cout << setw(FOUR) << i << ' ' << setw(FOUR) << negNum[i] << endl;

  cout << endl;

  return 0;

  
}
