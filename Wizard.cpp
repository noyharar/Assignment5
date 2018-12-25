
#include "Wizard.h"
Wizard :: Wizard(){
    power = 8;
    defence = 2;
    cost = 150;
}
Wizard :: ~Wizard(){}

int Wizard :: getPower()
{
    return power;
}

int Wizard :: getDefence()
{
    return defence;
}