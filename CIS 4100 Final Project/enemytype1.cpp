/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType1 Class Implementation
*/

#include "enemytype1.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Default Constructor
EnemyType1::EnemyType1():Enemy() {}

// Overloaded Constructor
EnemyType1::EnemyType1(string n, int xPos, int yPos, int st, double w, double h) {
	name = n;
	x_position = xPos;
	y_position = yPos;
	status = st;
	width = w;
	height = h;
}

// Getter for MOVEMENT constant
int EnemyType1::getMOVEMENT() {
	return MOVEMENT;
}

// Enemy moves in a random direction
void EnemyType1::move_position() {

	// If enemy is dead, it cannot move
	if (status == 0) {
		cout << name << " is dead and cannot move ";
	}
	
	else {
		// Seed random number generator
		unsigned int seed = time(0);
		srand(seed);

		// Type 1 Enemies can only move Left or Right
		// Choose a random direction. If enemy can't move in one direction, move in opposite direction instead.
		// LEFT = 0, RIGHT = 1
		int direction = rand() % 2;

		if (!validateMovement(direction)) {
			if (direction == 0)
				direction += 1;
			else
				direction -= 1;
		}

		// Enemy moves in chosen direction
		// Update x_position accordingly
		switch (direction) {
		case 0:
			x_position -= MOVEMENT;
			break;
		case 1:
			x_position += MOVEMENT;
			break;
		}

		cout << name << " moves to (" << x_position << "," << y_position << ") ";
	}
}

// Enemy attacks
void EnemyType1::fire_weapon() {

	// If enemy is dead, it cannot attack
	if (status == 0) {
		cout << name << " is dead and cannot attack" << endl;
	}
	
	else {
		// Seed random number generator
		unsigned int seed = time(0);
		srand(seed);

		int attack = rand() % 3;
		cout << name << " attacks with " << attackArr[attack] << endl;
	}
}

// Enemy is damaged, update status
void EnemyType1::update_status() {

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
			cout << " (\"roaaaar\")" << endl;
		}

		// Enemy takes 1 damage and still has 1+ HP left
		else {
			cout << " (\"ROOOAR\")" << endl;
		}
	}
}

// Redefined display function
void EnemyType1::displayInfo() {
	Enemy::displayInfo();
	cout << "Movement Speed: " << MOVEMENT << " feet/sec" << endl << endl;
}

// Check that enemy will stay within the given map
// LEFT = 0, RIGHT = 1
bool EnemyType1::validateMovement(int dir) {
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
	}
	return true;
}