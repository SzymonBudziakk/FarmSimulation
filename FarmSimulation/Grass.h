#include <iostream>
using namespace std;
#include "Plant.h"
#include "Organism.h"

class Grass : public Plant {
public:
	Grass(World* worldReference, int position[2], int age);

	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Grass();
};