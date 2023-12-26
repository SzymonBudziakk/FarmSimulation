#pragma once
#include "World.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;


class Organism {

protected:
	World* worldReference;
	int strength;
	int initiative;
	int position[2];
	int newPosition[2];
	int age;

public:
	Organism(World* worldReference, int strength, int initiative, int position[2], int age);
	virtual void printSymbol() = 0;
	virtual void action(World* worldReference) = 0;
	virtual void collision(World* worldReference, Organism* attacker) = 0;
	virtual void multiply(World* worldReference) = 0;
	virtual string getSpecies() = 0;
	virtual Organism* copy(int x, int y) = 0;
	virtual string getType() = 0;

	void moveToLocation(World* worldReference);
	void setProperCoordinatesAfterMoving();
	void setCoordinatesBack();
	void setX(int x);
	void setY(int y);
	void setStrength(int n);

	int getX();
	int getY();
	int getNewX();
	int getNewY();
	int getStrength();
	int getInitiative();
	int getAge();


	virtual ~Organism();


};