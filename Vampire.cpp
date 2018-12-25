
#include "Vampire.h"


Vampire :: Vampire(){
    power = 4;
    defence = 4;
    cost = 80;
}

int Vampire :: getPower()
{
    return power;
}

int Vampire :: getDefence()
{
    return defence;
}