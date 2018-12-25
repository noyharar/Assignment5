
#include "Vampire.h"


Vampire :: Vampire(){
    power = 4;
    defense = 4;
    cost = 80;
}

Vampire::~Vampire(){}

int Vampire :: getPower()
{
    return power;
}

int Vampire :: getDefence()
{
    return defense;
}