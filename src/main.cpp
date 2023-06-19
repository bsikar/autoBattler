#include "enemy.hpp"
#include "player.hpp"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>

using namespace std;

void clearInputBuffer() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getRandom() {
  srand(time(nullptr));
  return (rand() % 3) + 1;
}

bool getPlayerDetails(Player &player) {
  string name;

  cout << "Hello adventurer, what is your name: ";
  cin >> name;
  player.name = name;

  while (true) {
    char input;
    cout << endl << "Do you wish to fight? (y/n)" << endl;
    cin >> input;
    input = tolower(input);
    if (input == 'y') {
      return true;
    } else if (input == 'n') {
      cout << "Very well..." << endl;
      return false;
    } else {
      cout << "You did not enter a valid input, please try again.";
      clearInputBuffer();
    }
  }
}

void assignClass(Player &player) {
  int choice;
  string options = "(1. Knight, 2. Archer, 3. Footman)";
  cout << "Time to choose what class you want!" << endl
       << "Select from the following: " << options << endl;
  cin >> choice;

  while (true) {
    switch (choice) {
    case 1: {
      player = Knight(player.name);
      return;
    }
    case 2: {
      player = Archer(player.name);
      return;
    }
    case 3: {
      player = Footman(player.name);
      return;
    }
    default:
      cout << endl
           << "Please enter a valid input. " << options
           << endl; // Keeps looping until an appropriate input given
      clearInputBuffer();
      cin >> choice; // Gets input again SO IT DOESNT LOOP FOREVER
    }
  }
}
void assignEnemy(const string &playerName, Enemy &enemy) {
  switch (getRandom()) {
  case 1: {
    enemy = Bandit();
    break;
  }
  case 2: {
    enemy = ExperiencedBandit();
    break;
  }
  default: {
    enemy = BanditLeader();
  }
  }

  cout << "Prepare for battle " << playerName << "!" << endl;
  cout << "You have encountered a " << enemy.name << "!\n" << endl;
}

void battleSequence(Player &player, Enemy &enemy) {
  while (player.health > 0 && enemy.health > 0) {
    bool playerAttcked = false;
    bool enemyAttacked = false;

    if (player.speed >= enemy.speed) {
      enemy.health -= player.attack;
      playerAttcked = true;
      cout << "You are faster, you did " << player.attack
           << " damage, the enemy is at " << enemy.health << endl;
    } else {
      player.health -= enemy.attack;
      enemyAttacked = true;
      cout << "The enemy is faster, they did " << enemy.attack
           << " damage, you are at " << player.health << endl;
    }

    if (playerAttcked) {
      player.health -= enemy.attack;
      cout << "The enemy attacked, they did " << enemy.attack
           << " damage, you are at " << player.health << endl;
    } else {
      enemy.health -= player.attack;
      playerAttcked = true;
      cout << "You attacked, you did " << player.attack
           << " damage, the enemy is at " << enemy.health << endl;
    }
  }

  if (player.health > 0) {
    player.amountKilled += 1;
    cout << "You have slain an enemy!" << endl
         << "Your amount killed is: " << player.amountKilled << endl;
  } else {
    cout << "OH NOOO, You're dead!" << endl
         << "Your amount killed is: " << player.amountKilled << endl;
  }
}

bool promptForAnotherBattle(const Player &player, Enemy &enemy) {
  if (player.health <= 0) {
    return false;
  }

  char rematchInput;
  cout << "Would you like to fight again? (y/n): ";
  cin >> rematchInput;

  while (true) {
    if (tolower(rematchInput) == 'y') {
      cout << "Prepare for the next challenger!." << endl << endl;
      assignEnemy(player.name, enemy);
      return true;
    } else if (tolower(rematchInput) == 'n') {
      cout << "Leaving already? Anyways, you have slain " << player.amountKilled
           << " enemies." << endl
           << endl;
      return false;
    } else {
      clearInputBuffer();
      cout << "Error: Please enter valid value: ";
    }
  }
}

int main() {
  char rematchInput = ' ';
  bool rematch = false;
  Enemy enemy;
  Player player;

  if (!getPlayerDetails(player)) {
    return 0;
  }

  assignClass(player);
  player.displayStats();
  assignEnemy(player.name, enemy);

  do {
    battleSequence(player, enemy);
  } while (promptForAnotherBattle(player, enemy));

  clearInputBuffer();
  player.displayStats();
  cout << "Press Enter to finish" << endl;
  cin.get();

  return 0;
}
