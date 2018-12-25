#include "Zombie.h"

Zombie :: Zombie() {
    power = 2;
    defence = 5;
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
    return defence;
}

void Zombie :: specialSkill(){
    defence *= 2;
}