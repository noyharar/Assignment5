
#include "Vampire.h"


Vampire :: Vampire(){
    power = 4;
    defense = 4;
    cost = 80;
}

Vampire::~Vampire(){}

double Vampire :: getPower()
{
    return power;
}

int Vampire :: getDefense()
{
    return defense;
}