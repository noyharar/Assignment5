#include "Hero.h"


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

CreatureData :: ~CreatureData() {}

Hero :: Hero(){
    char* name = new char[31];
    heroName = new char[31];
    cout << "Please enter a username:\n";
    cin >> name;
    while(!legalName(name))
    {
        cout << "Please enter a username:\n";
        cin >> name;
    }
    strcpy(heroName,name);
    delete[] name;
    goldQty = 750;
    allHeros[this->getName()] = this;

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
    cout << getName() << " " << getTypeForPrint() + ":\n" << getGold() << " gold\n";;
    printCreatures();
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

void Hero::buyCreatures() {
    int buyMenu;
    cout << "Buy creatures:\n";
    cout << "1. Buy zombies\n";
    cout << "2. Buy Archers\n";
    cout << "3. Buy Vampire\n";
    cout << "4. Buy Wizard\n";
    cout << "5. Buy Black Dragon\n";
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
    cout << "Please Enter how many creatures you want to buy:\n";
    cin >> wantToBuy;
    totalCost = wantToBuy*(creatureList[index].creature->getCost());
    if(totalCost > goldQty) {
        cout << "You do not have enough gold\n";
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
    for(int i = 0 ; i < 5 ; i++) {
        if (creatureList[i].numOfCreature > 0) {
            if (i < 4) {
                cout << creatureList[i].numOfCreature << " " << creatureList[i].creName << " ";
            } else {
                cout << creatureList[i].numOfCreature << " " << creatureList[i].creName << ".";
            }
        }
    }
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

void Hero::attackOpponent()
{
    int numOfThisTurn,powerOfThisTurn, defenseOfAttackedOp;
    string creatureFight, myCreature;
    Hero* AttackedOp = NULL;
    //check if the attacked name is available in the users names
    while(AttackedOp == NULL){
        cout << "Please insert your opponent name:" << endl;
        string getHeroName;
        cin >> getHeroName;
        AttackedOp = searchHeroByName(getHeroName);
    }
    //print my hero details
    this->printNameType();
    this->printCreatures();
    cout << endl;
    AttackedOp->printNameType();
    AttackedOp->printCreatures();
    Hero* thisTurn = this;

    //fight until someone died
    while(thisTurn->ifNotDie() && AttackedOp->ifNotDie()){
        cout << thisTurn->getName() << "'s turn:" << endl;
        cout << "<MY_Creature> <Op_Creture>" << endl;
        cin >> creatureFight;
        string delim = " ";
        //my hero name
        myCreature = creatureFight.substr(0,creatureFight.find(delim));
        //attacked name
        creatureFight.erase(0,creatureFight.find(delim) + delim.length());
        //check if the creatures are valid
        if(thisTurn->isAvailableCreacure(myCreature) && AttackedOp->isAvailableCreacure(creatureFight))
        {
            CreatureData currentAttacedCreature = AttackedOp->creatureList[indexInList(creatureFight)];
            CreatureData thisCrearture = thisTurn->creatureList[indexInList(myCreature)];

            numOfThisTurn = thisCrearture.numOfCreature;
            powerOfThisTurn = thisCrearture.creature->getPower();
            defenseOfAttackedOp = currentAttacedCreature.creature->getDefense();
            //check and update how many creatures have been died
            currentAttacedCreature.numOfCreature = (numOfThisTurn*powerOfThisTurn)/defenseOfAttackedOp;

            //print the updated details
            this->printNameType();
            this->printCreatures();
            cout << endl;
            AttackedOp->printNameType();
            AttackedOp->printCreatures();
            thisTurn = AttackedOp;
            AttackedOp = this;
        }
    }

    //if someone died - no creatures
    if(!ifNotDie()){
        cout << "You have been perished\n";
    }else{
        cout << "You have been victorious\n";
    }
}


/**
 * Searches for the index of the Creature
 * for example Black_Dragon is index 0
 * @param creatureName - String of the Creature Name \"Black_Dragon\"
 * @return the index of the Creature
 */
int Hero :: indexInList(string creatureName){
    int index;
    if(creatureName == "Black_Dragon")
    {
        index = 0;
    }
    else if (creatureName == "Wizard")
    {
        index = 1;
    }
    else if (creatureName == "Archer")
    {
        index = 2;
    }
    else if (creatureName == "Vampire")
    {
        index = 3;
    }
    else if(creatureName == "Zombie")
    {
        index = 4;
    }
    return index;
}

/**
 * Checks whether or not the Hero is Perished
 * AKA all of its creatures are dead
 *
 * @return false if all of the Hero's Creatures are dead
 */
bool Hero :: ifNotDie(){
    int sum = 0;
    for(int i = 0; i < 5 ; i++) {
       sum += creatureList[i].numOfCreature;
    }
    if (sum == 0){
        return false;
    }else{
        return true;
    }
}

/**
 * Checks whether or not the Hero has more Creature from the type creatureName
 * @param creatureName - the type of the creature needed
 * @return true if the Hero has more Creature of type creatureName
 */
bool Hero :: isAvailableCreacure(string creatureName){
    int index = indexInList(creatureName);

    if (creatureList[index].numOfCreature > 0) {
        return true;
    }
        return false;
}