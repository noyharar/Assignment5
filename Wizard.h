#ifndef ASSIGNMENT5_WIZARD_H
#define ASSIGNMENT5_WIZARD_H

#include "Creature.h"

class Wizard : public Creature{
 private:


 public:
    Wizard();
    ~Wizard();
    double getPower()const override;
    int getDefense()const override;
    void specialSkill();
    void Attack(Creature* attackedCreature)const;
};


#endif //ASSIGNMENT5_WIZARD_H
