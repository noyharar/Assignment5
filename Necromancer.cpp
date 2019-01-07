//
// Created by ise on 23/12/18.
//

#include "Necromancer.h"
#include "Zombie.h"


Necromancer::Necromancer(string iHeroName):Hero(iHeroName)
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


/**
 * Increase Zombie num;
 */
void Necromancer::specialSkill()
{
    creatureList[4].numOfCreature++;
    cout << "Zombie added successfully" << endl;
}
