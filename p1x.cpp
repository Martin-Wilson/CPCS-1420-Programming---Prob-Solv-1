// Martin Wilson
// p1x.cpp
// A program that asks for user input to create a madlib-esque story

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

const char YES = 'y';


int main()
{
  //variables
  char ans;
  string dayOfWeek;
  string emotion1;
  int numOfPeople;
  int numOfFood;
  string foodItem;
  string adjective1;
  string emotion2;
  string adjective2;
  int cashPrize;
  string action;

  //Welcome message and prompt to see if the user wants to play a game
  cout << endl << endl << "Would you like to play a madlibs game? (y/n): ";
  cin >> ans;
  cin.ignore();
  
  //while loop to allow the user to play again if they want
  while(tolower(ans)==YES){


  
    //Hello message if they want to play a game
    cout << endl << "Hello and welcome to my madlibs program!" << endl;
    cout << "I will be asking you for some words and phrases to complete the";
    cout << " story." << endl;
    cout << "The theme is food competition." << endl << endl;
    cout << "Press Any Key Then Enter To Start: ";

    cin.get();
    cin.ignore();

    //Inputs for the madlib paragraph this program will creator
    cout << endl << endl << "Please type in day of the week: ";
    getline(cin, dayOfWeek);

    cout << endl << "Please type in an emotion: ";
    cin >> emotion1;

    cout << endl << "Please type in a positive whole number: ";
    cin >> numOfPeople;

    cout << endl << "Please type in a different number that is larger than "
         << "20: ";
    cin >> numOfFood;
    cin.ignore(1);
  
    cout << endl << "Please type in the plural form of a food: ";
    getline(cin, foodItem);

    cout << endl << "Please type in an adjective: ";
    cin >> adjective1;

    cout << endl << "Please type in a different adjective or feeling: ";
    cin >> emotion2;
    cin.ignore(1);
    
    cout << endl << "Please type in a smell: ";
    getline(cin, adjective2);

    cout << endl << "Please type in a positive whole number: ";
    cin >> cashPrize;
    cin.ignore(1);
  
    cout << endl << "Please type in an action: ";
    getline(cin, action);

  
    //outputs a paragraph with the embedded user input
    cout << endl << endl << "The Eating Competition." << endl << endl;
    cout << "Today is " << dayOfWeek << ", the day where I will participate"
         << endl << "in my first eating competition. I am feeling" << endl
         << emotion1 << " right now. Wow, look at all these people," << endl
         << "there must be at least " << numOfPeople << " people here." << endl
         << "Well I am ready to eat. I wonder what we will be eating today."
         << endl << "Uh Oh! We need to eat " << numOfFood << " " << foodItem
         << "." << endl << "This is going to be a " << adjective1 << " day. "
         << "Let's get started." << endl << "Ok the first couple weren't that "
         << "bad but the next ones are going to hurt." << endl << "Geez my "
         << "stomach feels " << emotion2 << ". It doesn't help that the"
         << endl
         << "person next to me smells like " << adjective2 << ". Finally only "
         << endl << "a few left, I can still win. Yes! I did it, I won" << endl
         << "the " << cashPrize << " dollar cash prize!!"  
         << " Now its time to " << action << "." << endl << endl;

    //prompt to ask the user if they want to play again
    cout << "Would you like to play agian? (y/n): "; 
    cin >> ans;
    cin.ignore();
    
  }

  cout << endl << endl << "Thanks for stopping by!" << endl << endl;
  
  return 0;
}
