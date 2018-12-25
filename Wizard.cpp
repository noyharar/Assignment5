
#include "Wizard.h"



Wizard :: Wizard(){
    power = 8;
    defense = 2;
    cost = 150;

}
Wizard :: ~Wizard(){}

double Wizard :: getPower()const
{
    return power;
}

int Wizard ::getDefense()const
{
    return defense;
}

void Wizard::Attack(Creature *attackedCreature) const
{

}

