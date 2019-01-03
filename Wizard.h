#ifndef ASSIGNMENT5_WIZARD_H
#define ASSIGNMENT5_WIZARD_H

#include "Creature.h"

class Wizard : public Creature{
 private:


 public:
    Wizard();
    ~Wizard();
    virtual double getPower()const override;
    virtual int getDefense()const override;
    virtual int getCost()const override;
    virtual void specialSkill();
    virtual void revertSpecialSkill();

};


#endif //ASSIGNMENT5_WIZARD_H
