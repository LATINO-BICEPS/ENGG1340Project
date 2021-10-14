#include "playerInfo.h"
#include <string>

using namespace player;

// declaring the struct

PlayerInfo::PlayerInfo() {
  // default
  friends[0] = false;
  friends[1] = false;
  friends[2] = false;
  friends[3] = false;
  friendCount = 0;
  hunger = 30;
  balance = 10000;
  fuel = 20; // can travel 16km/L
  daySinceLastSleep = 0;
  HP = 3;
  carParts = 0;
  shopCounter = 0;
  location = 0;
  needsCarParts = false;
}