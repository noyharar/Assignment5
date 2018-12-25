
#include "Wizard.h"
Wizard :: Wizard(){
    power = 8;
    defense = 2;
    cost = 150;
}
Wizard :: ~Wizard(){}

int Wizard :: getPower()
{
    return power;
}

int Wizard :: getDefence()
{
    return defense;
}