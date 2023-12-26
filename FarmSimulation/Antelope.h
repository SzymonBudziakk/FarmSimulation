#include <iostream>
using namespace std;
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope(World* worldReference, int position[2], int age);

	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	void collision(World* worldReference, Organism* attacker) override;
	void action(World* worldReference) override;

	~Antelope();
};