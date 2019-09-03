//Martin Wilson
//p4.cpp
//Monopoly
//This program is monopoly.
// 2-6 players will take part in a condense version on monopoly using SU
//landmarks. The game ends when any player runs out of money and the winner
//is the player with the most money.

#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct BoardPlace
{
  string name;
  int owner;
  int costToPurchase;
  int costToRent;
};

struct Player
{
  string name;
  int money;
  int location;
};

void boardSetup(BoardPlace arrB[], int& count);
//sets up the board to be played on
//count is the number of elements on the board
void setup(Player arrP[], int& count);
//sets up the player that will be played
//count is the number of players

void checkLoc(BoardPlace arrB[], int boardElements, Player arrP[],
              int playerIndex);
//takes in borad arrays of boards and players as well as the max board elements
//and the player index. This is a void function that does most of the heavy
//lifting, it checks and decides what to do based on player location
void findWinner(Player arrP[], int playerNumber);
//finds the winner

void welcome();
//welcome message

void goodbye();
//goodbye message

int findTheChapel(BoardPlace arrB[], string target, int boardElements);
//returns the index of the chapel

int diceRoll();
//returns a value from 1 - 6

bool takeTurn(BoardPlace arrB[], int boardElements, Player arrP[],
              int playerIndex);
//takes a turn for a player, returns a bool for whether the game is over or not

const string FNAME  = "/home/fac/sreeder/class/cs1420/p4input.dat";
const string CHAPEL = "Chapel of St. Ignatius";
const char YES = 'y';
const int GO = 200;
const int CHANCE = 50;
const int BMAX = 45;
const int PMAX = 7;
const int PMIN = 2;
const int MIN = 1;
const int MAX = 6;
const int STARTINGCASH = 1500;
const int STARTINGLOC = 0;

int main()
{
  BoardPlace boardList [BMAX]; 
  Player playerList [PMAX];

  bool gameDone = false;
  char ans = 'y';
  int playerNum = 1;
  int boardElements = 0;
  int numOfPlayers = 0;

  
  welcome();
  boardSetup(boardList, boardElements);

  while(tolower(ans) == YES){

    setup(playerList, numOfPlayers);
    
    while(!gameDone){
      
      gameDone = takeTurn(boardList, boardElements, playerList, playerNum);
      playerNum++;
      if(playerNum > numOfPlayers){
        playerNum = 1;
      }
    }

    findWinner(playerList, numOfPlayers);
  

  cout << endl << "Would you like to play again(y/n)? ";
  cin >> ans;
  }

  goodbye();
  
  return 0;
}

void boardSetup(BoardPlace arrB[], int& count)
{ 
  ifstream infile;

  
  infile.open(FNAME.c_str());

  if(infile.fail()){
    cout << "File error, exiting program..." << endl << "Press Enter ";
    cin.get();
  }

  
  while(count < BMAX && getline(infile, arrB[count].name)){
    infile >> arrB[count].owner >> arrB[count].costToPurchase
          >> arrB[count].costToRent;
    infile.ignore();
    count++;
  }

  infile.close();
  
}

void setup(Player arrP[], int& count)
{
  
  count = 0;
  
  while(count > PMAX-1 || count < PMIN){
  cout << "How many players would you like to play with today(2-6)? ";
  cin >> count;
  }
  
  for(int i = 1; i <= count; i++){
    cout << "Input a name for player " << i << ": ";
    cin >> arrP[i].name;
    arrP[i].money = STARTINGCASH;
    arrP[i].location = STARTINGLOC;
  }
  
}

void checkLoc(BoardPlace arrB[], int boardElements, Player arrP[],
              int playerIndex)
{

  char ans;
  int chanceRoll;
  int loc = arrP[playerIndex].location;
  int owner  = arrB[loc].owner;
  
  if(owner > 0){
    arrP[playerIndex].money -= arrB[loc].costToRent;

    cout << endl << "Uh Oh! You landed on " << arrB[loc].name
         << " which is owned "
         << "by " << arrP[owner].name << '.' << endl << "You need to pay "
         << arrB[loc].costToRent << '.' << endl << "You now have "
         << arrP[playerIndex].money << " dollars." << endl
         << "Press enter to continue: ";
    cin.get();
    cin.ignore();
  }
  else if(owner < 0){
    if(arrB[loc].name == "Chance"){

      cout << "You landed on chance. " << endl
           << "Press enter to roll a die: ";
      cin.ignore();
      cin.get();
      chanceRoll = diceRoll();
      if(chanceRoll > 3){
        cout << endl << "You rolled a " << chanceRoll << " which means "
             << "you get to moved to the Chapel.";
        arrP[playerIndex].location = findTheChapel(arrB, CHAPEL,
                                                   boardElements);
      }
      else{
        cout << endl << "You rolled a " << chanceRoll << " which means you "
             << "get 50 dollars. Yay!!!";
        arrP[playerIndex].money += CHANCE;
      }
      
    }

   
    else if(arrB[loc].name == "Fees"){
      cout << endl << "You landed on Fees, you need to pay 50 dollars to "
           << "bank.";
      arrP[playerIndex].money -= 50;
      cout << endl << "YOu now have " << arrP[playerIndex].money << " dollar.";
    }

    else if(arrB[loc].name == "Dean Jacob Diaz Office"){
      cout << endl << "You landed at the Dean's Office";
    }

    else if(arrB[loc].name == "Income Tax"){
      cout << endl
           << "You landed on Income Tax, you need to pay 200  dollars.";
      arrP[playerIndex].money -= 200;
      cout << endl << "You now have "
           << arrP[playerIndex].money << " dollars.";
    }
    else if(arrB[loc].name == "Chapel of St. Ignatius"){
      cout << endl
           << "You landed on Chapel of St. Ignatius, enjoy your rest!!";
    }

  }else{
    cout << endl << "You landed on " << arrB[loc].name << '.';

    if(arrP[playerIndex].money > arrB[loc].costToPurchase){
      cout << endl << "Would you like to purchase " << endl << arrB[loc].name
           << " for " << arrB[loc].costToPurchase << " dollars(y/n)? ";
      cin >> ans;

      if(tolower(ans) == YES){
        arrB[loc].owner = playerIndex;
        arrP[playerIndex].money -= arrB[loc].costToPurchase;
        
        cout << endl << "Congrats you just purchased " << arrB[loc].name
             << '.' << endl << "You now have " << arrP[playerIndex].money
             << " dollars.";
       }else{
        cout << endl <<  "Ok!";
      }
     
    } else {
      cout << endl << "You do not have enough to purchase this property.";
    }

  }
   
}

void findWinner(Player arrP[], int playerNumber)
{
  int maxLoc = 1;
  
  for(int i = 2; i <= playerNumber; i++){
    if(arrP[maxLoc].money < arrP[i].money){
      maxLoc = i;
    }
  }

  cout << endl << "Congrats to " << arrP[maxLoc].name
       << " for winning the game!!";
}

void welcome()
{
  cout << endl << "Hello and welcome to Fly By Night Games Company's Monopoly."
       << endl << "In this game 2-6 players will play a short version of "
       << endl << "Monopoly based on properties around Seattle University"
       << endl <<  ". Each player will start off with 1500 dollars to "
       << "purchase "
       << endl << "properties and settle debts. When a player runs out of "
       << "money the " << endl << "game ends, whomever has the most money "
       << "is the winner. " << endl << "Good Luck and have fun!!!"
       << endl << endl;
}

void goodbye()
{
  cout << endl << "Thanks for playing!!!" << endl << endl;
}

int findTheChapel(BoardPlace arrB[], string target, int boardElement){
  int count = 0;
  
  while( target != arrB[count].name){
    count++;
  }

  return count;
}

int diceRoll()
{
  unsigned seed = time(0);
  srand(seed);

  return (rand() % (MAX - MIN + 1)) + MIN;
}

bool takeTurn(BoardPlace arrB[], int boardElements, Player arrP[],
              int playerIndex)
{

  int roll;
  int newLoc;

  cout << endl << endl << "It's "
       << arrP[playerIndex].name << "'s turn. Press enter to roll "
       << "the dice.";
  cin.ignore();
  cin.get();

  roll = diceRoll() + diceRoll();
  newLoc = roll + arrP[playerIndex].location;
  
  cout << endl << "You rolled a " << roll << '.';

  if(newLoc > boardElements){
    roll = newLoc - boardElements;
    newLoc = roll - 1;

    arrP[playerIndex].money += GO;

      cout << endl << "You get 200 for passing GO.";
  }else{
    arrP[playerIndex].location = newLoc;
    cout << endl << "You're new position is " << arrP[playerIndex].location
         << '.';
  }

  checkLoc(arrB, boardElements, arrP, playerIndex);

  if(arrP[playerIndex].money < 0){
    return true;
  } else {
    return false;
  }
}
  
