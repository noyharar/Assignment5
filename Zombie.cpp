
#include "Zombie.h"


Zombie :: Zombie(){
    power = 2;
    defense = 5;
    cost = 50;

//  //  name = "Zombie";
}

Zombie :: ~Zombie() {}

double Zombie :: getPower()const
{
    return power;
}

int Zombie :: getDefense()const
{
    return defense;
}



void Zombie :: specialSkill(){
    defense *= 2;
}

void Zombie::Attack(Creature *attackedCreature) const
{

}
