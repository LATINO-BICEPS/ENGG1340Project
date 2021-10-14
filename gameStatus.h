// gameStatus.h
#ifndef gameStatus
#define gameStatus

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "destination.h"
#include "playerInfo.h"

//struct for storing game status
namespace game
{
  struct GameStatus {
      std::string difficulty;
      int day;
      bool status;
      int daysLeft;
      int totalDist;
      std::vector<Dest> destinations;
      GameStatus();
  };

  // two classes for game IO
  class saveIO {
    public:
      bool loadGame(player::PlayerInfo &p, game::GameStatus &g);
      bool saveGame(player::PlayerInfo &p, game::GameStatus &g);
  };

}

#endif