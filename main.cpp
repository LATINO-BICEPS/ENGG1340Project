#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <thread>

#include "gameTexts.h"
#include "gameMoves.h"

#include "gameStatus.h"
#include "playerInfo.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

int main(){
  player::PlayerInfo p; // init 2 objects, for storing game and player info respectively
  game::GameStatus g;
  game::saveIO s;
  
  string command;
  string gameDesc1 = "It is the modern era of the 21st Century and Christmas is quickly nearing! Like many others, you're gearing up for the winter season to visit your parents to celebrate with them. However, your parents live all the way on the other side of the world making meeting them less than trivial. Unfortunately, this alternate timeline of the universe has no signs of an aviation industry making air travel impossible! Fortunately for you, you own a high-speed supercar and are determined to celebrate with them.";
  string gameDesc2 = "Your goal is to cross the other side of the globe from Hong Kong to Argentina by car (20,000 kilometers). You start on November 1st with the hopes of making it to Argentina by December 25. The journey won't be easy - every single day will cost you resources and with your car being driven at full speed for long periods of time it could break down at any time! You can rest and sleep to recover your energy or keep driving and play a game of chance.. Do anything to make it to the end.\n";
  char preference;
  // gives user the option to load game at start up
  bool loaded = false;
  while(true){
    clearScreen();
    printText("Would you Like to");
    printText("1. Start your Adventure");
    printText("2. Know the Backstory of the Game");
    printText("3. Load Game");
    printText("4. Quit");
    cin>>preference;
    if(preference == '1'){
      break;
    } else if(preference == '2'){
      printText(gameDesc1);
      cout<<endl;
      printText(gameDesc2);
      enterToContinue();
    } else if(preference == '3'){
      s.loadGame(p, g);
      loaded = true;
      enterToContinue();
    } else if(preference == '4'){
      quit();
    }
  }
  if(!loaded){
    startGame(p, g); 
  } 
  while(g.status){
    displayMoves(p);
    cin>>command;
    if(command == "1" || command == "Drive" || command == "drive"){
      drive(p, g);
    }
    else if(command == "2" || command == "Rest" || command == "rest"){
      rest(p, g);
    }
    else if(command == "3" || command == "Work" || command == "work"){
      work(p, g);
    }
    else if(command == "4" || command == "Shop" || command == "shop"){
      shop(p);
    }
    else if(command == "5" || command == "Status" || command == "status"){
      status(p, g);
    }
    // hidden option for hitchhikers when available
    else if(command == "6" || command == "Save" || command == "save"){
      s.saveGame(p, g);
    }
    else if(command == "7" || command == "Load" || command == "quit"){
      s.loadGame(p, g);
    }
    else if(command == "8" || command == "Quit" || command == "quit"){
      quit();
    }
    // removed option to load at save points because it doesn't make sense
    // it has been replaced with loading at the start of the game instead.
    else{
      invalidInput();
    }
    // breaks the while loop if game is over
    if(gameOver(p, g)){
      g.status = false;
    }
    enterToContinue();
  }
  // win checking condition
  if(checkWin(p, g)){
    cout<<"You gave the presents!"<<endl;
  } 
  else{
    cout<<"You lost, try again!"<<endl;
  }

}