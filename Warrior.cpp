//
// Created by ise on 23/12/18.
//

#include "Warrior.h"

Warrior::Warrior(char* iheroName):Hero()
{
    strcpy(heroName,iheroName);
    type = "Warrior";
}

Warrior::~Warrior(){}


/*
string Warrior::getType()const
{
    return type;
}

char* Warrior::getName() const
{
    char *tempName = NULL;
    tempName = new char[strlen(heroName)];
    strcpy(tempName,heroName);
    return tempName;
}
*/


string Warrior::printCreatures() const
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

void Warrior::specialSkill()
{
    this->increaseGold(50);
}





