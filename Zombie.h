#ifndef ASSIGNMENT5_ZOMBIE_H
#define ASSIGNMENT5_ZOMBIE_H

#include "Creature.h"

class Zombie : public Creature {

 public:
    Zombie();
    ~Zombie();
    double getPower()const override;
    int getDefense()const override;
    int getCost()const override;
    void specialSkill();
//    void Attack(Creature* attackedCreature)const override;

};

#endif //ASSIGNMENT5_ZOMBIE_H
