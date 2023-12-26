#include <iostream>
using namespace std;
#include "Animal.h"

class Sheep : public Animal {
public:
	Sheep(World* worldReference, int position[2], int age);

	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Sheep();
};