#include "World.h"
#include "Turtle.h"

Turtle::Turtle(World* worldReference, int position[2], int age)
	: Animal(worldReference, 2, 1, position, age) {}

void Turtle::collision(World* worldReference, Organism* attacker) {


	if (attacker->getSpecies() == getSpecies()) {
		attacker->multiply(worldReference);
	}
	else {
		if (attacker->getStrength() < 5) {
			cout << "Turtle repels the attack of" << attacker->getSpecies() << "\n";
			attacker->setCoordinatesBack();
		}
		else if (attacker->getStrength() >= getStrength()) {
			cout << attacker->getSpecies() << " kills " << getSpecies() << "\n";
			worldReference->destroy(getX(), getY());
			attacker->moveToLocation(worldReference);
		}
		else {
			cout << getSpecies() << " defends against " << attacker->getSpecies() << "\n";
			worldReference->destroy(attacker->getX(), attacker->getY());

		}
	}
}

void Turtle::action(World* worldReference) {

	if (worldReference->randomNumber(0, 4) == 0) {
		setCoordinatesForMoving(worldReference);

		if (worldReference->isOccupied(newPosition[0], newPosition[1])) {
			worldReference->board[newPosition[0]][newPosition[1]]->collision(worldReference, this);
		}
		else {
			moveToLocation(worldReference);
		}
	}

	age++;
}

Organism* Turtle::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Turtle(worldReference, pos, 1);
}

void Turtle::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 14);
	cout << "Z";
	SetConsoleTextAttribute(baseColor, 7);
}

string Turtle::getSpecies() {
	return "Turtle";
}

Turtle::~Turtle() {}

