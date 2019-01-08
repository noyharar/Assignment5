#ifndef ASSIGNMENT5_WARRIOR_H
#define ASSIGNMENT5_WARRIOR_H

#include "Hero.h"

class Warrior : public Hero{
private:

public:
    Warrior(string&);
    ~Warrior();
    string getType()const;
//    void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
    void specialSkill();
//    void AddCreatureToList(Creature *c1)override;



};


#endif //ASSIGNMENT5_WARRIOR_H
