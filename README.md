# ENGG1340 Course Project 2020/2021

## Team members (Alphabetical Order)
James & Collin
 

## Game description
It is the modern era of the 21st Century and Christmas is quickly nearing! Like many others, you're gearing up
for the winter season to visit your parents to celebrate with them. However, your parents live
all the way on the other side of the world making meeting them less than trivial. Unfortunately, this 
alternate timeline of the universe has no signs of an aviation industry making air travel impossible! 
Fortunately for you, you own a high-speed supercar and are determined to celebrate with them. 

Your goal is to cross the other side of the globe from Hong Kong to Argentina by car (2,000 kilometers). 
You start on November 1st with the hopes of making it to Argentina by December 25. The journey won't be easy - 
every single day will cost you resources and with your car being driven at full speed for long periods of time,
it could break down at any time! You can rest and sleep to recover your energy or keep driving and play a game 
of chance.. Do anything to make it to the end. 

## List of Features Planned to be fulfilled
### 1. Difficulty
Players can choose their preferred playstyle by starting earlier to have more time to reach their destination, 
or have less time for a challenge. Medium is the default difficulty.

* Story Mode: No time limit
* Easy: September(4 months)
* Medium: October(3 months)
* Hard: November(2 months) 

### 2. Landmark Interactions
During the journey, the player will have an option to stop at certain landmarks(cities/countries) as a stopgap 
to replenish supplies and energy. Save/Load functionality are found in these spots.

* Replenish Resources
  * Hunger
  * Fuel
  * Sleep (Energy)
* Trade with the local residents
* Save/Load game
### 3. Status Model
It is crucial to keep the player informed of their current resources so they can make informed decisions.

* Hunger Bar
* Points System
  * More distance, more points
* Map System
  * Display where player currently is and show nearby/final destinations  
* Day Counter
  * Display how much time the player has left until December 25


### 4. Sleep
* Choosing to rest
  * Lose days but gain back energy
* Choosing not to rest
  * Save days but increase chance to crash (function of t time spent without resting)
    * Crashing loses days and $$

### 5. Working
Working will give them money but will result in lost time. Choosing not to work allows them to 
continue on driving but eventually, they will run out of resources. 

## Coding Elements
### 1. Generation of random game sets or events
For each turn the player takes, they will be given three options:
- Drive
  - Increments the distance counter by 200-400 kilometers and takes 2-7 days randomly
- Rest 
  - Increase HP by 1 (Up to a maximum of 3) and takes 2-7 days randomly
- Work 
  - Increase $$ by $4000 and takes 2-7 days randomly

### 2. Data structures for storing game status

Inside the playerInfo struct, player specific information will be stored, including:
- name, in the form of string
- hunger, in the form of integer
- balance, in the form of integer
- fuel, in the form of integer
- daySinceLastSleep, in the form of integer
- HP, in the form of integer
- carParts, in the form of integer
- shopCounter, in the form of integer, to count how many times player opened shop
- location, in the form of integer, to track which destination the player currently is in.
  
Inside the gameStatus struct, game specific information will be stored, including:
- difficulty, in the form of string
- day, in the form of integer
- status, in the form of boolean
- daysLeft, in the form of integer
- destinations, in the form of Dest vector
- GameStatus() function, which will output game information.

Inside the destination struct, location information will be stored, including:
- name, in the form of string
- description, in the form of string
- isEnd, in the form of boolean, tracking whether this node is the end of the game.

### 3. Dynamic memory management

Player's statistics and information will be declared in the very beginning of the program stored in 2 structs.
Destination information will be stored as a struct inside a vector in gameStatus.
The two structs will be updated each round.
Since this program does NOT use any new or malloc function, memory does not need to be delete or free afterwards.

### 4. File input/output (e.g., for loading/saving game status)

The program can store all the variables into a game.save file upon player's request. Which can then be loaded into the game again.

### 5. Program codes in multiple files

The main.cpp file contains the driver program and basic inputs for this game. Game text, game moves and structs will be declared and stored in separate files.



## Compile Instructions

Run ```make game``` to compile the game.
Do ```./game``` to start the game.