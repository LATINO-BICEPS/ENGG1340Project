// gameTexts.cpp
#include "gameTexts.h"
#include <chrono>
#include <thread>
#include <iostream>

// saves me time not typing these out all the 
// time and declutters the code
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::this_thread::sleep_for;
using std::chrono::seconds;
using std::flush;
using std::chrono::milliseconds;

void printText(string text){
  int x = 2, length = text.size();
  for(int i = 0; i < length; i++){
    if((i % x != 0 || i == 0)){
      cout<<text[i]<<flush;
    }
    else{ 
      sleep_for(milliseconds(15));
      cout<<text[i]<<flush; 
    } 
  }
  cout<<endl;
}