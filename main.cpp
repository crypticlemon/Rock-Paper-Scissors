#include <iostream>
#include <cstring>      // strlen
#include "game.h"  

using namespace std;

//Function to clear screen for both Windows and Linux
void clearScreen () {
  #ifdef WINDOWS
    system("cls");
  #else
    system("clear");
  #endif
}

int main (void) {
  char input, computer_input;
  
  Game game;
   
  while (input != 'q') {
    game.displayMenuHeader();

    do {
      cout << "Type r, p, or s for rock, paper, or scissors (q to quit): " << endl;
      cin >> input;
      input = tolower(input);
      
      if (!game.inputChecker(input, 'q')) {
        cout << "INVALID. Please retype." << endl;
      }
    } while (!game.inputChecker(input, 'q'));
    
    Player player(input, computer_input);

    if (input == 'q') {
      game.Quit();
    } else {

      player.getBotInput();

      player.displayGameResult();

      cin.get();
      cout << "Press ENTER to play again..." << endl;
      cin.get();
      clearScreen();
    }
  }
  return 0;
}