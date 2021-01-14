/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - Main File
*/

#include "Enemy.h"
#include "enemytype1.h"
#include "enemytype2.h"
#include "enemytype3.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {

	// Variable to store whether user continues simulation or stops
	char choice;

	// Intro message
	cout << "Welcome to the Video Game Enemy Battleground Simulation!" << endl << endl;

	// Create the enemies and put them in an array
	cout << "Loading enemies..." << endl << endl;
	
	const int maxEnemies = 3;
	Enemy* enemyPtrArr[maxEnemies];
	int enemyNum;

	EnemyType1 lionEnemy("Lion", 450, 500, 2, 8.5, 3.9);
	EnemyType2 heliEnemy("Helicopter", 15, 100, 7, 8.75, 11.4, 3);
	EnemyType3 robotEnemy("Robot", 798, 500, 4, 1.1, 6.2, 10);

	enemyPtrArr[0] = &lionEnemy;
	enemyPtrArr[1] = &heliEnemy;
	enemyPtrArr[2] = &robotEnemy;

	// Display enemy information
	for (int i = 0; i < maxEnemies; i++) {
		enemyPtrArr[i]->displayInfo();
	}

	// Seed random number generator
	unsigned int seed = time(0);
	srand(seed);

	cout << "Let's start the simulation!" << endl << endl;

	while (true) {

		// Every enemy moves randomly
		for (int i = 0; i < maxEnemies; i++) {
			enemyPtrArr[i]->move_position();
		}

		cout << endl;

		// A random enemy attacks
		enemyNum = rand() % maxEnemies;
		enemyPtrArr[enemyNum]->fire_weapon();

		// A random enemy updates status
		enemyNum = rand() % maxEnemies;
		enemyPtrArr[enemyNum]->update_status();

		// Ask user if he/she wants to continue or stop
		cout << endl << "Do you want to continue the simulation? (Y for Yes, anything else for No): " << endl;
		cin >> choice;
		cin.ignore(256, '\n');
		
		if (choice != 'Y')
			break;

		cout << endl;
	}

	cout << endl << "Exiting simulation. Have a nice day!";

	return 0;
}