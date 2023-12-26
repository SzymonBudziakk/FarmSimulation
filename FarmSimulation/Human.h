#pragma once
#include "Animal.h"
#include "World.h"

class Human : public Animal {
private:
	int superPowerCD = 0;

public:

	Human(World* worldReference, int position[2], int age);
	void printSymbol() override;
	void action(World* worldReference) override;
	void superPower();

	string getSpecies();

	Organism* copy(int x, int y) override;

	int getSuperPowerCD();
	void setSuperPowerCD(int number);

	~Human() override;

};