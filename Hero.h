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
protected:
    char* heroName;
    int goldQty;//between 0-2500
    CreatureData* creatureList;
    string type;


public:
    Hero();
    ~Hero();
    virtual string getType() const =0;
    void getMoney();
   // void attackOpponent(Hero);
    void heroDetails();
    void specialSkill();
    bool legalName(char* name);
   // void heroDetails();
    int getGold()const;
    void increaseGold(int amount);
    void decreaseGold(int amount);
    Hero& getHero();


    //    virtual void buyCreatures()=0;
    char* getName()const;
//    virtual void attackOpponent(/*Hero h1*/)=0;//How do i get a Hero Type variable
    virtual string printCreatures()const=0;
//    virtual void specialSkill()=0;
//    virtual void AddCreatureToList(Creature *c1)=0;



};
class CreatureData{
public:
    int numOfCreature;
    Creature* creature;
    CreatureData();
    CreatureData(Creature* cr, int num);
    ~CreatureData();
};


#endif //ASSIGNMENT5_HERO_H
