
#ifndef ASSIGNMENT5_BLACK_DRAGON_H
#define ASSIGNMENT5_BLACK_DRAGON_H

#include "Creature.h"

class Black_Dragon : public Creature{
public:
    Black_Dragon();
    ~Black_Dragon() override;
    double getPower();
    int getDefense();
//    void Attack(Creature* attackedCreature)const;
};


#endif //ASSIGNMENT5_BLACK_DRAGON_H
