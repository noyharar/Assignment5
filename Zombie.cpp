
#include "Zombie.h"


Zombie :: Zombie(){
    power = 2;
    defense = 5;
    cost = 50;
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

int Zombie :: getCost()const
{
    return cost;
}
void Zombie :: specialSkill(){
    power *= 2;
}

void Zombie ::revertSpecialSkill()
{
    power /= 2;
}

//void Zombie::Attack(Creature *attackedCreature) const
//{
//
//}
