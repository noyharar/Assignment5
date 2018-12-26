
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

void Vampire :: Attack(Creature *attackedCreature) const{}

