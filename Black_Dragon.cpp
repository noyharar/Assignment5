
#include "Black_Dragon.h"

Black_Dragon :: Black_Dragon() {
    power = 5;
    defense = 4;
    cost = 90;
}

Black_Dragon :: ~Black_Dragon() = default;

int Black_Dragon :: getPower()
{
    return power;
}

int Black_Dragon :: getDefence()
{
    return defense;
}