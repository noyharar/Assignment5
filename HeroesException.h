//
// Created by gal on 1/3/19.
//

#ifndef ASSIGNMENT5_HEROESEXCEPTION_H
#define ASSIGNMENT5_HEROESEXCEPTION_H
#include <iostream>

using namespace std;


class HeroesException {
 public:
  virtual void Handle()const = 0;
};

class IncorrectUsername:public HeroesException
{
  string username;
 public:
  IncorrectUsername():HeroesException() {};
  IncorrectUsername(string name):HeroesException(),username(name){};
  virtual void Handle()const { cout << "Please Enter a valid username instead of: " << username << endl; }
};

class InsufficientGold:public HeroesException
{
  double insGold;
 public:
  InsufficientGold():HeroesException() {};
  InsufficientGold(double goldUsed):HeroesException(),insGold(goldUsed) {};
  virtual void Handle()const { cout << "Insufficient Gold to buy this Creatues in " << insGold << " Gold" << endl; }
};

class IncorrectAttack:public HeroesException
{
  string attackedCreature;
 public:
  IncorrectAttack():HeroesException() {};
  IncorrectAttack(string creatureName):HeroesException(), attackedCreature(creatureName) {};
  virtual void Handle()const { cout << "The Creature '" << attackedCreature << "' Does Not Exists among the User's Creatures Please Try Again" << endl; }
};

class HeroNotExists:public HeroesException
{
  string searchedHero;
 public:
  HeroNotExists():HeroesException() {};
  HeroNotExists(string name):HeroesException(),searchedHero(name) {};
  virtual void Handle()const { cout << "The Hero '" << searchedHero << "' does not exists" << endl; }
};

class MustWaitThreeTurns:public HeroesException
{
 public:
  MustWaitThreeTurns():HeroesException() {};
  virtual void Handle()const { cout << "Cannot Attack before Everyone played 3 Turns" << endl; }
};

#endif //ASSIGNMENT5_HEROESEXCEPTION_H
