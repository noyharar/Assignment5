#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include "Creature.h"
#include "Zombie.h"
#include "Wizard.h"
#include "Hero.h"
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
//#include "Black_Dragon.h"

using namespace std;

void showAllHeros(Hero& h1);

int main() {
//    string test;
//    getline(cin, test);
//    cout << test;
    bool tookMyMoney = false, specailTurn = false;
    int attackMenu, choiceNum, buyMenu;
    int playerTurnNum;
    int insertedPlayers = 0;
    int numOfPlayers;
    numOfPlayers = 2;
    Hero *randomTurns[numOfPlayers];
    for (int i = 0; i < numOfPlayers; ++i) {
        randomTurns[i] = NULL;
    }
    Thief gal;
    Thief gal2;
//    Necromancer noy;
//    Necromancer noy2;
//    Necromancer noy3;
//    Warrior gal3;

    map<string,Hero*>::iterator it1;
    it1 = Hero::allHeros.begin();
    while (insertedPlayers < numOfPlayers && it1 != Hero::allHeros.end()) {
        playerTurnNum = rand() % numOfPlayers;
        if (randomTurns[playerTurnNum] == NULL) {
            randomTurns[playerTurnNum] = &it1->second->getHero();
            it1++;
            insertedPlayers++;
        }
    }


    playerTurnNum = 0;
    cout << "Wellcome <userName" << endl;
    while (1) {
        // print menu
        cout << "What is your next step in the path to victory?\n";
        cout << "1. Attack\n";
        cout << "2. Get daily gold\n";
        cout << "3. Buy creatures\n";
        cout << "4. Show details\n";
        cout << "5. Spacial skill\n";
        cout << "6. End of my turn\n";
        cout << "7. Exit\n";
        // get input from user
        cin >> choiceNum;
        // take action
        switch (choiceNum) {
            case 1:
                cout << "1. Show me my opponents\n";
                cout << "2. Attack hero\n";
                cin >> attackMenu;
                switch (attackMenu) {
                    case 1:
                        showAllHeros(randomTurns[playerTurnNum]->getHero());
                        break;
                    case 2:
                        if(randomTurns[playerTurnNum]->getHero().attackOpponent()) {
                                if (playerTurnNum + 1 >= numOfPlayers) {
                                    playerTurnNum = 0;
                                } else {
                                    playerTurnNum++;
                                }
                                tookMyMoney = false;
                                specailTurn = false;
                            }

                        break;
                    default:
                        cout << "please choose a valid number\n";
                }
                break;
            case 2:
                if(!tookMyMoney)
                {
                    randomTurns[playerTurnNum]->increaseGold(100);
                    tookMyMoney = true;
                }
                break;
            case 3:
                randomTurns[playerTurnNum]->buyCreatures();
                break;
            case 4:
                randomTurns[playerTurnNum]->heroDetails();
                break;
            case 5:
                if(!specailTurn)
                {
//                    try{
//
//                    }
//                    catch exception as e
//                    {
//
//                    }
                    randomTurns[playerTurnNum]->specialSkill();
                    specailTurn = true;
                }
                break;
            case 6:
                if(playerTurnNum + 1 >= numOfPlayers)
                {
                    playerTurnNum = 0;
                } else
                {
                    playerTurnNum++;
                }
                tookMyMoney = false;
                specailTurn = false;
                break;
            case 7:
                exit(0);
            default:
                cout << ("please choose a valid number\n");
        }
    }

        int x; // for BreakPoint
        return 0;
}


void showAllHeros(Hero& h1)
{

    map<string,Hero*>::iterator it1;
    it1 = Hero::allHeros.begin();
    while (it1 != Hero::allHeros.end() )
    {
        if(!(h1.getName() == it1->first)&& it1->second->getType() == "Warrior")
        {
            it1->second->printNameType();
        }
        it1++;
    }
    it1 = Hero::allHeros.begin();
    while (it1 != Hero::allHeros.end() )
    {
        if(!(h1.getName() == it1->first)&& it1->second->getType() == "Thief")
        {
            it1->second->printNameType();
        }
        it1++;
    }
    it1 = Hero::allHeros.begin();
    while (it1 != Hero::allHeros.end() )
    {
        if(!(h1.getName() == it1->first)&& it1->second->getType() == "Necromancer")
        {
            it1->second->printNameType();
        }
        it1++;
    }
}