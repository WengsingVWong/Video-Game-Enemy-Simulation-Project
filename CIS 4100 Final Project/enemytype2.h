/*
Author: Wengsing Wong
CIS 4100 MFA
Final Project - EnemyType2 Class Specification
*/

#include "enemy.h"
#ifndef ENEMYTYPE2_H
#define ENEMYTYPE2_H

class EnemyType2 : public Enemy {
private:

	// Distance a Type 2 Enemy (Military Aircraft) can travel in a single move_position() call
	const int MOVEMENT = 20;

	// Remaining supply of rockets for rocket launcher
	int supply = 0;

public:

	// Default Constructor
	EnemyType2();

	// Overloaded Constructor
	EnemyType2(string, int, int, int, double, double, int);

	// Getter for MOVEMENT constant
	int getMOVEMENT();

	// Getter for supply variable
	int getSupply();

	// Setter for supply variable
	void setSupply(int);

	// Enemy moves in a random direction
	void move_position();

	// Enemy attacks
	void fire_weapon();

	// Enemy is damaged, update status
	void update_status();

	// Redefined display function
	void displayInfo();

	// Validate enemy movement
	bool validateMovement(int);
};
#endif