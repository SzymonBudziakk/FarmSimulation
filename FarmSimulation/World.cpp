using namespace std;
#include <iostream>
#include <random>

#include "World.h"
#include "Organism.h"
#include "Human.h"

#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"

#include "Plant.h"
#include "Grass.h"
#include "Dandelion.h"
#include "Guarana.h"
#include "Nightshade.h"
#include "Hogweed.h"

void World::placeAfterSave(Organism* unit, int newStrength, int newX, int newY) {

	unit->setStrength(newStrength);
	unit->setX(newX);
	unit->setY(newY);
	addOrganismToQueue(unit);
	board[newX][newY] = unit;
}

World::World(ifstream& newFile) {

	int n;
	newFile >> cols;
	newFile >> rows;
	newFile >> turn;
	newFile >> n;

	maxX = cols - 1;
	maxY = rows - 1;
	mapPrinted = true;

	board = new Organism * *[cols];
	for (int i = 0; i < cols; i++) {
		board[i] = new Organism * [rows];
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			board[i][j] = nullptr;
		}
	}

	string species;
	int newX, newY, newAge, newStrength;

	for (int i = 0; i < n; i++) {
		newFile >> species;
		newFile >> newX;
		newFile >> newY;
		newFile >> newAge;
		newFile >> newStrength;

		int newPos[2] = { newX, newY };

		if (species == "Human") {
			placeAfterSave(new Human(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Wolf") {
			placeAfterSave(new Wolf(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Sheep") {
			placeAfterSave(new Sheep(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Fox") {
			placeAfterSave(new Fox(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Turtle") {
			placeAfterSave(new Turtle(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Antelope") {
			placeAfterSave(new Antelope(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Grass") {
			placeAfterSave(new Grass(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Dandelion") {
			placeAfterSave(new Dandelion(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Guarana") {
			placeAfterSave(new Guarana(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Nightshade") {
			placeAfterSave(new Nightshade(this, newPos, newAge), newStrength, newX, newY);
		}
		else if (species == "Hogweed") {
			placeAfterSave(new Hogweed(this, newPos, newAge), newStrength, newX, newY);
		}
		else {
			cout << "THE NAMES ARE NOT CORRECT!\n";
		}
	}

};

void World::saveToFile() {
	ofstream newFile;
	newFile.open("worldSave.txt", ios::out);

	if (newFile) {
		// kolumny, wiersze, numer tury, ilosc organizmow
		newFile << cols << " " << rows << " " << turn << " " << queue.size() << "\n";

		// typ, x, y, wiek, sila
		for (int i = 0; i < queue.size(); i++) {
			newFile << queue[i]->getSpecies() << " " << queue[i]->getX() << " " << queue[i]->getY() << " " << queue[i]->getAge() << " " << queue[i]->getStrength() << "\n";
		}

		newFile.close();
		cout << "SAVED TO THE FILE WAS SUCCESSFULL\n";
	}
	else {
		cout << "SOMETHING WENT WRONG WHEN SAVING GAME TO THE FILE\n";
	}
};


World::World(int cols, int rows) : cols(cols), rows(rows), maxX(cols - 1), maxY(rows - 1), mapPrinted(true) {

	board = new Organism * *[cols];
	for (int i = 0; i < cols; i++) {
		board[i] = new Organism * [rows];
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			board[i][j] = nullptr;
		}
	}

	int basicPos[2] = { 0, 0 };

	placeRandomly(new Human(this, basicPos, 0));

	// animals
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Wolf(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Sheep(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Fox(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Turtle(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Antelope(this, basicPos, 0));
	}

	// plants
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Grass(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Dandelion(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Guarana(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Nightshade(this, basicPos, 0));
	}
	for (int i = 0; i < randomNumber(3, 6); i++) {
		placeRandomly(new Hogweed(this, basicPos, 0));
	}

}

void World::destroy(int x, int y) {

	Organism* temp = board[x][y];
	removeOrganismFromQueue(temp);
	board[x][y] = nullptr;
}

int World::getNumberOfOrganisms() {
	return numberOfOrganisms;
}

void World::printWorld() {

	cout << "	TURN: " << turn << "\n\n";

	for (int i = 0; i < rows; i++) {
		cout << "	";
		for (int j = 0; j < cols; j++) {
			if (board[j][i] != nullptr) {
				cout << " ";
				board[j][i]->printSymbol();

			}
			else {
				cout << " .";
			}
		}
		cout << "\n";
	}


}

int World::randomNumber(int a, int b) {

	random_device rd;
	mt19937 eng(rd());
	uniform_int_distribution<> distr(a, b);
	return distr(eng);
}

bool World::isXYvalid(int x, int y) {

	if (x > maxX || y > maxY || x < 0 || y < 0) {
		return false;
	}
	return true;
}

int World::getMaxX() {
	return maxX;
}

int World::getMaxY() {
	return maxY;
}

char World::getAction() {
	return action;
}

void World::setAction(char action) {
	this->action = action;
}

void World::setNumberOfOrganisms(int n) {
	numberOfOrganisms = n;
}

Organism* World::getFromLocation(int x, int y) {
	return board[x][y];
}

void World::removeFromLocation(int x, int y) {
	board[x][y] = nullptr;
}

void World::placeInLocation(Organism* unit, int x, int y) {
	board[x][y] = unit;
}

bool World::isOccupied(int x, int y) {
	if (board[x][y] == nullptr) {
		return false;
	}
	return true;
}

void World::placeRandomly(Organism* unit) {

	int newX, newY;

	while (true) {
		newX = randomNumber(0, maxX);
		newY = randomNumber(0, maxY);

		if (board[newX][newY] == nullptr) {
			unit->setX(newX);
			unit->setY(newY);
			addOrganismToQueue(unit);
			board[newX][newY] = unit;
			break;
		}
	}
}

void World::printQueue() {
	for (int i = 0; i < numberOfOrganisms; i++) {
		cout << i << ".";
		queue[i]->printSymbol();

		cout << "init: " << queue[i]->getInitiative();
		cout << " age: " << queue[i]->getAge();
		cout << " strength: " << queue[i]->getStrength();
		cout << " pos xy: " << queue[i]->getX() << " " << queue[i]->getY();
		cout << " newPos xy: " << queue[i]->getNewX() << " " << queue[i]->getNewY();

		cout << "\n";

	}
}

void World::executeTurn() {

	sortQueueByInitiative();

	vector<Organism*> queueTemp(queue.begin(), queue.begin() + numberOfOrganisms);

	for (int i = 0; i < queueTemp.size(); i++) {
		queueTemp[i]->action(this);
	}

	queueTemp.clear();
	turn++;
}

void World::addOrganismToQueue(Organism* unit) {

	queue.push_back(unit);
	numberOfOrganisms++;
}

void World::removeOrganismFromQueue(Organism* unit) {

	for (auto it = queue.begin(); it != queue.end(); ) {
		if (*it == unit) {
			it = queue.erase(it);
		}
		else {
			it++;
		}
	}
	numberOfOrganisms--;
}

void World::sortQueueByInitiative() {

	Organism* temp;
	int n = numberOfOrganisms;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (queue[j]->getInitiative() < queue[j + 1]->getInitiative()) {
				temp = queue[j];
				queue[j] = queue[j + 1];
				queue[j + 1] = temp;
			}
			else if (queue[j]->getInitiative() == queue[j + 1]->getInitiative()) {
				if (queue[j]->getAge() < queue[j + 1]->getAge()) {
					temp = queue[j];
					queue[j] = queue[j + 1];
					queue[j + 1] = temp;
				}
			}
		}
	}
}