//
// Created by ise on 23/12/18.
//

#include "Necromancer.h"
#include "Zombie.h"


Necromancer::Necromancer():Hero()
{
    type = getType();
}

Necromancer::Necromancer(char *iheroName):Hero()
{
    strcpy(heroName,iheroName);
    type = "Necromancer";
}

Necromancer::~Necromancer(){}


string Necromancer::getType() const
{
    return "Necromancer";
}
/*
char *Necromancer::getName() const
{
    char *tempName = NULL;
    tempName = new char[strlen(heroName)];
    strcpy(tempName,heroName);
    return tempName;
}
*/

string Necromancer::printCreatures() const
{
    string s;
    /*
     * foreach creature in creatureList
     * {
     *      s = s + printCreature;
     * }
     */

    return s;
}

void Necromancer::specialSkill()
{
    Zombie zomb;
//    this->AddCreatureToList(&zomb);
}
