#ifndef playerInfo
#define playerInfo

#include <string>
#include <iostream>
#include <vector>

// struct for storing player informations
namespace player
{
  struct PlayerInfo {
    std::string name;
    bool friends[4]; // corresponds to Mechenic
    // Bouncer, Chef and Entertainer // abandoned function
    int friendCount; // max of 2 friends at once // abandoned function
    int hunger; // thirst is removed to simplify gameplay, carParts replaces it
    int balance;
    int fuel; 
    int daySinceLastSleep;
    int HP;
    int carParts; 
    int shopCounter;// helps me check if it is the player's first time entering the shop
    int location; // location of player, for gameStatus' map.
    bool needsCarParts;
    PlayerInfo();

  };
}

#endif