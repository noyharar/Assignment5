//
// Created by ise on 23/12/18.
//

#include "Thief.h"

Thief::Thief(char *iheroName):Hero()
{
    strcpy(heroName,iheroName);
    type = "Thief";
}


Thief::~Thief()
{

}

/*/// Gets the Type of the hero
/// \return
string Thief::getType() const
{
    return type;
}

/// Gets the name of the hero
/// \return char* as the name of the hero
char *Thief::getName() const
{
    char *tempName = NULL;
    tempName = new char[strlen(heroName)];
    strcpy(tempName,heroName);
    return tempName;
}
*/

/// Creates a string that contains all of this hero Creature details
/// \return String of creatures details
string Thief::printCreatures() const
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

/// Steals 70 Gold Pieces from a hero.
/// In order to call this method first retrieve a reference to a hero
/// \param h1 - Reference to the Hero to steal from
void Thief::specialSkill(Hero &h1)
{

    int h1Gold = h1.getGold();
    if (h1Gold >= 70)
    {
        h1.decreaseGold(70);
        this->increaseGold(70);
    } else
    {
        h1.decreaseGold(h1Gold);
        this->increaseGold(h1Gold);
    }
}


