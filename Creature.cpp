#include "Creature.h"

Creature::Creature(){}

Creature::~Creature(){}

void Creature::showDetails() const
{
    cout << "Attack level: " << getPower() << ", Defense level: " << getDefense() << endl;
}

