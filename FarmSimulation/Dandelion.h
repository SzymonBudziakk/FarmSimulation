#include <iostream>
using namespace std;
#include "Plant.h"
#include "Organism.h"

class Dandelion : public Plant {
public:
	Dandelion(World* worldReference, int position[2], int age);

	void action(World* worldReference) override;
	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Dandelion();
};