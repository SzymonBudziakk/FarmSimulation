#include "World.h"
#include "Guarana.h"
#include "Organism.h"
#include "Plant.h"

Guarana::Guarana(World* worldReference, int position[2], int age)
	: Plant(worldReference, 0, 0, position, age) {}

Organism* Guarana::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Guarana(worldReference, pos, 1);
}

void Guarana::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 10);
	cout << "G";
	SetConsoleTextAttribute(baseColor, 7);
}

void Guarana::collision(World* worldReference, Organism* attacker) {

	if (attacker->getStrength() >= getStrength()) {
		cout << attacker->getSpecies() << " kills " << getSpecies() << ". Strength was increased by 3 points\n";
		worldReference->destroy(getX(), getY());
		attacker->setStrength(getStrength() + 3);
		attacker->moveToLocation(worldReference);
	}
	else {
		cout << getSpecies() << " defends against " << attacker->getSpecies() << "\n";
		worldReference->destroy(attacker->getX(), attacker->getY());

	}
}

string Guarana::getSpecies() {
	return "Guarana";
}

Guarana::~Guarana() {}

