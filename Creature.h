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
    virtual ~Creature();
    virtual void Attack(Creature* attackedCreature)const=0;
    void showDetails()const;
    virtual int getPower()const=0;
    virtual int getDefense()const=0;
    virtual void specialSkill()const=0;



};
#endif //Creature_H