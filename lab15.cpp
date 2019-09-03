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

int findAPerson(const Person arr[], string target, int count);

void sortByName(Person arr[], int count);

void swapVal(Person& a, Person& b);

const string FNAME = "/home/fac/sreeder/class/cs1420/lab13input.dat";
const int MAX = 150;

int main()
{

  Person arr[MAX];
  
  ifstream infile;

  string target;
  int count = 0;
  int index;
  
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

  sortByName(arr, count);

  cout << endl << "Input a name to see if it is in the list of people: ";
  cin >> target;
  
  index = findAPerson(arr, target, count);

  if(index > 0){
    cout << endl << "Yes " << arr[index].name << " was in the list at"
         << " position " << index << '.';
    printOne(arr[index]);
  }
  else
    cout << endl << "No, there was no one with the name of " << target
         << "in the list.";
  
  cout << endl;
  
  return 0;
}

void printOne(Person their)
{

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

int findTheLeastDrinker(const Person arr[], int count)
{

  int leastCoffee = 0;

  for(int i = 1; i < count; i++){
    if(arr[i].coffee < arr[leastCoffee].coffee)
      leastCoffee = i;
  }

  return leastCoffee;
  
}

int findAPerson(const Person arr[], string target, int count)
{
  bool found = false;
  int middle;
  int first = 0;
  int last = count - 1;

  while(first <= last && !found){
    middle = (first + last)/2;

    if(arr[middle].name == target)
      found = true;

    else if(arr[middle].name < target)
      first = middle + 1;

    else
      last = middle - 1;
  }

  if(found)
    return middle;

  else
    return -1;
  
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
