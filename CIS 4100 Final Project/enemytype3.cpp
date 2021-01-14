/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType3 Class Implementation
*/

#include "enemytype3.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Default Constructor
EnemyType3::EnemyType3():Enemy() {}

// Overloaded Constructor
EnemyType3::EnemyType3(string n, int xPos, int yPos, int st, double w, double h, int am) {
	name = n;
	x_position = xPos;
	y_position = yPos;
	status = st;
	width = w;
	height = h;
	ammo = am;
}

// Getter for MOVEMENT constant
int EnemyType3::getMOVEMENT() {
	return MOVEMENT;
}

// Getter for ammo variable
int EnemyType3::getAmmo() {
	return ammo;
}

// Setter for ammo variable
void EnemyType3::setAmmo(int am) {
	ammo = am;
}

// Enemy moves in a random direction
void EnemyType3::move_position() {
	
	// If enemy is dead, it cannot move
	if (status == 0) {
		cout << name << " is dead and cannot move ";
	}

	else {
		// Seed random number generator
		unsigned int seed = time(0);
		srand(seed);

		// Type 3 Enemies can only move Left or Right
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
void EnemyType3::fire_weapon() {

	// If enemy is dead, it cannot attack
	if (status == 0) {
		cout << name << " is dead and cannot attack" << endl;
	}

	else {
		cout << name;

		// If enemy is out of ammo, it cannot attack
		if (ammo == 0) {
			cout << " is out of ammo, so it cannot attack" << endl;
		}

		// If enemy still has ammo, it attacks. Decrement remaining ammo accordingly
		else {
			ammo -= 1;
			cout << " fires Rifle (" << ammo << " bullet(s) left)" << endl;
		}
	}
}

// Enemy is damaged, update status
void EnemyType3::update_status() {

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
			cout << " (\"IMPOSSIBLE!!\")" << endl;
		}

		// Enemy takes 1 damage and still has 1+ HP left
		else {
			cout << " (\"EXTERMINATE\")" << endl;
		}
	}
}

// Redefined display function
void EnemyType3::displayInfo() {
	Enemy::displayInfo();
	cout << "Movement Speed: " << MOVEMENT << " feet/sec" << endl;
	cout << "Remaining Ammo: " << ammo << " bullet(s)" << endl << endl;
}

// Validate enemy movement
// LEFT = 0, RIGHT = 1
bool EnemyType3::validateMovement(int dir) {
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