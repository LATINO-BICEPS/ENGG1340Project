// destination.h
#ifndef destination
#define destination

#include <string>
#include <vector>
#include <iostream>
#include "gameTexts.h"

// a struct to store destination data
struct Dest {
        std::string name;
        std::string description;
        bool isEnd; //storing if this location is destination
};
#endif
