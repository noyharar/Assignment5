#include "Warrior.h"



Warrior::Warrior(string iheroName):Hero(iheroName)
{
    type = getType();
}

Warrior::~Warrior(){}



string Warrior::getType()const
{
    return "Warrior";
}



void Warrior::specialSkill()
{
    this->increaseGold(50);
}



