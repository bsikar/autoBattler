#ifndef ENEMY_CLASSES
#define ENEMY_CLASSES

#include <iostream>

using std::string, std::cout, std::endl;

struct Enemy {
  string name;
  int health;
  int attack;
  int speed;
};

struct Bandit : Enemy {
  Bandit() : Enemy{"Bandit", 10, 5, 5} {}
};

struct ExperiencedBandit : Enemy {
  ExperiencedBandit() : Enemy{"ExperiencedBandit", 20, 10, 8} {}
};

struct BanditLeader : Enemy {
  BanditLeader() : Enemy{"BanditLeader", 30, 15, 10} {}
};

#endif
