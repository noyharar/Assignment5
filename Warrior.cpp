#include "Warrior.h"

Warrior::Warrior() : Hero(){
    type = getType();
}

Warrior::Warrior(string iheroName):Hero()
{
//    strcpy(heroName,iheroName);
//    type = "Warrior";
}

Warrior::~Warrior(){}



string Warrior::getType()const
{
    return "Warrior";
}
/*
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



