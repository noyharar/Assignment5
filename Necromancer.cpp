//
// Created by ise on 23/12/18.
//

#include "Necromancer.h"
#include "Zombie.h"


Necromancer::Necromancer():Hero()
{
    type = getType();
}

//Necromancer::Necromancer(char *iheroName):Hero()
//{
//    strcpy(heroName,iheroName);
//    type = "Necromancer";
//}

Necromancer::~Necromancer(){}


string Necromancer::getType() const
{
    return "Necromancer";
}

char *Necromancer::getName() const
{
    char *tempName = NULL;
    tempName = new char[strlen(heroName)];
    strcpy(tempName,heroName);
    return tempName;
}
//
//void Necromancer::specialSkill() const
//{
//    Zombie zomb;
//    this->AddCreatureToList(&zomb);
//}
