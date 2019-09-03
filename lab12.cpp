//Martin Wilson
//lab12.cpp

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 25;
const int COL  = 11;

void sort(int arr[], int numE);

void swap(int& valA, int& valB);

int main ()
{
  unsigned seed = time(0);
  srand(seed);
  
  int ans = -1;
  int numbers[SIZE] = {0};

  while(ans < 1 || ans > SIZE){
    cout << "How many elements should be filled(1-25)? ";
    cin >> ans;
  }

  for(int i = 0; i < ans; i++)
    numbers[i] = rand();

  for(int i = 0; i < ans; i++)
    cout << endl << i << ". " << setw(COL) << numbers[i];

  sort(numbers, ans);

  cout << endl;
  
  for(int i = 0; i < ans; i++)
    cout << endl << i << ". " << setw(COL) << numbers[i];

  cout << endl;
  
  return 0;
}

void sort(int arr[], int numE)
{
  int index;
  
  for(int i = 0; i < numE; i++){
    index = i;
    for(int j = i+1; j < numE; j++){
      if(arr[j] < arr[index])
        index = j;
    }
    swap(arr[index], arr[i]);
  }

}

void swap(int& valA, int& valB)
{
  int temp = valA;
  valA = valB;
  valB = temp;
}
