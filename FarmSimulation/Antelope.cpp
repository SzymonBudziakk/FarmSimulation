#include "World.h"
#include "Antelope.h"

Antelope::Antelope(World* worldReference, int position[2], int age)
	: Animal(worldReference, 4, 4, position, age) {}

void Antelope::collision(World* worldReference, Organism* attacker) {


	if (attacker->getSpecies() == getSpecies()) {
		attacker->multiply(worldReference);
	}
	else {
		if (worldReference->randomNumber(0, 1) == 0) {
			if (attacker->getStrength() >= getStrength()) {
				cout << attacker->getSpecies() << " kills " << getSpecies() << "\n";
				worldReference->destroy(getX(), getY());
				attacker->moveToLocation(worldReference);
			}
			else {
				cout << getSpecies() << " defends against " << attacker->getSpecies() << "\n";
				worldReference->destroy(attacker->getX(), attacker->getY());

			}
		}
		else {
			cout << "Antelope runs away from a fight\n";
		}
	}
}

void Antelope::action(World* worldReference) {

	int number = worldReference->randomNumber(0, 3);
	switch (number) {
	case 0:
		newPosition[0] += 2;
		break;
	case 1:
		newPosition[0] -= 2;
		break;
	case 2:
		newPosition[1] += 2;
		break;
	case 3:
		newPosition[1] -= 2;
		break;
	}

	if (!worldReference->isXYvalid(newPosition[0], newPosition[1])) {
		if (newPosition[0] > worldReference->getMaxX()) {
			newPosition[0] -= 4;
		}
		else if (newPosition[0] < 0) {
			newPosition[0] += 4;
		}
		else if (newPosition[1] > worldReference->getMaxY()) {
			newPosition[1] -= 4;
		}
		else if (newPosition[1] < 0) {
			newPosition[1] += 4;
		}
	}

	if (worldReference->isOccupied(newPosition[0], newPosition[1])) {
		worldReference->board[newPosition[0]][newPosition[1]]->collision(worldReference, this);
	}
	else {
		moveToLocation(worldReference);
	}
	age++;
}

Organism* Antelope::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Antelope(worldReference, pos, 1);
}

void Antelope::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 14);
	cout << "A";
	SetConsoleTextAttribute(baseColor, 7);
}

string Antelope::getSpecies() {
	return "Antelope";
}

Antelope::~Antelope() {}

