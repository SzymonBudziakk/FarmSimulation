#include <iostream>
using namespace std;
#include "Animal.h"

class Wolf : public Animal {
public:
	Wolf(World* worldReference, int position[2], int age);

	Organism* copy(int x, int y) override;
	void printSymbol() override;
	string getSpecies() override;

	~Wolf();
};