#include <iostream>
#include <iomanip>      //setw
#include <stdlib.h>     // srand, rand
#include <time.h>       // time
#include "game.h"

using namespace std;

//*******************************************************
//PLAYER CLASS
//*******************************************************

//Initializes player1, player2, and choiceNameDisplay
Player::Player(char ch1, char ch2) 
: choiceNameDisplay {"Rock", "Paper", "Scissors"}
{
  player1 = ch1;
  player2 = ch2;
}

//Gets bot choice
void Player::getBotInput () {
  srand(time(NULL));
  player2 = choiceArray[rand() % numChoices];
}

//Returns win, loss, or tie as int
int Player::getGameResult () {
  int result; 
  // 1 = win, -1 = loss, 0 = tie
  
  if 
  (
    (player1 == 'r' && player2 == 's') ||
    (player1 == 's' && player2 == 'p') ||
    (player1 == 'p' && player2 == 'r')
  )
    result = 1;
  
  else if 
  (
    (player1 == 'r' && player2 == 'p') ||
    (player1 == 's' && player2 == 'r') ||
    (player1 == 'p' && player2 == 's')
  )
    result = -1;
  else if (player1 == player2) result = 0;

  return result;
}

//Gets full name of the player and bot's choice
std::string Player::getChoiceName (char ch) {
  std::string result;

  for (int i = 0; i < numChoices; i++) {
    if (ch == choiceArray[i])
      result = choiceNameDisplay[i];
  }
  return result;
}

//Prints result of the game
void Player::displayGameResult () {
  int printBotChoiceLen = 35;

  printASCIIHands();

  cout << "You chose: " << getChoiceName(player1);
  cout << right << setw(printBotChoiceLen) << "The bot chose: " << getChoiceName(player2) << endl;

  cout << endl;

  if (getGameResult() == 1) {
    cout << "You WIN!" << endl; 
    score++;
  } else if (getGameResult() == -1) {
    cout << "You LOSE!" << endl; 
    score--;
  }
  else cout << "It's a TIE!" << endl;
}

void Player::printASCIIHands() {
  //ASCII ART by Veronica Karlsson: https://www.asciiart.eu/people/body-parts/hand-gestures
  string rockPlayer = 
  "    _______\n"
  "---'   ____)\n"
  "      (_____)\n"
  "      (_____)\n"
  "      (____)\n"
  "---.__(___)";
  string paperPlayer = 
  "    _______\n"
  "---'   ____)____\n"
  "          ______)\n"
  "          _______)\n"
  "         _______)\n"
  "---.__________)";
  string scissorsPlayer = 
  "    _______\n"
  "---'   ____)____\n"
  "          ______)\n"
  "       __________)\n"
  "      (____)\n"
  "---.__(___)";

  string rockBot = 
  "  _______    \n"
  " (____   '---\n"
  "(_____)      \n"
  "(_____)      \n"
  " (____)      \n"
  "  (___)__.---"
  ;
  string paperBot = 
  "       _______    \n"
  "  ____(____   '---\n"
  " (______          \n"
  "(_______          \n"
  " (_______         \n"
  "   (__________.---\n";
  string scissorsBot = 
  "       _______    \n"
  "  ____(____   '---\n"
  " (______         \n"
  "(__________      \n"
  "     (_____)     \n"
  "      (___)__.---\n"
  ;

  switch(player1) {
    case 'r' :
      cout << rockPlayer;
      break;
    case 'p' :
      cout << paperPlayer;
      break;
    case 's' :
      cout << scissorsPlayer;
      break;
  }
  cout << endl;
  switch(player2) {
    case 'r' :
      cout << rockBot;
      break;
    case 'p' :
      cout << paperBot;
      break;
    case 's' :
      cout << scissorsBot;
      break;
  }
  cout << endl;
}