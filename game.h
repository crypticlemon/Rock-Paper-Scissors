#pragma once
#ifndef GAME_H
#define GAME_H

//Global variables across files
extern int score;
extern int numChoices;
extern char choiceArray[4];

class Game {
  public:
    bool inputChecker (char input, char exitChar);
    void Quit ();
    void displayMenuHeader ();
    int getHighScore ();
};

class Player {
  private:
    char player1, player2;
    std::string choiceNameDisplay[4];

  public:
    Player(char ch1, char ch2);
    void getBotInput ();
    void printASCIIHands ();
    void displayGameResult ();
    int getGameResult ();
    std::string getChoiceName (char ch);
};

#endif