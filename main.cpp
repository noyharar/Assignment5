#include <iostream>
#include <string.h>
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

int main() {
    int attackMenu, choiceNum, buyMenu;
    //    getUserNames();
   // string name = "Gal";
    //string name2 = "thief";
   // Warrior gal(name);
   // Warrior gal;
   // Hero hero;
    Thief gal;
    Necromancer noy;
      gal.buyCreatures();
    gal.heroDetails();
    gal.increaseGold(3000);
    gal.heroDetails();
//    gal.decreaseGold(1200);
//    gal.heroDetails();
//    gal.specialSkill();

//    Thief myThief(name2);
//    myThief.heroDetails();
//    myThief.specialSkill(gal);
//    myThief.heroDetails();
//    gal.heroDetails();


    //  Hero hero;
//    while (1) {
//        // print menu
//        cout << "What is your next step in the path to victory?\n";
//        cout << "1. Attack\n";
//        cout << "2. Get daily gold\n";
//        cout << "3. Buy creatures\n";
//        cout << "4. Show details\n";
//        cout << "5. Spacial skill\n";
//        cout << "6. End of my turn\n";
//        cout << "7. Exit\n";
//        // get input from user
//        cin >> choiceNum;
//        // take action
//        switch (choiceNum) {
//            case 1:
//                cout << "1. Show me my opponents\n";
//                cout << "2. Attack hero\n";
//                cin >> attackMenu;
//                switch (attackMenu) {
//                    case 1:
//                        //
//                        break;
//                    case 2:
//                        //
//                        break;
//                    default:
//                        cout << "please choose a valid number\n";
//                }
//                break;
//            case 2:
//                //increaseGold(100)
//                break;
//            case 3:
//                  /buyCreatures;
//                break;
//            case 4:
//                //
//                break;
//            case 5:
//                //
//                break;
//            case 6:
//                //
//                break;
//            case 7:
//                exit(0);
//            default:
//                cout << ("please choose a valid number\n");
//        }
//    }

        int x; // for BreakPoint
        return 0;
}