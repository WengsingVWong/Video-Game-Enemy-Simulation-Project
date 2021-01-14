/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType2 Class Implementation
*/

#include "enemytype2.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Default Constructor
EnemyType2::EnemyType2():Enemy() {}

// Overloaded Constructor
EnemyType2::EnemyType2(string n, int xPos, int yPos, int st, double w, double h, int sup) {
	name = n;
	x_position = xPos;
	y_position = yPos;
	status = st;
	width = w;
	height = h;
	supply = sup;
}

// Getter for MOVEMENT constant
int EnemyType2::getMOVEMENT() {
	return MOVEMENT;
}

// Getter for supply variable
int EnemyType2::getSupply() {
	return supply;
}

// Setter for supply variable
void EnemyType2::setSupply(int sup) {
	supply = sup;
}

// Enemy moves in a random direction
void EnemyType2::move_position() {
	
	// If enemy is dead, it cannot move
	if (status == 0) {
		cout << name << " is dead and cannot move ";
	}

	else {
		// Seed random number generator
		unsigned int seed = time(0);
		srand(seed);

		// Type 2 Enemies can move in any cardinal direction
		// Choose a random direction. If enemy can't move in one direction, choose another random direction.
		// LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3
		int direction = rand() % 4;

		while (!validateMovement(direction)) {
			direction = rand() % 4;
		}

		switch (direction) {
		case 0:
			x_position -= MOVEMENT;
			break;
		case 1:
			x_position += MOVEMENT;
			break;
		case 2:
			y_position -= MOVEMENT;
			break;
		case 3:
			y_position += MOVEMENT;
			break;
		}

		cout << name << " moves to (" << x_position << "," << y_position << ") ";
	}
}

// Enemy attacks
void EnemyType2::fire_weapon() {

	// If enemy is dead, it cannot attack
	if (status == 0) {
		cout << name << " is dead and cannot attack" << endl;
	}

	else {
		cout << name;

		// If enemy has no more weapons in supply, it cannot attack
		if (supply == 0) {
			cout << " has no more rockets to fire, so it cannot attack" << endl;
		}

		// If enemy still has 1+ weapons in supply, it attacks. Decrement remaining supply accordingly
		else {
			supply -= 1;
			cout << " fires Rocket Launcher (" << supply << " rocket(s) left)" << endl;
		}
	}
}

// Enemy is damaged, update status
void EnemyType2::update_status() {

	cout << name << " updates status: ";

	// Enemy is already dead
	if (status == 0) {
		cout << "Still dead" << endl;
	}

	else {
		status -= 1;
		cout << "Hit! " << status << " HP remaining";

		// Enemy takes 1 damage and dies
		if (status == 0) {
			cout << " (\"Mayday mayday!!\")" << endl;
		}

		// Enemy takes 1 damage and still has 1+ HP left
		else {
			cout << " (\"Still flyin\' here\")" << endl;
		}
	}
}

// Redefined display function
void EnemyType2::displayInfo() {
	Enemy::displayInfo();
	cout << "Movement Speed: " << MOVEMENT << " feet/sec" << endl;
	cout << "Rocket Supply: " << supply << " rocket(s)" << endl << endl;
}

// Validate enemy movement
// LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3
bool EnemyType2::validateMovement(int dir) {
	switch (dir) {
	case 0:
		if (x_position - MOVEMENT < MIN_X) {
			return false;
		}
		break;
	case 1:
		if (x_position + MOVEMENT > MAX_X) {
			return false;
		}
		break;
	case 2:
		if (y_position - MOVEMENT < MIN_Y) {
			return false;
		}
		break;
	case 3:
		if (y_position + MOVEMENT > MAX_Y) {
			return false;
		}
		break;
	}
	return true;
}