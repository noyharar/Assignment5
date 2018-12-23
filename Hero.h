#ifndef ASSIGNMENT5_HERO_H
#define ASSIGNMENT5_HERO_H

class Hero{
private:

    char* heroName[31];
    int goldQty;//between 0-2500
    Creature creatureList[5];


public:

    Hero();
    ~Hero();
    void buyCreatures();
    void getMoney();
    void attackOpponent(Hero);
    void heroDetails();
    void specialSkill();



};

#endif //ASSIGNMENT5_HERO_H
