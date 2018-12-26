
#ifndef ASSIGNMENT5_ARCHER_H
#define ASSIGNMENT5_ARCHER_H

#include "Creature.h"

class Archer : public Creature{

public:
    Archer();
    ~Archer();
    double getPower()const override;
    int getDefense()const override ;
    void specialSkill();
    void Attack(Creature* attackedCreature)const override;
    int getCost()const override;


};


#endif //ASSIGNMENT5_ARCHER_H
