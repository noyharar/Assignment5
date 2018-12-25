#ifndef ASSIGNMENT5_NECROMANCER_H
#define ASSIGNMENT5_NECROMANCER_H


#include "Hero.h"

class Necromancer : public Hero{

 public:

  Necromancer(char* heroName);
  ~Necromancer();
//  string getType()const override;
//  char* getName()const override;

//  void buyCreatures() override;
//  void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
  string printCreatures()const override;
  void specialSkill();
//  void AddCreatureToList(Creature *c1)override;


};


#endif //ASSIGNMENT5_NECROMANCER_H
