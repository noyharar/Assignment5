#ifndef ASSIGNMENT5_HERO_H
#define ASSIGNMENT5_HERO_H

#include <string>
#include <map>
#include "Creature.h"
#include "Zombie.h"
#include "Black_Dragon.h"
#include "Wizard.h"
#include "Vampire.h"
#include "Archer.h"

class CreatureData;

class Hero{
public:
    char *heroName;
    int goldQty;//between 0-2500
    CreatureData* creatureList;
    string type;

    static map<string,Hero*> allHeros;

//public:
    Hero();
    Hero(char*);
    ~Hero();

    void deleteDataFromMap();
    virtual string getType() const=0;
    void heroDetails();
    bool legalName(char* name);
    int getGold()const;
    void increaseGold(int amount);
    void decreaseGold(int amount);
    string getTypeForPrint() const;
    Hero& getHero();
    bool ifDie();
    bool isAvailableCreacure(string);
    void printNameType()const;
    int indexInList(string);
    string detailsForGame();



        Hero* searchHeroByName(const string heroByName)const;
    void buyCreatures();
    void helpToBuy(int index);
    char* getName()const;
    void printCreatures()const;
    bool attackOpponent();
//    virtual void attackOpponent(/*Hero h1*/)=0;//How do i get a Hero Type variable
    virtual void specialSkill()=0;
    static void printAllHeroses();
//    virtual void AddCreatureToList(Creature *c1)=0;
};

//////////////////////////////////////////////

class CreatureData{
public:
    int numOfCreature;
    Creature* creature;
    string creName;
    CreatureData();
    CreatureData(Creature*, string, int);
    ~CreatureData();
};


#endif //ASSIGNMENT5_HERO_H
