//Martin WIlson
//p3.cpp

//Purpose: This program is a game of chutes and ladders for two people.

//Input: Names and enter key hits are the only input needed in this program

//Processing: Input will not be processed. Only processing will be once the
//user hits enter to spin the spin and checks to see if the location the
//player moved to is the beginning of a chute or ladder and the random number
//generation

//Output: INSERTNAME moved INSERTNUMBER space(s)

//Example:
//         Input player1 name: Ryan
//         Input player2 name: Geff
//         Ryan, press enter to spin the spinner ENTER
//         Ryan, you moved RANDOMNUMBER(1-6) of space(s)
//         Geff, press enter to spin the spinner ENTER
//         Geff, you moved RANDOMNUMBER(1-6) of space(s)

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>


using namespace std;

const int MIN = 1;
const int MAX = 6;
const int WIN = 100;
const char YES = 'y';

void  welcome(string& name1, string& name2);
//IN players names
//welcomes the user and takes their name

void goodbye();
//says goodbye to users

int spinner();
// returns a valid spin value from MIN to MAX

int checkLocation(int location);
//IN location of player
//RETURNS value of chute or ladder at that location
//RETURNS zero if no chute or ladder

int takeTurn(int position, string name);
//IN player position and name
//takes turn for player

int main()
{
  string p1Name = ""; //Name of player 1
  string p2Name = ""; //Name of player 2
  char ans = 'y';
  int p1Loc = 0; //Player 1 location
  int p2Loc = 0; //PLayer 2 location
  bool p1Turn = true;
  
  
  unsigned seed = time(0);
  srand(seed);

  while(tolower(ans) == YES){

    p1Loc = 0;
    p2Loc = 0;
    
    welcome(p1Name, p2Name);
    
    while((p1Loc != WIN) && (p2Loc != WIN)){
      
      if(p1Turn){
        p1Loc =  takeTurn(p1Loc, p1Name);
        
        p1Turn = false;
      } else {
        p2Loc = takeTurn(p2Loc, p2Name);
 
        p1Turn = true;
      }
    }

    if(p1Loc == WIN)
      cout << endl << endl << "Congrats " << p1Name << " You won!!!!";
    else
      cout << endl << endl << "Congrats " << p2Name << " You won!!!!";
        
    cout << endl << "Would you like to play again(y/n)? ";
    cin >> ans;
  }

  goodbye();
  
  return 0;
}

void welcome(string& name1, string& name2)
{
  cout << endl << endl
       << "Hello and welcome to Fly By Night Games Company's Chutes and" 
       << " Ladders." << endl << "The objective of the game is to get to space"
       << ' ' << WIN << " before the other player."
       << endl << "Good Luck!!!" << endl << endl
       << "Input the name for the first player: ";
       
  cin >> name1;
  cout << endl << "Input the name for the second player: ";
  cin >> name2;
  cin.ignore();
}

void goodbye()
{
  cout << endl << endl <<  "Thanks for stopping by!!" << endl << endl;
}

int spinner()
{
  int spin = (rand()%(MAX - MIN + 1)) + MIN; 
  return spin;
}

int checkLocation(int ploc)
{
  if(ploc == 1)
    return 37;

  else if(ploc == 4)
    return 10;

  else if(ploc == 9)
    return 12;

  else if(ploc == 23)
    return 21;

  else if(ploc == 28)
    return 56;

  else if(ploc == 36)
    return 8;

  else if(ploc == 51)
    return 15;

  else if(ploc == 71)
    return 19;

  else if(ploc == 80)
    return 20;


  else if(ploc == 16)
    return -10;

  else if(ploc == 48)
    return -22;

  else if(ploc == 49)
    return -38;

  else if(ploc == 56)
    return -3;

  else if(ploc == 62)
    return -43;

  else if(ploc == 64)
    return -4;

  else if(ploc == 87)
    return -63;

  else if(ploc == 93)
    return -20;

  else if(ploc == 95)
    return -20;

  else if(ploc == 98)
    return -20;

  else
    return 0;
}

int takeTurn(int pos, string name)
{
  int spin = 0;
  int newPos = 0;
  int locCheck = 3;
  
  cout << endl << endl << endl
       << "It's " << name << "'s turn, press enter to spin the spinner. ";
  cin.ignore();
  spin = spinner();
  newPos = pos + spin;
  locCheck = checkLocation(newPos);

  
  cout << "You spun a " << spin << ". ";
  
  if(newPos <= 100){

    if(locCheck > 0){
      cout << endl << endl << "You get to move to space " << newPos
           << " which has a ladder. Yay!"
           << endl << "You get to move up " << locCheck << " spaces." << endl
           << "You are now on space " << locCheck + newPos << '.';
      
    } else if(locCheck < 0){
      cout << endl << endl << "You get to move to space "
           << newPos  << " which has a chute. "
           << "Oh No!" << endl << "You need to move back " << abs(locCheck)
           << " spaces." << endl << "You are now on space "
           << locCheck + newPos << '.';

      
    } else {
      cout << endl << "You are now on space " << locCheck + newPos<< '.';
      
    }
    
  } else{
    cout << endl << "You need to spin a " << WIN - pos << " or lower to be "
         << "able to move. ";
    return pos;
  }
  
  return locCheck + newPos;  


}
  
