#ifndef PLAYER_CLASSES
#define PLAYER_CLASSES

#include <iostream>

using std::string, std::cout, std::endl;

struct Player {
  string name;
  int health;
  int attack;
  int speed;
  int amountKilled;

  void displayStats() {
    cout << "You have chosen: " << name << ". Your stats are: ";
    cout << "Health: " << health << ", Attack: " << attack
         << ", Speed: " << speed << ", Amount Killed: " << amountKilled << "."
         << endl
         << endl;
  }
};

struct Knight : Player {
  Knight(string name) : Player{"Knight " + name, 100, 10, 6, 0} {}
};

struct Archer : Player {
  Archer(string name) : Player{"Archer " + name, 80, 20, 13, 0} {}
};

struct Footman : Player {
  Footman(string name) : Player{"Footman " + name, 90, 15, 8, 0} {}
};

#endif
