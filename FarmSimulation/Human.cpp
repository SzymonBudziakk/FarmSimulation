#include "Human.h"
#include "Animal.h"
#include <string>

Human::Human(World* worldReference, int position[2], int age)
	: Animal(worldReference, 5, 4, position, age) {

}

void Human::action(World* worldReference) {

	if (worldReference->getAction() == 100) {
		if (worldReference->isXYvalid(newPosition[0] + 1, newPosition[1])) {
			newPosition[0]++;
		}
	}
	else if (worldReference->getAction() == 97) {
		if (worldReference->isXYvalid(newPosition[0] - 1, newPosition[1])) {
			newPosition[0]--;
		}
	}
	else if (worldReference->getAction() == 119) {
		if (worldReference->isXYvalid(newPosition[0], newPosition[1] - 1)) {
			newPosition[1]--;
		}
	}
	else if (worldReference->getAction() == 115) {
		if (worldReference->isXYvalid(newPosition[0], newPosition[1] + 1)) {
			newPosition[1]++;
		}
	}
	else if (worldReference->getAction() == 101) {
		if (superPowerCD == 0) {
			superPower();
		}
		else {
			cout << "Superpower cooldown is equal to: " << superPowerCD << "\n";
		}
	}
	if (worldReference->getAction() != 101) {
		if (worldReference->isOccupied(newPosition[0], newPosition[1]) && (position[0] != newPosition[0] || position[1] != newPosition[1])) {

			worldReference->board[newPosition[0]][newPosition[1]]->collision(worldReference, this);
		}
		else if ((position[0] != newPosition[0] || position[1] != newPosition[1]) && worldReference->isXYvalid(newPosition[0], newPosition[1])) { // ??
			moveToLocation(worldReference);
		}
	}
	age++;
	if (superPowerCD > 0) {
		superPowerCD--;
	}
}

void Human::superPower() {

	cout << "Human has used his superpower\n";

	if (worldReference->isXYvalid(position[0] + 1, position[1])) {
		if (worldReference->board[position[0] + 1][position[1]] != nullptr) {
			worldReference->destroy(position[0] + 1, position[1]);
		}
	}
	if (worldReference->isXYvalid(position[0] - 1, position[1])) {
		if (worldReference->board[position[0] - 1][position[1]] != nullptr) {
			worldReference->destroy(position[0] - 1, position[1]);
		}
	}
	if (worldReference->isXYvalid(position[0], position[1] + 1)) {
		if (worldReference->board[position[0]][position[1] + 1] != nullptr) {
			worldReference->destroy(position[0], position[1] + 1);
		}
	}
	if (worldReference->isXYvalid(position[0], position[1] - 1)) {
		if (worldReference->board[position[0]][position[1] - 1] != nullptr) {
			worldReference->destroy(position[0], position[1] - 1);
		}
	}
	setSuperPowerCD(5);
}

Organism* Human::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Human(worldReference, pos, 0);
}



void Human::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 3);
	cout << "X";
	SetConsoleTextAttribute(baseColor, 7);
}

string Human::getSpecies() {
	return "Human";
}

int Human::getSuperPowerCD() {
	return superPowerCD;
}

void Human::setSuperPowerCD(int number) {
	superPowerCD = number;
}

Human::~Human() {}