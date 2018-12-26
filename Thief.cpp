#include "Thief.h"

Thief:: Thief():Hero()
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

/// Gets the name of the hero
/// \return char* as the name of the hero
char *Thief::getName() const
{
   char *tempName = NULL;
   tempName = new char[strlen(heroName)];
   strcpy(tempName,heroName);
   return tempName;
}



/// Steals 70 Gold Pieces from a hero.
/// In order to call this method first retrieve a reference to a hero
/// \param h1 - Reference to the Hero to steal from
//void Thief::specialSkill() const{
//
////
////    int h1Gold = h1.getGold();
////    if (h1Gold >= 70)
////    {
////        h1.decreaseGold(70);
////        this->increaseGold(70);
////    } else
////    {
////        h1.decreaseGold(h1Gold);
////        this->increaseGold(h1Gold);
////    }
//}


