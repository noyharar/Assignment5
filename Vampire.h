#ifndef ASSIGNMENT5_VAMPIRE_H
#define ASSIGNMENT5_VAMPIRE_H

#include "Creature.h"


class Vampire : public Creature{

public:
    Vampire();
    ~Vampire();
    double getPower();
    int getDefense();

};


#endif //ASSIGNMENT5_VAMPIRE_H
