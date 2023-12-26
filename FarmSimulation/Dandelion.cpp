#include "World.h"
#include "Dandelion.h"
#include "Organism.h"
#include "Plant.h"

Dandelion::Dandelion(World* worldReference, int position[2], int age)
	: Plant(worldReference, 0, 0, position, age) {}

Organism* Dandelion::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Dandelion(worldReference, pos, 1);
}

void Dandelion::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 10);
	cout << "D";
	SetConsoleTextAttribute(baseColor, 7);
}

void Dandelion::action(World* worldReference) {

	for (int i = 0; i < 3; i++) {
		if (worldReference->randomNumber(0, 5) == 0) {
			multiply(worldReference);
		}
	}

	age++;
}

string Dandelion::getSpecies() {
	return "Dandelion";
}

Dandelion::~Dandelion() {}

