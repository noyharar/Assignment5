#include "Hero.h"

CreatureData :: CreatureData(){
    numOfCreature = 0;
    creature = NULL;
}
CreatureData :: CreatureData(Creature* cr, int num)
{
    creature = cr;
    numOfCreature = num;
}

CreatureData :: ~CreatureData() {}

Hero :: Hero(){
    char* name = new char[31];
    heroName = new char[31];
    cout << "Please enter a username:\n";
    cin >> name;
    legalName(name);
    strcpy(heroName,name);
    delete[] name;

    goldQty = 750;

    Zombie* zombie = new Zombie();
    Wizard* wizard = new Wizard();
    Vampire* vampire = new Vampire();
    Archer* archer = new Archer();
    Black_Dragon* bDrag = new Black_Dragon();

    CreatureData cr0 = CreatureData(bDrag,0);
    CreatureData cr1 = CreatureData(wizard,0);
    CreatureData cr2 = CreatureData(archer,0);
    CreatureData cr3 = CreatureData(vampire,0);
    CreatureData cr4 = CreatureData(zombie,0);

    CreatureData* cList = new CreatureData[5] ;

    cList[0] = cr0;
    cList[1] = cr1;
    cList[2] = cr2;
    cList[3] = cr3;
    cList[4] = cr4;
}

Hero ::~Hero() {}


/*
 * need to change this function with errors
 */
bool Hero :: legalName(char* name){

    int length = strlen(name);
    if(length >31){
        cout << "illgal name - error exception\n";
        return false;
    }
    for(int i = 0; i < strlen(name); i++){
        if(!isalpha(name[i]) && !isdigit((int)name[i])){
            cout << "illgal name - error exception\n";
            return false;
        }
    }
    return true;

};

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

///// Gets the Type of the Hero
///// \return string as the Type of the Hero
//string Hero::getType() const
//{
//    return type;
//}

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