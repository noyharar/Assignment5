//
// Created by ise on 23/12/18.
//

#ifndef ASSIGNMENT5_THIEF_H
#define ASSIGNMENT5_THIEF_H

#include "Hero.h"

class Thief : public Hero{


 public:

  Thief(char* heroName);
  ~Thief();
//  string getType()const override;
//  char* getName()const override;

//  void buyCreatures() override;
//  void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
  string printCreatures()const override;
  void specialSkill(Hero &h1);
//  void AddCreatureToList(Creature *c1)override;


};


#endif //ASSIGNMENT5_THIEF_H
