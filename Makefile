Heroes.exe: main.o Archer.o Black_Dragon.o Creature.o Hero.o Necromancer.o Thief.o Vampire.o Wizard.o Zombie.o Warrior.o
	g++ main.o Archer.o Black_Dragon.o Creature.o Hero.o Necromancer.o Thief.o Vampire.o Wizard.o Zombie.o Warrior.o -o Heroes.exe

main.o: main.cpp Creature.h Zombie.h Wizard.h Hero.h Black_Dragon.h Vampire.h Archer.h Warrior.h Thief.h Necromancer.h HeroesException.h
	g++ -c main.cpp Creature.h Zombie.h Wizard.h Hero.h Black_Dragon.h Vampire.h Archer.h Warrior.h Thief.h Necromancer.h HeroesException.h


HeroesException.o: HeroesException.h
	g++ -c HeroesException.h

Hero.o: Hero.cpp Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h HeroesException.h
	g++ -c Hero.cpp Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h HeroesException.h

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h
	g++ -c Necromancer.cpp Necromancer.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h

Thief.o: Thief.cpp Thief.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h
	g++ -c Thief.cpp Thief.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h

Warrior.o: Warrior.cpp Warrior.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h
	g++ -c Warrior.cpp Warrior.h Hero.h Creature.h Zombie.h Black_Dragon.h Wizard.h Vampire.h Archer.h

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp Creature.h

Vampire.o: Vampire.cpp Vampire.h Creature.h
	g++ -c Vampire.cpp Vampire.h Creature.h

Wizard.o: Wizard.cpp Wizard.h Creature.h
	g++ -c Wizard.cpp Wizard.h Creature.h

Zombie.o: Zombie.cpp Zombie.h Creature.h
	g++ -c Zombie.cpp Zombie.h Creature.h

Archer.o: Archer.cpp Archer.h Creature.h
	g++ -c Archer.cpp Archer.h Creature.h

Black_Dragon.o: Black_Dragon.cpp Black_Dragon.h Creature.h
	g++ -c Black_Dragon.cpp Black_Dragon.h Creature.h

clean:
	rm -rf *.o *.gch Heroes.exe
