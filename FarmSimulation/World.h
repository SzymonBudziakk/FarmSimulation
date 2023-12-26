#pragma once
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Organism;

class World {
private:

	int cols, rows;
	int maxX, maxY;
	int turn = 1;
	bool mapPrinted = false;
	int numberOfOrganisms = 0;
	char action = 'l';

public:
	World(int cols, int rows);
	World(ifstream& loadFile);
	void saveToFile();

	int randomNumber(int a, int b);
	void printWorld();
	bool isXYvalid(int x, int y);
	bool isOccupied(int x, int y);
	void destroy(int x, int y);

	int getMaxX();
	int getMaxY();
	int getNumberOfOrganisms();
	void setNumberOfOrganisms(int n);
	char getAction();
	void setAction(char action);

	void placeRandomly(Organism* unit);
	void placeInLocation(Organism* unit, int x, int y);
	void removeFromLocation(int x, int y);
	void placeAfterSave(Organism* unit, int newStrength, int newX, int newY);


	Organism* getFromLocation(int x, int y);
	void executeTurn();

	void addOrganismToQueue(Organism* unit);
	void removeOrganismFromQueue(Organism* unit);
	void sortQueueByInitiative();
	void printQueue();

	Organism*** board;
	vector<Organism*> queue;
};