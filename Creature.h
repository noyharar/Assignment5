#ifndef Creature_H
#define Creature_H

#include <string>
#include <iostream>
#include <string.h>
using namespace std;

class Creature
{
protected:
    int power;
    int defense;
    int cost;
  //  string name;

public:


    Creature();
  //  Creature(string,int,int,int);
    ~Creature();
    virtual void Attack(Creature* attackedCreature)const;
    void showDetails()const;
    virtual int getPower() = 0;
    virtual int getDefense()= 0;
    virtual void specialSkill();



};
#endif //Creature_H