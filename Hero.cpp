#include <limits>
#include "Hero.h"
#include <istream>
#include "HeroesException.h"

map<string,Hero*> Hero::allHeros;

CreatureData :: CreatureData(){
    numOfCreature = 0;
    creature = NULL;
}
CreatureData :: CreatureData(Creature* cr,string name, int num)
{
    creName = name;
    creature = cr;
    numOfCreature = num;
}

CreatureData :: ~CreatureData() {

}

/////////////////////////////////////////////////////////////////

Hero :: Hero(){

    goldQty = 750;

    Zombie* zombie = new Zombie();
    Wizard* wizard = new Wizard();
    Vampire* vampire = new Vampire();
    Archer* archer = new Archer();
    Black_Dragon* bDrag = new Black_Dragon();

    CreatureData cr0 = CreatureData(bDrag,"Black_Dragon",0);
    CreatureData cr1 = CreatureData(wizard,"Wizard",0);
    CreatureData cr2 = CreatureData(archer,"Archer",0);
    CreatureData cr3 = CreatureData(vampire,"Vampire",0);
    CreatureData cr4 = CreatureData(zombie,"Zombie",0);

    creatureList  = new CreatureData[5] ;

    creatureList[0] = cr0;
    creatureList[1] = cr1;
    creatureList[2] = cr2;
    creatureList[3] = cr3;
    creatureList[4] = cr4;
}

Hero::Hero(string &name)
{
    heroName = name;
    goldQty = 750;

    Zombie* zombie = new Zombie();
    Wizard* wizard = new Wizard();
    Vampire* vampire = new Vampire();
    Archer* archer = new Archer();
    Black_Dragon* bDrag = new Black_Dragon();

    CreatureData cr0 = CreatureData(bDrag,"Black_Dragon",0);
    CreatureData cr1 = CreatureData(wizard,"Wizard",0);
    CreatureData cr2 = CreatureData(archer,"Archer",0);
    CreatureData cr3 = CreatureData(vampire,"Vampire",0);
    CreatureData cr4 = CreatureData(zombie,"Zombie",0);

    creatureList  = new CreatureData[5] ;

    creatureList[0] = cr0;
    creatureList[1] = cr1;
    creatureList[2] = cr2;
    creatureList[3] = cr3;
    creatureList[4] = cr4;

}
Hero ::~Hero() {
  for (int i = 0; i < 5 ; ++i)
    {
      delete creatureList[i].creature;
    }
    delete[]creatureList;
}



int Hero::getGold() const
{
    return goldQty;
}

/// Print the Hero Details
void Hero::heroDetails()
{
    cout << getName() << " " << getTypeForPrint() + ":\n" << getGold() << " gold\n";
    printCreatures();

    if(!ifDie()) {
        cout << endl;
    }
}

string Hero:: detailsForGame(){
    string details = "";
    details = type + " " + heroName + " " + to_string(goldQty)+ " ";
    for(int i = 0; i < 5; i++){
        details = details + to_string(creatureList[i].numOfCreature) + " " + creatureList[i].creName +" ";
    }
    return details;
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
/// \return string as the Type of the Hero
string Hero::getTypeForPrint() const
{
    return type;
}

/// Gets the name of the hero
/// \return char* as the name of the hero
string Hero::getName() const
{
    return heroName;
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

void Hero::buyCreatures() {
    int buyMenu;
    cout << "Buy creatures:\n";
    cout << "1. Buy Zombie.\n";
    cout << "2. Buy Archer.\n";
    cout << "3. Buy Vampire.\n";
    cout << "4. Buy Wizard.\n";
    cout << "5. Buy Black Dragon.\n";
    cin >> buyMenu;
    switch (buyMenu) {
        case 1:
            helpToBuy(4);
            break;

        case 2:
            helpToBuy(2);
            break;
        case 3:
            helpToBuy(3);
            break;
        case 4:
            helpToBuy(1);
            break;
        case 5:
            helpToBuy(0);
            break;
        default:
            cout << "please choose a valid number\n";

    }
}

void Hero :: helpToBuy(int index){
    int wantToBuy = 0;
    int totalCost = 0;
    creatureList[index].creature->showDetails();
//    cout << "Please Enter how many creatures you want to buy:\n";
    cin >> wantToBuy;
    totalCost = wantToBuy*(creatureList[index].creature->getCost());
    if(totalCost > goldQty) {
        double insGold = (double)totalCost;
        throw InsufficientGold(insGold);
    }else{
        creatureList[index].numOfCreature += wantToBuy;
        goldQty -= totalCost;
    }
}

/**
 * Prints each Creature of this Hero and its count
 * <NumberOfCreature1> <Creature1_Type>
 */
void Hero :: printCreatures()const{
    string printStr;
    for(int i = 0 ; i < 5 ; i++) {
        if (creatureList[i].numOfCreature > 0) {
            //     if (i < 4) {
            printStr = printStr + to_string(creatureList[i].numOfCreature) + " " + creatureList[i].creName +" ";
        }
    }
    cout << printStr.substr(0, printStr.length() - 1);

}


/**
 * Searches for a Hero in the map of all heroes by its name
 * @param heroByName - The name of the Hero
 * @return Pointer to the Hero with the name heroByName
 */
Hero* Hero::searchHeroByName(const string heroByName)const
{
    map<string,Hero*>::iterator it1;
    it1 = allHeros.find(heroByName);
    if(it1 != allHeros.end())
    {
        return allHeros[heroByName];
    } else
    {
        return NULL;
    }
}

void Hero :: deleteDataFromMap() {
    map<string, Hero *>::iterator it1;
    it1 = Hero::allHeros.begin();
    while (it1 != Hero::allHeros.end()) {
        Hero::allHeros.erase(it1);
        it1++;
    }
}
/**
 * Iterates over the Heroes map and prints them all
 */
void Hero::printAllHeroses()
{
    map<string,Hero*>::iterator it1;
    it1 = allHeros.begin();
    while (it1 != allHeros.end())
    {
        it1->second->heroDetails();
        it1++;
    }

}

/**
 * Prints Hero Name and its type
 * <HeroName1> <Type1>
 */
void Hero::printNameType()const
{
    cout << getName() << " " << getType() << endl;
}
void Hero::printNameType1()const
{
    cout << getName() << " " << getType();
}

bool Hero::attackOpponent()
{
    bool flipTurn = false, thisTurnSpecial = false, AttackedOpSpecial = false;
    int numOfThisTurn,powerOfThisTurn, defenseOfAttackedOp,howManyCan;
    string  Op_Creature;
    Hero* AttackedOp = NULL, *currentAttacker = this, *currentDefender = NULL;
    //check if the attacked name is available in the users names
    cout << "Please insert your opponent name:";
    string getHeroName;
    cin >> getHeroName;
    currentDefender = searchHeroByName(getHeroName);
    if(currentDefender == NULL)
        throw HeroNotExists(getHeroName);

//    while(AttackedOp == NULL){
//        cout << "Please insert your opponent name:" << endl;
//        string getHeroName;
//        cin >> getHeroName;
//        if(getHeroName == this->getName())
//            {
//                AttackedOp == NULL;
//            }else {
//                AttackedOp = searchHeroByName(getHeroName);
//            }
//        }
    //print my hero details
    this->printNameType();
    this->printCreatures();
    cout << endl;
    currentDefender->printNameType();
    currentDefender->printCreatures();
    cout << endl;

    Hero* thisTurn = currentAttacker;
    AttackedOp = currentDefender;

    //fight until someone died
    while(!thisTurn->ifDie() && !AttackedOp->ifDie())
    {
        cout << thisTurn->getName() << "'s turn:" << endl;
        string myCreature, creatureFight;
        //check that the creatures are legal
        creatureFight, myCreature = "";
        //check if the creatures are valid
        try
        {
//            do
//            {
//            }
//            while(indexInList(myCreature) == -1 || indexInList(creatureFight) == -1);
//            cout << "<MY_Creature> <Op_Creature>" << endl;
            cin >> myCreature >> creatureFight;

            if (thisTurn->isAvailableCreacure (myCreature) && AttackedOp->isAvailableCreacure (creatureFight))
            {
                if ((myCreature == "Zombie" && creatureFight == "Archer")
                        || (myCreature == "Archer" && creatureFight == "Black_Dragon"))
                {
                    thisTurn->creatureList[indexInList (myCreature)].creature->specialSkill ();
                    thisTurnSpecial = true;
                }
                if (myCreature == "Black_Dragon" && creatureFight == "Wizard")
                {
                    AttackedOp->creatureList[indexInList (creatureFight)].creature->specialSkill ();
                    AttackedOpSpecial = true;
                }

                //  CreatureData currentAttackedCreature = AttackedOp->creatureList[indexInList(creatureFight)];
                CreatureData thisCreature = thisTurn->creatureList[indexInList (myCreature)];
                numOfThisTurn = thisCreature.numOfCreature;
                powerOfThisTurn = thisCreature.creature->getPower ();
                //   defenseOfAttackedOp = currentAttackedCreature.creature->getDefense();
                defenseOfAttackedOp = AttackedOp->creatureList[indexInList (creatureFight)].creature->getDefense ();

                //check and update how many creatures have been died
                // currentAttackedCreature.numOfCreature -= (numOfThisTurn*powerOfThisTurn)/defenseOfAttackedOp;no
                howManyCan = (numOfThisTurn * powerOfThisTurn) / defenseOfAttackedOp;
                if (AttackedOp->creatureList[indexInList (creatureFight)].numOfCreature <= howManyCan)
                {
                    AttackedOp->creatureList[indexInList (creatureFight)].numOfCreature = 0;
                }
                else
                {
                    AttackedOp->creatureList[indexInList (creatureFight)].numOfCreature -= howManyCan;
                }

                if(thisTurnSpecial)
                {
                    //if this turn creature used its special skill
                    thisTurn->creatureList[indexInList(myCreature)].creature->revertSpecialSkill();
                }

                if(AttackedOpSpecial)
                {
                    //if the attacked creature used its special skill
                    AttackedOp->creatureList[indexInList(creatureFight)].creature->revertSpecialSkill();
                }

                if (!thisTurn->ifDie () && !AttackedOp->ifDie ())
                {
                    if(!flipTurn)
                    {
                        thisTurn = currentDefender;
                        AttackedOp = currentAttacker;
                    } else
                    {
                        thisTurn = currentAttacker;
                        AttackedOp = currentDefender;
                    }
                    flipTurn = !flipTurn;
                    //print the updated details
                    thisTurn->printNameType ();
                    thisTurn->printCreatures ();
                    cout << endl;
                    AttackedOp->printNameType ();
                    AttackedOp->printCreatures ();
                    cout << endl;
                }
            }
        }
        catch (HeroesException& e)
        {
            e.Handle ();
        }
    }
    //if someone died - no creatures
    if(this->ifDie()){
        cout << "You have been perished\n";
        return true;
    }else {
        this->increaseGold (currentDefender->getGold ());
        cout << "You have been victorious\n";
        return false;
    }
}


/**
 * Searches for the index of the Creature
 * for example Black_Dragon is index 0
 * @param creacureName - String of the Creature Name \"Black_Dragon\"
 * @return the index of the Creature
 */
int Hero :: indexInList(string creatureName){
    if(creatureName == "Black_Dragon")
    {
        return  0;
    }
    else if (creatureName == "Wizard")
    {
        return 1;
    }
    else if (creatureName == "Archer")
    {
        return 2;
    }
    else if (creatureName == "Vampire")
    {
        return  3;
    }
    else if(creatureName == "Zombie") {
        return  4;
    }
    throw IncorrectAttack(creatureName);
}

/**
 * Checks whether or not the Hero is Perished
 * AKA all of its creatures are dead
 *
 * @return false if all of the Hero's Creatures are dead
 */
bool Hero :: ifDie(){
    int sum = 0;
    for(int i = 0; i < 5 ; i++) {
        sum += creatureList[i].numOfCreature;
    }
    if (sum == 0){
        return true;
    }else{
        return false;
    }
}

/**
 * Checks whether or not the Hero has more Creature from the type creatureName
 * @param creatureName - the type of the creature needed
 * @return true if the Hero has more Creature of type creatureName
 */
bool Hero :: isAvailableCreacure(string creatureName){
    try
    {

        int index = indexInList (creatureName);

        if (creatureList[index].numOfCreature > 0)
        {
            return true;
        }
        throw IncorrectAttack(creatureName);
    }
    catch (IncorrectAttack& e)
    {
        throw e;
    }
}