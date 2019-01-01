
#include "Black_Dragon.h"

Black_Dragon :: Black_Dragon() {
    power = 9;
    defense = 10;
    cost = 200;
}

Black_Dragon :: ~Black_Dragon() = default;

double Black_Dragon :: getPower() const
{
    return power;
}

int Black_Dragon :: getDefense() const
{
    return defense;
}

int Black_Dragon :: getCost()const
{
    return cost;
}

void Black_Dragon :: specialSkill(){
    cout << "no special skil\n";
}

//void Black_Dragon::Attack(Creature *attackedCreature) const{}
