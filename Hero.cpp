#include "Hero.h"


Hero ::Hero() {
    goldQty = 750;
}

Hero::~Hero(){}


int Hero::getGold() const
{
    return goldQty;
}

/// Print the Hero Details
void Hero::heroDetails()
{
    cout << getName() << " " << getType() << " " << getGold() << " " << printCreatures() << endl;
}

/// Increases the number of gold of the Hero by amount
/// Max value of gold after increase is 2500
/// \param amount - how much gold to increase
void Hero::increaseGold(int amount)
{
    if(amount >= 0)
    {
        if(this->goldQty + amount >= 2500)
        {
            this->goldQty = 2500;
        } else
        {
            this->goldQty += amount;
        }
    }
}

/// In order to get a refernce to a specifc Hero
/// For example it is needed for the specail skill of thief
/// who needs to steal 70 Gold pieces from another Hero
/// \return Reference to this Hero
Hero &Hero::getHero()
{
    return *this;
}

/// Gets the Type of the Hero
/// \return string as the Type of the Hero
string Hero::getType() const
{
    return type;
}

/// Gets the name of the hero
/// \return char* as the name of the hero
char* Hero::getName() const
{
    char *tempName = NULL;
    tempName = new char[strlen(heroName)];
    strcpy(tempName,heroName);
    return tempName;
}

/// Decreases the number of gold of the Hero by amount
/// Min value of gold after decrease is 0
/// \param amount - How much gold to decrease
void Hero::decreaseGold(int amount)
{
    if(amount >= 0)
    {
        if(this->goldQty - amount <= 0)
        {
            this->goldQty = 0;
        } else
        {
            this->goldQty -= amount;
        }
    }
}







