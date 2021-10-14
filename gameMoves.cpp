// gameMoves.cpp
#include <ctime> 
#include <random> 
#include <cmath>
#include <chrono>
#include <thread>

#include "gameStatus.h"
#include "playerInfo.h"
#include "gameMoves.h"


using namespace std;
using std::this_thread::sleep_for;
using std::chrono::milliseconds;

// enterToContinue function
// just a function to ask player to confirm
// before proceeding to next stage
void enterToContinue(){
  cout<<endl;
  cin.ignore();
  cout<<"Press 'Enter' to continue.";
  cin.ignore();
  cout<<endl;
}


// StartGame function, called when the game starts
// It is to let the user choose difficulty, initialize
// player's variable accordingly and open shop for the
// first time.
// Accepts PlayerInfo and GameStatus as input
// parameters, updates the program within and returns void.
void startGame(player::PlayerInfo &p, game::GameStatus &g) {
  char preference;
  clearScreen();
  while(true){
    cout<<"What is your first name? "<<endl; cin>>p.name;
    cout<<"Is "<<p.name<<" correct? (y/n) "<<endl; cin>>preference;
    if(preference == 'y'){
      break;
    }
  }
  // pick a date to choose
  clearScreen();
  preference = 'n';
  printText("You can choose a date to start which will affect the difficulty of your game.\n");
  printText("Medium is the default difficulty.\n");
  cout<<endl;
  cout<<"* Story Mode: No time limit"<<endl;
  cout<<"* Easy: September(4 months)"<<endl;
  cout<<"* Medium: October(3 months)"<<endl;
  cout<<"* Hard: November(2 months)" <<endl;
  cout<<endl;
  while(true){
    printText("What is your preferred difficulty? (story/easy/medium/hard)"); cin>>g.difficulty;
    string output = (g.difficulty == "story") ? "story" : g.difficulty;
    cout<<"Is "<< output << " mode correct? (y/n) " <<endl; cin>>preference;

    if(preference == 'y'){
      // set the daysLeft to corresponding difficulty's time limit
      if(g.difficulty == "story"){
        g.daysLeft = 9999; // effectively unlimited time unless there is a better alternative
        break;
      } else if(g.difficulty == "easy"){
        g.daysLeft = 120;
        break;
      } else if(g.difficulty == "medium"){
        g.daysLeft = 90;
        break;
      } else if(g.difficulty == "hard"){
        g.daysLeft = 60;
        break;
      }
    }
  }
  clearScreen();  
  // u have money, choose to spend them at start
  // item menu etc..
  printText("Prior to leaving Hong Kong, you have to make some preparations and buy necessary equipment for the journey. You have $40,000 to spend, though it is not necessary to spend it all immediately. You can buy all your necessities for the journey at every stop you make. If you're going all the way to Argentina, these are the essentials. \n");
  // 20,000 km: with a 17km/L efficiency, need at least 1250L of fuel, $19/L
  printText("1. Gasoline to fuel your car");
  printText("2. Food to last you the journey");
  printText("3. Spare parts to fix your car\n");
  // there's a weird quirk where I need cin.ignore() before and after the cout statement
  cin.ignore();
  cout<<"Press 'Enter' to enter the shop.";
  cin.ignore();
  clearScreen();
  shop(p);
  printText("Good luck on the long journey ahead of you!\n");
  enterToContinue();
}



// Show all possible moves the player can do
// This accepts playerInfo and returns nothing,
// outputs option for player to choose in the console.
void displayMoves(player::PlayerInfo &p){
  clearScreen();
  printText("You may: ");
  cout<<endl;
  cout<<"1. Continue on Driving"<<endl;
  cout<<"2. Stop to Rest"<<endl;
  cout<<"3. Go Work"<<endl;
  cout<<"4. Shop"<<endl;
  cout<<"5. Check my Status"<<endl;
  cout<<"6. Save my Game"<<endl;
  cout<<"7. Load my Game"<<endl;
  cout<<"8. I'm done playing. Quit."<<endl;
  cout<<endl;
  printText("What do you pick?");
} 


// used in driveTransition()
// accepts nothing and returns nothing
// it is to clear the screen when driveTransition is called.
void clearScreen(){
  system("clear");
}


// Rest Transition, it is called when sleep
// function is called. It clears the screen and prints
// a sleeping ASCII art in the console. It accepts playerInfo and GameStatus
// and returns nothing
void restTransition(player::PlayerInfo &p, game::GameStatus &g){
  int counter = 0, delay = 1000;
  
  while(counter < 4){
    clearScreen();
    if(counter == 0){
      cout<<endl; cout<<endl; cout<<endl;
    } else if(counter == 1){
      cout<<endl; cout<<endl; cout<<R"(z             )"<<endl;
    } else if(counter == 2){
      cout<<endl; cout<<R"(  z           )"<<endl; cout<<R"(z             )"<<endl;
    } else if(counter == 3){
      cout<<R"(             Z         )"<<endl; cout<<R"(  z           )"<<endl; cout<<R"(z             )"<<endl;
    }
    cout<<R"(
          _____|~~\_____      _____________
  _-~               \    |    \
  _-    | )     \    |__/   \   \
  _-         )   |   |  |     \  \
  _-    | )     /    |--|      |  |
 __-_______________ /__/_______|  |_________
(                |----         |  |
 `---------------'--\\\\      .`--'
                              `||||  
    )"<<endl;
  // taken from https://www.asciiart.eu/people/sleeping
  sleep_for(milliseconds(delay));
  counter += 1;
  }
}


// Work Transition, it is called when work() is called
// It clears the screen and prints a money Logo ASCII art
// The function accepts playerInfo and gameStatus as input parameters
// and returns nothing.
void workTransition(player::PlayerInfo &p, game::GameStatus &g){
  int counter = 0, delay = 1000;
  clearScreen();
  string moneyLogo = R"(                                                                     
                                  @@@@@@,                                       
                                *@@@@@@@@@@@#.                                  
                               *@@@@@@@@@@@@@@@@@@@@@@%                         
                               @@@@@@@@@@@@@@@@@@@@@@@.                         
                                @@@@@@@@@@@@@@@@@@@@@.                          
                                 @@@@@@@@@@@@@@@@@@.                            
                                 @@@@@@/*(@@@@@.
                                ./@@@@@*  .*@@@@/.                                   
                            (.,@@@@@@@@@@@@@@@@@@(                              
                            @@@@@@@@@@@@@@@@@@@@@@@@                            
                         #@@@@@@@@@@@@@.   @@@@@@@@@@@/                         
                       &@@@@@@@@@@@@( ., .  .&@@@@@@@@@@(                       
                     (@@@@@@@@@@@@    @*   /    @@@@@@@@@@,                     
                    @@@@@@@@@@@@@   #@@.   @@@  @@@@@@@@@@@@                    
                   @@@@@@@@@@@@@@    %@.   @@@@@@@@@@@@@@@@@@                   
                  @@@@@@@@@@@@@@@@@          %@@@@@@@@@@@@@@@@                  
                  @@@@@@@@@@@@@@@@@@@@@.        /@@@@@@@@@@@@@.  
                  @@@@@@@@@@@@@@@@@@@@@.   @@&   #@@@@@@@@@@@@%                 
                   @@@@@@@@@@@@@@   @@@.   @@@   @@@@@@@@@@@@@/                 
                    @@@@@@@@@@@@@@     .   .    @@@@@@@@@@@@@@                  
                     .@@@@@@@@@@@@@@@@*    .#@@@@@@@@@@@@@@@@                   
                        @@@@@@@@@@@@@@@,   @@@@@@@@@@@@@@@@                     
                           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@                        
                                ,%@@@@@@@@@@@@@@@@*                                                          
  )";
  
  int x = 2, length = moneyLogo.size();
  for(int i = 0; i < length; i++){
    if((i % x != 0 || i == 0)){
      cout<<moneyLogo[i]<<flush;
    }
    else{ 
      sleep_for(milliseconds(1));
      cout<<moneyLogo[i]<<flush; 
    } 
  }
  cout<<endl;
  // image from https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.pngitem.com%2Fmiddle%2FihobJoR_money-logo-transparent-dollar-bag-icon-png-png%2F&psig=AOvVaw3cjvTvRRXaFUlh97Tj9wkY&ust=1618830132895000&source=images&cd=vfe&ved=0CA0QjhxqFwoTCIDGvq7Sh_ACFQAAAAAdAAAAABAQ
}


// Drive Transition, it is called when drive() is called
// It is used to clear the screen, calculate drive distance.
// It accepts playerInfo and GameStatus as input and returns nothing
void driveTransition(player ::PlayerInfo &p, game::GameStatus &g){
  int distCountry = 200; // to be changed to rng MAYBE
  int fuelRequired = ceil(double(distCountry)/16), foodRequired = ceil(double(distCountry)/20); // rounded up 12.5 -> 13
  int index = 0, counter = 0, numPortions = 10; // numPortions determines how many iterations/how fine each increment is
  int distTravelled = 0, distTravelledDummy = 0; // temp var for trail completion calc.
  int fuelDummy = p.fuel;
  int hungerDummy = p.hunger;
  int startTrail = 0, endTrail = 100, delay = 500; // how wide the trail should be, delay(miliseconds)
  
  // determine how far the car can go
  if(p.fuel > fuelRequired && p.hunger > foodRequired){
    distTravelled = distCountry;
    p.fuel -= fuelRequired;
    p.hunger -= foodRequired;
  } else{
    distTravelled = p.fuel*16;
    p.fuel -= p.fuel;
    p.hunger -= p.hunger;
  }
  int increment = distTravelled/numPortions; // holds the iterations of distTravelled broken down into n parts
  while(counter <= numPortions){
    // clear screen on startup
    if(counter == 0){
      clearScreen();
    }
    double x = double(distTravelledDummy)/double(distCountry); // x: how complete it is
    int index = x*(endTrail+1);
    // check to see if they completed the path 100%
    if(x >= 1){
      index = endTrail;
    }
    string trail;
    // make the trail (|----------X-------|)
    for(int i = startTrail; i < endTrail+1; i++){
      trail += '-';
    }
    trail[startTrail] = '|'; trail[endTrail] = '|';
    // linearly display where we are with an 'X'
    trail[index] = 'X';
    cout<<trail<<endl;
    // display stats
    cout<<"Completion: "<<x*100<<'%'<<'\n'<<endl;
    cout<<"Fuel: "<<fuelDummy - x*fuelRequired<<endl;
    cout<<"Hunger: "<<hungerDummy - x*foodRequired <<endl;
    cout<<"From: "<<g.destinations[p.location].name<<endl;
    cout<<"Destination: "<<g.destinations[p.location+1].name<<endl; 
    cout<<"Distance Travelled: "<<distTravelledDummy<<" km"<<endl;
    cout<<"Distance Left: "<<distCountry-distTravelledDummy<<" km"<<endl;
    cout<<"Total Distance Travelled: "<<g.totalDist + x*distTravelledDummy<<endl;
    cout<<"Fuel required: "<<fuelRequired<<'\n'<<endl;
    sleep_for(milliseconds(delay));
    counter += 1;
    // make an if else where it won't clear the last screen to display game over
    // i.e. if distTravelled < distCountry, game over
    if(counter != numPortions+1){
      clearScreen();
    }
    distTravelledDummy = increment*counter;
  }
  g.totalDist += distTravelled;
}

// car crashing function
// it calculates the probability 
bool crashing(player::PlayerInfo &p) {
  if (p.daySinceLastSleep < 30) {
    int crashProbability = randomfunc(p.daySinceLastSleep, 30);
    if (crashProbability >= 25) {
      return true;
    } else {
      return false;
    }
  } else {
    return true;
  }
  
}

// drive function
// It is to initialize the drive function
// and prints the welcome message!
// 
void drive(player::PlayerInfo &p, game::GameStatus &g){
  clearScreen();
  // crashing function calc. and the lines to print to be implemented
  driveTransition(p,g);

  
  int daysPassed = incrementClock(g);
  p.daySinceLastSleep += daysPassed;

  bool crashed = crashing(p); // check if player crashes andgets to advance to next spot


  if (!crashed) {
    p.location += 1;
    std::string toPrint1 = "Welcome to " + g.destinations[p.location].name;
    printText(toPrint1);
    printText(g.destinations[p.location].description);
  } else {
    string toPrint1 = "Oh no, you crashed! You've wasted " + to_string(daysPassed) + " days.";
    string toPrint2 = "Be sure to sleep for a decreased chance of crashing.";
    string toPrint3 = "";
    string toPrint4 = "";
    string toPrint5 = "";
    cout<<endl;
    printText(toPrint1);
    printText(toPrint2);
    if (p.carParts > 0) {
      toPrint3 = "Since you have car parts available, you can repair your car using them!";
      toPrint4 = "As you repaired your vehicle quickly, you moved to your next destination.";
      printText(toPrint3);
      printText(toPrint4);
      p.carParts -= 1;
      cout << endl;
      p.location += 1;
      std::string toPrint1 = "Welcome to " + g.destinations[p.location].name;
      printText(toPrint1);
      printText(g.destinations[p.location].description);
    } else {
      string toPrint3 = "You don't have any spare parts either, you are hiring a mechanic from the previous country to tow your car back for repair. It costs you $8000.";
      if (p.balance > 8000) {
        string toPrint4 = "You have enough money to hire a mechanic, money has been deducted.";
        string toPrint5 = "You are back in the previous city again.";
        printText(toPrint3);
        printText(toPrint4);
        printText(toPrint5);
      } else {
        string toPrint4 = "You don't have enough money to hire a mechanic, you are stranded!";
        printText(toPrint3);
        printText(toPrint4);
        g.status = false;
      }
    }
  }
}

// rest function, one of the moves for player
// The player's daySinceLastSleep will be reset to 0
// such that the chance of crashing will decrease dramatically
void rest(player::PlayerInfo &p, game::GameStatus &g){
  restTransition(p, g);
  p.daySinceLastSleep = 0;
  incrementClock(g);
  string toPrint1 = "You feel energetic!\n";
  printText(toPrint1);
}
void work(player::PlayerInfo &p, game::GameStatus &g){
  workTransition(p, g);
  p.daySinceLastSleep += incrementClock(g);
  int moneyGot = randomfunc(2000, 30000);
  p.balance += moneyGot;
  string toPrint1 = "You have earned $" + to_string(moneyGot); 
  string toPrint2 = "Your total balance is: $" + to_string(p.balance) + "\n";
  // cout<<"You have earned $"<<moneyGot<<'\n'<<endl;
  printText(toPrint1);
  printText(toPrint2);
}


// quit function, display end message, accepts and returns nothing
void quit(){
  printText("Thanks for playing!");
  exit(0);
}


// shop function, creates a shop for player to buy
// in game items
// accepts player::PlayerInfo and returns nothing
void shop(player::PlayerInfo &p){
  int gasQty = 0, foodQty = 0, partsQty = 0;
  int gasPrice = 20, foodPrice = 20, partsPrice = 4000;
  char option;
  while(true){
    clearScreen();

    //printing stop UI
    cout<<"-------- Your Trusty Store ------"<<endl; // potentially we could append the country name to make it more dynamic
    cout<<"---------------------------------"<<endl;
    cout<<"1. Gas                    "<<gasQty<<'x'<<"    "<<'$'<<gasQty*gasPrice<<endl;
    cout<<"2. Food                   "<<foodQty<<'x'<<"    "<<'$'<<foodQty*foodPrice<<endl;
    cout<<"3. Spare Car Parts        "<<partsQty<<'x'<<"    "<<'$'<<partsQty*partsPrice<<endl;
    cout<<"4. Checkout and Leave\n"<<endl;
    int totalCost = gasQty*gasPrice+foodQty*foodPrice+partsQty*partsPrice, remainingBalance = p.balance-totalCost;
    cout<<"Total cost: "<<totalCost<<endl;
    cout<<"Your current balance: "<<remainingBalance<<endl;
    cout<<"What would you like to buy? (1/2/3/4)"<<endl; cin>>option;

    // switcher for different cases
    if(option == '1'){
      if(p.shopCounter == 0){
        printText("To travel 2,000km, you will need at least 140L of gasoline. It is recommended you should get an excess of 20-30L of gasoline.");
      }
      printText("How many liters(L) of gasoline would you want to buy? It's $20/L. (Max: 2500)");
      while(true){
        cin>>gasQty;
        if((gasQty >= 0 && gasQty <= 2500) || gasQty == 0){
          if(remainingBalance - gasQty*gasPrice >= 0){
            break;
          }
        }
      }
    } else if(option == '2'){
      if(p.shopCounter == 0){
        printText("It's recommended that you get at least 110kg of food for the journey.");
      }
      printText("How many kilograms of food would you want? It's $10/kg. (Max: 2500) ");
      while(true){
        cin>>foodQty;
        if((foodQty > 0 && foodQty <= 2500) || foodQty == 0){
          if(remainingBalance - foodQty*foodPrice >= 0){
            break;
          }
        }
      } 
    } else if(option == '3'){
      if(p.shopCounter == 0){
        printText("It's recommended that you get at least 2-3 spare tires to aid you in your journey.");
      }
      printText("How many tires would you like to buy? It's 4000/part. (Max: 2500)");
      while(true){
        cin>>partsQty;
        if((partsQty >= 0 && partsQty <= 2500) || partsQty == 0){
          if(remainingBalance - partsQty*partsPrice >= 0){
            break;
          }
        }
      }
    } else if(option == '4'){
      char pref;
      cout<<"The total cost is "<<totalCost<<endl;
      cout<<"Your remaining balance will be "<<remainingBalance<<endl;
      cout<<"Is there anything else you would like to buy? (y/n)"<<endl; cin >> pref;
      if(pref == 'n'){
        p.balance = remainingBalance;
        p.carParts += partsQty;
        p.fuel += gasQty;
        p.hunger += foodQty;
        p.shopCounter += 1; // signifies that first playthrough is over once incremented from 0
        break;
      }
    }
  }
}

// hitchhiker, abandoned function
void hitchhiker(){

}


// status function
// display player location and other
// essential information
// accepts player::PlayerInfo and game::GameStatus
// and returns nothing
void status(player::PlayerInfo &p, game::GameStatus &g){
  string toPrint1 = "You are currently at " + g.destinations[p.location].name + ".";
  string toPrint2 = "Balance: " + to_string(p.balance) + " hunger: " + to_string(p.hunger);
  string toPrint3 = "HP: " + to_string(p.HP);
  string toPrint4 = "Fuel: " + to_string(p.fuel) + " CarParts: " + to_string(p.carParts);
  string toPrint5 = "You have " + to_string(g.daysLeft) + " days left and you have not sleep for " + to_string(p.daySinceLastSleep) +" days.";
  printText(toPrint1);
  printText(toPrint2);
  printText(toPrint4);
  // printText(toPrint3);
  printText(toPrint5);
}


// checkHitchAvailable, abandoned function
bool checkHitchAvailable(player::PlayerInfo){
  return false; // placeholder
}


// invalidInput function, generate random string if
// player has wrong input. accepts nothing and
// returns nothing
// the fallback if there is an invalid input for any move
void invalidInput(){
  srand(time(NULL));
  int value = rand() % 10 + 1;
  switch(value){
    case 1:
    case 2:
    case 3:
    case 4: {
      printText("I don't seem to know what you're asking for. Try again.");
      break;
    }
    case 5:
    case 6:
    case 7: {
      printText("Are you feeling too tired? I'm not sure what you're asking for.");
      break;
    }
    case 8:
    case 9:
    case 10: {
      printText("Try again! I might just understand you this time around");
    }
  }
} 


// randomfunc function,
// random number generator using system entropy
// (true random using noise generated from system)
// accepts 2 integer input as range and returns
// an integer
int randomfunc(int i, int j) {
  std::random_device rd;
  std::uniform_int_distribution<> randgener(i, j);  
  return randgener(rd);
}


// incrementClock function,
// increase day clock randomly by 2-7 days
// ran every time a move is done
// accepts game::GameStatus as input
// and returns an integer (how many days passed)
int incrementClock(game::GameStatus &g){
  int dayPassed = randomfunc(2, 7); 
  g.day += dayPassed;
  g.daysLeft -= dayPassed;
  string toPrint = to_string(dayPassed) + " days has passed. It is now day " + to_string(g.day) + ".";
  printText(toPrint);
  return dayPassed;
}


// gameOver function,
// check if game has ended
// accepts player::PlayerInfo and game::GameStatus
// returns true if gameOver, else return false;
bool gameOver(player::PlayerInfo &p, game::GameStatus &g){
  
  if (g.destinations[p.location].isEnd || p.fuel <= 0 || p.HP <= 0 || p.hunger <= 0) {
    return true;
  }
  if (g.daysLeft > 0) {
    return false;
  }
  return true;
  } // return true if game over


// checkWin function,
// check if player has won the game
// or not
// accepts player::PlayerInfo and game::GameStatus
// as input and return true if the player won,
// else returns false
bool checkWin(player::PlayerInfo &p, game::GameStatus &g){
  if (g.destinations[p.location].isEnd) {
    return true;
  }
  return false;
}