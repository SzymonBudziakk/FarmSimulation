#include "World.h"
#include "Sheep.h"

Sheep::Sheep(World* worldReference, int position[2], int age)
	: Animal(worldReference, 4, 4, position, age) {}

Organism* Sheep::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Sheep(worldReference, pos, 1);
}

void Sheep::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 14);
	cout << "O";
	SetConsoleTextAttribute(baseColor, 7);
}

string Sheep::getSpecies() {
	return "Sheep";
}

Sheep::~Sheep() {}

