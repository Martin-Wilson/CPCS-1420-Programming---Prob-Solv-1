//Martin Wilson
//p2.cpp

//purpose: a number guessing game for the user that loop infinitly if the user
//wants it too

//input: only input is a char for continued playing and a number

//output: prompts to play and numbers, and feedback for guesses

//process: checks the input to the randomly generated number and continues
//to ask for input until input is equal to the randomly generated number

//example: Hello input a number from 1 to 9
//9
//your guess was to high try again
//4
//good work, you've correctly guessed the number

#include <iostream>
#include <cstdlib>

using namespace std;


const int MIN = 1; //The minimum guessing value
const int MAX = 7; //The maximum guessing value
const char YES = 'y'; //The value for if they want to play again

int main(){

//this seeds the "random" number generator to the system time
  unsigned seed =  time(0);
  srand(seed);
  
  char ans; //answer for if the user wants to continue the game
  int guess; //the users guess for the number
  int corNum; //the correct answer the user must guess

  cout << endl << endl << "Hello and welcome to my number guessing game!!"
       << endl <<  "The point of the game  an number between " << MIN
       << " and " << MAX << "." << endl
       << "You keep on guessing until you get the correct answer" << endl 
       << "Would you like to play (y/n): ";
  cin >> ans;

  while(tolower(ans) == YES){

    corNum = (rand()%(MAX - MIN +1)) + MIN;
    guess = 0;
    
    
    cout << endl << endl << "The point of the game is to correctly guess "
         << "a number between " << MIN << " and " << MAX << "." << endl
         << "You can keep on guessing until "
         << "you get the correct answer. Good luck!!!" << endl << endl
         << "Enter in your first guess, remember the number is between "
         << MIN << " and " << MAX << ". ";
    cin >> guess;

    while(guess != corNum){
    
      if(guess > corNum){
        cout << "Your guess is too high, try again." << endl << endl 
             << "Enter a number between " << MIN << " and " << MAX << ". ";
        cin >> guess;
        
      } else{  
        cout << "Your guess is too low, try again." << endl << endl  
             << "Enter a number between " << MIN << " and " << MAX << ". ";
        cin >> guess;

      }

      
    }

  cout << "Nice job " << guess << " was the correct answer!!"  
       << endl << endl << "Would you like to play again(y/n)? ";  
  cin >> ans;

  }

  cout << endl << endl << "Thanks for stopping by!!" << endl << endl;
  return 0;
}
