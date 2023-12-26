#include "Animal.h"
#include "Organism.h"
#include "World.h"
#include <string>
#include <iostream>
using namespace std;



Animal::Animal(World* worldReference, int strength, int initiative, int position[2], int age)
	: Organism(worldReference, strength, initiative, position, age) {
}

void Animal::setCoordinatesForMoving(World* worldReference) {

	int number = worldReference->randomNumber(0, 3);
	switch (number) {
	case 0:
		newPosition[0] += 1;
		break;
	case 1:
		newPosition[0] -= 1;
		break;
	case 2:
		newPosition[1] += 1;
		break;
	case 3:
		newPosition[1] -= 1;
		break;
	}

	if (!worldReference->isXYvalid(newPosition[0], newPosition[1])) {
		if (newPosition[0] > worldReference->getMaxX()) {
			newPosition[0] -= 2;
		}
		else if (newPosition[0] < 0) {
			newPosition[0] += 2;
		}
		else if (newPosition[1] > worldReference->getMaxY()) {
			newPosition[1] -= 2;
		}
		else if (newPosition[1] < 0) {
			newPosition[1] += 2;
		}
	}

}

void Animal::multiply(World* worldReference) {

	int number = worldReference->randomNumber(0, 7);
	int multX = -1, multY = -1;
	bool quit = false;
	int round = 0;

	while (!quit) {
		switch (number) {
		case 0:
			multX = position[0] + 1;
			multY = position[1];
			if (worldReference->isXYvalid(multX, multY) && (multX != newPosition[0] || multY != newPosition[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}

		case 1:
			multX = position[0] - 1;
			multY = position[1];
			if (worldReference->isXYvalid(multX, multY) && (multX != newPosition[0] || multY != newPosition[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 2:
			multX = position[0];
			multY = position[1] + 1;
			if (worldReference->isXYvalid(multX, multY) && (multX != newPosition[0] || multY != newPosition[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 3:
			multX = position[0];
			multY = position[1] - 1;
			if (worldReference->isXYvalid(multX, multY) && (multX != newPosition[0] || multY != newPosition[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 4:
			multX = newPosition[0] + 1;
			multY = newPosition[1];
			if (worldReference->isXYvalid(multX, multY) && (multX != position[0] || multY != position[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 5:
			multX = newPosition[0] - 1;
			multY = newPosition[1];
			if (worldReference->isXYvalid(multX, multY) && (multX != position[0] || multY != position[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 6:
			multX = newPosition[0];
			multY = newPosition[1] + 1;
			if (worldReference->isXYvalid(multX, multY) && (multX != position[0] || multY != position[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
			}
			else {
				number += 1;
			}
		case 7:
			multX = newPosition[0];
			multY = newPosition[1] - 1;
			if (worldReference->isXYvalid(multX, multY) && (multX != position[0] || multY != position[1])) {
				if (!worldReference->isOccupied(multX, multY)) {
					quit = true;
					break;
				}
				else {
					if (round == 0) {
						number = 0;
						round = 1;
					}
					else {
						round = 2;
						quit = true;
						break;
					}
				}
			}
			else {
				if (round == 0) {
					number = 0;
					round = 1;
				}
				else {
					round = 2;
					quit = true;
					break;
				}
			}
		}
	}

	if (round == 2) {
		/*cout << "THERE IS NO AVAILABLE SPACE FOR MULTIPLICATION\n";*/
	}
	else if (worldReference->randomNumber(0, 1) == 0) {
		Organism* temp = copy(position[0], position[1]);
		temp->setX(multX);
		temp->setY(multY);
		temp->setCoordinatesBack();
		worldReference->board[multX][multY] = temp;
		worldReference->addOrganismToQueue(temp);

		cout << "Animal " << getSpecies() << " has been multiplicated\n";
	}

	setCoordinatesBack();
}

void Animal::collision(World* worldReference, Organism* attacker) {


	if (attacker->getSpecies() == getSpecies()) {
		attacker->multiply(worldReference);
	}
	else {
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
}


void Animal::action(World* worldReference) {

	setCoordinatesForMoving(worldReference);

	if (worldReference->isOccupied(newPosition[0], newPosition[1])) {
		worldReference->board[newPosition[0]][newPosition[1]]->collision(worldReference, this);
	}
	else {
		moveToLocation(worldReference);
	}
	age++;
}

string Animal::getType() {
	return "Animal";
}

void Animal::printSymbol() {}

Animal::~Animal() {}
