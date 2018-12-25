#include "Zombie.h"

Zombie :: Zombie() {
    power = 2;
    defense = 5;
    cost = 50;
  //  name = "Zombie";
}

Zombie :: ~Zombie() {}

int Zombie :: getPower()
{
    return power;
}

int Zombie :: getDefence()
{
    return defense;
}

void Zombie :: specialSkill(){
    defense *= 2;
}