#ifndef ASSIGNMENT5_ZOMBIE_H
#define ASSIGNMENT5_ZOMBIE_H

#include "Creature.h"

class Zombie : public Creature {

public:
    Zombie();
    ~Zombie();
    int getPower();
    int getDefence();
    void specialSkill();
};

#endif //ASSIGNMENT5_ZOMBIE_H
