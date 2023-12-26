#include "World.h"
#include "Fox.h"

Fox::Fox(World* worldReference, int position[2], int age)
	: Animal(worldReference, 3, 7, position, age) {}

Organism* Fox::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Fox(worldReference, pos, 1);
}

void Fox::action(World* worldReference) {

	setCoordinatesForMoving(worldReference);

	if (worldReference->isOccupied(newPosition[0], newPosition[1]) && worldReference->board[newPosition[0]][newPosition[1]]->getStrength() > strength) {
		setCoordinatesBack();
		cout << "Fox avoids attacking a stronger opponent\n";
	}
	else if (worldReference->isOccupied(newPosition[0], newPosition[1])) {
		worldReference->board[newPosition[0]][newPosition[1]]->collision(worldReference, this);
	}
	else {
		moveToLocation(worldReference);
	}
	age++;
}


void Fox::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 14);
	cout << "L";
	SetConsoleTextAttribute(baseColor, 7);
}

string Fox::getSpecies() {
	return "Fox";
}

Fox::~Fox() {}

