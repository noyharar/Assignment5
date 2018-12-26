#include "Hero.h"

CreatureData :: CreatureData(){
    numOfCreature = 0;
    creature = NULL;
}
CreatureData :: CreatureData(Creature* cr, int num)
{
    creature = cr;
    numOfCreature = num;
}

CreatureData :: ~CreatureData() {}

Hero :: Hero(){
    goldQty = 750;
    Zombie* zombie = new Zombie();
    Wizard* wizard = new Wizard();
    Vampire* vampire = new Vampire();
    Archer* archer = new Archer();
    Black_Dragon* bDrag = new Black_Dragon();

    CreatureData cr0 = CreatureData(bDrag,0);
    CreatureData cr1 = CreatureData(wizard,0);
    CreatureData cr2 = CreatureData(archer,0);
    CreatureData cr3 = CreatureData(vampire,0);
    CreatureData cr4 = CreatureData(zombie,0);

    CreatureData* cList = new CreatureData[5] ;

    cList[0] = cr0;
    cList[1] = cr1;
    cList[2] = cr2;
    cList[3] = cr3;
    cList[4] = cr4;
}

Hero ::~Hero() {}

