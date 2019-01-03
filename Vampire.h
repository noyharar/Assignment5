#ifndef ASSIGNMENT5_VAMPIRE_H
#define ASSIGNMENT5_VAMPIRE_H

#include "Creature.h"


class Vampire : public Creature{

public:
    Vampire();
    ~Vampire();
    virtual double getPower()const override;
    virtual int getDefense()const override;
    virtual int getCost()const override;
    virtual void specialSkill();
    virtual void revertSpecialSkill();



};


#endif //ASSIGNMENT5_VAMPIRE_H
