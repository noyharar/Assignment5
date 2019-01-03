
#ifndef ASSIGNMENT5_BLACK_DRAGON_H
#define ASSIGNMENT5_BLACK_DRAGON_H

#include "Creature.h"

class Black_Dragon : public Creature{
public:
    Black_Dragon();
    ~Black_Dragon() override;
    virtual double getPower()const override;
    virtual int getDefense()const override;
    virtual int getCost()const override;
    virtual void specialSkill();
    virtual void revertSpecialSkill();

};

#endif //ASSIGNMENT5_BLACK_DRAGON_H
