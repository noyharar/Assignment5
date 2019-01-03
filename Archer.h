
#ifndef ASSIGNMENT5_ARCHER_H
#define ASSIGNMENT5_ARCHER_H

#include "Creature.h"

class Archer : public Creature{

public:
    Archer();
    ~Archer();
    virtual double getPower()const override;
    virtual int getDefense()const override;
    virtual int getCost()const override;
    virtual void specialSkill();
    virtual void revertSpecialSkill();


};


#endif //ASSIGNMENT5_ARCHER_H
