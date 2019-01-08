#include <limits>
#include "Thief.h"

Thief:: Thief(string& iHeroName):Hero(iHeroName)
{
    type = getType();
}
//
//Thief::Thief(char *iheroName):Hero()
//{
//    strcpy(heroName,iheroName);
//    type = "Thief";
//}


Thief::~Thief()
{

}

// Gets the Type of the hero

string Thief::getType() const
{
    return "Thief";
}


void Thief::specialSkill()
{
    int theAmountToSteal = 70;
    cout << "Please insert hero name:" << endl;
    string getHeroName = "";
    cin.ignore ();
    getline (cin, getHeroName);
    Hero* stealFromHim = searchHeroByName(getHeroName);
    if (stealFromHim != NULL)
    {
        Hero& refToSteal = *stealFromHim;
        specialSkilled(refToSteal);
    } else
    {
        cout << "There is no such Hero" << endl;
    }
}

/// Steals 70 Gold Pieces from a hero.
/// In order to call this method first retrieve a reference to a hero
/// \param h1 - Reference to the Hero to steal from
void Thief::specialSkilled(Hero& h1){


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


