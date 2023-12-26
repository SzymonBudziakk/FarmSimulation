#include "World.h"
#include "Hogweed.h"
#include "Organism.h"
#include "Plant.h"

Hogweed::Hogweed(World* worldReference, int position[2], int age)
	: Plant(worldReference, 10, 0, position, age) {}

Organism* Hogweed::copy(int x, int y) {
	int pos[2] = { x, y };
	return new Hogweed(worldReference, pos, 1);
}

void Hogweed::printSymbol() {
	HANDLE baseColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(baseColor, 10);
	cout << "B";
	SetConsoleTextAttribute(baseColor, 7);
}

void Hogweed::action(World* worldReference) {

	if (worldReference->isXYvalid(position[0] + 1, position[1])) {
		if (worldReference->board[position[0] + 1][position[1]] != nullptr && worldReference->board[position[0] + 1][position[1]]->getType() == "Animal") {
			cout << getSpecies() << " kills " << worldReference->board[position[0] + 1][position[1]]->getSpecies() << "\n";
			worldReference->destroy(position[0] + 1, position[1]);
		}
	}
	if (worldReference->isXYvalid(position[0] - 1, position[1])) {
		if (worldReference->board[position[0] - 1][position[1]] != nullptr && worldReference->board[position[0] - 1][position[1]]->getType() == "Animal") {
			cout << getSpecies() << " kills " << worldReference->board[position[0] - 1][position[1]]->getSpecies() << "\n";
			worldReference->destroy(position[0] - 1, position[1]);
		}
	}
	if (worldReference->isXYvalid(position[0], position[1] + 1)) {
		if (worldReference->board[position[0]][position[1] + 1] != nullptr && worldReference->board[position[0]][position[1] + 1]->getType() == "Animal") {
			cout << getSpecies() << " kills " << worldReference->board[position[0]][position[1] + 1]->getSpecies() << "\n";
			worldReference->destroy(position[0], position[1] + 1);
		}
	}
	if (worldReference->isXYvalid(position[0], position[1] - 1)) {
		if (worldReference->board[position[0]][position[1] - 1] != nullptr && worldReference->board[position[0]][position[1] - 1]->getType() == "Animal") {
			cout << getSpecies() << " kills " << worldReference->board[position[0]][position[1] - 1]->getSpecies() << "\n";
			worldReference->destroy(position[0], position[1] - 1);
		}
	}

	age++;
}

void Hogweed::collision(World* worldReference, Organism* attacker) {

	cout << attacker->getSpecies() << " eats " << getSpecies() << "\n";
	worldReference->destroy(attacker->getX(), attacker->getY());
	worldReference->destroy(getX(), getY());

}

string Hogweed::getSpecies() {
	return "Hogweed";
}

Hogweed::~Hogweed() {}

