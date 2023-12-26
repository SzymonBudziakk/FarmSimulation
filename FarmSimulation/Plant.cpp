#include "Plant.h"
#include "Organism.h"
#include "World.h"


Plant::Plant(World* worldReference, int strength, int initiative, int position[2], int age)
	: Organism(worldReference, strength, initiative, position, age) {
}

void Plant::collision(World* worldReference, Organism* attacker) {

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

void Plant::multiply(World* worldReference) {

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
		/*cout << "There is no available space for multiplication " << getSpecies() << "\n";*/
	}
	else {
		Organism* temp = copy(position[0], position[1]);
		temp->setX(multX);
		temp->setY(multY);
		worldReference->board[multX][multY] = temp;
		worldReference->addOrganismToQueue(temp);

		cout << "Plant " << getSpecies() << " has been multiplied\n";
	}

}


void Plant::action(World* worldReference) {

	if (worldReference->randomNumber(0, 5) == 0) {
		multiply(worldReference);
	}


	age++;
}

string Plant::getType() {
	return "Plant";
}

void Plant::printSymbol() {}

Plant::~Plant() {}
