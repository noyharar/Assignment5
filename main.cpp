#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <sys/stat.h>
#include <random>

#include "Creature.h"
#include "Zombie.h"
#include "Wizard.h"
#include "Hero.h"
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
#include "Black_Dragon.h"



using namespace std;
struct stat info; // Used to check whether or not folder/file is exists

std::string exec(const char* cmd);

void CreateFolder();

void showAllHeros(Hero& h1);

int nextTurn(int, int);

bool tookMyMoney = false, specailTurn = false;

int main(){

//  cout << "The Game Has Stated " << endl << "And The location of the exe file is:" << endl;
//  CreateFolder();

//    string test;
//    getline(cin, test);
//    cout << test;
  int attackMenu, choiceNum, buyMenu;
  int playerTurnNum;
  int insertedPlayers = 0;
  int numOfPlayers;
//  numOfPlayers = atoi(argv[2])+atoi(argv[3]) + atoi(argv[4]);
    numOfPlayers = 3;
  Hero *randomTurns[numOfPlayers];
  for (int i = 0; i < numOfPlayers; ++i) {
      randomTurns[i] = NULL;
    }
    Thief gal;
    Thief gal2;
    Necromancer noy;
//    Necromancer noy2;
//    Necromancer noy3;
//    Warrior gal3;

//TODO: Change rand() to random() as in the /**/
/*
  long rndom;
  while (true)
    {
      rndom = random ()%10;
      cout << rndom << endl;
    }
    */
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
    int deadCounter = 0, threefirstgames = 0;

  while (deadCounter < numOfPlayers-1) {
      if (randomTurns[playerTurnNum]->getHero().ifDie() && threefirstgames > 3*numOfPlayers) {
          nextTurn(playerTurnNum, numOfPlayers);
          break;
      }
      cout << "Wellcome " << randomTurns[playerTurnNum]->getName() << endl;
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
                  if(threefirstgames > 3*numOfPlayers) {
                      if (randomTurns[playerTurnNum]->getHero().attackOpponent()) {
                          if (playerTurnNum + 1 >= numOfPlayers) {
                              playerTurnNum = 0;
                          } else {
                              playerTurnNum++;
                          }
                          tookMyMoney = false;
                          specailTurn = false;

                      }
                      deadCounter++;
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
              playerTurnNum = nextTurn(playerTurnNum,numOfPlayers);
          break;

          case 7:
            exit(0);
          default:
            cout << ("please choose a valid number\n");
        }
    }
    cout << "The winner is " << randomTurns[playerTurnNum]->getName() << endl;

  int x; // for BreakPoint
  return 0;
}

int nextTurn(int playerTurnNum, int numOfPlayers){
    if(playerTurnNum + 1 >= numOfPlayers)
    {
        playerTurnNum = 0;
    } else
    {
        playerTurnNum++;
    }
    tookMyMoney = false;
    specailTurn = false;
    return playerTurnNum;
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

//TODO: Maybe we should Recursivly create the folder inside GamePlay
/***
 * Creates the folder of the game
 *
 *
 */
void CreateFolder ()
{
  int check;
  char *dirName;

 // dirName = "./GamePlay";
  if (stat (dirName, &info) != 0)
    {
      // Folder does not exists
      check = mkdir (dirName, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
      if (-1 == check)
        {
          // Could not create the folder
        }
      else
        {
          // Created the new Folder
          // Create the Files of the Useres Now
          cout << exec ("pwd") << endl;
        }

    }
  else if (info.st_mode & S_IFDIR)
    {
      // it is a directory and it is already created
      // Create the Files of the Users Now
      cout << exec ("pwd") << endl;
    }
  else
    {
      // Not A directory and cannot run the Program
      exit(1);
    }




}

std::string exec (const char *cmd)
{
  char buffer[128];
  std::string result = "";
  FILE* pipe = popen(cmd, "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try {
      while (fgets(buffer, sizeof buffer, pipe) != NULL) {
          result += buffer;
        }
    } catch (...) {
      pclose(pipe);
      throw;
    }
  pclose(pipe);
  return result;
}

