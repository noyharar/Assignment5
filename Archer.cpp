#include "Archer.h"


Archer :: Archer() {
    power = 5;
    defence = 4;
    cost = 90;
}

Archer :: ~Archer() {}

int Archer :: getPower()
{
    return power;
}

int Archer :: getDefence()
{
    return defence;
}

void Archer :: specialSkill(){
    defence *= 1.2;
}