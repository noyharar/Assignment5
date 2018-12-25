#ifndef ASSIGNMENT5_WARRIOR_H
#define ASSIGNMENT5_WARRIOR_H

#include "Hero.h"

class Warrior : public Hero{
 private:

 public:
    Warrior(char* heroName);
    ~Warrior();
//    string getType()const override;
//    char* getName()const override;

//    void buyCreatures() override;
//    void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
    string printCreatures()const override;
    void specialSkill();
//    void AddCreatureToList(Creature *c1)override;



};


#endif //ASSIGNMENT5_WARRIOR_H
