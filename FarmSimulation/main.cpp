using namespace std;
#include <iostream>
#include <fstream>

#include "Organism.h"
#include "World.h"



int main() {

	system("cls");
	cout << "	Szymon Budziak Farm Simulation\n\n";
	
	cout << "	1 -> start new game\n";
	cout << "	2 -> load game from a file\n";
	cout << "	3 -> save the game (when playing)\n\n";

	cout << "	Q -> end game\n";
	cout << "	W, A, S, D -> movement\n";
	cout << "	E -> burning enemies special ability\n";


	int N, M;
	char startOption;
	cout << "	Write and confirm an action: ";
	startOption = getchar();

	while (startOption != '1' && startOption != '2') {
		startOption = getchar();
	}

	if (startOption == '1') {
		cout << "	Width of the board: ";
		cin >> N;
		cout << "	Height of the board: ";
		cin >> M;

		World* world = new World(N, M);
		bool quitGame = false;

		world->printWorld();

		while (!quitGame) {

			char action = getchar();

			while (action != 97 && action != 100 && action != 115 && action != 119 && action != 101) {

				if (action == 113) {
					quitGame = true;
					break;
				}
				else if (action == '3') {	// SAVING THE GAME
					cout << "SAVING THE GAME\n";
					world->saveToFile();
					quitGame = true;
					break;
				}
				else {
					action = getchar();
				}
			}

			system("cls");

			world->setAction(action);
			world->executeTurn();
			world->printWorld();
		}
	}
	else if (startOption == '2') {			// WCZYTANIE Z PLIKU

		ifstream newFile;
		newFile.open("worldSave.txt", ios::in);

		if (newFile) {

			World* loadedWorld = new World(newFile);
			bool quitGame = false;
			loadedWorld->printWorld();

			while (!quitGame) {

				char action = getchar();

				while (action != 97 && action != 100 && action != 115 && action != 119 && action != 101) {

					if (action == 113) {
						quitGame = true;
						break;
					}
					else if (action == '3') {	// SAVING THE GAME
						cout << "SAVING THE GAME\n";
						loadedWorld->saveToFile();
						quitGame = true;
						break;

					}
					else {
						action = getchar();
					}
				}

				system("cls");

				loadedWorld->setAction(action);
				loadedWorld->executeTurn();
				loadedWorld->printWorld();
			}
		}
		else {
			cout << "Something went wrong\n";
		}
	}

	cout << "\nTHE GAME HAS ENDED";
	return 0;
}