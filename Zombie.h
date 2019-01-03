#ifndef ASSIGNMENT5_ZOMBIE_H
#define ASSIGNMENT5_ZOMBIE_H

#include "Creature.h"

class Zombie : public Creature {

 public:
    Zombie();
    virtual ~Zombie();
    virtual double getPower()const override;
    virtual int getDefense()const override;
    virtual int getCost()const override;
    virtual void specialSkill();
    virtual void revertSpecialSkill();
//    void Attack(Creature* attackedCreature)const override;

};

#endif //ASSIGNMENT5_ZOMBIE_H
