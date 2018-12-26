
#ifndef ASSIGNMENT5_BLACK_DRAGON_H
#define ASSIGNMENT5_BLACK_DRAGON_H

#include "Creature.h"

class Black_Dragon : public Creature{
public:
    Black_Dragon();
    ~Black_Dragon() override;
    double getPower() const override ;
    int getDefense() const override ;
    void Attack(Creature* attackedCreature)const override;
    int getCost()const override;
};


#endif //ASSIGNMENT5_BLACK_DRAGON_H
