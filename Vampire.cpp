
#include "Vampire.h"


Vampire :: Vampire(){
    power = 4;
    defense = 4;
    cost = 80;
}

Vampire::~Vampire(){}

double Vampire :: getPower() const
{
    return power;
}

int Vampire :: getDefense() const
{
    return defense;
}

int Vampire :: getCost()const
{
    return cost;
}

void Vampire :: Attack(Creature *attackedCreature) const{}

