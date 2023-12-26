using namespace std;
#include <iostream>
#include "Organism.h"
#include "World.h"


Organism::Organism(World* worldReference, int strength, int initiative, int position[2], int age)
	: worldReference(worldReference), strength(strength), initiative(initiative), age(age) {

	this->position[0] = position[0];
	this->position[1] = position[1];
	newPosition[0] = position[0];
	newPosition[1] = position[1];
}

void Organism::setProperCoordinatesAfterMoving() {
	if (this != nullptr) {
		position[0] = newPosition[0];
		position[1] = newPosition[1];
	}

}

void Organism::moveToLocation(World* worldReference) {

	if (worldReference->isXYvalid(getNewX(), getNewY())) {
		worldReference->board[getNewX()][getNewY()] = this;
		worldReference->board[getX()][getY()] = nullptr;
		worldReference->board[getNewX()][getNewY()]->setProperCoordinatesAfterMoving();
	}
	else {
		worldReference->board[getX()][getY()]->setCoordinatesBack();
	}
}

void Organism::setCoordinatesBack() {
	if (this != nullptr) {
		newPosition[0] = position[0];
		newPosition[1] = position[1];
	}
}

int Organism::getStrength() {
	return strength;
}

void Organism::setStrength(int n) {
	strength = n;
}

int Organism::getInitiative() {
	return initiative;
}

int Organism::getAge() {
	return age;
}

int Organism::getX() {
	return position[0];
}

int Organism::getY() {
	return position[1];
}

int Organism::getNewX() {
	return newPosition[0];
}

int Organism::getNewY() {
	return newPosition[1];
}

void Organism::setX(int x) {
	position[0] = x;
	newPosition[0] = x;
}

void Organism::setY(int y) {
	position[1] = y;
	newPosition[1] = y;
}


Organism::~Organism() {}


