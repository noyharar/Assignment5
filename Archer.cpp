#include "Archer.h"


Archer :: Archer() {
    power = 5;
    defense = 4;
    cost = 90;
}

Archer :: ~Archer() {}

double Archer :: getPower() const
{
    return power;
}

int Archer ::getDefense() const
{
    return defense;
}

int Archer :: getCost()const
{
    return cost;
}

void Archer :: specialSkill(){
    power *= 1.2;
}

void Archer::revertSpecialSkill()
{
    power /= 1.2;
}

//void Archer :: Attack(Creature *attackedCreature) const{}
