
#ifndef ASSIGNMENT5_THIEF_H
#define ASSIGNMENT5_THIEF_H

#include "Hero.h"

class Thief : public Hero{
 private:
  void specialSkilled(Hero& h1);
 public:
    Thief();
  //  Thief(char* heroName);
    ~Thief();
    string getType()const override;
//  void attackOpponent(/*Hero h1*/)override;//How do i get a Hero Type variable
    void specialSkill() override;

//  void AddCreatureToList(Creature *c1)override;


};




#endif //ASSIGNMENT5_THIEF_H
