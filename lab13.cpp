//Martin Wilson
//lab13.cpp

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Person{

  string name;
  int age;
  int coffee;
};

void printOne(Person their);

int findTheOldPerson(const Person arr[], int count);
//returns the index of the oldest person

int findTheLeastDrinker(const Person arr[], int count);
//returns the index of the person who drinks the least amount of coffee

void sortByName(Person arr[], int count);

void swapVal(Person& a, Person& b);

const string FNAME = "/home/fac/sreeder/class/cs1420/lab13input.dat";
const int MAX = 150;

int main()
{

  Person arr[MAX];
  
  ifstream infile;

  int count = 0;
  int oldie;
  int noCoffee;
  
  infile.open(FNAME.c_str());

  if(infile.fail()){
    cout << "File error press enter to exit program... ";
    cin.get();
      return 0;
  }

  while(count < MAX && infile >> arr[count].name){
    infile >> arr[count].age >> arr[count].coffee;
    infile.ignore();
    count++;
  }

  infile.close();


  cout << "Oldest: ";
  oldie = findTheOldPerson(arr, count);
  printOne(arr[oldie]);

  cout << endl << "No Coffee: ";
  noCoffee = findTheLeastDrinker(arr, count);
  printOne(arr[noCoffee]);

  cout << endl << endl << "Start of list";
  for(int i = 0; i < count; i++){
    printOne(arr[i]);
  }

  sortByName(arr, count);

  cout << endl << endl << "Start of sorted";
  for(int i = 0; i < count; i++){
    printOne(arr[i]);
  }


  cout << endl;
  
  return 0;
}

void printOne(Person their){

  cout << endl << "Name:" << their.name << "  " << "Age:" << their.age
       << "  " << "Coffee Amount:" << their.coffee << endl;
}

int findTheOldPerson(const Person arr[], int count){

  int oldestIndex = 0;
  
  for(int i = 1; i < count; i++){
    if(arr[i].age > arr[oldestIndex].age)
      oldestIndex = i;
  }

  return oldestIndex;
}

int findTheLeastDrinker(const Person arr[], int count){

  int leastCoffee = 0;

  for(int i = 1; i < count; i++){
    if(arr[i].coffee < arr[leastCoffee].coffee)
      leastCoffee = i;
  }

  return leastCoffee;
  
}

void sortByName(Person arr[],int count){

  int index;

  for(int i = 0; i < count; i++){
    index = i;

    for(int j = i+1; j < count; j++){
      if(arr[j].name < arr[index].name)
        index = j;
    }

    swapVal(arr[index], arr[i]);
  }
}

void swapVal(Person& a, Person& b){

  Person c;
  c = b;
  b = a;
  a = c;
  
}
