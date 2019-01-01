
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

int Wizard :: getCost()const
{
    return cost;
}

void Wizard :: specialSkill(){
    defense *= 2;
}

//void Wizard::Attack(Creature *attackedCreature) const {}

