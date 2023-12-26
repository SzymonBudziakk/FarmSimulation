#pragma once
#include "Organism.h"
#include <iostream>
#include <string>
using namespace std;

class Animal : public Organism {
public:

	Animal(World* worldReference, int strength, int initiative, int position[2], int age);


	void action(World* worldReference) override;
	void setCoordinatesForMoving(World* worldReference);

	string getType() override;
	void collision(World* worldReference, Organism* attacker) override;

	void printSymbol() override = 0;
	void multiply(World* worldReference) override;

	~Animal() override;

};