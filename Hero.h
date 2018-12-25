#ifndef ASSIGNMENT5_HERO_H
#define ASSIGNMENT5_HERO_H

#include "Creature.h"
#include <string>

using namespace std;

class Hero{
 protected:

    char heroName[31];
    int goldQty;//between 0-2500
    string type;

//    char* heroName[31];
//    Creature creatureList[5];

public:
    Hero();
    ~Hero();
    void heroDetails();
    int getGold()const;
    void increaseGold(int amount);
    void decreaseGold(int amount);
    Hero& getHero();

//    virtual void buyCreatures()=0;
    string getType()const;
    char* getName()const;
//    virtual void attackOpponent(/*Hero h1*/)=0;//How do i get a Hero Type variable
    virtual string printCreatures()const=0;
//    virtual void specialSkill()=0;
//    virtual void AddCreatureToList(Creature *c1)=0;
};

#endif //ASSIGNMENT5_HERO_H
