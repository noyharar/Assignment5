#ifndef ASSIGNMENT5_NECROMANCER_H
#define ASSIGNMENT5_NECROMANCER_H


#include "Hero.h"

class Necromancer : public Hero{

public:
    Necromancer();
  //  Necromancer(char* heroName);
    ~Necromancer();
    string getType()const;
  char* getName()const;

//  void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
    void specialSkill() override ;
//  void AddCreatureToList(Creature *c1)override;


};
#endif //ASSIGNMENT5_NECROMANCER_H