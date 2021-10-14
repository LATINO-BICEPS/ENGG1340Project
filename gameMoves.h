// gameMoves.h
#ifndef gameMoves
#define gameMoves

#include "gameStatus.h"
#include "playerInfo.h"

// function prototypes
// for comments refer to .cpp
void invalidInput();
void drive(player::PlayerInfo &p, game::GameStatus &g);
bool crashing(player::PlayerInfo &p);
void rest(player::PlayerInfo &p, game::GameStatus &g);
void work(player::PlayerInfo &p, game::GameStatus &g);
void shop(player::PlayerInfo &p);
int incrementClock(game::GameStatus &g);
void quit();
int randomfunc(int i, int j);
bool checkHitchAvailable(player::PlayerInfo);
bool checkWin(player::PlayerInfo &p, game::GameStatus &g);
bool gameOver(player::PlayerInfo &p, game::GameStatus &g);
void hitchhiker();
void status(player::PlayerInfo &p, game::GameStatus &g);
void startGame(player::PlayerInfo &p, game::GameStatus &g);
void displayMoves(player::PlayerInfo &p);
int randomfunc(int i, int j);
int incrementClock(game::GameStatus &g);
void driveTransition(player::PlayerInfo &p, game::GameStatus &g);
void workTransition(player::PlayerInfo &p, game::GameStatus &g);
void restTransition(player::PlayerInfo &p, game::GameStatus &g);
void clearScreen();
void enterToContinue();

#endif