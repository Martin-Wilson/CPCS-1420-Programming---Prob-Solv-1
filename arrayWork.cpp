#include <iostream>

using namespace std;

void printer(int arr1[]);

int main(){

  int arr[10] = {0};


  
  return 0;
}

void printer(int arr1[]){

  for(int i = 0; i < 10; i ++)
    cout << endl << arr1[i];
  
}
