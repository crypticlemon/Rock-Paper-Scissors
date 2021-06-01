#include <iostream>
#include <iomanip>      //setw
#include "game.h"

using namespace std;

//Initialize global file variables
int score = 0;
int numChoices = 3;
char choiceArray[4] = {'r', 'p', 's'};

//*******************************************************
//GAME CLASS
//*******************************************************

//Checks if input is valid: rock, paper, or scissors
bool Game::inputChecker(char input, char exitChar) {
  bool inChoices = false;
 
  if (input == exitChar) inChoices = true;
  else {
    for (int i = 0; i < numChoices; i++)
      if (input == choiceArray[i]) inChoices = true;
  }

  return inChoices;
}

//Gets current score
int Game::getHighScore () {
  return score * 100;
}

//Quits game
void Game::Quit() {
  cout << "\nQuitting game...\nBye bye!" << endl;
  exit(1);
}

//Displays the title and highscore
void Game::displayMenuHeader () {
  int printScoreLen = 32;
  
  cout << "ROCK PAPER SCISSORS";
  cout << right << setw(printScoreLen) << "SCORE: " << getHighScore() << endl;
  cout << "-------------------" << endl;
}