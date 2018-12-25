#include "Creature.h"

Creature::Creature()
{
//    this->name = "EmptyCreature";
//    this->cost = 0;
//    this->defense = 0;
//    this->power = 0;
}

//Creature::Creature(string iName, int iPower, int iDefense, int iCost)
//{
//    name = iName;
//    power = iPower;
//    defense = iDefense;
//    cost = iCost;
//}

void Creature::showDetails() const
{
    cout << "Attack level: " << power << ", Defense level: " << defense << endl;
}

int Creature::getPower() const
{
    return this->power;
}

int Creature::getDefense() const
{
    return this->defense;
}


void Creature::Attack(Creature &attackedCreature)
{

}