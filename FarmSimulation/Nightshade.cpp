#include "World.h"
#include "Nightshade.h"
#include "Organism.h"
#include "Plant.h"

Nightshade::Nightshade(World* worldReference, int position[2], int age)
	: Plant(worldReference, 99, 0, position, age) {}

Organism* Nightshade::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Nightshade(worldReference, pos, 1);
}

void Nightshade::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 10);
	cout << "J";
	SetConsoleTextAttribute(baseColor, 7);
}

void Nightshade::collision(World* worldReference, Organism* attacker) {

	cout << attacker->getSpecies() << " eats " << getSpecies() << "\n";
	worldReference->destroy(attacker->getX(), attacker->getY());
	worldReference->destroy(getX(), getY());

}

string Nightshade::getSpecies() {
	return "Nightshade";
}

Nightshade::~Nightshade() {}

