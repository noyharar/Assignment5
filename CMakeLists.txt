cmake_minimum_required(VERSION 3.9)
project(Assignment5)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment5 main.cpp Creature.cpp Hero.cpp Black_Dragon.cpp Necromancer.cpp Zombie.cpp Vampire.cpp Thief.cpp Warrior.cpp Wizard.cpp Archer.cpp HeroesException.h)