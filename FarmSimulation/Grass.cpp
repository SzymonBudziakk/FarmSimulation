#include "World.h"
#include "Grass.h"
#include "Organism.h"
#include "Plant.h"

Grass::Grass(World* worldReference, int position[2], int age)
	: Plant(worldReference, 0, 0, position, age) {}

Organism* Grass::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Grass(worldReference, pos, 1);
}

void Grass::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 10);
	cout << "#";
	SetConsoleTextAttribute(baseColor, 7);
}

string Grass::getSpecies() {
	return "Grass";
}

Grass::~Grass() {}

