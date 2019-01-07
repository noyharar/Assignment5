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
#include "HeroesException.h"
#include <fstream>
#include <sstream>


using namespace std;
struct stat info; // Used to check whether or not folder/file is exists

std::string exec(const char* cmd);

bool myCreateFolder (string&);

void showAllHeros(Hero& h1);
string getNameFromUser();
int nextTurn(int, int);

void writeTheLastGame(int, Hero**, string&, string&);

void createLastGame(string);

bool tookMyMoney = false, specailTurn = false;
int threefirstgames = 0;
int playerTurnNum = 0 ;
int numOfPlayers = 0;
int deadCounter = 0;
Hero **randomTurns;

int main(int argc, char *argv[]) {

//  cout << "The Game Has Stated " << endl << "And The location of the exe file is:" << endl;
//  myCreateFolder();
    int attackMenu, choiceNum ;
    int insertedPlayers = 0;
    randomTurns = NULL;
    string nameOfHero;
    string gameFolder;
    string heroesFolder;
    string heroNameFolder;
    string stam;







    if(argc > 2) {
        /**
       *receive num of heroes and create them
       */
       /************** Close Program if Args are not Valid **************/
       string warriorNum = argv[2];
       string thiefNum = argv[3];
       string necroNum = argv[4];
       if(!(warriorNum == "1" || warriorNum == "2" || warriorNum == "3" ) || !( thiefNum ==  "1"  ||  thiefNum ==  "2" || thiefNum ==  "3" ) || !( necroNum == "2" || necroNum == "1" || necroNum == "3"))
         {
            return 0;
         }

         /*********************************************************************/
         numOfPlayers = stoi(warriorNum) + stoi(thiefNum) + stoi(necroNum);
         randomTurns = new Hero *[numOfPlayers];
         for (int i = 0; i < numOfPlayers; ++i)
           {
             randomTurns[i] = NULL;
           }
         string userName = "";
         for (int i = 2; i < argc; i++)
           {
             for (int j = 0; j < atoi (argv[i]); j++)
               {
                 if (i == 2)
                   {
                     cout << "Please insert warrior number " << j + 1 << " name:" << endl;
                     try
                       {
                         userName = getNameFromUser ();
                         Hero *war = new Warrior (userName);
                         Hero::allHeros[war->getName ()] = war;
                       }
                     catch (HeroesException &e)
                       {
                         e.Handle ();
                         j--;
                       }
                   }
                 else if (i == 3)
                   {
                     cout << "Please insert thief number " << j + 1 << " name:" << endl;
                     try
                       {
                         userName = getNameFromUser ();
                         Hero *thief = new Thief (userName);
                         Hero::allHeros[thief->getName ()] = thief;
                       }
                     catch (HeroesException &e)
                       {
                         e.Handle ();
                         j--;
                       }
                   }
                 else if (i == 4)
                   {
                     cout << "Please insert necromancer number " << j + 1 << " name:" << endl;
                     try
                       {
                         userName = getNameFromUser ();
                         Hero *necromancer = new Necromancer (userName);
                         Hero::allHeros[necromancer->getName ()] = necromancer;
                       }
                     catch (HeroesException &e)
                       {
                         e.Handle ();
                         j--;
                       }
                   }
               }
           }

/**
 * create random array of players' turns
 */
         map<string, Hero *>::iterator it1;
         it1 = Hero::allHeros.begin ();
         while (insertedPlayers < numOfPlayers && it1 != Hero::allHeros.end ())
           {
             playerTurnNum = rand () % numOfPlayers;
             if (randomTurns[playerTurnNum] == NULL)
               {
//            cout << it1->first << endl;
                 randomTurns[playerTurnNum] = &it1->second->getHero ();
//            cout << randomTurns[playerTurnNum]->getName() << endl;
                 it1++;
                 insertedPlayers++;
               }
           }

    }
    else {
       createLastGame("game/game.txt");
       if(randomTurns == NULL)
         {
           return 0;
         }
    }


 /********************* Delete Last Game Files ***********************/
  string rmCommand = "rm -rf ";
  gameFolder = "./game";
  heroesFolder = "./Heroes";
  rmCommand = rmCommand + gameFolder + " " + heroesFolder;
  system(rmCommand.c_str ());
  /********************************************************************/


//TODO: Change rand() to random() as in the /**/
/*
  long rndom;
  while (true)
    {
      rndom = random ()%10;
      cout << rndom << endl;
    }
    */
  while (deadCounter < numOfPlayers-1) {
      //check if the player already died and jump to the next
          if (randomTurns[playerTurnNum]->getHero().ifDie() && threefirstgames > 3*numOfPlayers) { //&& deadCounter >= numOfPlayers -1) {
              playerTurnNum = nextTurn(playerTurnNum, numOfPlayers);
          }
      string currentPlayerName = randomTurns[playerTurnNum]->getName();
      cout << "Welcome " << currentPlayerName << endl;
      // print menu
      cout << "What is your next step in the path to victory?\n";
      cout << "1. Attack\n";
      cout << "2. Get daily gold\n";
      cout << "3. Buy creatures\n";
      cout << "4. Show details\n";
      cout << "5. Special skill\n";
      cout << "6. End of my turn\n";
      cout << "7. Exit\n";
      // get input from user
      cin >> choiceNum;
      // take action
      switch (choiceNum) {
          case 1:
            cout << "1. Show me my opponents\n";
            cout << "2.Attack hero\n";
            cin >> attackMenu;
          switch (attackMenu) {
              case 1:
                showAllHeros(randomTurns[playerTurnNum]->getHero());
//                cin.get();
//                cin.get();
                cin.ignore ();
                getline(cin, stam);
              break;
              case 2:
                try
                  {
                    if (threefirstgames > 3 * numOfPlayers){
                        if (randomTurns[playerTurnNum]->getHero ().attackOpponent ())
                          {
                            playerTurnNum = nextTurn (playerTurnNum, numOfPlayers);

                          }
                        deadCounter++;
                        threefirstgames++;
                      }
                    else
                      {
                          cout << "Cannot Attack before Everyone played 3 Turns" << endl;
                      }
                  }
                  catch (HeroesException& e)
                    {
                      e.Handle ();
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
            try{
              randomTurns[playerTurnNum]->buyCreatures();
            }
            catch (HeroesException& e){
              e.Handle ();
            }
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
            else
              {
                cout << "You cannot use your special skill twice" << endl;
              }
          break;

          case 6:
              playerTurnNum = nextTurn(playerTurnNum,numOfPlayers);
              threefirstgames++;
          break;

          case 7:
              //Delete map
//              randomTurns[playerTurnNum]->deleteDataFromMap();
              gameFolder = "./game";
              if(!myCreateFolder (gameFolder))
                {
    //                  exit(0);
                }
              heroesFolder = "./Heroes";
              heroNameFolder = "";
              if(myCreateFolder (heroesFolder))
                {
                  for (int i = 0; i < numOfPlayers; ++i)
                    {
                      heroNameFolder = heroesFolder + "/" + randomTurns[i]->getName ();
                      myCreateFolder (heroNameFolder);
                    }

                }
              writeTheLastGame(playerTurnNum,randomTurns,gameFolder,heroesFolder);
            exit(0);
          default:
            cout << ("please choose a valid number\n");
        }
    }
    cout << "The winner is " << randomTurns[playerTurnNum]->getName() << endl;

//    randomTurns[playerTurnNum]->deleteDataFromMap();
    gameFolder = "./game";
    if(!myCreateFolder (gameFolder))
      {
        //                  exit(0);
      }
    heroesFolder = "./Heroes";
    heroNameFolder = "";
    if(myCreateFolder (heroesFolder))
      {
        for (int i = 0; i < numOfPlayers; ++i)
          {
            heroNameFolder = heroesFolder + "/" + randomTurns[i]->getName ();
            myCreateFolder (heroNameFolder);
          }

      }
    writeTheLastGame(playerTurnNum,randomTurns,gameFolder,heroesFolder);


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
    threefirstgames++;
    return playerTurnNum;
}




string getNameFromUser()
{
    string name = "";
    // cout << "for tetst\n";
    getline(cin, name);
    int length = name.length();
    if(length >31){
        throw IncorrectUsername(name);
    }
    for(int i = 0; i < length; i++){
        if(!isalpha(name[i]) && !isdigit((int)name[i])){
            throw IncorrectUsername(name);
        }
    }
//    while(!legalName(name))
//    {
//        cout << "Please enter a username:\n";
//        cin >> name;
//    }

    return name;
}




/**
 * case 1 -  show the opponnet instead the current player
 * @param h1
 */
void showAllHeros(Hero& h1)
{

  map<string,Hero*>::iterator it1;
  it1 = Hero::allHeros.begin();
  while (it1 != Hero::allHeros.end() )
    {
      if(!(h1.getName() == it1->first)&& it1->second->getType() == "Warrior")
        {
          if(!it1->second->ifDie () || threefirstgames < 3 * numOfPlayers)
            {
              it1->second->printNameType();
            }
        }
      it1++;
    }
  it1 = Hero::allHeros.begin();
  while (it1 != Hero::allHeros.end() )
    {
      if(!(h1.getName() == it1->first)&& it1->second->getType() == "Thief")
        {
          if(!it1->second->ifDie () || threefirstgames < 3*numOfPlayers)
            {
              it1->second->printNameType();
            }        }
      it1++;
    }
  it1 = Hero::allHeros.begin();
  while (it1 != Hero::allHeros.end() )
    {
      if(!(h1.getName() == it1->first)&& it1->second->getType() == "Necromancer")
        {
          if(!it1->second->ifDie () || threefirstgames < 3 * numOfPlayers)
            {
              it1->second->printNameType();
            }        }
      it1++;
    }
}

//TODO: Maybe we should Recursivly create the folder inside GamePlay
/***
 * Creates the folder of the game
 *
 *
 */
bool myCreateFolder (string& folderPath)
{
  int check;
  const char *dirName;

  dirName = folderPath.c_str ();
  if (stat (dirName, &info) != 0)
    {
      // Folder does not exists
      check = mkdir (dirName, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
      if (-1 == check)
        {
          // Could not create the folder
          return false;
        }
      else
        {
          // Created the new Folder
          // Create the Files of the Useres Now
          return true;
        }

    }
  else if (info.st_mode & S_IFDIR)
    {
      // it is a directory and it is already created
      // Create the Files of the Users Now
      return true;
    }
  else
    {
      // Not A directory and cannot run the Program
      return false;
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

void writeTheLastGame(int indexOfPlayer,Hero **randomArray, string& gameFolder, string& heroFolder){
    std::ofstream outfile (gameFolder + "/game.txt");
    outfile << numOfPlayers << endl;
    outfile << indexOfPlayer << endl;
    outfile << deadCounter << endl;
    outfile << tookMyMoney << endl;
    outfile << specailTurn << endl;
    outfile << threefirstgames << endl;
    for (int j = 0; j < numOfPlayers; ++j)
    {
      outfile << randomArray[j]->getHero().detailsForGame() + "\n";
    }
    string chmodCmd = "chmod 777 " + gameFolder + "/game.txt";

    system(chmodCmd.c_str ());
    outfile.close ();

    for(int i = 0; i < numOfPlayers; i++){
        outfile.open (heroFolder + "/" + randomArray[i]->getName () + "/" + randomArray[i]->getName ());
        outfile << randomArray[i]->getHero().detailsForGame() + "\n";
        outfile.close ();
    }
//    outfile.close();
}
void createLastGame(string fileName){
    string line;
    ifstream myfile (fileName);

    if (myfile.is_open())
    {
        int index = 0;
        string name;
        //get NumOfPlayers
        getline(myfile,line);
        numOfPlayers = stoi(line);
        //get Index of the current Player Turn
        getline (myfile,line);
        playerTurnNum = stoi(line);// line with the index of turn
        //get the dead counter
        getline (myfile,line);
        deadCounter = stoi(line);
        if(deadCounter == numOfPlayers - 1)
          {
            return;
          }
        randomTurns = new Hero*[numOfPlayers];

        int moneyTurn;
        getline (myfile,line);
        moneyTurn = stoi(line);
        if(moneyTurn == 0)
          {
            tookMyMoney = false;
          }
          else if(moneyTurn == 1)
          {
            tookMyMoney = true;
          }

        int specialMyTurn;
        getline (myfile,line);
        specialMyTurn = stoi(line);
        if(specialMyTurn == 0)
          {
            specailTurn = false;
          }
        else if(specialMyTurn == 1)
          {
            specailTurn = true;
          }

        getline (myfile,line);
        threefirstgames = stoi(line);

        while(index < numOfPlayers){
        while ( getline (myfile,line) ) {
            string arr[13];
            int i = 0;
            //split to array
            stringstream ssin(line);
            while (ssin.good() && i < 13) {
                ssin >> arr[i];
                ++i;
            }
            if (arr[0] == "Warrior") {
                Hero* current;
                Hero *war = new Warrior(arr[1]);
                Hero::allHeros[arr[1]] = war;
                randomTurns[index] = war;
                }
                if (arr[0] == "Thief") {
                    Hero *thi = new Thief(arr[1]);
                    Hero::allHeros[arr[1]] = thi;
                    randomTurns[index] = thi;

                }
                if (arr[0] == "Necromancer") {
                    Hero *nec = new Necromancer(arr[1]);
                    Hero::allHeros[arr[1]] = nec;
                    randomTurns[index] = nec;
                }
            randomTurns[index]->goldQty = stoi(arr[2]);
            int k = 0;
                for(int j = 3; j < 13; j=j+2) {
                     if(k < 5) {
                         randomTurns[index]->creatureList[k].numOfCreature = stoi(arr[j]);
                         k++;
                    }
                }
                index++;
            }
        }
        myfile.close();
//        return *currentRandom;
    }

    else
      {
        cout << "Unable to open file";
//        return NULL;
      }
}



