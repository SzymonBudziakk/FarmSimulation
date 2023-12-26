#include <iostream>
using namespace std;
#include "Plant.h"
#include "Organism.h"

class Guarana : public Plant {
public:
	Guarana(World* worldReference, int position[2], int age);

	void collision(World* worldReference, Organism* attacker) override;
	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Guarana();
};