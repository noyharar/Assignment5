#ifndef ASSIGNMENT5_VAMPIRE_H
#define ASSIGNMENT5_VAMPIRE_H

#include "Creature.h"


class Vampire : public Creature{

public:
    Vampire();
    ~Vampire();
    double getPower() const override;
    int getDefense() const override;
    void Attack(Creature* attackedCreature)const override;
    int getCost()const override;


};


#endif //ASSIGNMENT5_VAMPIRE_H
