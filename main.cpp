#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main() {
    int attackMenu, choiceNum, buyMenu;

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
                        //
                        break;
                    case 2:
                        //
                        break;
                    default:
                        cout << "please choose a valid number\n";
                }
                break;
            case 2:
                //
                break;
            case 3:
                cout << "Buy creatures:\n";
                cout << "1. Buy zombies\n";
                cout << "2. Buy Archers\n";
                cout << "3. Buy Vampire\n";
                cout << "4. Buy Wizard\n";
                cout << "5. Buy Black Dragon\n";
                cin >> buyMenu;
                switch (buyMenu) {
                    case 1:
                        //
                        break;
                    case 2:
                        //
                        break;
                    case 3:
                        //
                        break;
                    case 4:
                        //
                        break;
                    case 5:
                        //
                        break;
                    default:
                        cout << "please choose a valid number\n";
                }
                break;
            case 4:
                //
                break;
            case 5:
                //
                break;
            case 6:
                //
                break;
            case 7:
                exit(0);
            default:
                cout << ("please choose a valid number\n");
        }
    }
        return 0;
}