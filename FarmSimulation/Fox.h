#include <iostream>
using namespace std;
#include "Animal.h"

class Fox : public Animal {
public:
	Fox(World* worldReference, int position[2], int age);

	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;
	void action(World* worldReference) override;

	~Fox();
};