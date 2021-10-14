// gameStatus.cpp
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "gameStatus.h"
#include "playerInfo.h"
#include "gameTexts.h"

using namespace game;

// declaring the struct

GameStatus::GameStatus() {
  difficulty = "medium";
  day = 0;
  status = true;
  daysLeft = 90;
  totalDist = 0;
  destinations.push_back(Dest{"Hong Kong", "", false});
  destinations.push_back(Dest{"Macao", "It is also spelled as Macau and officially the Macao Special Administrative Region of the People's Republic of China. With a population of 700,000 and an area of 32.9 sq. km, it is without a doubt the most densely populated region in the world.", false});
  destinations.push_back(Dest{"Thailand", "Previously known as Siam, now called the Kingdom of Thailand officially is a country in Southeast Asia. Because of it being inland and location in the latitude aspect, a major portion of Thailand experience a long period of hot weather where 40C is expected. It has a population of 66 million people and an area size of 513,000 sq. km.", false});
  destinations.push_back(Dest{"India", "Formally called the Republic of India, it resides in South Asia as well. It has the second largest population in the world, second only to China. India has a population of 1.4 billion people and an area of 3.3 million sq. km.", false});
  destinations.push_back(Dest{"Pakistan", "Its official name is the Islamic Republic of Pakistan. Known as the site of several ancient cultures, it is widely popular amongst historians. It has a population of 212 million people and an area spanning 881,000 sq. km.", false});
  destinations.push_back(Dest{"Iran", "Iran is known as housing one of the world's oldest civilizations dating back to the fourth milennium BC. It is a country in Western Asia surrounded by Afghanistan, Turkmenistan and Iraq. It has a population of 83 million and an area of 1.7 million sq. km.", false});
  destinations.push_back(Dest{"Egypt", "Home to the oldest of the Seven Wonders of the Ancient World - the Great Pyramid of Giza, Egypt had not failed to impress modern day architects with pyramids that has stayed erect for almost 5000 years. It has a population of 101 million people and an area of 1 million sq. km.", false});
  destinations.push_back(Dest{"Libya", "Formally called the State of Libya. The country is located in northern Africa and is the 4th largest in the continent. It has a population of 7 million and an area of 1.8 million sq. km.", false});
  destinations.push_back(Dest{"Algeria", "Like Libya, Algeria resides in northern Africa as well. It is the largest country in Africa with a population of 44 million and an area of 2.4 million sq. km.", false});
  destinations.push_back(Dest{"Brazil", "It is known as a melting pot of different cultures - with over a century of mass immigration internationally, it has become one of the most ethnically diverse nations in the world. It has a population of 211 million people and an area of 8.5 million sq. km.", false});
  destinations.push_back(Dest{"Chile", "It is the southernmost country in the world - closest to Antarctica - cornered by Peru to the North and Argentina to the east. It has a population of 18 million and an area of 750,000 sq. km.", false});
  destinations.push_back(Dest{"Argentina", "Widely known to most football fans as the birthplace of the often considered greatest football player of all time - Lionel Messi. Argentina is also by far the largest Spanish-speaking nation by far in the world. It has a population of 45 million and an area of 2.8 million sq. km.", true});
}

//read from save funtion, return true if success, else return false;
bool saveIO::loadGame(player::PlayerInfo &p, game::GameStatus &g) {
  std::string toPrint1 = "Enter the filename (default: save.txt ): ";
  std::string filename = "save.txt", input = "";
  std::cout << toPrint1;
  std::cin >> input;
  if (input == "") {
    input = filename;
  }
  std::ifstream fin(input);
  if (fin.fail()) {
    std::cout << "Error: File does not exist!" << std::endl;
    return false;
  } else {
    std::string buffer1;
    //PlayerInfo first, then gameInfo

    for (int i = 0; i < 4; i++) { //friends info
      std::getline(fin, buffer1);
      p.friends[i] = std::stoi(buffer1);
    }
    std::getline(fin, buffer1);
    p.friendCount = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.hunger = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.balance = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.fuel = std::stoi(buffer1);
    
    std::getline(fin, buffer1);
    p.daySinceLastSleep = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.HP = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.carParts = std::stoi(buffer1);
    std::getline(fin, buffer1);
    p.shopCounter = std::stoi(buffer1);

    std::getline(fin, buffer1);
    p.location = std::stoi(buffer1);

    std::getline(fin, buffer1);
    g.difficulty = buffer1;
    std::getline(fin, buffer1);
    g.day = std::stoi(buffer1);
    std::getline(fin, buffer1);
    if (buffer1 == "false") {
      g.status = false;
    } else {
      g.status = true;
    }
    std::getline(fin, buffer1);
    g.daysLeft = std::stoi(buffer1);
    
    std::getline(fin, buffer1);
    p.name = buffer1;

    fin.close();
    std::cout << "Load finished!" << std::endl;
    return true;
  }
}

//save to file funtion, return true if success, else return false;
bool saveIO::saveGame(player::PlayerInfo &p, game::GameStatus &g) {
  std::string toPrint1 = "Enter the filename to save (default: save.txt ): ";
  std::string filename = "save.txt", input = "";
  std::cout << toPrint1;
  std::cin >> input;
  if (input == "") {
    input = filename;
  }
  std::ofstream fout(input);
  if (fout.fail()) {
    std::cout << "Error: Unable to open file!" << std::endl;
    return false;
  } else {
    fout << p.friends[0] << std::endl << p.friends[1] << std::endl << p.friends[2] << std::endl << p.friends[3] << std::endl;
    fout << p.friendCount << std::endl << p.hunger << std::endl << p.balance << std::endl << p.fuel << std::endl;
    fout << p.daySinceLastSleep << std::endl << p.HP << std::endl << p.carParts << std::endl << p.shopCounter << std::endl;
    fout << p.location << std::endl;
    fout << g.difficulty << std::endl << g.day << std::endl << g.status << std::endl << g.daysLeft << std::endl;
    fout << p.name;
    fout.close();
    std::cout << "Save finished!" << std::endl;
    return true;
  }


}