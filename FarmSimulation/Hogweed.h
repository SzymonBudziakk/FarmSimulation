#include <iostream>
using namespace std;
#include "Plant.h"
#include "Organism.h"

class Hogweed : public Plant {
public:
	Hogweed(World* worldReference, int position[2], int age);

	void collision(World* worldReference, Organism* attacker) override;
	void action(World* worldReference) override;
	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Hogweed();
};