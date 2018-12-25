#ifndef ASSIGNMENT5_WIZARD_H
#define ASSIGNMENT5_WIZARD_H

#include "Creature.h"

class Wizard : public Creature{

public :
    Wizard();
    ~Wizard();
    int getPower();
    int getDefence();
    void specialSkill();
};


#endif //ASSIGNMENT5_WIZARD_H
