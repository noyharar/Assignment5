#ifndef ASSIGNMENT5_HERO_H
#define ASSIGNMENT5_HERO_H

#include "Creature.h"
#include "Zombie.h"
#include "Black_Dragon.h"
#include "Wizard.h"
#include "Vampire.h"
#include "Archer.h"

class CreatureData;

class Hero{
public:
    char* heroName;
    int goldQty;//between 0-2500
    CreatureData* creatureList;
    string type;

public:

    Hero();
    ~Hero();


    virtual string getType() const=0;
    void heroDetails();
    bool legalName(char* name);
    int getGold()const;
    void increaseGold(int amount);
    void decreaseGold(int amount);
    string getTypeForPrint() const;
    Hero& getHero();


    void buyCreatures();
    void helpToBuy(int index);
    char* getName()const;
    void printCreatures()const;
//     void attackOpponent(Hero);
//    virtual void attackOpponent(/*Hero h1*/)=0;//How do i get a Hero Type variable
//    virtual void specialSkill() const=0;
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
