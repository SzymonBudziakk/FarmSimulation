#pragma once
#include "Organism.h"
#include <iostream>
#include <string>
using namespace std;

class Plant : public Organism {
public:

	Plant(World* worldReference, int strength, int initiative, int position[2], int age);

	string getType() override;
	void action(World* worldReference) override;

	void collision(World* worldReference, Organism* attacker) override;
	void printSymbol() override = 0;
	void multiply(World* worldReference) override;

	~Plant() override;

};