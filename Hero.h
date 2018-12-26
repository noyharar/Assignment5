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


public:
    Hero();
    ~Hero();
  //  virtual string getType()=0;
    void buyCreatures();
    void getMoney();
   // void attackOpponent(Hero);
    void heroDetails();
    void specialSkill();
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
