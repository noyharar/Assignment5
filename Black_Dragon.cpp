
#include "Black_Dragon.h"

Black_Dragon :: Black_Dragon() {
    power = 5;
    defence = 4;
    cost = 90;
}

Black_Dragon :: ~Black_Dragon() {}

int Black_Dragon :: getPower()
{
    return power;
}

int Black_Dragon :: getDefence()
{
    return defence;
}