#include "World.h"
#include "Wolf.h"

Wolf::Wolf(World* worldReference, int position[2], int age)
	: Animal(worldReference, 9, 5, position, age) {}

Organism* Wolf::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Wolf(worldReference, pos, 1);
}

void Wolf::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 14);
	cout << "W";
	SetConsoleTextAttribute(baseColor, 7);
}

string Wolf::getSpecies() {
	return "Wolf";
}

Wolf::~Wolf() {}

